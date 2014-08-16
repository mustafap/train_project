/*
 * RSTrainVehicle.cpp
 *
 *  Created on: 20 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainVehicle.h"
#include "RSTrainRoadWatcher.h"
#include "RSTrainControlValve.h"
#include "RSTrainBrakeCylinder.h"
#include "RailwayElement.h"
#include <math.h>
using namespace std;


RSTrainVehicle::RSTrainVehicle() {
	this->posvel = vector<double>(2);
	this->posvel[0] = 0;
	this->posvel[1] = 0;
	this->frontCoupling = 0;
	this->rearCoupling = 0;
	this->freightType = 0;
	this->brakePipePresure = 5;
	this->controlValve = 0;
	this->brakeCylinder = 0;
}

RSTrainVehicle::~RSTrainVehicle() {
}


double RSTrainVehicle::getAccelaration() {
	return accelaration;
}


void RSTrainVehicle::setAccelaration(double accelaration) {
	this->accelaration = accelaration;
}


double RSTrainVehicle::getAdheranceForce() {
	return adheranceForce;
}


double RSTrainVehicle::getArPressure() {

}


RSTrainCoupling* RSTrainVehicle::getRearCoupling() {

	return rearCoupling;

}


void RSTrainVehicle::setRearCoupling(RSTrainCoupling* rearCoupling) {
	this->rearCoupling = rearCoupling;
}


double RSTrainVehicle::getBcPressure() {

}


double RSTrainVehicle::getBrakeForce() {
	return brakeForce;
}


void RSTrainVehicle::setBrakeForce(double brakeForce) {
	this->brakeForce = brakeForce;
}


double RSTrainVehicle::getBrakePipePresure() {
	return brakePipePresure;
}


void RSTrainVehicle::setBrakePipePresure(double brakePipePresure) {
	this->brakePipePresure = brakePipePresure;
}


double RSTrainVehicle::getCoefFriction() {
	return coefFriction;
}


void RSTrainVehicle::setCoefFriction(double coefFriction) {
	this->coefFriction = coefFriction;
}


double RSTrainVehicle::getCurve() {
	return curve;
}


void RSTrainVehicle::setCurve(double curve) {
	this->curve = curve;
}


double RSTrainVehicle::getCurveResistanceForce() {
	return curveResistanceForce;
}


void RSTrainVehicle::setCurveResistanceForce(double curveResistanceForce) {
	this->curveResistanceForce = curveResistanceForce;
}


int RSTrainVehicle::getFreightType() {
	return freightType;
}


void RSTrainVehicle::setFreightType(int freightType) {
	this->freightType = freightType;
}


RSTrainCoupling* RSTrainVehicle::getFrontCoupling() {
	return frontCoupling;
}


void RSTrainVehicle::setFrontCoupling(RSTrainCoupling* frontCoupling) {
	this->frontCoupling = frontCoupling;
}


double RSTrainVehicle::getFrontPosition() {
	return frontPosition;
}


void RSTrainVehicle::setFrontPosition(double frontPosition) {
	this->frontPosition = frontPosition;
}


double RSTrainVehicle::getLength() {
	return length;
}


void RSTrainVehicle::setLength(double length) {
	this->length = length;
}


double RSTrainVehicle::getMass() {
	return mass;
}


void RSTrainVehicle::setMass(double mass) {
	this->mass = mass*9.81;
	this->setMassInTons(mass / 1000);
}


double RSTrainVehicle::getMassInTons() {
	return massInTons;
}


void RSTrainVehicle::setMassInTons(double massInTons) {
	this->massInTons = massInTons;
}

int RSTrainVehicle::getNumberAxles() {
	return numberAxles;
}

void RSTrainVehicle::setNumberAxles(int numberAxles) {
	this->numberAxles = numberAxles;
}

double RSTrainVehicle::getPosition() {
	return position;
}

void RSTrainVehicle::setPosition(double position) {
	this->position = position;
}

double RSTrainVehicle::getDiameterOfWheel() {
	return diameterOfWheel;
}

void RSTrainVehicle::setDiameterOfWheel(double diameterOfWheel) {
	this->diameterOfWheel = diameterOfWheel;
}

vector<double>& RSTrainVehicle::getPosvel() {
	return posvel;
}

void RSTrainVehicle::setPosvel(vector<double>& posvel) {
	this->posvel = posvel;
}

RailwayElement* RSTrainVehicle::getRailRoad() {
	return railRoad;
}

void RSTrainVehicle::setRailRoad(RailwayElement* railRoad) {

	// take the railway element
	this->railRoad = railRoad;

	// create roadwatcher
	this->watcher = new RSTrainRoadWatcher(this, this->railRoad);
}

double RSTrainVehicle::getRampResistanceForce() {
	return rampResistanceForce;
}

void RSTrainVehicle::setRampResistanceForce(double rampResistanceForce) {
	this->rampResistanceForce = rampResistanceForce;
}

double RSTrainVehicle::getRearPosition() {
	return rearPosition;
}

void RSTrainVehicle::setRearPosition(double rearPosition) {
	this->rearPosition = rearPosition;
}

double RSTrainVehicle::getRollingResistanceForce() {
	return rollingResistanceForce;
}

void RSTrainVehicle::setRollingResistanceForce(double rollingResistanceForce) {
	this->rollingResistanceForce = rollingResistanceForce;
}

double RSTrainVehicle::getSlope() {
	return slope;
}

void RSTrainVehicle::setSlope(double slope) {
	this->slope = slope;
	this->calcAlfa();
}

double RSTrainVehicle::getVelocity() {
	return velocity;
}

void RSTrainVehicle::setVelocity(double velocity) {

	// take the velocity (m/sec)
	this->velocity = velocity;

	// convert the velocity information to km/h unit
	this->velocityKPH = 3.6 * velocity;
}

double RSTrainVehicle::getVelocityKph() {
	return velocityKPH;
}

void RSTrainVehicle::setVelocityKph(double velocityKph) {
	velocityKPH = velocityKph;
	this->velocity = velocityKph / 3.6;
}

double RSTrainVehicle::getAdheranceCoef() {
	return adheranceCoef;
}

void RSTrainVehicle::setAdheranceCoef(double adheranceCoef) {
	this->adheranceCoef = adheranceCoef;
}

double RSTrainVehicle::getAlfa() {
	return alfa;
}

void RSTrainVehicle::setAlfa(double alfa) {
	this->alfa = alfa;
}

double RSTrainVehicle::getTotalForce() {
	return totalForce;
}

void RSTrainVehicle::setTotalForce(double totalForce) {
	this->totalForce = totalForce;
}

RSTrainRoadWatcher* RSTrainVehicle::getWatcher() {
	return watcher;
}

void RSTrainVehicle::setWatcher(RSTrainRoadWatcher* watcher) {
	this->watcher = watcher;
}

void RSTrainVehicle::InitPosition(int roadindex, double position) {

	// take initial position (meter)
	this->position = position;

	// set front position of the vehicle
	this->setFrontPosition(position + ((this->length) / 2));

	// set back position of the vehicle
	this->setRearPosition(position - ((this->length) / 2));

	// set current road index
	this->watcher->setCurrentRoadIndex(roadindex);

	// set road position on the given road
	this->watcher->setRoadPosition(position);

	// initialize the watcher
	this->watcher->Init();
}

void RSTrainVehicle::InitSpeed(double speed) {

	// initialize the velocity (m/sec)
	this->setVelocity(speed);

	// assign the posvel[1] element with the velocity informotion, it is required for integration
	this->posvel[1] = speed;
}

void RSTrainVehicle::calcAlfa() {

	//tan(alfa) = slope/1000
	// alfa = atan(slope/1000)
	this->alfa = atan(this->slope);

}

void RSTrainVehicle::calcCurveResistance() {
	// curve (rc ) nin birimine bakýlmasý lazým

	//		  6500
	//Fcur =-------- * Gl
	//		rc - 55

	// Gl = Mt * cos(alfa)
	if (this->velocityKPH == 0) {
		this->curveResistanceForce = 0;
		return;
	}
	if (this->curve == 0) {
		this->curveResistanceForce = 0;
		return;
	}

	double Rc = this->curve;
	double G = this->massInTons;
	this->curveResistanceForce = (6500 / (Rc - 55)) * (G) * -1;

	if (this->velocityKPH < 0)
		this->curveResistanceForce = this->curveResistanceForce * -1;

}

void RSTrainVehicle::calcRampResistance() {
	// verilen slope deðerine dikkat et

	//Framp = mgsin(angle)

	rampResistanceForce = mass * sin(alfa) * -1;
}

void RSTrainVehicle::calcAdheranceForce() {

	// T = Gl*u
	// Gl = mgcos
	this->adheranceForce = (this->adheranceCoef) * (this->mass) * 9.81
			* cos(this->alfa)*2;
}

void RSTrainVehicle::calcAhreranceCoef() {

	//		  8 + 0.1*Vkm
	//Uv = U*-------------
	//		  8 + 0.2*Vkm

	double V_abs = fabs(this->velocityKPH);

	this->adheranceCoef = (this->coefFriction)
			* ((8 + 0.1 * V_abs) / (8 + 0.2 * V_abs));

}

void RSTrainVehicle::calcCoefFriction() {
	this->coefFriction = 0.3;
}


RSTrainBrakeCylinder* RSTrainVehicle::getBrakeCylinder(){
	return brakeCylinder;
}

void RSTrainVehicle::setBrakeCylinder(
		RSTrainBrakeCylinder* brakeCylinder) {
	this->brakeCylinder = brakeCylinder;
}

RSTrainControlValve* RSTrainVehicle::getControlValve(){
	return controlValve;
}

void RSTrainVehicle::setControlValve(RSTrainControlValve* controlValve) {
	this->controlValve = controlValve;
}

RSTrainRollingResistanceCalculator* RSTrainVehicle::getRollingResistanceForceCalculator() {

	return this->rollingResistanceForceCalculator;
}

void RSTrainVehicle::setRollingResistanceForceCalculator(
		RSTrainRollingResistanceCalculator* rollingResistanceForceCalculator) {

	this->rollingResistanceForceCalculator = rollingResistanceForceCalculator;
}
