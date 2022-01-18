#ifndef escenario_h
#define escenario_h


#include "ns3/node-container.h"


#define SUBRED "10.1.0.0"
#define MASCARA "255.255.0.0"
#define PUERTO 9


using namespace ns3;


typedef struct{
	int bCubeLevel;
	int nNodosDim;
} StageConfig_t;

NodeContainer topologiaFisica(int dim, int levels);
double escenario(StageConfig_t *config);


#endif