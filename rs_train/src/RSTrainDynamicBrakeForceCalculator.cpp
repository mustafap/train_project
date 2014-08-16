/*
 * RSTrainDynamicBrakeForceCalculator.cpp
 *
 *  Created on: 15 Tem 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainDynamicBrakeForceCalculator.h"
#include "RSTrainLocomotive.h"
#include <math.h>
RSTrainDynamicBrakeForceCalculator::RSTrainDynamicBrakeForceCalculator(
		RSTrainLocomotive* parent) {
	// TODO Auto-generated constructor stub

	this->parent = parent;
}

RSTrainDynamicBrakeForceCalculator::~RSTrainDynamicBrakeForceCalculator() {
	// TODO Auto-generated destructor stub
}

RSTrainLocomotive* RSTrainDynamicBrakeForceCalculator::getParent() {
	return parent;
}

void RSTrainDynamicBrakeForceCalculator::setParent(RSTrainLocomotive* parent) {
	this->parent = parent;
}

double RSTrainDynamicBrakeForceCalculator::CalculateDynamicBrakeForce() {

	double F = 0;

	double V = this->parent->getVelocityKph();

	double V_abs = fabs(V);

	int DB_State = this->parent->getDynamicBrake();

	switch (DB_State) {
	case 0: {
		F = 0;
		break;
	}
	case 1: {
		if (V_abs >= 5 && V_abs <= 90) {
			F = 0.9059 * V_abs + 5.471;
		}
		break;
	}
	case 2: {
		if (V_abs >= 5 && V_abs <= 79) {
			F = 1.203 * V_abs + 4.986;
		} else if (V_abs > 79 && V_abs <= 90) {
			F = (-0.6589 * V_abs * V_abs + 130.6 * V_abs - 537.9) / (V_abs - 22.35);
		}

		break;
	}
	case 3: {
		if (V_abs >= 5 && V_abs <= 68) {
			F = 1.571 * V_abs + 8.143;
		} else if (V_abs > 68 && V_abs <= 90) {
			F = (-0.6589 * V_abs * V_abs + 130.6 * V_abs - 537.9) / (V_abs - 22.35);
		}
		break;
	}
	case 4: {
		if (V_abs >= 5 && V_abs <= 61) {
			F = 1.982 * V_abs + 9.089;
		} else if (V_abs > 61 && V_abs <= 90) {
			F = (-0.6589 * V_abs * V_abs + 130.6 * V_abs - 537.9) / (V_abs - 22.35);
		}
		break;
	}
	case 5: {
		if (V_abs >= 5 && V_abs <= 54) {
			F = 2.51 * V_abs + 9.449;
		} else if (V_abs > 54 && V_abs <= 90) {
			F = (-0.6589 * V_abs * V_abs + 130.6 * V_abs - 537.9) / (V_abs - 22.35);
		}
		break;
	}
	case 6: {
		if (V_abs >= 5 && V_abs <= 49) {
			F = 3 * V_abs + 13;
		} else if (V_abs > 49 && V_abs <= 90) {
			F = (-0.6589 * V_abs * V_abs + 130.6 * V_abs - 537.9) / (V_abs - 22.35);
		}
		break;
	}
	case 7: {
		if (V_abs >= 5 && V_abs <= 45) {
			F = 3.6 * V_abs + 15;
		} else if (V_abs > 45 && V_abs <= 90) {
			F = (-0.6589 * V_abs * V_abs + 130.6 * V_abs - 537.9) / (V_abs - 22.35);
		}
		break;
	}
	case 8: {
		if (V_abs >= 5 && V_abs <= 37.5) {
			F = 4.338 * V_abs + 14.31;
		} else if (V_abs > 37.5 && V_abs <= 45) {
			F = 177;
		} else if (V_abs > 45 && V_abs <= 90) {
			F = (-0.6589 * V_abs * V_abs + 130.6 * V_abs - 537.9) / (V_abs - 22.35);
		}
		break;
	}
	case 9: {
		if (V_abs >= 5 && V_abs <= 32) {
			F = 5.074 * V_abs + 14.63;
		} else if (V_abs > 32 && V_abs <= 45) {
			F = 177;
		} else if (V_abs > 45 && V_abs <= 90) {
			F = (-0.6589 * V_abs * V_abs + 130.6 * V_abs - 537.9) / (V_abs - 22.35);
		}
		break;
	}
	case 10: {
		if (V_abs >= 5 && V_abs <= 28) {
			F = 5.609 * V_abs + 19.96;
		} else if (V_abs > 28 && V_abs <= 45) {
			F = 177;
		} else if (V_abs > 45 && V_abs <= 90) {
			F = (-0.6589 * V_abs * V_abs + 130.6 * V_abs - 537.9) / (V_abs - 22.35);
		}
		break;
	}

	default:
		break;
	}

	F *=1000;
	if(V > 0){
		F *=-1;
	}
	return F;
}
