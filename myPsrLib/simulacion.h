#ifndef simulacion_h
#define simulacion_h

#include <string>
#include "ns3/gnuplot.h"
#include "ns3/average.h"
#include "punto.h"
#include "paramRange.h"


using namespace ns3;
using namespace std;


typedef struct{
	string title;
	string absTitle;
	string ordTitle;
	char curveExpresion[30];
} TitulosGrafica_t;
/*
 *	Descripcion: Calcula estimaciones de un valor en un cierto intervalo de confianza.
 */
template <typename T>
Punto punto(T * scenaryParams, double abscisa, int numIter, int porcentajeConzianza, double (*escenario)(T * scenaryParams));

template <typename T, typename U>
Gnuplot2dDataset curva(T * scenaryParams, string curveName, ParamRange<T> variableParam, int numIter, int porcentajeConzianza, double (*escenario)(T * scenaryParams));

template <typename T, typename U, typename V>
Gnuplot grafica(T * scenaryParams, TitulosGrafica_t titulos, ParamRange<U> curveParam, ParamRange<V> pointParam, int numIter, int porcentajeConzianza, double (*escenario)(T * scenaryParams));


#endif
