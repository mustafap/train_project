/*
 * RSTrainRunforLocomotiveCoupling.cpp
 *
 *  Created on: 15 Aðu 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainRunforLocomotiveCoupling.h"

RSTrainRunforLocomotiveCoupling::RSTrainRunforLocomotiveCoupling() {
	// TODO Auto-generated constructor stub

}

RSTrainRunforLocomotiveCoupling::~RSTrainRunforLocomotiveCoupling() {
	// TODO Auto-generated destructor stub
}

void RSTrainRunforLocomotiveCoupling::calcDistance() {

	double d = this->distance;

	double trend = this->distance - this->prevDistance;

	if (d >= (-25)) {
		this->couplingForce = 0;
		return;
	}

	if (d < -25) {

		if (trend >= 0) {
			this->couplingForce = Kdec * (d + 25);
		} else if (trend < 0) {
			this->couplingForce = Kinc * (d + 25);
		}
	}

}
