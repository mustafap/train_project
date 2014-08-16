/*
 * RSTrainTractionForceCalculator.cpp
 *
 *  Created on: 15 Tem 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainTractionForceCalculator.h"
#include "RSTrainLocomotive.h"
#include <math.h>
RSTrainTractionForceCalculator::RSTrainTractionForceCalculator(
		RSTrainLocomotive* parent) {
	// TODO Auto-generated constructor stub

	this->parent = parent;

}

RSTrainTractionForceCalculator::~RSTrainTractionForceCalculator() {
	// TODO Auto-generated destructor stub
}

RSTrainLocomotive* RSTrainTractionForceCalculator::getParent() {
	return parent;
}

void RSTrainTractionForceCalculator::setParent(RSTrainLocomotive* parent) {
	this->parent = parent;
}

double RSTrainTractionForceCalculator::CalculateTractionForce() {

	double V = this->parent->getVelocityKph();

	double V_abs = fabs(V);

	int T_State = this->parent->getThrottle();

	double T_Force = 0;

	switch (T_State) {

		case 0: {
			T_Force = 0;
			break;
		}

		case 1: {
			if ((V_abs >= 0) && (V_abs <= 10))
				T_Force = (-0.75 * V_abs + 19) * 1000;
			else
				T_Force = 0;
			break;
		}
		case 2: {
			if (V_abs >= 0 && V_abs <= 15)
				T_Force = (-1 * V_abs + 50) * 1000;
			else
				T_Force = 0;
			break;
		}
		case 3: {
			if (V_abs >= 0 && V_abs <= 13)
				T_Force = (-1.423 * V_abs + 87.5) * 1000;
			else if (V_abs > 13 && V_abs <= 25)
				T_Force = ((-28.5 * V_abs + 1336) / (V_abs + 1)) * 1000;
			else
				T_Force = 0;
			break;
		}
		case 4: {
			if (V_abs >= 0 && V_abs <= 19)
				T_Force = (-1.737 * V_abs + 133) * 1000;
			else if (V_abs > 19 && V_abs <= 39)
				T_Force = ((-46.82 * V_abs + 2835) / (V_abs + 0.4709)) * 1000;
			else
				T_Force = 0;
			break;
		}
		case 5: {
			if (V_abs >= 0 && V_abs <= 23)
				T_Force = (-2.065 * V_abs + 185) * 1000;
			else if (V_abs > 23 && V_abs <= 50)
				T_Force = ((-54.16 * V_abs + 4134) / (V_abs - 2.015)) * 1000;
			else
				T_Force = 0;
			break;
		}
		case 6: {
			if (V_abs >= 0 && V_abs <= 27.5)
				T_Force = (-1.973 * V_abs + 236) * 1000;
			else if (V_abs > 27.5 && V_abs <= 62)
				T_Force = ((-40.56 * V_abs + 4216) / (V_abs - 10.54)) * 1000;
			else
				T_Force = 0;
			break;
		}
		case 7: {
			if (V_abs >= 0 && V_abs <= 31)
				T_Force = (-1.968 * V_abs + 286) * 1000;
			else if (V_abs > 31 && V_abs <= 71)
				T_Force = ((-55.84 * V_abs + 6135) / (V_abs - 11.42)) * 1000;
			else
				T_Force = 0;
			break;
		}
		case 8: {
			if (V_abs >= 0 && V_abs < 34)
				T_Force = (-1.971 * V_abs + 336) * 1000;
			else if (V_abs > 34 && V_abs <= 83)
				T_Force = ((0.5545 * V_abs * V_abs + -141.8 * V_abs + 10960) / (V_abs - 8.845))
						* 1000;
			else
				T_Force = 0;
			break;
		}
		case 9: {
			if (V_abs >= 0 && V_abs < 35)
				T_Force = (-1.943 * V_abs + 387.5) * 1000;
			else if (V_abs > 35 && V_abs <= 41)
				T_Force = ((-146.7 * V_abs + 23300) / (V_abs + 21.86)) * 1000;
			else if (V_abs > 41 && V_abs <= 90)
				T_Force = ((0.4588 * V_abs * V_abs - 116.5 * V_abs + 10310) / (V_abs - 18.1))
						* 1000;
			else
				T_Force = 0;
			break;
		}
		case 10: {
			if (V_abs >= 0 && V_abs < 35)
				T_Force = (-1.943 * V_abs + 387.5) * 1000;
			else if (V_abs > 35 && V_abs <= 46)
				T_Force = ((-53.82 * V_abs + 15980) / (V_abs + 9.121)) * 1000;
			else if (V_abs > 46 && V_abs <= 90)
				T_Force = ((0.8968 * V_abs * V_abs - 196.4 * V_abs + 14410) / (V_abs - 16.36))
						* 1000;
			else
				T_Force = 0;
			break;
		}
		case 11: {
			if (V_abs >= 0 && V_abs < 35)
				T_Force = (-1.943 * V_abs + 387.5) * 1000;
			else if (V_abs > 35 && V_abs <= 53)
				T_Force = ((-39.57 * V_abs + 14820) / (V_abs + 7.046)) * 1000;
			else if (V_abs > 53 && V_abs <= 90)
				T_Force = ((-0.2925 * V_abs * V_abs - 6.85 * V_abs + 7205) / (V_abs - 24.62))
						* 1000;
			else
				T_Force = 0;
			break;
		}
		case 12: {
			if (V_abs >= 0 && V_abs < 35)
				T_Force = (-1.943 * V_abs + 387.5) * 1000;
			else if (V_abs > 35 && V_abs <= 60)
				T_Force = ((-37.11 * V_abs + 14580) / (V_abs + 6.561)) * 1000;
			else if (V_abs > 60 && V_abs <= 90)
				T_Force = ((0.2654 * V_abs * V_abs - 134.6 * V_abs + 16080) / (V_abs - 11.92))
						* 1000;
			else
				T_Force = 0;
			break;
		}
		case 13: {
			if (V_abs >= 0 && V_abs < 35)
				T_Force = (-1.943 * V_abs + 387.5) * 1000;
			else if (V_abs > 35 && V_abs <= 67)
				T_Force = ((-31.49 * V_abs + 14100) / (V_abs + 5.652)) * 1000;
			else if (V_abs > 67 && V_abs <= 90)
				T_Force = ((1.393 * V_abs * V_abs - 459.6 * V_abs + 42360) / (V_abs + 43.58))
						* 1000;
			else
				T_Force = 0;
			break;
		}
		case 14: {
			if (V_abs >= 0 && V_abs < 35)
				T_Force = (-1.943 * V_abs + 387.5) * 1000;
			else if (V_abs > 35 && V_abs <= 73)
				T_Force = ((-22.58 * V_abs + 13280) / (V_abs + 4.053)) * 1000;
			else if (V_abs > 73 && V_abs <= 90)
				T_Force = ((-115.7 * V_abs + 19260) / (V_abs - 1.901)) * 1000;
			else
				T_Force = 0;
			break;
		}
		default:
			break;
	}


	return T_Force;

}
