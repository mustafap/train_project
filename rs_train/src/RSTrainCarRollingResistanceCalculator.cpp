/*
 * RSTrainCarRollingResistanceCalculator.cpp
 *
 *  Created on: 15 Tem 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainCarRollingResistanceCalculator.h"
#include "RSTrainCar.h"
#include <math.h>


RSTrainCarRollingResistanceCalculator::RSTrainCarRollingResistanceCalculator(
		RSTrainCar* parent) {

	this->parent = parent;
}

RSTrainCarRollingResistanceCalculator::~RSTrainCarRollingResistanceCalculator() {
	// TODO Auto-generated destructor stub
}

RSTrainCar* RSTrainCarRollingResistanceCalculator::getParent() {

	return parent;
}

void RSTrainCarRollingResistanceCalculator::setParent(RSTrainCar* parent) {

	this->parent = parent;
}

double RSTrainCarRollingResistanceCalculator::CalculateRollingResistance() {

		// 0 = Good
		// 1 = Passanger

		double V = this->parent->getVelocityKph();
		double V_abs = fabs(V);

		double G = this->parent->getMassInTons();

		int FreightType = this->parent->getFreightType();

		double F = 0;

		if(V_abs == 0)
		{
			F = 0;
			return F;
		}

		switch (FreightType) {
			case 0:{
				F = (20 + (0.057 / 10)*V_abs*V_abs)*G*-1;
				break;
			}
			case 1:{
				F = (19.86 + 0.0932*V_abs + 0.00161*V_abs*V_abs)*G * -1;
				break;
			}
			default:
				break;
		}


		if(V < 0)
			F *=-1;

		return F;
}
