
#include <fstream>

#include "ns3/log.h"
#include "ns3/command-line.h"
#include "ns3/gnuplot.h"

#include "simulacion.h"
#include "paramRange.h"
#include "escenario.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("Main");

typedef struct{
	int porcentajeConzianza = 95;
	int numIter = 2;
	int bCubeLevelIni = 0;    // Comproar si está entre 0 y 3
	int numBCubeLevels = 4;
	int nNodos = 4;
	Time delay;
	int regBinarioPuentes = 10000;
	double coefRB = 1.5;
	int numRB = 3;
	uint32_t porcentajeTrafico = 30;
	uint32_t coefT = 4;
	int numT = 3;
} AFP_t;

void symRetXVel(AFP_t *config);
void symPerXTra(AFP_t *config);

int main (int argc, char *argv[]){
	
	
	// Command line arguments
	CommandLine cmd;
	
	AFP_t params;
	params.delay = Time("20us");
	
	cmd.AddValue("numIter", "Número de iteraciones para la simulación.", params.numIter);
	cmd.AddValue("conf", "Porcentaje de confianza para los valores.", params.porcentajeConzianza);
	cmd.AddValue("bCubeIni", "Nivel de BCube inicial", params.bCubeLevelIni);
	cmd.AddValue("nBCubeLev", "Número de niveles BCube a simular.", params.numBCubeLevels);
	cmd.AddValue("nNodos", "Número total de equipos.", params.nNodos);
	cmd.AddValue("delay", "Retardo de propagación entre puentes.", params.delay);
	cmd.AddValue("regBin", "Regimen binario inicial de los puentes.", params.regBinarioPuentes);
	cmd.AddValue("varRB", "Variación del regimen binario (geométrica)", params.coefRB);
	cmd.AddValue("numRB", "Número de valores de regimen binario a probar", params.numRB);
	cmd.AddValue("traf", "Porcentaje de tráfico que cursan las fuentes.", params.porcentajeTrafico);
	cmd.AddValue("varT", "Variación del tráfico (aritmética)", params.coefT);
	cmd.AddValue("numT", "Número de valores de tráfico a probar", params.numT);
	cmd.Parse(argc, argv);
	NS_LOG_INFO("Param: Número de iteraciones para la simulación: " << params.numIter);
	NS_LOG_INFO("Param: Porcentaje de confianza: " << params.porcentajeConzianza);
	NS_LOG_INFO("Param: Nivel inicial BCube: " << params.bCubeLevelIni);
	NS_LOG_INFO("Param: Número de niveles BCube a simular: " << params.numBCubeLevels);
	NS_LOG_INFO("Param: Número de equipos: " << params.nNodos);
	NS_LOG_INFO("Param: Retardo de los enlaces: " << params.delay);
	NS_LOG_INFO("Param: Regimen binario de los enlaces: " << params.regBinarioPuentes);
	NS_LOG_INFO("Param: Variación regimen binario: " << params.coefRB);
	NS_LOG_INFO("Param: Numero de valores de regimen binario: " << params.numRB);
	NS_LOG_INFO("Param: Porcentaje de trafico a cursar: " << params.porcentajeTrafico);
	NS_LOG_INFO("Param: Variación del tráfico: " << params.coefT);
	NS_LOG_INFO("Param: Numero de valores de tráfico: " << params.numT);
	
	
	// Configure simulation
	Time::SetResolution(Time::NS);
	
	symRetXVel(&params);
	symPerXTra(&params);
	
	return 0;
	
}
	
void symRetXVel(AFP_t *params){
	
	bool ControlaTrafico = false;
	
	StageConfig_t stageConfig;
	stageConfig.bCubeLevel = params->bCubeLevelIni;
	stageConfig.nNodos = params->nNodos;
	stageConfig.puenteConfig.regimenBinario = DataRate(params->regBinarioPuentes);
	stageConfig.puenteConfig.delay = params->delay;
	stageConfig.ControlaTrafico = ControlaTrafico;
	stageConfig.ret = delay;
	
	ParamRange<int> bCubeLevelParam(&stageConfig.bCubeLevel, PROGRESSION_ARITMETIC, params->numBCubeLevels-1);
	bCubeLevelParam.SetAritmeticProgressionRate(1);
	ParamRange<DataRate> regBinarioPuentesParam(&stageConfig.puenteConfig.regimenBinario, PROGRESSION_GEOMETRIC, params->numRB-1);
	regBinarioPuentesParam.SetGeometricProgressionRate(params->coefRB-1);

	// Configure graphic
	TitulosGrafica_t titulos;
	titulos.title = string("Retardo medio según velocidad de transmisión con " + std::to_string(params->numIter) + " iteraciones por punto");
	titulos.absTitle = string("Regimen binario [b/s]");
	titulos.ordTitle = string("Retado medio [ms]");
	strcpy(titulos.curveExpresion, "BCube %0.f");
	
	
	// Simulate
	Gnuplot grafiquita = grafica<StageConfig_t, int, DataRate>(&stageConfig, titulos, bCubeLevelParam, regBinarioPuentesParam, params->numIter, params->porcentajeConzianza, escenario);	
	
	std::ofstream fichero ("Retardo.plt");
	grafiquita.GenerateOutput (fichero);
	fichero << "pause -1" << std::endl;
	fichero.close ();
	
}

void symPerXTra(AFP_t *params){
	
	bool ControlaTrafico = true;
	
	StageConfig_t stageConfig;
	stageConfig.bCubeLevel = params->bCubeLevelIni;
	stageConfig.nNodos = params->nNodos;
	stageConfig.puenteConfig.regimenBinario = DataRate(params->regBinarioPuentes);
	stageConfig.puenteConfig.delay = params->delay;
	stageConfig.PorcentajeTrafico = params->porcentajeTrafico;
	stageConfig.ControlaTrafico = ControlaTrafico;
	stageConfig.ret = perdidas;
	
	ParamRange<int> bCubeLevelParam(&stageConfig.bCubeLevel, PROGRESSION_ARITMETIC, params->numBCubeLevels-1);
	bCubeLevelParam.SetAritmeticProgressionRate(1);
	ParamRange<uint32_t> MaxTraficoParam(&stageConfig.PorcentajeTrafico, PROGRESSION_ARITMETIC, params->numT-1);
	MaxTraficoParam.SetAritmeticProgressionRate(params->coefT-1);

	// Configure graphic
	TitulosGrafica_t titulos;
	titulos.title = string("Paquetes Perdidos segun el Maximo Porcentaje de Trafico, con " + std::to_string(params->numIter) + " iteraciones por punto");
	titulos.absTitle = string("Maximo Porcentaje de Trafico  [%]");
	titulos.ordTitle = string("Paquetes Perdidos [%]");
	strcpy(titulos.curveExpresion, "BCube %0.f");
	
	
	// Simulate
	Gnuplot grafiquita = grafica<StageConfig_t, int, uint32_t>(&stageConfig, titulos, bCubeLevelParam, MaxTraficoParam, params->numIter, params->porcentajeConzianza, escenario);	
	
	std::ofstream fichero ("Perdidas.plt");
	grafiquita.GenerateOutput (fichero);
	fichero << "pause -1" << std::endl;
	fichero.close ();
	
}