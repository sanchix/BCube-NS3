#include "ns3/ptr.h"
#include "ns3/application-container.h"

using namespace ns3;

class AppOnOff
{
public:
	AppOnOff (ApplicationContainer emisores);
	void transmision (Ptr<const Packet> paquete);
	int getNumeroTX ();
private:
	int numeroTX = 0;
};
