#include "llamada.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("Llamada");

Llamada::Llamada(NodeContainer nodos, double duracion, double max_t_inicio){

	TasaApp = DataRate("32kb/s");
	TamPack = 92;

	double tiempoAppOn = 0.350;
	double tiempoAppOff = 0.650;
	Ptr<ExponentialRandomVariable> Exp_ON = CreateObject<ExponentialRandomVariable> ();
	Ptr<ExponentialRandomVariable> Exp_OFF = CreateObject<ExponentialRandomVariable> ();
	Exp_ON->SetAttribute ("Mean", DoubleValue (tiempoAppOn));
	Exp_OFF->SetAttribute ("Mean", DoubleValue (tiempoAppOff));
	Config::SetDefault ("ns3::OnOffHelper::OnTime",PointerValue(Exp_ON));
  	Config::SetDefault ("ns3::OnOffHelper::OffTime",PointerValue(Exp_OFF));

	TodosNodos = nodos;
	nodeCalledList = std::vector<int> (TodosNodos.GetN(),LIBRE);

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

    if(nodeCalledList.at(nodo_origen->GetId()) != LIBRE){
        nodeCalledList.at(nodo_origen->GetId()) = IMPACIENTE;
    }
    else{
    	uint32_t id_destino;
        do{
            id_destino = Uniform_equipo_destino->GetInteger();
        }
        while(nodeCalledList.at(id_destino) != LIBRE);
        
        nodeCalledList.at(nodo_origen->GetId()) = OCUPADO;
        nodeCalledList.at(id_destino) = OCUPADO;
        
        // CREAR APLICACIONES FUENTES
		NodeContainer Nodo_Origen;
		NodeContainer Nodo_Destino;

		Nodo_Origen.Add(nodo_origen);
		Nodo_Destino.Add(TodosNodos.Get(id_destino));
		
		Time t_inicio = Simulator::Now()+Seconds(Exp_duracion->GetValue());
		
		OnOffHelper H_ClientOnOff_origen ("ns3::UdpSocketFactory",InetSocketAddress(Nodo_Destino.Get(0)->GetObject<Ipv4L3Protocol>()->GetAddress(1, 0).GetLocal(), PUERTO));
		H_ClientOnOff_origen.SetConstantRate(TasaApp,TamPack);
		H_ClientOnOff_origen.Install (Nodo_Origen);
        Simulator::Schedule(t_inicio, &Llamada::Hang,this, Nodo_Origen.Get(0), Nodo_Destino.Get(0));
        
        OnOffHelper H_ClientOnOff_destino ("ns3::UdpSocketFactory",InetSocketAddress(Nodo_Origen.Get(0)->GetObject<Ipv4L3Protocol>()->GetAddress(1, 0).GetLocal(), PUERTO));
		H_ClientOnOff_destino.SetConstantRate(TasaApp,TamPack);
		H_ClientOnOff_destino.Install (Nodo_Destino);
        
    }
}

void Llamada::Hang(Ptr<Node> nodo_origen,Ptr<Node> nodo_destino){

	uint32_t id_destino = nodo_destino->GetId();
	uint32_t id_origen = nodo_origen->GetId();

    // CERRAR APLICACIONES
    nodo_origen->GetApplication(1)->Dispose();
    nodo_destino->GetApplication(1)->Dispose();
    NS_LOG_DEBUG("Numero de Aplicaciones del origen: "<< nodo_origen->GetNApplications());
    NS_LOG_DEBUG("Numero de Aplicaciones del destino: "<< nodo_destino->GetNApplications());

    // Nueva llamada del origen
    nodeCalledList.at(id_origen) = LIBRE;
    Time t_inicio = Seconds(int64x64_t(Uniform_t_inicio->GetInteger()));
    Simulator::Schedule(Simulator::Now()+t_inicio, &Llamada::Call,this, nodo_origen);
    
    // Nueva llamada del destino (si la quiere)
    if(nodeCalledList.at(id_destino) == IMPACIENTE){

        nodeCalledList.at(id_destino) = LIBRE;
        Simulator::Schedule(Simulator::Now(), &Llamada::Call,this, nodo_destino);
    }

}