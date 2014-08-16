/*
 * RSTrainCoupling.cpp
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainCoupling.h"
#include "RSTrainVehicle.h"
#include <vector>
using namespace std;
RSTrainCoupling::RSTrainCoupling() {

	this->distance=0;
	this->prevDistance=0;
	this->backVehicle=0;
	this->frontVehicle=0;
	this->couplingForce=0;
	this->Kinc = 26000;
	this->Kdec = 1000;

}

 RSTrainVehicle* RSTrainCoupling::getBackVehicle()  {
	return backVehicle;
}

void RSTrainCoupling::setBackVehicle( RSTrainVehicle* backVehicle) {
	this->backVehicle = backVehicle;
	this->backVehicle->setFrontCoupling(this);
}

double RSTrainCoupling::getCouplingForce()  {
	return couplingForce;
}

void RSTrainCoupling::setCouplingForce(double couplingForce) {
	this->couplingForce = couplingForce;
}

double RSTrainCoupling::getDistance()  {
	return distance;
}

void RSTrainCoupling::setDistance(double distance) {
	this->distance = distance;
}

 RSTrainVehicle* RSTrainCoupling::getFrontVehicle()  {
	return frontVehicle;
}

void RSTrainCoupling::setFrontVehicle( RSTrainVehicle* frontVehicle) {
	this->frontVehicle = frontVehicle;
	this->frontVehicle->setRearCoupling(this);
}

RSTrainCoupling::~RSTrainCoupling() {

}

void RSTrainCoupling::calcDistance() {

	// coupling e ba�l� �n arac�n posvel vectorunu al
	vector<double>& posvelfront = this->frontVehicle->getPosvel();

	// coupling e ba�l� arka arac�n posvel vectorunu al
	vector<double>& posvelback = this->backVehicle->getPosvel();

	// �nceki mesafeyi tut
	this->prevDistance = this->distance;

	// coupling �zerindeki de�i�imi hesapla
	// posvel[0] ara�lar�n pozisyon de�i�imlerini verir
	this->distance = (posvelfront[0] - posvelback[0]) * 1000; // Convert into milimeter


}

void RSTrainCoupling::calcCouplingForce() {

	double d = this->distance;

	double trend = this->distance - this->prevDistance;

	if(d >= (-25)  &&  d <=25)
	{
		this->couplingForce =0;
		return;
	}

	if( d > 25)
	{
		if( trend >=0 )
		{
			this->couplingForce = Kinc*(d-25);
		}
		else if( trend < 0)
		{
			this->couplingForce = Kdec*(d-25);
		}
	}
	else if( d < -25)
	{
		if( trend >=0 )
		{
			this->couplingForce = Kdec*(d+25);
		}
		else if( trend < 0)
		{
			this->couplingForce = Kinc*(d+25);
		}
	}

}

double RSTrainCoupling::getKdec(){
	return Kdec;
}



double RSTrainCoupling::getKinc(){
	return Kinc;
}


