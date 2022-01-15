#ifndef puente_helper_h
#define puente_helper_h

#include "ns3/core-module.h"
#include "ns3/node.h"
#include "ns3/data-rate.h"
#include "ns3/node-container.h"
#include "ns3/net-device-container.h"


using namespace ns3;

#define DEFFAULT_CONFIG {DataRate("100Mb/s")}

typedef struct{
	DataRate regimenBinario;
	int deviceQueueSize = -1;
} PuenteConfig_t;


Ptr<Node> PuenteHelper (NodeContainer nodosLan, NetDeviceContainer & d_nodosLan, PuenteConfig_t *config);


#endif