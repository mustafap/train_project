/*
 * RSTrainBrakePipePressureUpdater.cpp
 *
 *  Created on: 17 Nis 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainBrakePipePressureUpdater.h"
#include "RSTrainVehicle.h"
#include "RSTrainLocomotive.h"
#include "pugixml.hpp"
#include <string>
#include <iostream>
using namespace std;

RSTrainBrakePipePressureUpdater::RSTrainBrakePipePressureUpdater() {

	this->size = 0;

	this->nominalPressure = 5;

	this->minPressure = 0;

	this->maxPressure = 7;

	this->overLoadPressure = 5.4;

	this->pressureLapReleaseRate = 0.2;

	this->pressureLapServiceRate = -0.2;

	this->pressureReleaseRate = 0.7;

	this->pressureServiceRate = -0.7;

	this->emergencyBrake = false;

	this->p1 = 0;
	this->p2 = 0;
	this->dP = 0;

}

void RSTrainBrakePipePressureUpdater::InitVehicles(
		vector<RSTrainVehicle*>* vehicles) {

	this->Vehicles = vehicles;

	size = this->Vehicles->size();

	this->Pressures = vector<double>(size);

	this->pipeState = new int[size];

	this->leakage = new double[size];

	for (int i = 0; i < size; i++) {
		this->Pressures[i] = (*(this->Vehicles))[i]->getBrakePipePresure();

		this->pipeState[i] = 0;

		this->leakage[i] = 0;
	}

	this->currentState = 0;

	this->firstLocomotive =
			dynamic_cast<RSTrainLocomotive*>((*(this->Vehicles))[0]);

}

RSTrainBrakePipePressureUpdater::RSTrainBrakePipePressureUpdater(
		vector<RSTrainVehicle*>* vehicles) {

	this->Vehicles = vehicles;

	this->runforLocomotive = 0;

	size = this->Vehicles->size();

	this->Pressures = vector<double>(size);

	this->pipeState = new int[size];

	this->leakage = new double[size];

	for (int i = 0; i < size; i++) {
		this->Pressures[i] = (*(this->Vehicles))[i]->getBrakePipePresure();

		this->pipeState[i] = 0;

		this->leakage[i] = 0;
	}

	this->currentState = 0;

	this->firstLocomotive =
			dynamic_cast<RSTrainLocomotive*>((*(this->Vehicles))[0]);

	string pipe_file_name = "BrakePipe.xml";

	pugi::xml_document doc;

	if (!doc.load_file(pipe_file_name.c_str())) {
		cout << "File Could not Found : " << pipe_file_name << endl;
	}

	pugi::xml_node BrakePipe = doc.child("BrakePipe");

	this->nominalPressure =
			BrakePipe.child("nominalPressure").text().as_double();

	this->minPressure = BrakePipe.child("minPressure").text().as_double();

	this->maxPressure = BrakePipe.child("maxPressure").text().as_double();

	this->overLoadPressure =
			BrakePipe.child("overLoadPressure").text().as_double();

	this->pressureLapReleaseRate =
			BrakePipe.child("pressureLapReleaseRate").text().as_double();

	this->pressureLapServiceRate =
			BrakePipe.child("pressureLapServiceRate").text().as_double();

	this->pressureReleaseRate =
			BrakePipe.child("pressureReleaseRate").text().as_double();

	this->pressureServiceRate =
			BrakePipe.child("pressureServiceRate").text().as_double();

	this->k = BrakePipe.child("k").text().as_double();

	this->emergencyBrake = false;

	this->p1 = 0;
	this->p2 = 0;
	this->dP = 0;
}

RSTrainBrakePipePressureUpdater::~RSTrainBrakePipePressureUpdater() {

}

void RSTrainBrakePipePressureUpdater::calcBrakePipePressures(double dt) {

	this->calcFirstLocomotivePressure(dt);

	if(runforLocomotive !=0){
		this->calcRunforLocomotiveBrakePipePressure(dt);
	}

	for (int i = 1; i < size; i++) {

		if(Pressures[i] > Pressures[i-1]){
			p1 = Pressures[i];
			p2 = Pressures[i-1];
		}else{
			p1 = Pressures[i-1];
			p2 = Pressures[i];
		}

		dP = p1-p2;

		if (pipeState[i] != 0) {
			currentState = pipeState[i];
		}

		switch (currentState) {
		case 0: {

			p1 -= k*dP;
			p2 += k*dP;

			if(Pressures[i] > Pressures[i-1]){
				Pressures[i] = p1;
				Pressures[i-1] = p2;
			}else{
				Pressures[i-1] = p1;
				Pressures[i] = p2;
			}

			break;
		}
		case 1: {

			if (pipeState[i] == 1) {
				break;
			}

			p1 -= k * dP;
			p2 += k * dP;

			if (Pressures[i] > Pressures[i - 1]) {
				Pressures[i] = p1;
				Pressures[i - 1] = p2;
			} else {
				Pressures[i - 1] = p1;
				Pressures[i] = p2;
			}

			break;
		}
		case 2: {

			if (pipeState[i] == 2) {

				double ratio = leakage[i] / 100;

				p1 -= k * dP;
				p2 += k * dP;

				p1 = p1*(1-ratio);
				p2 = p2*(1-ratio);

				if (Pressures[i] > Pressures[i - 1]) {
					Pressures[i] = p1;
					Pressures[i - 1] = p2;
				} else {
					Pressures[i - 1] = p1;
					Pressures[i] = p2;
				}
				break;
			}

			p1 -= k * dP;
			p2 += k * dP;

			if (Pressures[i] > Pressures[i - 1]) {
				Pressures[i] = p1;
				Pressures[i - 1] = p2;
			} else {
				Pressures[i - 1] = p1;
				Pressures[i] = p2;
			}

			break;
		}
		case 3: {

			if (pipeState[i] == 3) {
				Pressures[i] = 0;
				Pressures[i - 1] = 0;
				break;
			}

			p1 -= k * dP;
			p2 += k * dP;

			if (Pressures[i] > Pressures[i - 1]) {
				Pressures[i] = p1;
				Pressures[i - 1] = p2;
			} else {
				Pressures[i - 1] = p1;
				Pressures[i] = p2;
			}

			break;
		}
		default:
			break;
		}

	}

}

void RSTrainBrakePipePressureUpdater::updateBrakePipePressures() {

	for (int i = 0; i < size; i++) {
		(*(this->Vehicles))[i]->setBrakePipePresure(this->Pressures[i]);
	}
}

void RSTrainBrakePipePressureUpdater::calcFirstLocomotivePressure(double dt) {

	if (emergencyBrake == false) {

		int state = this->firstLocomotive->getBrakeValve();

		switch (state) {
		case 1: {
			// fast increase
			this->calcFirstLocomotivePressureForGivenState(dt, this->pressureReleaseRate);
			break;
		}

		case 2: {
			// normal increase
			this->calcFirstLocomotivePressureForGivenState(dt, this->pressureLapReleaseRate);
			break;
		}

		case 3: {

			break;
		}

		case 4: {
			// normal decrease
			this->calcFirstLocomotivePressureForGivenState(dt, this->pressureLapServiceRate);
			break;
		}

		case 5: {
			this->calcFirstLocomotivePressureForGivenState(dt, this->pressureServiceRate);
			break;
		}

		default:
			break;
		}

	} else {

		this->calcFirstLocomotivePressureForGivenState(dt, this->pressureServiceRate);

	}

}

void RSTrainBrakePipePressureUpdater::calcRunforLocomotiveBrakePipePressure(double dt) {

	int state = this->runforLocomotive->getBrakeValve();

	switch (state) {
	case 1: {
		// fast increase
		this->calcRunforLocomotivePressureForGivenState(dt,
				this->pressureReleaseRate);
		break;
	}

	case 2: {
		// normal increase
		this->calcRunforLocomotivePressureForGivenState(dt,
				this->pressureLapReleaseRate);
		break;
	}

	case 3: {

		break;
	}

	case 4: {
		// normal decrease
		this->calcRunforLocomotivePressureForGivenState(dt,
				this->pressureLapServiceRate);
		break;
	}

	case 5: {
		this->calcRunforLocomotivePressureForGivenState(dt,
				this->pressureServiceRate);
		break;
	}

	default:
		break;
	}



}

void RSTrainBrakePipePressureUpdater::calcFirstLocomotivePressureForGivenState(double dt,
		double rate) {

	double currentPressure = this->firstLocomotive->getBrakePipePresure();

	if((currentPressure >= minPressure) && (currentPressure <= maxPressure)){

		double newPressure = currentPressure + rate * dt;

		if (newPressure <= minPressure) {
			newPressure = minPressure;
		}
		if (newPressure >= maxPressure) {
			newPressure = maxPressure;
		}

		this->Pressures[0] = newPressure;


	}
}

void RSTrainBrakePipePressureUpdater::calcRunforLocomotivePressureForGivenState(
		double dt, double rate) {

	double currentPressure = this->runforLocomotive->getBrakePipePresure();

	if ((currentPressure >= minPressure) && (currentPressure <= maxPressure)) {

		double newPressure = currentPressure + rate * dt;

		if (newPressure <= minPressure) {
			newPressure = minPressure;
		}
		if (newPressure >= maxPressure) {
			newPressure = maxPressure;
		}

		this->runforLocomotive->setBrakePipePresure(newPressure);

	}
}

void RSTrainBrakePipePressureUpdater::setBrakePipeFault(int car_index,
		int faultState) {

	this->pipeState[car_index] = faultState;
}

void RSTrainBrakePipePressureUpdater::setEmergencyBrake(bool emergencyBrake) {

	this->emergencyBrake = emergencyBrake;
}

int RSTrainBrakePipePressureUpdater::getCurrentState() {
	return currentState;
}

void RSTrainBrakePipePressureUpdater::setCurrentState(int currentState) {
	this->currentState = currentState;
}

bool RSTrainBrakePipePressureUpdater::isEmergencyBrake() {
	return emergencyBrake;
}


double RSTrainBrakePipePressureUpdater::getMaxPressure() {
	return maxPressure;
}

void RSTrainBrakePipePressureUpdater::setMaxPressure(double maxPressure) {
	this->maxPressure = maxPressure;
}

double RSTrainBrakePipePressureUpdater::getMinPressure() {
	return minPressure;
}

void RSTrainBrakePipePressureUpdater::setMinPressure(double minPressure) {
	this->minPressure = minPressure;
}

double RSTrainBrakePipePressureUpdater::getNominalPressure() {
	return nominalPressure;
}

void RSTrainBrakePipePressureUpdater::setNominalPressure(
		double nominalPressure) {
	this->nominalPressure = nominalPressure;
}

double RSTrainBrakePipePressureUpdater::getOverLoadPressure()  {
	return overLoadPressure;
}

void RSTrainBrakePipePressureUpdater::setOverLoadPressure(
		double overLoadPressure) {
	this->overLoadPressure = overLoadPressure;
}


double RSTrainBrakePipePressureUpdater::getPressureLapReleaseRate() {
	return pressureLapReleaseRate;
}

void RSTrainBrakePipePressureUpdater::setPressureLapReleaseRate(
		double pressureLapReleaseRate) {
	this->pressureLapReleaseRate = pressureLapReleaseRate;
}

double RSTrainBrakePipePressureUpdater::getPressureLapServiceRate() {
	return pressureLapServiceRate;
}

void RSTrainBrakePipePressureUpdater::setPressureLapServiceRate(
		double pressureLapServiceRate) {
	this->pressureLapServiceRate = pressureLapServiceRate;
}

double RSTrainBrakePipePressureUpdater::getPressureReleaseRate() {
	return pressureReleaseRate;
}

void RSTrainBrakePipePressureUpdater::setPressureReleaseRate(
		double pressureReleaseRate) {
	this->pressureReleaseRate = pressureReleaseRate;
}


double RSTrainBrakePipePressureUpdater::getPressureServiceRate() {
	return pressureServiceRate;
}

void RSTrainBrakePipePressureUpdater::setPressureServiceRate(
		double pressureServiceRate) {
	this->pressureServiceRate = pressureServiceRate;
}

void RSTrainBrakePipePressureUpdater::setLeakage(int index, double leakage) {

	this->leakage[index] = leakage;
}

int RSTrainBrakePipePressureUpdater::getFaultState(int index) {

	return this->pipeState[index];
}

double RSTrainBrakePipePressureUpdater::getLeakage(int index) {

	return this->leakage[index];
}

double RSTrainBrakePipePressureUpdater::getK() {
	return k;
}

void RSTrainBrakePipePressureUpdater::setK(double k) {
	this->k = k;
}

RSTrainLocomotive* RSTrainBrakePipePressureUpdater::getRunforLocomotive(){
	return runforLocomotive;
}



void RSTrainBrakePipePressureUpdater::setRunforLocomotive(
		RSTrainLocomotive* runforLocomotive) {
	this->runforLocomotive = runforLocomotive;
}


