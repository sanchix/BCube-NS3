#include "ns3/object-base.h"
#include "ns3/log.h"
#include "AppOnOff.h"


using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("AppOnOff");


AppOnOff::AppOnOff (Ptr<Application> emisor)
{
	
	emisor->TraceConnectWithoutContext ("Tx", MakeCallback(&AppOnOff::transmision, this) );  
	

}

void
AppOnOff::transmision (Ptr<const Packet> paquete)
{	
	NS_LOG_FUNCTION (paquete);
	numeroTX = numeroTX + 1;
	tiempo_ult_paq = Simulator::Now();
}

int
AppOnOff::getNumeroTX ()
{	
	return numeroTX;
}

Time
AppOnOff::getTUltPaq ()
{	
	return tiempo_ult_paq;
}
