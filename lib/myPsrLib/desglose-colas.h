#include "ns3/node-container.h"

using namespace ns3;

/****************************************************************
/ Colas en un nodo, con indice el correspondiente al dispositivo:
/   Ptr<NetDevice>           dispo = nodo->GetDevice (indice):
/   Ptr<TrafficControlLayer> tcl   = nodo->GetObject <TrafficControlLayer> ();
/     Por dispositivo:
/        En el dispositivo
/            dispo->GetObject<CsmaNetDevice> ()->GetQueue ()
/          y devuelve un Ptr<Queue<Packet>>
/        En el TrafficControlLayer Ptr<TrafficControlLayer> tcl:
/            tcl->GetRootQueueDiscOnDevice (dispo)
/          y devuelve Ptr<QueueDisc>
/     Desde el TrafficControlLayer:
/            ObjectPtrContainerValue puntero;
/            tcl->GetAttribute ("RootQueueDiscList", puntero);
/            puntero.Get (indice);
/          y devuelve un Ptr<QueueDisc>
****************************************************************/
void
Colas (NodeContainer nodos);
