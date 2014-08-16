/*
 * RSTrainControlValve.cpp
 *
 *  Created on: 26 May 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainControlValve.h"
#include "RSTrainVehicle.h"
#include "pugixml.hpp"
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

RSTrainControlValve::RSTrainControlValve(RSTrainVehicle* parent) {

	this->parent = parent;

	pugi::xml_document doc;
	if(doc.load_file("ControlValve.xml")){

		pugi::xml_node ControlValve = doc.child("ControlValve");

		this->ARPressure = ControlValve.child("AuxillaryReservoirPressure").text().as_double();

		this->BCPressure = ControlValve.child("BrakeCylinderPressure").text().as_double();

		this->flowConstant = ControlValve.child("flowConstant").text().as_double();

		this->flowConstantGood = ControlValve.child("flowConstantGood").text().as_double();

		this->flowConstantPassanger = ControlValve.child("flowConstantPassanger").text().as_double();

		this->BPPressure = parent->getBrakePipePresure();

		this->isEqualied = false;

		this->triggered = false;

		this->GOUP = 1;

		this->GODOWN = -1;

		this->err = 0;

		this->diff = 0;

		this->faultState = 0;

		this->direction = GOUP;
	}else{

		this->ARPressure = 5;

		this->BCPressure = 0;

		this->BPPressure = 5;

		this->isEqualied = false;

		this->triggered = false;

		this->flowConstant = 10;

		this->flowConstantGood = 10;

		this->flowConstantPassanger = 10;

		this->GOUP = 1;

		this->GODOWN = -1;

		this->err = 0;

		this->diff = 0;

		this->faultState = 0;

		this->direction = GOUP;

		cout<<"XML-File Could not Found : ControlValve.xml"<<endl;
	}

}

RSTrainControlValve::~RSTrainControlValve() {

}

double RSTrainControlValve::getArPressure() {
	return ARPressure;
}

void RSTrainControlValve::setArPressure(double arPressure) {
	ARPressure = arPressure;
}

double RSTrainControlValve::getBcPressure() {
	return BCPressure;
}

void RSTrainControlValve::setBcPressure(double bcPressure) {
	BCPressure = bcPressure;
}

RSTrainVehicle* RSTrainControlValve::getParent() {
	return parent;
}

void RSTrainControlValve::setParent(RSTrainVehicle* parent) {
	this->parent = parent;
}

double RSTrainControlValve::getBpPressure() {
	return BPPressure;
}

void RSTrainControlValve::setBpPressure(double bpPressure) {
	BPPressure = bpPressure;
}

void RSTrainControlValve::setFaultState(int faultState) {

	this->faultState = faultState;
}


void RSTrainControlValve::CalcPressures(double dt) {

	this->CalcDifferences();

	this->CheckDifference();

	if (this->BPPressure <= 4.5) {

		if (!isEqualied) {

			if (triggered) {

				if (parent->getFreightType() == 0) {
					flowConstant = flowConstantGood;
				}
				if (parent->getFreightType() == 1) {
					flowConstant = flowConstantPassanger;
				}

				this->ARPressure += this->direction * this->flowConstant * dt;

				if (((direction == GOUP) && (faultState != 1))
						|| ((direction == GODOWN) && (faultState != 2))) {
					this->BCPressure -= this->direction * this->flowConstant
							* dt;
				}
			}
		}

	} else {

		if (this->ARPressure < 5) {

			this->ARPressure += flowConstant * dt;
		}

		if (this->BCPressure > 0) {
			this->BCPressure -= flowConstant * dt;
		}

	}
}

void RSTrainControlValve::CheckDifference() {

	if (err >= 0.05 || err <= -0.05) {
		this->isEqualied = false;
	} else {
		this->isEqualied = true;
	}

	if (diff >= 0.2 || diff <= -0.2) {

		this->triggered = true;

		if (diff > 0) {
			this->direction = GODOWN;
		} else {
			this->direction = GOUP;
		}
	} else {
		this->triggered = false;
	}
}

void RSTrainControlValve::CalcDifferences() {

	this->BPPressure = this->parent->getBrakePipePresure();
	diff = ARPressure - BPPressure;
	err = diff;

}

int RSTrainControlValve::getFaultState() {
	return faultState;
}

double RSTrainControlValve::getDiff(){
	return diff;
}

double RSTrainControlValve::getFlowConstant() {
	return flowConstant;
}

