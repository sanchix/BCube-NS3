#include "ns3/ptr.h"
#include "ns3/application-container.h"
#include "ns3/simulator.h"

using namespace ns3;

class AppOnOff
{
public:
	AppOnOff (Ptr<Application> emisor);
	void transmision (Ptr<const Packet> paquete);
	int getNumeroTX ();
        Time getTUltPaq ();
private:
	int numeroTX = 0;
        Time tiempo_ult_paq;
};
