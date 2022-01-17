
#ifndef escenario_h
#define escenario_h


using namespace ns3;


typedef struct{
	int nDim;
	int nNodosDim;
} StageConfig_t;


double escenario(StageConfig_t *config);