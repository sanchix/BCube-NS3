
#include "ns3/log.h"
#include "ns3/command-line.h"

using namespace ns3;


NS_LOG_COMPONENT_DEFINE ("Hola_Mundo");


int main (int argc, char *argv[]){
	
	Time::SetResolution(Time::NS);
	
	
	
	NS_LOG_INFO("Hola Mundo");
	
	return 0;
	
}