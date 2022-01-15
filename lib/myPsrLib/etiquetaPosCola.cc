
#include "etiquetaPosCola.h"

NS_LOG_COMPONENT_DEFINE("EtiquetaPosCola");

TypeId QueuePosTag::GetTypeId (void){
	
	static TypeId tid = TypeId ("QueuePosTag")
		.SetParent<Tag> ()
		.AddConstructor<QueuePosTag> ()
		.AddAttribute ("QueuePos",
					"Position in queue!",
					EmptyAttributeValue (),
					MakeIntegerAccessor(&QueuePosTag::GetQueuePos),
					MakeIntegerChecker<uint32_t>());
					/*MakeTimeAccessor (&QueuePosTag::GetTimestamp),
					MakeTimeChecker ());*/
	return tid;
  
}
TypeId QueuePosTag::GetInstanceTypeId (void) const{
	
	return GetTypeId ();
  
}
 
uint32_t QueuePosTag::GetSerializedSize (void) const{
	
	return 4;
  
}

void QueuePosTag::Serialize (TagBuffer i) const{
	
	int32_t t = m_posCola;
	i.Write ((const uint8_t *)&t, 4);
	
}

void QueuePosTag::Deserialize (TagBuffer i){
	
	int32_t t;
	i.Read ((uint8_t *)&t, 4);
	m_posCola = t;
	
}
 
void QueuePosTag::SetQueuePos (uint32_t pos){
	
	m_posCola = pos;
	
}

uint32_t QueuePosTag::GetQueuePos (void) const{
	
	return m_posCola;
  
}
 
void QueuePosTag::Print (std::ostream &os) const{
	
	os << "t=" << m_posCola;
  
}