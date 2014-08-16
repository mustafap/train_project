/*
 * RSTrainLocomotiveRollingResistanceCalculator.cpp
 *
 *  Created on: 15 Tem 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainLocomotiveRollingResistanceCalculator.h"
#include "RSTrainLocomotive.h"
#include <math.h>

RSTrainLocomotiveRollingResistanceCalculator::RSTrainLocomotiveRollingResistanceCalculator(
		RSTrainLocomotive* parent) {

	this->parent = parent;
}

RSTrainLocomotiveRollingResistanceCalculator::~RSTrainLocomotiveRollingResistanceCalculator() {
	// TODO Auto-generated destructor stub
}

RSTrainLocomotive* RSTrainLocomotiveRollingResistanceCalculator::getParent() {
	return parent;
}

void RSTrainLocomotiveRollingResistanceCalculator::setParent(
		RSTrainLocomotive* parent) {
	this->parent = parent;
}

double RSTrainLocomotiveRollingResistanceCalculator::CalculateRollingResistance() {

	// Locomotive rolling resistance function
	double V = this->parent->getVelocityKph();
	double V_abs = fabs(V);

	double G = this->parent->getMassInTons();

	int n = this->parent->getNumberAxles();

	double F = 0;

	if (V == 0) {
		F = 0;
		return F;
	}

	F = (6.5 * G + 130 * n + 0.1 * G * V_abs
			+ 0.3 * V_abs * V_abs) * -1;

	if (V < 0)
		F *= -1;

	return F;

}
