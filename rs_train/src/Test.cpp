/*
 * Test.cpp
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */


#include <iostream>
#include "RSTrainCar.h"
#include "RSTrainLocomotive.h"
#include "RSTrainCoupling.h"
#include "RSTrainParser.h"
#include "RSTrainLocomotiveParser.h"
#include "RSTrainCarParser.h"
#include "RSTrainRailwayElementParser.h"
#include "RSTrainDynamicModel.h"
#include "RSTrainSimulator.h"
#include "RSTrainRoadWatcher.h"
#include "RSTrainGetter.h"
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
using namespace boost::date_time;
using namespace std;

void test(RSTrainVehicle* op,int x)
{
	op->setAccelaration(x);
	cout<<op->getAccelaration()<<endl;;
}

int main() {

	RSTrainSimulator simulator;


	simulator.InitRailwayElement("IRoad_Edited.xml");
	simulator.addLocomotive(0);
	//simulator.addCar(0);
	//simulator.addCar(0);
	//simulator.addCar(0);
	//simulator.addCar(0);
	//simulator.addCar(0);
	//simulator.addCar(0);
	simulator.InitPositions(2,1450);
	simulator.InitBreakePipe();
	simulator.InitSpeed(0);
	simulator.setThrottlePos(0,1);

	simulator.updateVariables(0);

	simulator.updateForces(0);
	cout<<"test"<<endl;
	simulator.setBrakeValvePos(0);
	//simulator.doIntegration();


	RSTrainGetter* G = simulator.getGetterAndLogger();
	simulator.Start();

	//simulator.doIntegration();
	//int i;
	while(true)
	{
		G->GetAndLog(G->TOTALFORCE, 0, 0,true);
		G->GetAndLog(G->VELOCITYKPH,0,0,true);
	}


	//simulator.start();

	/*
	 * Some operations
	 * ...
	 * ...
	 * ...
	 * ...
	 */





	return 0;
}




