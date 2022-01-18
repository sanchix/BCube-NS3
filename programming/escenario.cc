#include "ns3/core-module.h"
#include "ns3/node-container.h"
#include "ns3/udp-echo-helper.h"
#include "ns3/udp-client-server-helper.h" //Cambiar por Helper de OnOff
#include <math.h>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("Escenario");


NodeContainer crea_escenario (int dimension, int equipos){
  NS_LOG_FUNCTION ("Dimension: " << dimension);
  NS_LOG_FUNCTION ("Numero de equipos: " << equipos);
  double niveles = pow(equipos,1.0/(dimension+1))
  NS_LOG_INFO ("Niveles por dimension: " << niveles);
  
  NodeContainer Bcube0;
  NodeContainer nodos;
  NodeContainer Contenedor;

  if (dimension != 0){

    int i = 0;
    int j = 0;
    for (i=0;i<dimension;i++){
      for (j=0;j<niveles-1;j++){
        Bcube0 = crea_escenario (dimension-1,niveles);
        nodos.add(BCube0);

      }
    }

  }else{
    NodeContainer BCube0(niveles);
    Contenedor = BCube0;
  }

  return Contenedor;

}

