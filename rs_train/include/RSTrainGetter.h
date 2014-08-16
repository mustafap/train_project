/*
 * RSTrainGetter.h
 *
 *  Created on: 11 Agu 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINGETTER_H_
#define RSTRAINGETTER_H_

#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

class RSTrainGetter;
class RSTrainSimulator;

class RSTrainGetter {
public:

	RSTrainGetter(RSTrainSimulator* parent);
	virtual ~RSTrainGetter();

	double GetAndLog(string variableName ,int V_index =0 , int BC_index = 0, bool log_on_off = true);

	string VELOCITYKPH;
	string ACCELERATION;

	string POSITION;
	string FRONTPOSITION;
	string REARPOSITION;

	string BRAKEPIPEPRESSURE;

	string SLOPE;

	string ROLLINGRESISTANCEFORCE;
	string CURVERESISTANCEFORCE;
	string RAMPRESISTANCEFORCE;
	string ADHERANCEFORCE;
	string BRAKEFORCE;
	string TOTALFORCE;

	string THROTTLEPOSITION;
	string DYNAMICBRAKEPOSITION;
	string BRAKEVALVEPOSITION;
	string AUXILARYBRAKEPOSITION;
	string BRAKECYLINDERCOUNT;
	string TRACTIONFORCE;
	string DYNAMICBRAKEFORCE;

	string COUPLINGDISTANCE;
	string COUPLINGFORCE;
	string COUPLINGINCREMENTALCONSTANT;
	string COUPLINGDECREMENTALCONSTANT;

	string AUXILIARYRESERVOIRPRESSURE;
	string BRAKECYLINDERPRESSURE;
	string CONTROLVALVEFLOWCONSTANT;
	string ARPRESSURE_BPPRESSURE_DIFFERENCE;
	string BRAKECYLINDERFAULT;
	string BRAKECYLINDERSPRINGMOVEMENT;
	string MODERABLEPRESSURE;
	string MODERABLEDECREASEPRESSURERATE;
	string MODERABLEINCREASEPRESSURERATE;
	string MODERABLEMAXINCREASEPRESSURERATE;
	string MODERABLEMAXPRESSURE;

	string ROADINDEX;
	string VERTICALPROFILEINDEX;
	string SECTIONINDEX;
	string SECTIONPOSITION;
	string VERTICALPROFILEPOSITION;
	string COMPLETEDROADLENGTH;
	string COMPLETEDSECTIONSLENGTH;
	string COMPLETEDVERTICALPROFILESLENGTH;

	string BRAKEPIPENOMINALPRESSURE;
	string BRAKEPIPEMINPRESSURE;
	string BRAKEPIPEMAXPRESSURE;
	string BRAKEPIPEOVERLOADPRESSURE;
	string BRAKEPIPEPRESSURELAPRELEASERATE;
	string BRAKEPIPEPRESSURELAPSERVICERATE;
	string BRAKEPIPEPRESSURERELEASERATE;
	string BRAKEPIPEPRESSURESERVICERATE;
	string BRAKEPIPEFAULTSTATE;
	string BRAKEPIPELEAKAGE;

	string TIME;
	string TIMERANGE;
	string VEHICLENUMBER;





private:

	RSTrainSimulator* parent;

	map<string,double(*)(RSTrainSimulator*,int,int)> func;

	ofstream Logger;

	string logFileName;
};

#endif /* RSTRAINGETTER_H_ */
