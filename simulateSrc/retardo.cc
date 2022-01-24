
#include "retardo.h"


using namespace ns3;


NS_LOG_COMPONENT_DEFINE ("Retardo");

//Observador que recibe el node container completo y ya el se las apaña. Esta to gucci
//Sirve para calcular el retardo medio de los paquetes


Retardo::Retardo(){
	m_cuenta = 0;
	enviados = 0;
	average = Time("0s");
};


void
Retardo::AddServers (NodeContainer nodos)
{

  for (uint32_t i=0; i< nodos.GetN(); i++){
	Ptr<UdpServer> servidor = nodos.Get(i)->GetApplication(0)->GetObject<UdpServer>();
	servidor->TraceConnectWithoutContext ("Rx",
											MakeCallback(&Retardo::RxEnd,
														this)); 
	}
}

void
Retardo::NewCall (Ptr<OnOffApplication> emisor){
	emisor->TraceConnectWithoutContext ("Tx",
											MakeCallback(&Retardo::TxIni,
														this));
}

void
Retardo::TxIni (Ptr<const Packet> paquete)
{
  NS_LOG_FUNCTION (paquete);
  TimestampTag etiqueta;
  etiqueta.SetTimestamp(Now());
  NS_LOG_DEBUG ("Creado paquete: "<<paquete->GetUid()<<" con timestamp: "<<etiqueta.GetTimestamp());
  paquete->AddPacketTag(etiqueta);
  enviados++;
}

void
Retardo::RxEnd (Ptr<const Packet> paquete)
{
  NS_LOG_FUNCTION (paquete);

  TimestampTag etiqueta;
  paquete->PeekPacketTag(etiqueta);
  average = average + (Now()-etiqueta.GetTimestamp());
  m_cuenta++;
  NS_LOG_DEBUG ("Llego el paquete "<<paquete->GetUid()<<"con Timestamp: "<<etiqueta.GetTimestamp()<<" media ahora: "<<average/m_cuenta);
  if((int)(Simulator::Now().GetSeconds()*10 / STOPTIME) > getPercent()){
	  getPercent() = (Simulator::Now().GetSeconds()*10 / STOPTIME);
	  NS_LOG_INFO("Status: " << getPercent()*10 << "%");
  }
}

Time
Retardo::RetardoMedio ()
{
  if (m_cuenta == 0){
    m_cuenta=1;
  }
  NS_LOG_LOGIC("El retardo medio es :"<< average/m_cuenta);
  NS_LOG_LOGIC("La suma de retardos es  :"<< average);
  NS_LOG_LOGIC("El numero de muestras es :"<< m_cuenta);

  return average/m_cuenta;
}

double
Retardo::PorcentajePerdidaPaqs()
{
	int diff = enviados - m_cuenta;
	double porcent = (double)diff/enviados;
	porcent = porcent*100;
	NS_LOG_DEBUG("Calculando % pedPaq, enviados: "<<enviados<<", recibidos: "<<m_cuenta<<" "<<diff<<" "<<porcent);
	
	return porcent;	
}