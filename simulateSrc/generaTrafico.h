#ifndef generaTrafico_h
#define generaTrafico_h

#include "ns3/core-module.h"
#include "ns3/node-container.h"
#include "ns3/on-off-helper.h"
#include "ns3/udp-client-server-helper.h" 
#include "ns3/inet-socket-address.h"
#include "llamada.h"

#define PUERTO 9

using namespace ns3;

/*
Función que instalará en los nodos del contenedor los equipos necesarios los clientes y en los equipos necesarios los servidores siguiendo el método de generación de tráfico "StaggeredProb" dado en el artículo.

Parámetros:
NodeContainer nodos_BCube : contenedor con todos los nodos BCube dentro.
*/
Llamada *generaTrafico (NodeContainer nodos_BCube, bool ControlaTrafico, uint32_t PorcentajeTrafico);

#endif