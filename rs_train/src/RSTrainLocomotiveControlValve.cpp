/*
 * RSTrainLocomotiveControlValve.cpp
 *
 *  Created on: 8 Tem 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainLocomotiveControlValve.h"
#include "RSTrainVehicle.h"
#include "RSTrainLocomotive.h"
#include "pugixml.hpp"
#include <iostream>
using namespace std;

RSTrainLocomotiveControlValve::RSTrainLocomotiveControlValve(
		RSTrainVehicle* parent) :
		RSTrainControlValve(parent) {
	// TODO Auto-generated constructor stub
	this->moderablePressure = 0;

	this->locomotive_parent =dynamic_cast<RSTrainLocomotive*>(parent);

	pugi::xml_document doc;

	if(doc.load_file("ControlValve.xml")){

		pugi::xml_node ControlValve = doc.child("ControlValve");

		this->decreasePressureRate = ControlValve.child("decreasePressureRate").text().as_double();

		this->increasePressureRate = ControlValve.child("increasePressureRate").text().as_double();

		this->maxIncreasePressureRate = ControlValve.child("maxIncreasePressureRate").text().as_double();

		this->maxModerablePressure = ControlValve.child("maxModerablePressure").text().as_double();

	}else {

		this->decreasePressureRate = -0.2;

		this->increasePressureRate = 0.2;

		this->maxIncreasePressureRate = 0.8;

		this->maxModerablePressure = 3.8;

		cout<<"XML-File Could no Found :" <<"ControlValve.xml"<<endl;
	}

}

RSTrainLocomotiveControlValve::~RSTrainLocomotiveControlValve() {
	// TODO Auto-generated destructor stub
}

void RSTrainLocomotiveControlValve::CalcPressures(double dt) {

	RSTrainControlValve::CalcPressures(dt);

	this->CalcModerablePressure(dt);

}

void RSTrainLocomotiveControlValve::CalcModerablePressure(double dt) {

	int state = this->locomotive_parent->getAuxBrake();

	// tahliye durumu = 1 (-0.2 ATM/sec)
	// yol durumu = 2 (no change)
	// fren durumu = 3 (+0.2 ATM/sec)
	// fren sabit durumu = 4 (+0.8 ATM/sec  --> 3.8 ATM'ye kadar)

	switch (state) {
		case 1:{
			//Tahliye durumu
			this->CalcModerablePressureForGivenRate(dt,this->decreasePressureRate);

			break;
		}
		case 2:{

			// No change

			break;
		}
		case 3:{

			// Fren durumu

			this->CalcModerablePressureForGivenRate(dt,this->increasePressureRate);
			break;
		}
		case 4:{

			// Fren sabit durumu

			this->CalcModerablePressureForGivenRate(dt,this->maxIncreasePressureRate);
			break;
		}
		default:
			break;
	}


}

void RSTrainLocomotiveControlValve::CalcModerablePressureForGivenRate(double dt,
		double rate) {

	double newModerablePressure = this->moderablePressure +   rate*dt;

	if( (newModerablePressure >= 0) && (newModerablePressure <= maxModerablePressure) ){
		this->moderablePressure = newModerablePressure;
	}else if(newModerablePressure > maxModerablePressure){
		this->moderablePressure = maxModerablePressure;
	}else if(newModerablePressure < 0){
		this->moderablePressure = 0;
	}

}

double RSTrainLocomotiveControlValve::getBcPressure() {

	if (! (locomotive_parent->isPurger())) {

		if (moderablePressure >= BCPressure) {
			return moderablePressure;
		} else {
			return BCPressure;
		}
	}else{
		return moderablePressure;
	}
}

double RSTrainLocomotiveControlValve::getDecreasePressureRate() {
	return decreasePressureRate;
}

void RSTrainLocomotiveControlValve::setDecreasePressureRate(
		double decreasePressureRate) {
	this->decreasePressureRate = decreasePressureRate;
}

double RSTrainLocomotiveControlValve::getIncreasePressureRate(){
	return increasePressureRate;
}

void RSTrainLocomotiveControlValve::setIncreasePressureRate(
		double increasePressureRate) {
	this->increasePressureRate = increasePressureRate;
}



double RSTrainLocomotiveControlValve::getMaxIncreasePressureRate() {
	return maxIncreasePressureRate;
}

void RSTrainLocomotiveControlValve::setMaxIncreasePressureRate(
		double maxIncreasePressureRate) {
	this->maxIncreasePressureRate = maxIncreasePressureRate;
}

double RSTrainLocomotiveControlValve::getMaxModerablePressure(){
	return maxModerablePressure;
}

void RSTrainLocomotiveControlValve::setMaxModerablePressure(
		double maxModerablePressure) {
	this->maxModerablePressure = maxModerablePressure;
}

double RSTrainLocomotiveControlValve::getModerablePressure() {
	return moderablePressure;
}

void RSTrainLocomotiveControlValve::setModerablePressure(
		double moderablePressure) {
	this->moderablePressure = moderablePressure;
}
