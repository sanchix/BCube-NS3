#include "ns3/core-module.h"
#include "ns3/node-container.h"
#include "ns3/on-off-helper.h"
#include "ns3/udp-client-server-helper.h" 

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
void generaTrafico (NodeContainer nodos_BCube, double prob_level1, double prob_level2);


void generaTrafico (NodeContainer nodos_BCube, double prob_level1, double prob_level2){
  
  NS_LOG_FUNCTION ("Contenedor con " << nodos_BCube.GetN() << " nodos");

  // Creamos la Aplicacion UdpServer (sumdireo) 
  UdpServerHelper H_ServerUdp (PUERTO); 
  ApplicationContainer C_App_Sumidero = H_ServerUdp.Install (sumidero);

  // Creamos las Aplicaciones ON OFF (fuente)
  Time TiempoTotalON = Seconds(75) ;
  DataRate TasaApp("32kb/s");
  Double tiempoAppOn = 0.350;
  Double tiempoAppOff = 0.650;
  Ptr<ExponentialRandomVariable> x1 = CreateObject<ExponentialRandomVariable> ();
  x1->SetAttribute ("Mean", DoubleValue (tiempoAppOn));
  Ptr<ExponentialRandomVariable> x2 = CreateObject<ExponentialRandomVariable> ();
  x2->SetAttribute ("Mean", DoubleValue (tiempoAppOff));

  NS_LOG_DEBUG("Datos Aplicación ON OFF: ");
  NS_LOG_DEBUG("Tiempo que durarán las llamadas: "<<TiempoTotalON);  
  NS_LOG_DEBUG("Velocidad de generación de la App: "<<TasaApp);

  OnOffHelper H_ClientOnOff ("ns3::UdpSocketFactory",InetSocketAddress(C_Interfaces.GetAddress (0), PUERTO));
  H_ClientOnOff.SetConstantRate(TasaApp,TamPaqFuente);
  H_ClientOnOff->SetAttribute("OnTime",PointerValue(x1));
  H_ClientOnOff->SetAttribute("OffTime",PointerValue(x2));
  H_ClientOnOff->SetAttribute("StopTime",TimeValue(TiempoTotalON));

  ApplicationContainer C_App_Fuente = H_ClientOnOff.Install (C_NodosFuente);
  
  /*
  //Varias fuentes en un mismo nodo
  std::vector <ApplicationContainer> Contenedores_App_Fuentes;
  ApplicationContainer C_Todas_App_Fuente;
  for (i=0;i<NumFuentes;i++){
    ApplicationContainer C_App_Fuente = H_ClientOnOff.Install (C_NodosFuente);
    C_Todas_App_Fuente.Add(C_App_Fuente);
    Contenedores_App_Fuentes.push_back(C_App_Fuente);
  }
  */
  
}
