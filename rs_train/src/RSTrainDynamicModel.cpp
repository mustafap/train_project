/*
 * RSTrainDynamicModel.cpp
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainDynamicModel.h"
#include "RSTrainVehicle.h"
using namespace std;

RSTrainDynamicModel::RSTrainDynamicModel() {
	this->vehicle = 0;

}

RSTrainDynamicModel::~RSTrainDynamicModel() {
}

 RSTrainVehicle* RSTrainDynamicModel::getVehicle()  {
	return vehicle;
}

void RSTrainDynamicModel::setVehicle( RSTrainVehicle* vehicle) {
	this->vehicle = vehicle;
}

void RSTrainDynamicModel::operator ()(const vector<double>& x,
		vector<double>& dxdt, const double /*t*/) {

	dxdt[0] = x[1];
	dxdt[1] = vehicle->getTotalForce()*9.81/vehicle->getMass();
	vehicle->setAccelaration(dxdt[1]);

}
