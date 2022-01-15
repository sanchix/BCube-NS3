#ifndef paramRange_h
#define paramRange_h


#include "ns3/nstime.h"


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
		int index;
		int _indexLimit;
		ProgressionType_T _progressionType;
		bool definedProgressionRate = false;
		double geometricProgressionRate;
		T aritmeticProgressionRate;
		virtual T progressionAritmetic();
		virtual T progressionGeometric();
};


#endif