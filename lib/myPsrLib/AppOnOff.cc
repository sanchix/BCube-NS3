#include "ns3/object-base.h"
#include "ns3/log.h"
#include "AppOnOff.h"


using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("AppOnOff");


AppOnOff::AppOnOff (ApplicationContainer emisores)
{
	for(ApplicationContainer::Iterator i = emisores.Begin (); i != emisores.End (); i++){
			Ptr<Application> object = *i;
			object->TraceConnectWithoutContext ("Tx", MakeCallback(&AppOnOff::transmision, this) );  
	}

}

void
AppOnOff::transmision (Ptr<const Packet> paquete)
{	
	NS_LOG_FUNCTION (paquete);
	numeroTX = numeroTX + 1;
}

int
AppOnOff::getNumeroTX ()
{	
	return numeroTX;
}