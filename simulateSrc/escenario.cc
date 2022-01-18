
#include "ns3/command-line.h"
#include "ns3/node-container.h"
#include "ns3/node.h"
#include "ns3/internet-stack-helper.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/ipv4-interface-container.h"
#include "ns3/udp-client-server-helper.h"
#include "ns3/on-off-helper.h"
#include "ns3/udp-echo-client.h"
#include "ns3/application-container.h"
#include "ns3/point-to-point-net-device.h"
#include "ns3/point-to-point-channel.h"
#include "ns3/uinteger.h"
#include "ns3/error-model.h"
#include "ns3/enum.h"
#include "ns3/double.h"
#include "ns3/uinteger.h"
#include "ns3/pointer.h"
#include "ns3/csma-helper.h"
#include "ns3/udp-socket-factory.h"
#include "ns3/queue-disc.h"
#include "ns3/traffic-control-layer.h"
#include "ns3/queue.h"
#include "ns3/csma-net-device.h"
#include "ns3/net-device-container.h"
#include "ns3/fifo-queue-disc.h"
#include "ns3/ipv4-global-routing-helper.h"

#include "ns3/ipv4-nix-vector-helper.h"
#include "ns3/ipv4-nix-vector-routing.h"

#include "escenario.h"
#include "puente_helper.h"


using namespace ns3;

NS_LOG_COMPONENT_DEFINE("Escenario");

int coordToIndex(int dimSize, int dim, int coord);

double escenario(StageConfig_t *config){
	
	// Eliminar cualquier variable o elemento de red de una simulación anterior.
	Simulator::Destroy();
	
	NodeContainer todosNodos = topologiaFisica(config->bCubeLevel, config->nNodosDim);
	NS_LOG_INFO("Topology generated");
	NS_LOG_DEBUG("El numero de equipos es: "<< todosNodos.GetN());

/*
	for (uint32_t i = 0; i<todosNodos.GetN();i++){
		Ptr<Node> aux = todosNodos.Get(i);
		NS_LOG_DEBUG("ID: "<<aux->GetId() << "  IP:");
		
		Ptr<Ipv4L3Protocol> L_IP = aux->GetObject<Ipv4L3Protocol> ();
		NS_LOG_DEBUG("El numero de interfaces es: "<< L_IP->GetNInterfaces());
		for (uint32_t j=0; j< L_IP->GetNInterfaces() ;j++){
			NS_LOG_DEBUG( L_IP->GetAddress (j, 0).GetLocal () );
		}
	}
*/
	return 1;
	
}

NodeContainer topologiaFisica(int bCubeLevel, int dimSize){
	
	int nDims = bCubeLevel+1;
	int numEquipos = pow(dimSize,nDims);
	NS_LOG_INFO("NumEquipos = " << numEquipos);
	
	NodeContainer todosNodos(numEquipos);
	NetDeviceContainer c_dispositivos;
	
	Ipv4NixVectorHelper h_Nix_Routing;
	
	InternetStackHelper h_pila;
	h_pila.SetRoutingHelper(h_Nix_Routing);
	h_pila.SetIpv6StackInstall (false);
	h_pila.Install (todosNodos);

	PuenteConfig_t puenteConfig;
	puenteConfig.regimenBinario = DataRate(0);
	
			
	NS_LOG_INFO("BCUBE " << bCubeLevel);
		
	// For every dim
	for(int i = 0; i < nDims; i++){
		NS_LOG_INFO("For dim " << i);
		
		// For every switch
		for(int j = 0; j < pow(dimSize, nDims-1); j++){
			
			std::string cstr = "Coords: ";
			
			int indexBase = 0;
			
			for(int k = 0; k < nDims-1; k++){
				int c = (j/(int)pow(dimSize,k))%dimSize;
				indexBase += coordToIndex(dimSize, (k+1+i)%nDims, c);
				cstr += "\t" + std::to_string(c);
			}
			NS_LOG_INFO(cstr + "\tbase: " + std::to_string(indexBase));
			
			NodeContainer line;
			NetDeviceContainer nodosLan;
			for(int k = 0; k < dimSize; k++){
				int index = indexBase+coordToIndex(dimSize, i, k);
				line.Add(todosNodos.Get(index));
			}
			NS_LOG_INFO(line.GetN());
			PuenteHelper(line, nodosLan, &puenteConfig);
			c_dispositivos.Add(nodosLan);	
			
		}
		
	}
		
	return todosNodos;
	
}

int coordToIndex(int dimSize, int dim, int coord){
	int index = -1;
	if(coord < dimSize && coord >= 0){
		index = pow(dimSize, dim)*coord;
	}
	return index;
}