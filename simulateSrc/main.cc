
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
	int numIter = 2;
	int bCubeLevel = 0;    // Comproar si está entre 0 y 3
	int nNodos = 4;
	int regBinarioPuentes = 100000;
	Time delay("20us");
	
	cmd.AddValue("numIter", "Número de iteraciones para la simulación: ", numIter);
	cmd.AddValue("nNodos", "Número total de equipos: ", nNodos);
	cmd.AddValue("delay", "Número total de equipos: ", delay);
	cmd.Parse(argc, argv);
	NS_LOG_DEBUG("Param: Número de iteraciones para la simulación: " << numIter);
	NS_LOG_DEBUG("Param: Número de equipos: " << nNodos);
	

	// Configure simulation
	Time::SetResolution(Time::NS);	
	
	StageConfig_t stageConfig;
	stageConfig.bCubeLevel = bCubeLevel;
	stageConfig.nNodos = nNodos;
	stageConfig.puenteConfig.regimenBinario = DataRate(regBinarioPuentes);
	stageConfig.puenteConfig.delay = delay;
	
	ParamRange<int> bCubeLevelParam(&stageConfig.bCubeLevel, PROGRESSION_ARITMETIC, 3);
	bCubeLevelParam.SetAritmeticProgressionRate(1);
	ParamRange<DataRate> regBinarioPuentesParam(&stageConfig.puenteConfig.regimenBinario, PROGRESSION_GEOMETRIC, 0);
	regBinarioPuentesParam.SetGeometricProgressionRate(2);


	// Configure graphic
	TitulosGrafica_t titulos;
	titulos.title = string("Retardo según velocidad de enlace con " + std::string(numIter) + " iteraciones por punto");
	titulos.absTitle = string("Velocidad de enlace [b/s]");
	titulos.ordTitle = string("Retardo medio [ms]");
	strcpy(titulos.curveExpresion, "BCube %0.f");
	
	
	// Simulate
	Gnuplot grafiquita = grafica<StageConfig_t, int, DataRate>(&stageConfig, titulos, bCubeLevelParam, regBinarioPuentesParam, numIter, porcentajeConzianza, escenario);	
	
	std::ofstream fichero ("Trabajo.plt");
	grafiquita.GenerateOutput (fichero);
	fichero << "pause -1" << std::endl;
	fichero.close ();

	
	return 0;
	
}