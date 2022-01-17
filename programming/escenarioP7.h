
#ifndef escenarioP7_h
#define escenarioP7_h


#include "ns3/node.h"
#include "ns3/bridge-net-device.h"

#include "puente_helper.h"

/*
#define SERVER_PORT    9
#define SERVER_NODE_INDEX 0


#define UDP_HEADER_SIZE 8
#define IP_HEADER_SIZE 20
#define PPP_HEADER_SIZE 2
*/
#define MASCARA "255.255.255.0"


using namespace ns3;
using namespace std;


typedef struct{
	Ptr<RandomVariableStream> tON;
	Ptr<RandomVariableStream> tOFF;
	DataRate tasaEnvioOn;
	Time tiempoTX;
} ClientConfig_t;

typedef struct{
	int indiceFuenteEnSubred;
	ClientConfig_t clientConfig;
} ApplicationConfig_t;

typedef struct{
	uint32_t numSubredes;
	
	uint32_t numEquipos;
	vector<string> dirSubredes;
	string prefixSubredesInternas;
	PuenteConfig_t puenteConfig;
	
	ApplicationConfig_t applicationConfig;
	
	Time instanteCaidaEnlace;
	Time duracionCaidaEnlace;
	
} StageConfig_t;


/*
 *	Configura y simula un escenario.
 */
double escenario(StageConfig_t *config);

NodeContainer creaSubred(uint32_t numEquipos, string dirSubred, Ptr<Node> encaminador = 0);

void dibuja (NodeContainer nodos, Ptr<Node> puente);

Ptr<BridgeNetDevice> GetBridgeNetDevice (Ptr<Node> nodo);



#endif