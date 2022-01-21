#ifndef paramRange_h
#define paramRange_h


#include <math.h>

#include "ns3/log.h"
#include "ns3/nstime.h"
#include "ns3/data-rate.h"



using namespace ns3;


typedef enum{PROGRESSION_GEOMETRIC, PROGRESSION_ARITMETIC} ProgressionType_T;

template<typename T>
class ParamRange{
	public:
		ParamRange(T * param, ProgressionType_T progressionType, int indexLimit);
		void SetGeometricProgressionRate(double rate);
		void SetAritmeticProgressionRate(T rate);
		bool Next();
		T Current();
		double CurrentDouble();
		void Reset();
	private:
		T initialValue;
		T * _param;
		uint64_t index;
		uint64_t _indexLimit;
		ProgressionType_T _progressionType;
		bool definedProgressionRate = false;
		double geometricProgressionRate;
		T aritmeticProgressionRate;
		virtual T progressionAritmetic();
		virtual T progressionGeometric();
};


#endif