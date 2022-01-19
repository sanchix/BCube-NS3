
#include "ns3/core-module.h"
#include "ns3/node-container.h"
#include "ns3/on-off-helper.h"
#include "ns3/udp-client-server-helper.h" 
#include "ns3/inet-socket-address.h"
#include "llamada.h"

#define PUERTO 9

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("Genera_Trafico");

/*
Función que instalará en los nodos del contenedor los equipos necesarios los clientes y en los equipos necesarios los servidores siguiendo el método de generación de tráfico "StaggeredProb" dado en el artículo.

Parámetros:
NodeContainer nodos_BCube : contenedor con todos los nodos BCube dentro.
double prob_level1 : probabilidad de que se genere trafico hacia un servidor del mismo nivel 1 de BCube.
double prob_level2 : probabilidad de que se genere trafico hacia un servidor del mismo nivel 2 de BCube.

Aclaración: probabilidad de enviar a un nodo arbitrario (1 - prob_level1 + prob_level2)
*/
void generaTrafico (NodeContainer nodos_BCube);

void generaTrafico (NodeContainer nodos_BCube){
  
  NS_LOG_FUNCTION ("Contenedor con " << nodos_BCube.GetN() << " nodos");

  // Creamos la Aplicacion UdpServer (sumidero) 
  UdpServerHelper H_ServerUdp (PUERTO); 
  ApplicationContainer C_App_Sumidero = H_ServerUdp.Install (nodos_BCube);

  // Creamos las llamadas
  Llamada(nodos_BCube,60.0, 300.0);
}
