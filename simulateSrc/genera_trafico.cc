
#include "ns3/core-module.h"
#include "ns3/node-container.h"
#include "ns3/on-off-helper.h"
#include "ns3/udp-client-server-helper.h" 
#include "ns3/inet-socket-address.h"

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

  // Parametros de las Aplicaciones On Off
  DataRate TasaApp("32kb/s");
  uint32_t TamPaqFuente = 92;
  double tiempoAppOn = 0.350;
  double tiempoAppOff = 0.650;
  Ptr<ExponentialRandomVariable> Exp_ON = CreateObject<ExponentialRandomVariable> ();
  Ptr<ExponentialRandomVariable> Exp_OFF = CreateObject<ExponentialRandomVariable> ();
  Exp_ON->SetAttribute ("Mean", DoubleValue (tiempoAppOn));
  Exp_OFF->SetAttribute ("Mean", DoubleValue (tiempoAppOff));


  NS_LOG_DEBUG("Datos Aplicación ON OFF: ");
  NS_LOG_DEBUG("Velocidad de generación de la App: "<<TasaApp);

  // Creamos las Aplicaciones ON OFF (fuente)
  Config::SetDefault ("ns3::OnOffHelper::OnTime",PointerValue(Exp_ON));
  Config::SetDefault ("ns3::OnOffHelper::OffTime",PointerValue(Exp_OFF));

  ApplicationContainer C_App_Fuente;
  Time TiempoLlamada = Seconds(75);
  NodeContainer Nodo_Origen;
  NodeContainer Nodo_Destino;

  // En bucle de manera aleatoria
  //TiempoLlamada = 
  //Nodo_Origen.Add()
  //Nodo_Destino.Add()
 
  OnOffHelper H_ClientOnOff ("ns3::UdpSocketFactory",InetSocketAddress(Nodo_Destino.Get(0)->GetObject<Ipv4L3Protocol>()->GetAddress(1, 0).GetLocal(), PUERTO));
  H_ClientOnOff.SetConstantRate(TasaApp,TamPaqFuente);
  ApplicationContainer.Add(H_ClientOnOff.Install (Nodo_Origen));
  
}
