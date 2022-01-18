
#include <string>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ns3/gnuplot.h"
#include "ns3/log.h"
#include "ns3/rng-seed-manager.h"
#include "simulacion.h"
#include "punto.h"
#include "tStudent.h"
#include "escenario.h"


using namespace ns3;
using namespace std;


NS_LOG_COMPONENT_DEFINE("Simulacion");


#define QUEUE_TYPE 1
struct mymsgbuf{
	long mtype;
	double mval;
};


template <typename T>
Punto punto(T * scenaryParams, double abscisa, int numIter, int porcentajeConzianza, double (*escenario)(T * scenaryParams)){
	
	NS_LOG_FUNCTION(abscisa);
	
	double error = 0;
	Average<double> pointValue;
	key_t clave = ftok(".", 'm');
	int msgqueue_id;
	struct mymsgbuf qbuffer;
	pid_t pid;
	pid_t jobs[200];    //OJO
	
	pointValue.Reset();
		
	if(numIter > 200){
		throw;
	}
	
	for(int i = 0; i < numIter; i++){
		SeedManager::SetSeed(SeedManager::GetSeed()+1);
		pid = fork();
		if(pid == 0){    // Hijo
			if((msgqueue_id=msgget(clave,IPC_CREAT|0660)) == -1){
				NS_LOG_ERROR("ERROR AL CREAR LA COLA");
				throw;
			}
			qbuffer.mtype = QUEUE_TYPE;
			qbuffer.mval = escenario(scenaryParams);
			msgsnd(msgqueue_id, &qbuffer, sizeof(double), 0);
			//std::terminate();
			kill(getpid(), SIGKILL);
		}
		else{
			jobs[i] = pid;
		}
	}
	if((msgqueue_id=msgget(clave,IPC_CREAT|0660)) == -1){
		NS_LOG_ERROR("ERROR AL CREAR LA COLA");
		throw;
	}
	
	for(int i = 0; i < numIter; i++){
		//wait(jobs[i]);
		msgrcv(msgqueue_id, &qbuffer, sizeof(double), QUEUE_TYPE, 0);
		pointValue.Update(qbuffer.mval);
		NS_LOG_DEBUG("Recibido valor: " << qbuffer.mval << " de pid " << jobs[i]);
	}
	
	try{
		error = tStudentInv(numIter-1, (double)(100-porcentajeConzianza)/200) * sqrt(pointValue.Var()/numIter);
	}catch(string msg){
		NS_LOG_ERROR("Failed to calcule t-Student value: " << msg);
	}
	
	NS_LOG_INFO("Simulation result: " << pointValue.Mean() << ", error: " << error);
	
	return Punto(abscisa, pointValue.Mean(), error);

}


template <typename T, typename U>
Gnuplot2dDataset curva(T * scenaryParams, string curveName, ParamRange<U> variableParam, int numIter, int porcentajeConzianza, double (*escenario)(T * scenaryParams)){
	
	NS_LOG_FUNCTION(curveName);
	
	variableParam.Reset();
	
	Gnuplot2dDataset curvita(curveName);
	curvita.SetStyle(Gnuplot2dDataset::LINES_POINTS);
	curvita.SetErrorBars(Gnuplot2dDataset::Y);
	
	do{
		Punto puntito = punto(scenaryParams, variableParam.CurrentDouble(), numIter, porcentajeConzianza, escenario);
		curvita.Add(puntito.abscisa(), puntito.ordenada(), puntito.error());
	}while(variableParam.Next());
	
	return curvita;
	
}


template <typename T, typename U, typename V>
Gnuplot grafica(T * scenaryParams, TitulosGrafica_t titulos, ParamRange<U> curveParam, ParamRange<V> pointParam, int numIter, int porcentajeConzianza, double (*escenario)(T * scenaryParams)){
	
	NS_LOG_FUNCTION(titulos.title);
	
	Gnuplot grafiquita;
	
	curveParam.Reset();
	
	grafiquita.SetTitle(titulos.title);
	grafiquita.SetLegend(titulos.absTitle, titulos.ordTitle);
	
	do{
		char curveName[30];
		sprintf(curveName, titulos.curveExpresion, curveParam.CurrentDouble());
		Gnuplot2dDataset curvita = curva(scenaryParams, string(curveName), pointParam, numIter, porcentajeConzianza, escenario);
		grafiquita.AddDataset(curvita);
	}while(curveParam.Next());
	
	return grafiquita;
	
}


// TRAMPA

template Punto punto<StageConfig_t>(StageConfig_t *, double, int, int, double (*)(StageConfig_t *));

template Gnuplot2dDataset curva<StageConfig_t, Time>(StageConfig_t * scenaryParams, string curveName, ParamRange<Time> variableParam, int numIter, int porcentajeConzianza, double (*escenario)(StageConfig_t * scenaryParams));

template Gnuplot2dDataset curva<StageConfig_t, double>(StageConfig_t * scenaryParams, string curveName, ParamRange<double> variableParam, int numIter, int porcentajeConzianza, double (*escenario)(StageConfig_t * scenaryParams));

template Gnuplot grafica<StageConfig_t, double, Time>(StageConfig_t * scenaryParams, TitulosGrafica_t titulos, ParamRange<double> curveParam, ParamRange<Time> pointParam, int numIter, int porcentajeConzianza, double (*escenario)(StageConfig_t * scenaryParams));

template Gnuplot grafica<StageConfig_t, int, Time>(StageConfig_t * scenaryParams, TitulosGrafica_t titulos, ParamRange<int> curveParam, ParamRange<Time> pointParam, int numIter, int porcentajeConzianza, double (*escenario)(StageConfig_t * scenaryParams));

template Gnuplot grafica<StageConfig_t, int, int>(StageConfig_t * scenaryParams, TitulosGrafica_t titulos, ParamRange<int> curveParam, ParamRange<int> pointParam, int numIter, int porcentajeConzianza, double (*escenario)(StageConfig_t * scenaryParams));
