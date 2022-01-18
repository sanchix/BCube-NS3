
#include "ns3/log.h"
#include "ns3/command-line.h"
#include "ns3/gnuplot.h"

#include "ns3/command-line.h"
#include "ns3/node-container.h"
#include "ns3/node.h"
#include "ns3/internet-stack-helper.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/application-container.h"
#include "ns3/uinteger.h"
#include "ns3/error-model.h"
#include "ns3/enum.h"
#include "ns3/double.h"
#include "ns3/pointer.h"

#include "simulacion.h"
#include "paramRange.h"
#include "escenario.h"


using namespace ns3;


NS_LOG_COMPONENT_DEFINE ("Hola_Mundo");


int main (int argc, char *argv[]){
	
	Time::SetResolution(Time::NS);
	
	CommandLine cmd;
	
	int porcentajeConzianza = 95;
	
	int numIter = 1;
	int bCubeLevel = 2;    // Comproar si está entre 0 y 2
	int nNodosDim = 16;
	int p1 = 0;
	int p2 = 1;
	
	cmd.AddValue("numIter", "Número de iteraciones para la simulación", numIter);
	cmd.AddValue("bCubeLevel", "Número de niveles BCube", bCubeLevel);
	cmd.AddValue("nNodosDim", "Número de equipos por nivel", nNodosDim);
	cmd.Parse(argc, argv);
	NS_LOG_DEBUG("Param: Número de iteraciones para la simulación" << numIter);
	NS_LOG_DEBUG("Param: Nivel de BCube" << bCubeLevel);
	NS_LOG_DEBUG("Param: Número de nodos por nivel BCube" << nNodosDim);
	
		
	StageConfig_t stageConfig;
	stageConfig.bCubeLevel = bCubeLevel;
	stageConfig.nNodosDim = nNodosDim;
	
	ParamRange<int> p1Param(&p1, PROGRESSION_ARITMETIC, 2);
	p1Param.SetAritmeticProgressionRate(15);
	ParamRange<int> p2Param(&p2, PROGRESSION_ARITMETIC, 2);
	p2Param.SetAritmeticProgressionRate(15);


	TitulosGrafica_t titulos;
	titulos.title = string("HOLA SOY GERMAN");
	titulos.absTitle = string("Tamaño cola");
	titulos.ordTitle = string("Temperatura");
	strcpy(titulos.curveExpresion, "%i personas");
	
	Gnuplot grafiquita = grafica<StageConfig_t, int, int>(&stageConfig, titulos, p1Param, p2Param, numIter, porcentajeConzianza, escenario);	
	
	std::ofstream fichero ("Trabajo.plt");
	grafiquita.GenerateOutput (fichero);
	fichero << "pause -1" << std::endl;
	fichero.close ();

	
	return 0;
	
}