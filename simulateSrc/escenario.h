#ifndef escenario_h
#define escenario_h


#include <math.h>

#include "ns3/node-container.h"
#include "ns3/net-device-container.h"
#include "ns3/node.h"
#include "ns3/internet-stack-helper.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/ipv4-interface-container.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/ipv4-nix-vector-helper.h"
#include "ns3/ipv4-nix-vector-routing.h"

#include "retardo.h"
#include "puente_helper.h"
#include "generaTrafico.h"

#define SUBRED "10.1.0.0"
#define MASCARA "255.255.0.0"

#define STOPTIME 140


using namespace ns3;


typedef struct{
	int bCubeLevel;
	int nNodos;
	PuenteConfig_t puenteConfig;
	bool ControlaTrafico;
	uint32_t PorcentajeTrafico;
} StageConfig_t;

typedef struct{
	NodeContainer nodes;
	NetDeviceContainer devices;
} TopologyElements_t;


double escenario(StageConfig_t *config);

void topologiaFisica(int bCubeLevel, int dimSize, TopologyElements_t &topology, PuenteConfig_t *puenteConfig);

void asignaDirecciones(TopologyElements_t &topology, int nDim, int dimSize);

int coordToIndex(int dimSize, int dim, int coord);


#endif