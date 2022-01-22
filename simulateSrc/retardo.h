#ifndef retardo_h
#define retardo_h


#include "ns3/log.h"
#include "ns3/ptr.h"
#include "ns3/tag.h"
#include "ns3/node.h"
#include "ns3/packet.h"
#include "ns3/nstime.h"
#include "ns3/udp-server.h"
#include "ns3/object-base.h"
#include "ns3/core-module.h"
#include "ns3/node-container.h"
#include "ns3/udp-echo-client.h"
#include "ns3/onoff-application.h"
#include "ns3/point-to-point-net-device.h"

#include "etiquetaTiempo.h"

#define STOPTIME 140


using namespace ns3;


class Retardo
{
public:
		   Retardo ();
  void     AddServers (NodeContainer nodos);
  void     TxIni (Ptr<const Packet> paquete);
  void     RxEnd (Ptr<const Packet> paquete);
  void 	   NewCall (Ptr<OnOffApplication> emisor);
  Time     RetardoMedio   ();
  double	   PorcentajePerdidaPaqs();

private:
  Time      average;
  static auto getPercent() -> int& {
	  static int percent = 0;
	  return percent;
  }
  uint32_t  m_cuenta;
  uint32_t  enviados;
    
};


#endif