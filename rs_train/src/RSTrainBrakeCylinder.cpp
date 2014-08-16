/*
 * RSTrainBrakeCylinder.cpp
 *
 *  Created on: 18 Haz 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainBrakeCylinder.h"
#include "RSTrainControlValve.h"
#include "RSTrainVehicle.h"
#include "pugixml.hpp"
#include <math.h>
#include <iostream>
using namespace std;
RSTrainBrakeCylinder::RSTrainBrakeCylinder(RSTrainVehicle* parent,
		RSTrainControlValve* controlValve) {
	// TODO Auto-generated constructor stub
	this->controlValve = controlValve;

	this->parent = parent;

	pugi::xml_document doc;
	bool test = doc.load_file("BrakeCylinder.xml");
	if(test){

		pugi::xml_node BrakeCylinder = doc.child("BrakeCylinder");

		this->A = BrakeCylinder.child("A").text().as_double();

		this->E1 = BrakeCylinder.child("E1").text().as_double();

		this->E2 = BrakeCylinder.child("E2").text().as_double();

		this->F = BrakeCylinder.child("F").text().as_double();

		this->Fs = BrakeCylinder.child("Fs").text().as_double();

		this->Pbc = BrakeCylinder.child("Pbc").text().as_double();

		this->dx = BrakeCylinder.child("dx").text().as_double();

		this->k = BrakeCylinder.child("k").text().as_double();

		this->l = BrakeCylinder.child("l").text().as_double();

		this->u = BrakeCylinder.child("u").text().as_double();

		this->CompLength = BrakeCylinder.child("CompLength").text().as_double();

		this->V = BrakeCylinder.child("V").text().as_double();

	}else{

		this->A = 0.05;

		this->E1 = 0.98;

		this->E2 = 0.9;

		this->F = 0;

		this->Fs = 0;

		this->Pbc = 0;

		this->dx = 0;

		this->k = 22727.2;

		this->l = 3.75;

		this->u = 0;

		this->CompLength = 0.22;

		this->V = 0;

		cout<<"XML-File Could not Found :" << "BrakeCylinder.xml"<<endl;

	}


}

RSTrainBrakeCylinder::~RSTrainBrakeCylinder() {
	// TODO Auto-generated destructor stub
}

void RSTrainBrakeCylinder::CalcAirBrakeForce() {

	Pbc = controlValve->getBcPressure() * 100000;

	V = parent->getVelocity();

	if (CheckCompressionCondition()) {

		this->CalcF();

		this->CalcU();

		this->CalcFs();

		if( V > 0){
			Fs *= -1;
		}

	}else{
		Fs = 0;
	}



}

double RSTrainBrakeCylinder::getDx()  {
	return dx;
}

double RSTrainBrakeCylinder::getAirBrakeForce() {

	return Fs;

}

bool RSTrainBrakeCylinder::CheckCompressionCondition() {

	bool return_value = false;

	dx = (Pbc * A) / k;

	if (dx >= CompLength) {
		return_value = true;
	} else {
		return_value = false;
	}

	return return_value;
}

void RSTrainBrakeCylinder::CalcF() {

	F = (Pbc * A - CompLength * k) * E1 * l * E2;
}

void RSTrainBrakeCylinder::CalcU() {

	//
	//	 	    [  16*F        ]
	//		    [ ------ + 100 ]
	//			[  9800        ]     [ 3.6 * V  + 100]
	// u = 0.6*------------------ * ------------------
	//			[ 80*F         ]     [ 5*3.6*V + 100 ]
	//          [------- + 100 ]
	//          [ 9800         ]

	double V_abs = fabs(V);

	u = 0.6 * (((16 * F / 9800) + 100) / ((80 * F / 9800) + 100))
			* ((3.6 * V_abs + 100) / (5 * 3.6 * V_abs + 100));
}

void RSTrainBrakeCylinder::CalcFs() {

	Fs = u*F;
}
