/*
 * RSTrainCar.cpp
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainCar.h"
#include "RSTrainRoadWatcher.h"
#include "RSTrainCoupling.h"
#include "RSTrainCarRollingResistanceCalculator.h"
#include "RSTrainControlValve.h"
#include "RSTrainBrakeCylinder.h"
#include <math.h>

RSTrainCar::RSTrainCar() {
	this->totalForce=0;
	this->rollingResistanceForce=0;
	this->curveResistanceForce=0;
	this->velocity=0;
	this->velocityKPH=0;

	this->rollingResistanceForceCalculator = new RSTrainCarRollingResistanceCalculator(this);


}

RSTrainCar::~RSTrainCar() {
	// TODO Auto-generated destructor stub
}


void RSTrainCar::calcCarRollingResistence() {

	rollingResistanceForce = rollingResistanceForceCalculator->CalculateRollingResistance();
}


void RSTrainCar::updateVariables(double dt) {

	// pozisyon deðiþimden kaynaklanan yol bilgisinin deðiþmesiyle ilgilenir
	this->watcher->update();

	// hýz deðiþimden dolayý aracýn sahip olduðu hýzý deðiþitiri
	this->setVelocity(this->posvel[1]);

	// coefficient friction ý hesapla
	this->calcCoefFriction();

	// adherance coefficient i hesapla
	this->calcAhreranceCoef();
}

void RSTrainCar::calcPipeBrakeForce(double dt) {

	this->controlValve->CalcPressures(dt);
	this->brakeCylinder->CalcAirBrakeForce();
}


void RSTrainCar::calcEffectiveForceWithAdherance() {

	double F = 0;
	double F_abs = 0;

	F += this->brakeCylinder->getAirBrakeForce();
	F_abs = fabs(F);

	if(F_abs <= this->adheranceForce){
		this->totalForce += F;
	}
}

void RSTrainCar::calcCouplingForcesOnTheVehicle() {

	if (this->frontCoupling != 0)
		this->totalForce += this->frontCoupling->getCouplingForce();
	if (this->rearCoupling != 0)
		this->totalForce -= this->rearCoupling->getCouplingForce();

}

void RSTrainCar::calcPhysicalForcesOnTheVehicle() {

	this->totalForce += this->rollingResistanceForce;
	this->totalForce += this->curveResistanceForce;
	this->totalForce += this->rampResistanceForce;

}
void RSTrainCar::calcTotalForce() {

	this->totalForce = 0;

	this->calcEffectiveForceWithAdherance();

	this->calcCouplingForcesOnTheVehicle();

	this->calcPhysicalForcesOnTheVehicle();


	// Brake force will be added later
}



void RSTrainCar::calcForce(double dt) {

	this->calcAdheranceForce();
	this->calcCarRollingResistence();
	this->calcCurveResistance();
	this->calcRampResistance();

	//Air Brake Force Calculation
	this->calcPipeBrakeForce(dt);


	if(this->rearCoupling != 0)
		this->rearCoupling->calcCouplingForce();

	this->calcTotalForce();
}
