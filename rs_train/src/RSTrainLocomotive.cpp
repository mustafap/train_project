/*
 * RSTrainLocomotive.cpp
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainLocomotive.h"
#include "RSTrainRoadWatcher.h"
#include "RSTrainCoupling.h"
#include "RSTrainTractionForceCalculator.h"
#include "RSTrainDynamicBrakeForceCalculator.h"
#include "RSTrainLocomotiveRollingResistanceCalculator.h"
#include "RSTrainLocomotiveControlValve.h"
#include "RSTrainBrakeCylinder.h"
#include <iostream>
#include <math.h>
using namespace std;


RSTrainLocomotive::RSTrainLocomotive() {
	this->throttle = 0;
	this->dynamicBrake = 0;
	this->dynamicBrakeForce = 0;

	this->auxBrake = 2;
	this->brakeValve = 3;

	this->tractionForceCalculator = new RSTrainTractionForceCalculator(this);

	this->dynamicBrakeForceCalculator = new RSTrainDynamicBrakeForceCalculator(this);

	this->rollingResistanceForceCalculator = new RSTrainLocomotiveRollingResistanceCalculator(this);

	this->purger = false;
}

RSTrainLocomotive::~RSTrainLocomotive() {
	// TODO Auto-generated destructor stub
}

int RSTrainLocomotive::getAuxBrake() {
	return auxBrake;
}

void RSTrainLocomotive::setAuxBrake(int auxBrake) {
	this->auxBrake = auxBrake;
}

int RSTrainLocomotive::getBrakeValve() {
	return brakeValve;
}

void RSTrainLocomotive::setBrakeValve(int brakeValve) {
	this->brakeValve = brakeValve;
}

bool RSTrainLocomotive::isCompressorActive() {
	return compressorActive;
}

void RSTrainLocomotive::setCompressorActive(bool compressorActive) {
	this->compressorActive = compressorActive;
}

int RSTrainLocomotive::getDirection() {
	return direction;
}

void RSTrainLocomotive::setDirection(int direction) {
	this->direction = direction;
}

int RSTrainLocomotive::getDynamicBrake() {
	return dynamicBrake;
}

void RSTrainLocomotive::setDynamicBrake(int dynamicBrake) {
	this->dynamicBrake = dynamicBrake;
}

double RSTrainLocomotive::getMainPipePressure() {
	return mainPipePressure;
}

void RSTrainLocomotive::setMainPipePressure(double mainPipePressure) {
	this->mainPipePressure = mainPipePressure;
}

double RSTrainLocomotive::getMainReservoirPressure() {
	return mainReservoirPressure;
}

void RSTrainLocomotive::setMainReservoirPressure(double mainReservoirPressure) {
	this->mainReservoirPressure = mainReservoirPressure;
}

bool RSTrainLocomotive::isMotorActive() {
	return motorActive;
}

void RSTrainLocomotive::setMotorActive(bool motorActive) {
	this->motorActive = motorActive;
}

bool RSTrainLocomotive::isPurger() {
	return purger;
}

void RSTrainLocomotive::setPurger(bool purger) {
	this->purger = purger;
}

int RSTrainLocomotive::getThrottle() {
	return throttle;
}

void RSTrainLocomotive::setThrottle(int throttle) {
	this->throttle = throttle;
}

double RSTrainLocomotive::getTractionForce() {
	return tractionForce;
}

double RSTrainLocomotive::getDynamicBrakeForce() {
	return dynamicBrakeForce;
}

void RSTrainLocomotive::calcLocomotiveRollingResistance() {

	rollingResistanceForce = rollingResistanceForceCalculator->CalculateRollingResistance();
}

void RSTrainLocomotive::calcTractionForce() {

	this->tractionForce = this->tractionForceCalculator->CalculateTractionForce();

}

void RSTrainLocomotive::calcDynamicBrakeForce() {

	dynamicBrakeForce = dynamicBrakeForceCalculator->CalculateDynamicBrakeForce();

}

void RSTrainLocomotive::calcPipeBreakForce(double dt) {

	for(int i = 0; i<brakeCylinderCount;i++){

		this->controlValves[i]->CalcPressures(dt);
		this->brakeCylinders[i]->CalcAirBrakeForce();

	}

}

void RSTrainLocomotive::updateVariables(double dt) {

	this->watcher->update();
	this->setVelocity(this->posvel[1]);
	this->calcCoefFriction();
	this->calcAhreranceCoef();

	// Variables depends on brake will be updated if required
}

void RSTrainLocomotive::addLocomotiveControlValve(
		RSTrainControlValve* controlvalve) {

	this->controlValves.push_back(controlvalve);
}

RSTrainControlValve* RSTrainLocomotive::getLocomotiveControlValve(int index) {

	return this->controlValves[index];
}

void RSTrainLocomotive::addLocomotiveBrakeCylinder(RSTrainBrakeCylinder* brakeCylinder) {

	this->brakeCylinders.push_back(brakeCylinder);
}

RSTrainBrakeCylinder* RSTrainLocomotive::getLocomotiveBrakeCylinder(int index) {

	return this->brakeCylinders[index];
}



void RSTrainLocomotive::calcEffectiveForceWithAdherance() {

	double F = 0;
	double F_abs = 0;

	for(int i = 0; i<numberAxles;i++){

		F = (this->tractionForce);
		F += (this->dynamicBrakeForce);
		F += this->brakeCylinders[i%brakeCylinderCount]->getAirBrakeForce() / 2;

		F_abs = fabs(F);
		if(F_abs <= this->adheranceForce){

			this->totalForce += F;

		}
	}

}

void RSTrainLocomotive::calcCouplingForcesOnTheVehicle() {

	if (this->frontCoupling != 0)
		this->totalForce += this->frontCoupling->getCouplingForce();
	if (this->rearCoupling != 0)
		this->totalForce -= this->rearCoupling->getCouplingForce();

}

void RSTrainLocomotive::calcPhysicalForcesOnTheVehicle() {

	this->totalForce += this->rollingResistanceForce;

	//cout<<"Roll:"<<this->rollingResistanceForce<<endl;

	this->totalForce += this->curveResistanceForce;

	//cout<<"curve :"<<this->curveResistanceForce<<endl;

	this->totalForce += this->rampResistanceForce;

	//cout<<"ramp: "<<this->rampResistanceForce<<endl;

	//cout<<"alfa: "<<this->alfa<<endl;
}



void RSTrainLocomotive::calcTotalForce() {

	this->totalForce = 0;

	this->calcEffectiveForceWithAdherance();

	this->calcCouplingForcesOnTheVehicle();

	this->calcPhysicalForcesOnTheVehicle();

}

vector<RSTrainControlValve*>& RSTrainLocomotive::getControlValves()  {
	return controlValves;
}



void RSTrainLocomotive::calcForce(double dt) {

	this->calcTractionForce();

	this->calcDynamicBrakeForce();

	this->calcPipeBreakForce(dt);

	this->calcAdheranceForce();

	this->calcLocomotiveRollingResistance();

	this->calcCurveResistance();

	this->calcRampResistance();

	if (this->rearCoupling != 0)
		this->rearCoupling->calcCouplingForce();

	this->calcTotalForce();
}

int RSTrainLocomotive::getBrakeCylinderCount() const {
	return brakeCylinderCount;
}

void RSTrainLocomotive::setBrakeCylinderCount(int brakeCylinderCount) {
	this->brakeCylinderCount = brakeCylinderCount;
}
