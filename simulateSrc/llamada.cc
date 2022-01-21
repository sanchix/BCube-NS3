#include "llamada.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("Llamada");


Llamada::Llamada(NodeContainer nodos, double duracion, double max_t_inicio){
	
	NS_LOG_FUNCTION("Entramos en el constructor Llamada: ");
	NS_LOG_FUNCTION("La duracion media de las llamadas será: "<< duracion);
	NS_LOG_FUNCTION("El máximo tiempo en el que podrá comenzar una llamada: "<< max_t_inicio);

	TasaApp = DataRate("32kb/s");
	TamPack = 92;

	double tiempoAppOn = 0.350;
	double tiempoAppOff = 0.650;
	Exp_ON = CreateObject<ExponentialRandomVariable> ();
	Exp_OFF = CreateObject<ExponentialRandomVariable> ();
	Exp_ON->SetAttribute ("Mean", DoubleValue (tiempoAppOn));
	Exp_OFF->SetAttribute ("Mean", DoubleValue (tiempoAppOff));

	Exp_0 = CreateObject<ConstantRandomVariable> ();
	Exp_1 = CreateObject<ConstantRandomVariable> ();
	Exp_0->SetAttribute ("Constant", DoubleValue (0.0));
	Exp_1->SetAttribute ("Constant", DoubleValue (1.0));
	
	//NS_LOG_DEBUG("Tam pack: " << TamPack);


	TodosNodos = nodos;
	nodeCalledList = new std::vector<int> (TodosNodos.GetN(),int(LIBRE));
	nNodesInCall = 0;
	
	Uniform_t_inicio = CreateObject<UniformRandomVariable> ();
	Uniform_t_inicio->SetAttribute ("Min", DoubleValue (0.0));
	Uniform_t_inicio->SetAttribute ("Max", DoubleValue (max_t_inicio));

	Exp_duracion = CreateObject<ExponentialRandomVariable> ();
	Exp_duracion->SetAttribute ("Mean", DoubleValue (duracion));

	Uniform_equipo_destino = CreateObject<UniformRandomVariable> ();
	Uniform_equipo_destino->SetAttribute ("Min", DoubleValue (0.0));
	Uniform_equipo_destino->SetAttribute ("Max", DoubleValue (double(TodosNodos.GetN()-1)));

	Time t_inicio;
	for(uint32_t i = 0; i<TodosNodos.GetN(); i++){
		t_inicio = Seconds(int64x64_t(Uniform_t_inicio->GetInteger()));	
        Simulator::Schedule(t_inicio, &Llamada::Call, this, TodosNodos.Get(i));
	}
	
	
}

