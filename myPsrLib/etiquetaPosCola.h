#ifndef etiquetaPosCola_h
#define etiquetaPosCola_h

#include "ns3/core-module.h"
#include "ns3/network-module.h"
 
#include "ns3/stats-module.h"


using namespace ns3;


class QueuePosTag : public Tag {
	
	public:
		static TypeId GetTypeId (void);
		virtual TypeId GetInstanceTypeId (void) const;
		
		virtual uint32_t GetSerializedSize (void) const;
		virtual void Serialize (TagBuffer i) const;
		virtual void Deserialize (TagBuffer i);
		
		// these are our accessors to our tag structure
		void SetQueuePos (uint32_t pos);
		uint32_t GetQueuePos (void) const;
		
		void Print (std::ostream &os) const;
		
	private:
		uint32_t m_posCola;
  
		// end class TimestampTag
};

#endif