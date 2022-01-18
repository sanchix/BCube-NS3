/*#include "ns3/core-module.h"
#include "ns3/node-container.h"
#include "ns3/udp-echo-helper.h"
#include "ns3/udp-client-server-helper.h" //Cambiar por Helper de OnOff

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("Genera_Trafico");
*/
/*
Función que instalará en los nodos del contenedor los equipos necesarios los clientes y en los equipos necesarios los servidores siguiendo el método de generación de tráfico "StaggeredProb" dado en el artículo.

Parámetros:
NodeContainer nodos_BCube : contenedor con todos los nodos BCube dentro.
double prob_level1 : probabilidad de que se genere trafico hacia un servidor del mismo nivel 1 de BCube.
double prob_level2 : probabilidad de que se genere trafico hacia un servidor del mismo nivel 2 de BCube.

Aclaración: probabilidad de enviar a un nodo arbitrario (1 - prob_level1 + prob_level2)
*/

/*
void generaTrafico (NodeContainer nodos_BCube, double prob_level1, double prob_level2);



void generaTrafico (NodeContainer nodos_BCube, double prob_level1, double prob_level2){
  
  NS_LOG_FUNCTION ("Contenedor con los nodos: " << nodos_BCube);
  
  
}


*/