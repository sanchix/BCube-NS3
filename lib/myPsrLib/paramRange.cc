
#include "paramRange.h"


using namespace ns3;


NS_LOG_COMPONENT_DEFINE("ParamRange");



// General


template<typename T>
ParamRange<T>::ParamRange(T * param, ProgressionType_T progressionType, int indexLimit){
	_param = param;
	initialValue = *_param;
	_progressionType = progressionType;
	_indexLimit = indexLimit;
}


template<typename T>
void ParamRange<T>::SetGeometricProgressionRate(double rate){
	definedProgressionRate = true;
	geometricProgressionRate = rate;
}

template<typename T>
void ParamRange<T>::SetAritmeticProgressionRate(T rate){
	definedProgressionRate = true;
	aritmeticProgressionRate = rate;
}

template<typename T>
bool ParamRange<T>::Next(){
	
	bool hasNext = false;
	index++;
	
	if(!definedProgressionRate){
		throw;
	}
	
	if(index <= _indexLimit){
		hasNext = true;
		if(_progressionType == PROGRESSION_ARITMETIC){
			*_param = progressionAritmetic();
		}
		else if(_progressionType == PROGRESSION_GEOMETRIC){
			*_param = progressionGeometric();
		}
		NS_LOG_DEBUG("Index: " << index << ", value: " << *_param);
	}
	
	return hasNext;
}

template<typename T>
T ParamRange<T>::Current(){
	return *_param;
}

template<typename T>
void ParamRange<T>::Reset(){
	index = 0;
	*_param = initialValue;
}

template<typename T>
T ParamRange<T>::progressionAritmetic(){
	return initialValue + aritmeticProgressionRate * index;
}

template<typename T>
T ParamRange<T>::progressionGeometric(){
	return initialValue * pow(geometricProgressionRate, index);    // Ojo con los índices en la progresión geométrica
}

template<typename T>
double ParamRange<T>::CurrentDouble(){
	double result = -1;
	if(std::is_same<T, double>::value){
		result = *(double *)_param;
	}
	else if(std::is_same<T, Time>::value){
		Time *aux = (Time *)_param;
		result = aux->GetSeconds();
	}
	else if(std::is_same<T, int>::value){
		result = (double)*(int *)_param;
	}
	else if(std::is_same<T, uint32_t>::value){
		result = (double)*(uint32_t *)_param;
	}
	else if(std::is_same<T, DataRate>::value){
		DataRate *aux = (DataRate *)_param;
		result = aux->GetBitRate();
	}
	return result;
}
		

// Trampa

template class ParamRange<Time>;
template class ParamRange<double>;
template class ParamRange<int>;
template class ParamRange<uint32_t>;
template class ParamRange<DataRate>;