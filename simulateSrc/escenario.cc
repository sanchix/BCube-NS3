
#include "escenario.h"
#include "puente_helper.h"
#include "generaTrafico.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("Escenario");


double escenario(StageConfig_t *config){
	
	// Eliminar cualquier variable o elemento de red de una simulación anterior.
	Simulator::Destroy();
	
	TopologyElements_t topology;
	double nNodosDim = config->bCubeLevel>0?pow(config->nNodos, 1/config->bCubeLevel):config->nNodos;
	NS_LOG_INFO("Generating topology for " << nNodosDim << " nodes in each one of the " << config->bCubeLevel + 1 << " dims");
	topologiaFisica(config->bCubeLevel, nNodosDim, topology);
	NS_LOG_INFO("Topology generated");
	NS_LOG_DEBUG("El numero de equipos es: "<< topology.nodes.GetN());

	asignaDirecciones(topology);
	Llamada *llamada = generaTrafico(topology.nodes);
	llamada = llamada;

	//AppOnOff Obs_OnOff = llamada->GetObserver();
	
	Simulator::Stop(Seconds(300));
	Simulator::Run();

	for (uint32_t j = 0; j<100;j++){
		NS_LOG_DEBUG("El nodo "<<j<< " ha recibido "<< topology.nodes.Get(j)->GetApplication(0)->GetObject<UdpServer>()->GetReceived() <<" paquetes");
	}
	//NS_LOG_DEBUG ("El observador nos da este ultimo tiempo: " << Obs_OnOff.getTUltPaq());
	return 1.0;
	
}


void asignaDirecciones(TopologyElements_t &topology){
	
	Ipv4NixVectorHelper h_Nix_Routing;
	
	InternetStackHelper h_pila;
	h_pila.SetRoutingHelper(h_Nix_Routing);
	h_pila.SetIpv6StackInstall (false);
	h_pila.Install (topology.nodes);
	NS_LOG_INFO("Internet stack installed");
	
	Ipv4AddressHelper h_direcciones (SUBRED, MASCARA);
	Ipv4InterfaceContainer c_interfaces = h_direcciones.Assign (topology.devices);
	Ipv4NixVectorRouting IPv4NixVectorRouting = Ipv4NixVectorRouting();
	NS_LOG_INFO("Direcciones colocadas");

	// Generación de rutas en un fichero para debug
	/*OutputStreamWrapper Outputwrapper = OutputStreamWrapper("NixVector12.txt",std::ios::out);
	IPv4NixVectorRouting.PrintRoutingPath(topology.nodes.Get(0),topology.nodes.Get(1)->GetObject<Ipv4L3Protocol>()->GetAddress(1, 0).GetLocal(),&Outputwrapper,Time::MS);
	IPv4NixVectorRouting.PrintRoutingPath(topology.nodes.Get(0),topology.nodes.Get(1)->GetObject<Ipv4L3Protocol>()->GetAddress(2, 0).GetLocal(),&Outputwrapper,Time::MS);
	IPv4NixVectorRouting.PrintRoutingPath(topology.nodes.Get(0),topology.nodes.Get(1)->GetObject<Ipv4L3Protocol>()->GetAddress(3, 0).GetLocal(),&Outputwrapper,Time::MS);
	IPv4NixVectorRouting.PrintRoutingPath(topology.nodes.Get(0),topology.nodes.Get(1024)->GetObject<Ipv4L3Protocol>()->GetAddress(1, 0).GetLocal(),&Outputwrapper,Time::MS);
	IPv4NixVectorRouting.PrintRoutingPath(topology.nodes.Get(0),topology.nodes.Get(2800)->GetObject<Ipv4L3Protocol>()->GetAddress(1, 0).GetLocal(),&Outputwrapper,Time::MS);
	*/
	
	// Trazas
	for (uint32_t i = 0; i<topology.nodes.GetN(); i++){
		Ptr<Node> aux = topology.nodes.Get(i);
		NS_LOG_DEBUG("ID: "<<aux->GetId() << "  IP:");
		
		Ptr<Ipv4L3Protocol> L_IP = aux->GetObject<Ipv4L3Protocol> ();
		NS_LOG_DEBUG("El numero de interfaces es: "<< L_IP->GetNInterfaces());
		for (uint32_t j=0; j< L_IP->GetNInterfaces() ;j++){
			NS_LOG_DEBUG( L_IP->GetAddress (j, 0).GetLocal () );
		}
	}
	
}


void topologiaFisica(int bCubeLevel, int dimSize, TopologyElements_t &topology){
	
	int nDims = bCubeLevel+1;
	int numEquipos = pow(dimSize,nDims);
	NS_LOG_INFO("NumEquipos = " << numEquipos);
	
	topology.nodes = NodeContainer(numEquipos);

	PuenteConfig_t puenteConfig;
	puenteConfig.regimenBinario = DataRate(0);
	
			
	NS_LOG_INFO("BCUBE " << bCubeLevel);
		
	// For every dim
	for(int i = 0; i < nDims; i++){
		NS_LOG_INFO("For dim " << i);
		
		// For every switch
		for(int j = 0; j < pow(dimSize, nDims-1); j++){
			
			std::string cstr = "Coords: ";
			
			// Generate coordinates of base element
			int indexBase = 0;
			for(int k = 0; k < nDims-1; k++){
				int c = (j/(int)pow(dimSize,k))%dimSize;
				indexBase += coordToIndex(dimSize, (k+1+i)%nDims, c);
				cstr += "\t" + std::to_string(c);
			}
			NS_LOG_INFO(cstr + "\tbase: " + std::to_string(indexBase));
			
			// Compose line and create bridge
			NodeContainer line;
			NetDeviceContainer nodosLan;
			for(int k = 0; k < dimSize; k++){
				int index = indexBase+coordToIndex(dimSize, i, k);
				line.Add(topology.nodes.Get(index));
			}
			NS_LOG_INFO(line.GetN());
			PuenteHelper(line, nodosLan, &puenteConfig);
			topology.devices.Add(nodosLan);	
			
		}
		
	}
	
}


int coordToIndex(int dimSize, int dim, int coord){
	int index = -1;
	if(coord < dimSize && coord >= 0){
		index = pow(dimSize, dim)*coord;
	}
	return index;
}
