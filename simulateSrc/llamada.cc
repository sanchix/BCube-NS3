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
	
	NS_LOG_INFO("Tam pack: " << TamPack);
	
}

void Llamada::Call(Ptr<Node> nodo_origen){
	
	NS_LOG_FUNCTION("CALL - El id del nodo llamante: "<< nodo_origen->GetId());
	NS_LOG_FUNCTION("El estado del nodo es: "<<nodeCalledList->at(nodo_origen->GetId()));

	int i = 0;
	for (std::vector<int>::iterator it = nodeCalledList->begin(); it != nodeCalledList->end(); ++it){
		NS_LOG_DEBUG("El valor del estado del nodo "<<i<<" es "<< *it);
		i++;
	}
	NS_LOG_INFO("nNodesInCall: " << nNodesInCall);

    if(nodeCalledList->at(nodo_origen->GetId()) != LIBRE){
        nodeCalledList->at(nodo_origen->GetId()) = IMPACIENTE;
		int i = 0;
		for (std::vector<int>::iterator it = nodeCalledList->begin(); it != nodeCalledList->end(); ++it){
			NS_LOG_DEBUG("El valor del estado del nodo "<<i<<" es "<< *it);
			i++;
		}
    }
    else{
    	uint32_t id_destino = 0;
		Uniform_equipo_destino->SetAttribute("Max", DoubleValue((double)(TodosNodos.GetN()-2-nNodesInCall)));
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
		
		Time t_fin = Seconds(Exp_duracion->GetValue());
		NS_LOG_DEBUG("El tiempo de finalizacíon de la llamada es :" << t_fin);

		OnOffHelper H_ClientOnOff_origen ("ns3::UdpSocketFactory",InetSocketAddress(Nodo_Destino.Get(0)->GetObject<Ipv4L3Protocol>()->GetAddress(1, 0).GetLocal(), PUERTO));
		H_ClientOnOff_origen.SetConstantRate(TasaApp,TamPack);
		H_ClientOnOff_origen.SetAttribute("OnTime",PointerValue(Exp_ON));
  		H_ClientOnOff_origen.SetAttribute("OffTime",PointerValue(Exp_OFF));
		H_ClientOnOff_origen.Install (Nodo_Origen);
        Simulator::Schedule(t_fin, &Llamada::Hang,this, Nodo_Origen.Get(0), Nodo_Destino.Get(0));
        
        OnOffHelper H_ClientOnOff_destino ("ns3::UdpSocketFactory",InetSocketAddress(Nodo_Origen.Get(0)->GetObject<Ipv4L3Protocol>()->GetAddress(1, 0).GetLocal(), PUERTO));
		H_ClientOnOff_destino.SetConstantRate(TasaApp,TamPack);
		H_ClientOnOff_destino.SetAttribute("OnTime",PointerValue(Exp_ON));
		H_ClientOnOff_destino.SetAttribute("OffTime",PointerValue(Exp_OFF));
		H_ClientOnOff_destino.Install (Nodo_Destino);
        
    }
}

void Llamada::Hang(Ptr<Node> nodo_origen,Ptr<Node> nodo_destino){

	uint32_t id_destino = nodo_destino->GetId();
	uint32_t id_origen = nodo_origen->GetId();
	NS_LOG_FUNCTION("HANG - El id del nodo llamante: "<< id_origen);
	NS_LOG_FUNCTION("HANG - El id del nodo llamado: "<< id_destino);

    // CERRAR APLICACIONES
    int numAppOrig = nodo_origen->GetNApplications();
    int numAppDestino = nodo_destino->GetNApplications();
    NS_LOG_DEBUG("HANG - ANTES Numero de Aplicaciones del origen: "<< numAppOrig);
    NS_LOG_DEBUG("HANG - ANTES Numero de Aplicaciones del destino: "<< numAppDestino);
    
    //ObjectDeleter::Delete(GetPointer(nodo_origen->GetApplication(1)->GetObject<Object>()));
    //ObjectDeleter::Delete(GetPointer(nodo_destino->GetApplication(1)->GetObject<Object>()));
    //nodo_origen->GetApplication(1)->Dispose();
    //nodo_destino->GetApplication(1)->Dispose();
    //ns3::DefaultDeleter<Application>::Delete(GetPointer(nodo_origen->GetApplication(1)));
    //ns3::DefaultDeleter<Application>::Delete(GetPointer(nodo_destino->GetApplication(1)));
    
    //Cambiamos los parametros de la aplicacion para que no mande mas trafico...
    nodo_origen->GetApplication(numAppOrig-1)->SetAttribute("OnTime",PointerValue(Exp_0));
   	nodo_destino->GetApplication(numAppDestino-1)->SetAttribute("OffTime",PointerValue(Exp_1));
   	
    NS_LOG_DEBUG("HANG - DESPUES Numero de Aplicaciones del origen: "<< numAppOrig);
    NS_LOG_DEBUG("HANG - DESPUES Numero de Aplicaciones del destino: "<< numAppDestino);

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