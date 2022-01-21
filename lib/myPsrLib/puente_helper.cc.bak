
#include "ns3/core-module.h"
#include "ns3/node.h"
#include "ns3/node-container.h"
#include "ns3/net-device-container.h"
#include "ns3/csma-helper.h"
#include "ns3/bridge-helper.h"
#include "ns3/queue.h"
#include "ns3/csma-net-device.h"

#include "puente_helper.h"


NS_LOG_COMPONENT_DEFINE("PuenteHelper");


using namespace ns3;


Ptr<Node> PuenteHelper (NodeContainer nodosLan, NetDeviceContainer & d_nodosLan, PuenteConfig_t *config){
	
	NetDeviceContainer d_puertosBridge;
	CsmaHelper         h_csma;
	BridgeHelper       h_bridge;
	Ptr<Node>          puente = CreateObject<Node>();
	
	// Data rate config
	if(config->regimenBinario.GetBitRate() != 0){
		h_csma.SetChannelAttribute("DataRate", DataRateValue(config->regimenBinario));
	}
	
	for (NodeContainer::Iterator indice = nodosLan.Begin (); indice != nodosLan.End (); indice++){
			
		NetDeviceContainer enlace = h_csma.Install(NodeContainer (*indice, puente));
		d_nodosLan.Add (enlace.Get (0));
		d_puertosBridge.Add (enlace.Get (1));
		
	}
	
	h_bridge.Install (puente, d_puertosBridge);
	
	Ptr<NetDevice> bridgePort = d_puertosBridge.Get(0);
	Ptr<CsmaChannel> channel = bridgePort->GetChannel()->GetObject<CsmaChannel>();
	DataRateValue dataRate;
	channel->GetAttribute("DataRate", dataRate);
	
	// Device queue configuration
	if(config->deviceQueueSize != -1){
		QueueSize deviceQueueSize(ns3::PACKETS, config->deviceQueueSize);
		for(NetDeviceContainer::Iterator i = d_puertosBridge.Begin(); i != d_puertosBridge.End(); i++){
			Ptr<Queue<Packet>> deviceQueue = (*i)->GetObject<CsmaNetDevice>()->GetQueue();
			deviceQueue->SetMaxSize(deviceQueueSize);
		}
	}
	
	NS_LOG_INFO("Creado puente: (regimen_binario=" << dataRate.Get() << ")");
	
	return puente;
	
}