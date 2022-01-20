
#include "generaTrafico.h"
NS_LOG_COMPONENT_DEFINE ("Genera_Trafico");

Llamada *generaTrafico (NodeContainer nodos_BCube){
  
  NS_LOG_FUNCTION ("Contenedor con " << nodos_BCube.GetN() << " nodos");

  // Creamos la Aplicacion UdpServer (sumidero) 
  UdpServerHelper H_ServerUdp (PUERTO); 
  ApplicationContainer C_App_Sumidero = H_ServerUdp.Install (nodos_BCube);

  // Creamos las llamadas
  NS_LOG_DEBUG("Llamamos a llamadas");
  return new Llamada(nodos_BCube,60.0, 300.0);
}
