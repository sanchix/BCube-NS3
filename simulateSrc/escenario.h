#ifndef escenario_h
#define escenario_h


#include "ns3/node-container.h"
#include "ns3/net-device-container.h"


#define SUBRED "10.1.0.0"
#define MASCARA "255.255.0.0"


using namespace ns3;


typedef struct{
	int bCubeLevel;
	int nNodosDim;
} StageConfig_t;

typedef struct{
	NodeContainer nodos;
	NetDeviceContainer c_dispositivos;
} topologyElements_t;

void topologiaFisica(int bCubeLevel, int dimSize, topologyElements_t &elements);
double escenario(StageConfig_t *config);


#endif