void Llamada::Call(Ptr<Node> nodo_origen){
	
	NS_LOG_FUNCTION("CALL - El id del nodo llamante: "<< nodo_origen->GetId());
	NS_LOG_DEBUG("El estado del nodo es: "<<nodeCalledList->at(nodo_origen->GetId()));

	uint32_t id_destino = 0;
	int nodosLibres = TodosNodos.GetN()-1-nNodesInCall;	

	// Trazas
	if (nodo_origen->GetNApplications() > 1){
		TimeValue t_parada;
		nodo_origen->GetApplication(nodo_origen->GetNApplications() - 1)->GetAttribute("StopTime", t_parada);
		NS_LOG_DEBUG ("Valor del tiempo de parada del nodo " << nodo_origen->GetId() << ": "<< t_parada.Get());
	}	
	//int i = 0;
	//for (std::vector<int>::iterator it = nodeCalledList->begin(); it != nodeCalledList->end(); ++it){
	//	NS_LOG_DEBUG("El valor del estado del nodo "<<i<<" es "<< *it);
	//	i++;
	//}
	NS_LOG_DEBUG("nNodesInCall: " << nNodesInCall);


	// Si está ocupado -> impaciente
    if(nodeCalledList->at(nodo_origen->GetId()) != LIBRE){
        nodeCalledList->at(nodo_origen->GetId()) = IMPACIENTE;
        // Trazas
		//int i = 0;
		//for (std::vector<int>::iterator it = nodeCalledList->begin(); it != nodeCalledList->end(); ++it){
		//	NS_LOG_DEBUG("El valor del estado del nodo "<<i<<" es "<< *it);
		//	i++;
		//}
    }
	// Si está libre pero no se puede llamar
    else if(nodosLibres <= 0){
			Time t_inicio = Seconds(int64x64_t(Uniform_t_inicio->GetInteger()));
			Simulator::Schedule(t_inicio, &Llamada::Call, this, nodo_origen);
	}
		
	// Si sí se puede llamar
	else{
		
		Uniform_equipo_destino->SetAttribute("Max", DoubleValue((double)(nodosLibres-1)));
		uint32_t id_destino_libre = Uniform_equipo_destino->GetInteger();
	
		// id_destino_libre = 3
		//                |
		// OOXOOOXOOXOOOOOXO
		// index -> 3

		NS_LOG_DEBUG("El id del nodo destino libre: " << id_destino_libre);
		uint32_t index = 0;
		while(index <= id_destino_libre){
			while(nodeCalledList->at(id_destino) != LIBRE || id_destino == nodo_origen->GetId()){
				id_destino++;
			}
			id_destino++;
			index++;
		}
		id_destino--;

		NS_LOG_DEBUG("El id del nodo destino: " << id_destino);

		nodeCalledList->at(nodo_origen->GetId()) = OCUPADO;
		nodeCalledList->at(id_destino) = OCUPADO;
		nNodesInCall += 2;
		
		// CREAR APLICACIONES FUENTES
		NodeContainer Nodo_Origen;
		NodeContainer Nodo_Destino;

		Nodo_Origen.Add(nodo_origen);
		Nodo_Destino.Add(TodosNodos.Get(id_destino));

		ApplicationContainer App_Nodo_Origen;
		
		Time t_fin = Seconds(Exp_duracion->GetValue());
		NS_LOG_DEBUG("El tiempo de finalizacíon de la llamada es :" << t_fin);

		OnOffHelper H_ClientOnOff_origen ("ns3::UdpSocketFactory",InetSocketAddress(Nodo_Destino.Get(0)->GetObject<Ipv4L3Protocol>()->GetAddress(1, 0).GetLocal(), PUERTO));

		H_ClientOnOff_origen.SetConstantRate(TasaApp,TamPack);		
		H_ClientOnOff_origen.SetAttribute("OnTime",PointerValue(Exp_ON));
		H_ClientOnOff_origen.SetAttribute("OffTime",PointerValue(Exp_OFF));
		H_ClientOnOff_origen.SetAttribute("StopTime",TimeValue(Simulator::Now()+t_fin));
		App_Nodo_Origen=H_ClientOnOff_origen.Install (Nodo_Origen);
		
		OnOffHelper H_ClientOnOff_destino ("ns3::UdpSocketFactory",InetSocketAddress(Nodo_Origen.Get(0)->GetObject<Ipv4L3Protocol>()->GetAddress(1, 0).GetLocal(), PUERTO));
		H_ClientOnOff_destino.SetConstantRate(TasaApp,TamPack);
		H_ClientOnOff_destino.SetAttribute("OnTime",PointerValue(Exp_ON));
		H_ClientOnOff_destino.SetAttribute("OffTime",PointerValue(Exp_OFF));
		H_ClientOnOff_origen.SetAttribute("StopTime",TimeValue(Simulator::Now()+t_fin));
		H_ClientOnOff_destino.Install (Nodo_Destino);

		Simulator::Schedule(t_fin, &Llamada::Hang,this, Nodo_Origen.Get(0), Nodo_Destino.Get(0));
        
    }
	
}


void Llamada::Hang(Ptr<Node> nodo_origen,Ptr<Node> nodo_destino){

    uint32_t id_destino = nodo_destino->GetId();
    uint32_t id_origen = nodo_origen->GetId();
    NS_LOG_FUNCTION("HANG - El id del nodo llamante: "<< id_origen);
    NS_LOG_FUNCTION("HANG - El id del nodo llamado: "<< id_destino);

    // Nueva llamada del origen
    nodeCalledList->at(id_origen) = LIBRE;
    Time t_inicio = Seconds(int64x64_t(Uniform_t_inicio->GetInteger()));
    Simulator::Schedule(t_inicio, &Llamada::Call,this, nodo_origen);
    
    // Nueva llamada del destino (si la quiere)
    if(nodeCalledList->at(id_destino) == IMPACIENTE){
		NS_LOG_INFO("Era impaciente");
        Simulator::Schedule(Seconds(0), &Llamada::Call,this, nodo_destino);
    }
	nodeCalledList->at(id_destino) = LIBRE;
	
	nNodesInCall -= 2;
}