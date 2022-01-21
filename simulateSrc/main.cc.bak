
#include <fstream>

#include "ns3/log.h"
#include "ns3/command-line.h"
#include "ns3/gnuplot.h"

#include "simulacion.h"
#include "paramRange.h"
#include "escenario.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("Main");


int main (int argc, char *argv[]){
	
	
	// Command line arguments
	CommandLine cmd;
	
	int porcentajeConzianza = 95;
	int numIter = 1;
	int bCubeLevel = 0;    // Comproar si está entre 0 y 3
	int nNodosDim = 16;
	int regBinarioPuentes = 10;
	
	cmd.AddValue("numIter", "Número de iteraciones para la simulación: ", numIter);
	cmd.AddValue("nNodosDim", "Número de equipos por nivel: ", nNodosDim);
	cmd.Parse(argc, argv);
	NS_LOG_INFO("Param: Número de iteraciones para la simulación" << numIter);
	NS_LOG_INFO("Param: Número de nodos por nivel BCube" << nNodosDim);
	

	// Configure simulation
	Time::SetResolution(Time::NS);	
	
	StageConfig_t stageConfig;
	stageConfig.bCubeLevel = bCubeLevel;
	stageConfig.nNodosDim = nNodosDim;
	
	ParamRange<int> bCubeLevelParam(&bCubeLevel, PROGRESSION_ARITMETIC, 3);
	bCubeLevelParam.SetAritmeticProgressionRate(1);
	ParamRange<int> regBinarioPuentesParam(&regBinarioPuentes, PROGRESSION_GEOMETRIC, 3);
	regBinarioPuentesParam.SetGeometricProgressionRate(10);


	TitulosGrafica_t titulos;
	titulos.title = string("Retardo según velocida de enlace");
	titulos.absTitle = string("Velocida de enlace");
	titulos.ordTitle = string("Retardo medio");
	strcpy(titulos.curveExpresion, "BCube %0.f");
	
	Gnuplot grafiquita = grafica<StageConfig_t, int, int>(&stageConfig, titulos, bCubeLevelParam, regBinarioPuentesParam, numIter, porcentajeConzianza, escenario);	
	
	std::ofstream fichero ("Trabajo.plt");
	grafiquita.GenerateOutput (fichero);
	fichero << "pause -1" << std::endl;
	fichero.close ();

	
	return 0;
	
}