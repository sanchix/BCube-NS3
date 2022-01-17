#include "ns3/log.h"
#include "ns3/node-container.h"
#include "ns3/csma-net-device.h"
#include "ns3/queue-disc.h"
#include "ns3/queue.h"
#include "ns3/traffic-control-layer.h"
#include "ns3/object-ptr-container.h"
#include "desglose-colas.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("DesgloseColas");


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
Colas (NodeContainer nodos)
{
  // Para cada nodo en el contenedor
  for (uint32_t indice = 0; indice < nodos.GetN (); indice++)
    {
      // Obtenemos el puntero al nodo
      Ptr<Node> nodo = nodos.Get (indice);
      // Obtenemos el puntero al TCL del nodo (OJO: puede ser nulo)
      Ptr<TrafficControlLayer> tcl = nodo->GetObject <TrafficControlLayer> ();

      NS_LOG_INFO ("Información del nodo " << indice);
      // Para cada dispositivo en el nodo
      for (uint32_t indice2 = 0; indice2 < nodo->GetNDevices (); indice2++)
        {
          // Obtenemos el puntero al dispositivo
          Ptr<NetDevice> dispo = nodo->GetDevice (indice2);
          NS_LOG_INFO ("  Tipo dispositivo " << indice2 <<
                       ": " << dispo->GetInstanceTypeId ().GetName ());
          // Sólo si el dispositivo es CsmaNetDevice buscamos la cola
          // (habría que añadir SimpleNetDevice y PointToPointNetDevice)
          if ("ns3::CsmaNetDevice" == dispo->GetInstanceTypeId ().GetName ())
            {
              // Obtenemos el puntero a la cola de transmisión del dispositivo
              // (OJO: puede ser nulo).
              Ptr<Queue<Packet>> queue = dispo->GetObject<CsmaNetDevice> ()->
                GetQueue ();
              if (queue)
                NS_LOG_INFO ("    Cola en dispositivo " << indice2 <<
                             " de nodo " << indice << ": " <<
                             queue->GetInstanceTypeId ().GetName () <<
                             " con " << queue->GetMaxSize () <<
                             " de tamaño máximo");
              else
                NS_LOG_INFO ("    Cola en dispositivo " << indice2 <<
                             " de nodo " << indice << ": Ninguna");
            }
          // Si hay TCL buscamos la cola de control del dispositivo
          if (tcl)
            {
              // Obtenemos el puntero a la cola (OJO: puede ser nulo)
              // utilizando el método del TCL.
              Ptr<QueueDisc> valor = tcl->GetRootQueueDiscOnDevice (dispo);
              if (valor)
                NS_LOG_INFO ("    Según TCL: " <<
                             valor->GetInstanceTypeId ().GetName () <<
                             " con " << valor->GetMaxSize () <<
                             " de tamaño máximo");
              else
                NS_LOG_INFO ("    Según TCL: Sin cola");
            }
        }

      // Otra forma de obtener las colas de control de los dispositivos
      if (tcl)
        {
          ObjectPtrContainerValue puntero;
          // Obtenemos la lista de colas.
          tcl->GetAttribute ("RootQueueDiscList", puntero);
          NS_LOG_INFO ("  Dispositivos según TCL: " << puntero.GetN ());
          // Para cada elemento de la lista
          for (std::size_t orden = 0;  orden < puntero.GetN (); orden++)
            // Obtenemos el puntero a la cola (OJO: puede ser nulo)
            if (puntero.Get (orden))
              {
                Ptr<QueueDisc> cola = puntero.Get (orden)->
                  GetObject<QueueDisc> ();
                NS_LOG_INFO ("    Num orden: " << orden << " tipo: " <<
                             cola->GetInstanceTypeId ().GetName () <<
                             " con " << cola->GetMaxSize () <<
                             " de tamaño máximo y " <<
                             cola->GetNQueueDiscClasses () <<
                             " disciplinas de cola");
              }
            else
              NS_LOG_INFO ("    Num orden: " << orden << " sin cola");
        }
    }
}
