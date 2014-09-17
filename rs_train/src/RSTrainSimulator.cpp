/*
 * RSTrainSimulator.cpp
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "boost/numeric/odeint.hpp"
#include "RSTrainSimulator.h"
#include "RSTrainDynamicModel.h"
#include "RSTrainVehicle.h"
#include "RSTrainLocomotive.h"
#include "RSTrainCar.h"
#include "RSTrainLocomotiveParser.h"
#include "RSTrainCarParser.h"
#include "RSTrainCoupling.h"
#include "RailwayElement.h"
#include "RSTrainRailwayElementParser.h"
#include "RSTrainRoadWatcher.h"
#include "RSTrainBrakePipePressureUpdater.h"
#include "RSTrainBrakePipeParser.h"
#include "RSTrainControlValve.h"
#include "RSTrainBrakeCylinder.h"
#include "RSTrainLocomotiveControlValve.h"
#include "RSTrainGetter.h"
#include "RSTrainRunforLocomotiveCoupling.h"
#include <boost/thread.hpp>
#include <boost/date_time.hpp>

RSTrainSimulator::RSTrainSimulator() {

	this->prevVehicle = 0;
	this->vehicleNumber = 0;
	this->railwayelement = 0;
	this->mainLocomotive = 0;
	this->runforLocomotive = 0;
	this->time = 0;
	this->resume = true;
	this->run = new boost::condition_variable();
	this->bPupdater = 0;

	this->getterAndLogger = new RSTrainGetter(this);


}

RSTrainSimulator::~RSTrainSimulator() {
}

vector<RSTrainVehicle*>& RSTrainSimulator::getVehicleVector() {
	return vehicleVector;
}

vector<RSTrainCoupling*>& RSTrainSimulator::getCouplingVector() {
	return couplingVector;
}

double RSTrainSimulator::getDt() {
	return dt;
}

double RSTrainSimulator::getVehicleNumber() {
	return vehicleNumber;
}

void RSTrainSimulator::setFreightType(int index, int freightType) {
	this->vehicleVector[index]->setFreightType(freightType);
}

void RSTrainSimulator::setMass(int index, double mass) {
	this->vehicleVector[index]->setMass(mass);
}

double RSTrainSimulator::getRange() {
	return range;
}

double RSTrainSimulator::getTime() {
	return time;
}


void RSTrainSimulator::setLocomotiveBCPurgeFault(int vehicleIndex,
		int brakeCylinderIndex, bool enable) {

	RSTrainLocomotive* l =
			dynamic_cast<RSTrainLocomotive*>(this->vehicleVector[vehicleIndex]);
	if (l) {
		if (enable) {

			l->getLocomotiveControlValve(brakeCylinderIndex)->setFaultState(1);

		} else {

			l->getLocomotiveControlValve(brakeCylinderIndex)->setFaultState(0);

		}
	}



}

void RSTrainSimulator::setLocomotiveBCEnabled(int vehicleIndex,
		int brakeCylinderIndex, bool enable) {

	RSTrainLocomotive* l =
			dynamic_cast<RSTrainLocomotive*>(this->vehicleVector[vehicleIndex]);

	if (l) {
		if (enable) {

			l->getLocomotiveControlValve(brakeCylinderIndex)->setFaultState(2);

		} else {

			l->getLocomotiveControlValve(brakeCylinderIndex)->setFaultState(0);

		}
	}



}

void RSTrainSimulator::setCarBreakCylinderPurgeFault(int index, bool enable) {

	if(enable){
		this->vehicleVector[index]->getControlValve()->setFaultState(1);
	}else{
		this->vehicleVector[index]->getControlValve()->setFaultState(0);
	}


}

void RSTrainSimulator::setCarBCEnabled(int index, bool enable) {

	if(enable){
		this->vehicleVector[index]->getControlValve()->setFaultState(2);
	}else{
		this->vehicleVector[index]->getControlValve()->setFaultState(0);
	}

}

int RSTrainSimulator::getCarBCFaultState(int index) {

	return this->vehicleVector[index]->getControlValve()->getFaultState();
}

int RSTrainSimulator::getLocomotiveBCFaultState(int vehicleIndex, int brakeCylinderIndex) {

	RSTrainLocomotive* loco = dynamic_cast<RSTrainLocomotive*>(this->vehicleVector[vehicleIndex]);

	RSTrainControlValve* cv = loco->getLocomotiveControlValve(brakeCylinderIndex);

	int fault = cv->getFaultState();

	return fault;
}

void RSTrainSimulator::setCarBPCEnabled(int index, bool enable) {

	if(enable){
		this->bPupdater->setBrakePipeFault(index,1);
	}else{
		this->bPupdater->setBrakePipeFault(index,0);
	}
}




void RSTrainSimulator::setCarBPD(int index, bool enable) {

	if(enable){

		this->bPupdater->setBrakePipeFault(index,3);

	}else{

		this->bPupdater->setBrakePipeFault(index,0);
	}
}

void RSTrainSimulator::setLeakage(int index, double leakage) {

	this->bPupdater->setBrakePipeFault(index,2);
	this->bPupdater->setLeakage(index,leakage);
}

void RSTrainSimulator::setCarEBPull(int index, bool enable) {

	this->EmergencyBrakeOn();

}

int RSTrainSimulator::getBPFaultState(int index) {

	if(bPupdater != 0){
		return this->bPupdater->getFaultState(index);
	}else{
		return 0;
	}
}

double RSTrainSimulator::getBPLeakage(int index) {

	if(bPupdater !=0){
		return this->bPupdater->getLeakage(index);
	}else{
		return 0;
	}

}

void RSTrainSimulator::EmergencyBrakeOn() {

	this->bPupdater->setEmergencyBrake(true);

}

void RSTrainSimulator::EmergencyBrakeOff() {

	this->bPupdater->setEmergencyBrake(false);
}

void RSTrainSimulator::PurgerOn(int index) {

	this->locomotives[index]->setPurger(true);
}

void RSTrainSimulator::PurgerOff(int index) {

	this->locomotives[index]->setPurger(false);
}

void RSTrainSimulator::setThrottlePos(int index, int throttlepos) {
	((RSTrainLocomotive*) (this->vehicleVector[index]))->setThrottle(
			throttlepos);
}

void RSTrainSimulator::setBrakeValvePos(int brakevalvepos) {


	if(mainLocomotive){
		mainLocomotive->setBrakeValve(brakevalvepos);
	}

}

void RSTrainSimulator::setAuxBrakePos(int auxbrakepos) {


	if(mainLocomotive){
		mainLocomotive->setAuxBrake(auxbrakepos);
	}
}

int RSTrainSimulator::getDynamicBrakePos() {

	if(mainLocomotive){
		return this->mainLocomotive->getDynamicBrake();
	}else{
		return 0;
	}



}

void RSTrainSimulator::setDynamicBrakePos(int dynamicBrakeState) {

	if(mainLocomotive){

		mainLocomotive->setDynamicBrake(dynamicBrakeState);

	}
}

double RSTrainSimulator::getDynamicBrakeForce() {

	if(mainLocomotive){

		return this->mainLocomotive->getDynamicBrakeForce();

	}else{

		return 0;

	}
}



void RSTrainSimulator::setDirection(int index, int direction) {
}

void RSTrainSimulator::setMotorActive(int index, int motorindex, bool enable) {
}

void RSTrainSimulator::setCompressorActive(int index, bool enable) {
}

void RSTrainSimulator::setMainReservoirPressure(int index, double pressure) {
}

void RSTrainSimulator::setMainPipePressure(int index, double pressure) {
}

double RSTrainSimulator::getBrakePipePressure(int index) {

	double return_value = this->vehicleVector[index]->getBrakePipePresure();

	return return_value;
}

void RSTrainSimulator::InitRailwayElement(string xmlFileName) {
	RSTrainParser<RailwayElement>* parser =
			RSTrainRailwayElementParser::getInstance();
	this->railwayelement = parser->spawnFromXML(xmlFileName);
}




void RSTrainSimulator::removeRunforLocomotive() {

	if(runforLocomotive != 0){

		vehicleNumber--;

		vehicleVector.pop_back();

		this->bPupdater->setRunforLocomotive(0);
	}

}

void RSTrainSimulator::addRunforLocomotive(int locotype) {

	// get the parser
	RSTrainParser<RSTrainLocomotive>* parser =
			RSTrainLocomotiveParser::getInstance();

	// create locomotive
	RSTrainVehicle* locomotive = parser->spawnFromXML("E43000.xml");

	RSTrainLocomotive* locomotive_ =
			dynamic_cast<RSTrainLocomotive*>(locomotive);

	// check whether the locomotive is created or not
	if (locomotive_) {

		// supply rail road to the vehicle
		locomotive_->setRailRoad(this->railwayelement);

		int BCSize = locomotive_->getBrakeCylinderCount();

		for (int i = 0; i < BCSize; i++) {
			RSTrainControlValve* CV = new RSTrainLocomotiveControlValve(
					locomotive);

			RSTrainBrakeCylinder* bc = new RSTrainBrakeCylinder(locomotive, CV);

			locomotive_->addLocomotiveControlValve(CV);
			locomotive_->addLocomotiveBrakeCylinder(bc);
		}
		// connect the vehicle created
		this->connectRunforLocomotive(locomotive);

		this->runforLocomotive = locomotive_;

		this->bPupdater->setRunforLocomotive(runforLocomotive);

	} else {
		cout << "Locomotive could not be created !!" << endl;
	}

}
void RSTrainSimulator::addLocomotive(int locotype) {

	// get the parser
	RSTrainParser<RSTrainLocomotive>* parser =
			RSTrainLocomotiveParser::getInstance();

	// create locomotive
	RSTrainVehicle* locomotive = parser->spawnFromXML("E43000.xml");

	RSTrainLocomotive* locomotive_ = dynamic_cast<RSTrainLocomotive*>(locomotive);

	// check whether the locomotive is created or not
	if (locomotive_) {

		// supply rail road to the vehicle
		locomotive_->setRailRoad(this->railwayelement);

		int BCSize = locomotive_->getBrakeCylinderCount();

		for (int i = 0; i < BCSize; i++) {
			RSTrainControlValve* CV = new RSTrainLocomotiveControlValve(locomotive);

			RSTrainBrakeCylinder* bc = new RSTrainBrakeCylinder(locomotive, CV);

			locomotive_->addLocomotiveControlValve(CV);
			locomotive_->addLocomotiveBrakeCylinder(bc);
		}
		// connect the vehicle created
		this->connectCreatedVehicle(locomotive);

		if(vehicleNumber == 1){
			mainLocomotive =  locomotive_;
		}


		this->locomotives.push_back(locomotive_);
	}else{
		cout << "Locomotive could not be created !!" << endl;
	}




}



// creation of  vagons
void RSTrainSimulator::addCar(int carType) {

	// get car parser
	RSTrainParser<RSTrainCar>* parser = RSTrainCarParser::getInstance();

	// create a vagon via the parser
	RSTrainVehicle* car = parser->spawnFromXML("Car.xml");

	// check whether the vagon is created or not
	if (!car) {
		cout << "Locomotive could not be created !!" << endl;
		return;
	}

	// let the car to know the rail road
	car->setRailRoad(this->railwayelement);

	RSTrainControlValve* cv = new RSTrainControlValve(car);

	car->setControlValve(cv);

	RSTrainBrakeCylinder* bc = new RSTrainBrakeCylinder(car,cv);

	car->setBrakeCylinder(bc);

	this->connectCreatedVehicle(car);
}

void RSTrainSimulator::connectCreatedVehicle(RSTrainVehicle* vehicle) {

	// add given vehicle to the system

	// check whether the given vehicle is the first or not
	if (this->prevVehicle != 0) { // if the vehicle is not the first one

		// create a coupling element
		RSTrainCoupling* coupling = new RSTrainCoupling();

		// assign the front vehicle of the coupling
		coupling->setFrontVehicle(this->prevVehicle);

		// assign the back vehicle of the coupling
		coupling->setBackVehicle(vehicle);

		// add the created coupling the coupling vector
		this->couplingVector.push_back(coupling);

		// add the vehicle to the vehicle vector
		this->vehicleVector.push_back(vehicle);

		// increase the vehicle number
		this->vehicleNumber++;
	} else // if the vehicle is the first one
	{
		// add the vehicle to the vehicle vector
		this->vehicleVector.push_back(vehicle);

		// increase the vehicle number
		this->vehicleNumber++;
	}

	// assign prevVehicle as the created vehicle
	this->prevVehicle = vehicle;

}


void RSTrainSimulator::connectRunforLocomotive(RSTrainVehicle* vehicle) {

	// add given vehicle to the system

	// check whether the given vehicle is the first or not
	if (this->prevVehicle != 0) { // if the vehicle is not the first one

		// create a coupling element
		RSTrainCoupling* coupling = new RSTrainRunforLocomotiveCoupling();

		// assign the front vehicle of the coupling
		coupling->setFrontVehicle(this->prevVehicle);

		// assign the back vehicle of the coupling
		coupling->setBackVehicle(vehicle);

		// add the created coupling the coupling vector
		this->couplingVector.push_back(coupling);

		// add the vehicle to the vehicle vector
		this->vehicleVector.push_back(vehicle);

		// increase the vehicle number
		this->vehicleNumber++;
	}

}


void RSTrainSimulator::InitPositions(int roadindex,
		double LocalRoadPositionOfFirstVehicle) {

	// check are there any vehicle
	if (!vehicleNumber) {
		cout << "No Vehicle Found to InitPositions" << endl;
		return;
	}

	// take the given road position
	double position = LocalRoadPositionOfFirstVehicle;

	// assign  position of the first vehicle
	this->vehicleVector[0]->InitPosition(roadindex, position);

	// take the length of the vehicle
	double length = this->vehicleVector[0]->getLength();

	// initialize positions of  other vehicles
	for (int i = 1; i < this->vehicleNumber; i++) {

		// find the position of next car
		position -= (length / 2);

		// take the vehicle
		RSTrainVehicle* vehicle = this->vehicleVector[i];

		// take the length of the vehicle
		length = vehicle->getLength();

		// calculate mid position of the vehicle
		position -= (length / 2);

		// assign  local position of the vehicle
		vehicle->InitPosition(roadindex, position);
	}
}

void RSTrainSimulator::InitRunforLocomotivePosition(int roadindex,
		double LocalRoadposition) {

	if(runforLocomotive != 0){

		runforLocomotive->InitPosition(roadindex,LocalRoadposition);

	}

}

void RSTrainSimulator::InitBreakePipe() {

	// create breakepipe and relate with the vehicles
	RSTrainParser<RSTrainBrakePipePressureUpdater>* parser = RSTrainBrakePipeParser::getInstance();

	this->bPupdater = parser->spawnFromXML("BrakePipe.xml");

	this->bPupdater->InitVehicles(&(this->vehicleVector));

	this->vehicleVector[0]->setBrakePipePresure(this->bPupdater->getNominalPressure());

}

void RSTrainSimulator::InitSpeed(double speed) {


	// initialize the vehicles speed, given parameter must be m/s
	for (int i = 0; i < this->vehicleNumber; i++) {
		this->vehicleVector[i]->InitSpeed(speed);
	}

}

void RSTrainSimulator::InitRunforLocomotiveSpeed(double speed) {

	if(runforLocomotive != 0){

		runforLocomotive->InitSpeed(speed);
	}
}

void RSTrainSimulator::updateForces(double dt) {

	// calculates the net force on the vehicles
	for (int i = 0; i < vehicleNumber; i++) {
		// Calculate forces on all vehicles
		this->vehicleVector[i]->calcForce(dt);
	}
}

void RSTrainSimulator::updateVariables(double dt) {

	// calculates the pipe pressures seen by the vehicles
	this->bPupdater->calcBrakePipePressures(dt);

	// updates the pipe pressures seen by the vehicles
	this->bPupdater->updateBrakePipePressures();

	// updates variables depended on position and velocity changes
	for (int i = 0; i < this->vehicleNumber; i++) {
		this->vehicleVector[i]->updateVariables(dt);
	}

	// calculates distance on the joint elemenets
	int couplingNumber = this->couplingVector.size();
	for (int i = 0; i < couplingNumber; i++) {
		this->couplingVector[i]->calcDistance();
	}

}

void RSTrainSimulator::changeSwitchState(int globalID, int stateNumber,
		string stateValue) {

	eSwitch sw = this->railwayelement->geteSwitchFromGlobalID(globalID);

	switch (stateNumber) {
	case 1:
		sw.setState1(stateValue);
		break;

	case 2:
		sw.setState2(stateValue);
		break;
	default:
		break;
	}
}

void RSTrainSimulator::doIntegration() {

	boost::mutex m;
	boost::numeric::odeint::runge_kutta4<vector<double> > stepper;
	boost::posix_time::ptime prev_time;
	boost::posix_time::ptime curr_time;

	prev_time = boost::posix_time::microsec_clock::local_time();

	boost::mutex::scoped_lock lock(m);

	while (true) {

		curr_time = boost::posix_time::microsec_clock::local_time();

		boost::posix_time::time_duration diff_time(curr_time - prev_time);

		range = diff_time.total_microseconds();
		range = range / 1000000;

		dt = 0.01;

		if (resume) {
			double t = 0;
			while (t < range) {
				if ((t + dt) > range) {
					dt = range - t;
					time += dt;
					t = range;
				} else {
					t += dt;
					time += dt;
				}

				for (int i = 0; i < vehicleNumber; i++) {
					RSTrainVehicle* vehicle = this->vehicleVector[i];
					this->dynamicModel.setVehicle(vehicle);
					stepper.do_step(this->dynamicModel, vehicle->posvel, t, dt);

				}
				this->updateVariables(dt);
				this->updateForces(dt);

				prev_time = curr_time;
			}
		} else {
			((boost::condition_variable*) run)->wait(lock);
			prev_time = boost::posix_time::microsec_clock::local_time();
		}
	}



//	double t =0;
//	dt = 0.1;
//	int a;
//			for (; t <100; t += dt) {
//				for (int i = 0; i < vehicleNumber; i++) {
//					RSTrainVehicle* vehicle = this->vehicleVector[i];
//					this->dynamicModel.setVehicle(vehicle);
//					stepper.do_step(this->dynamicModel, vehicle->posvel, t, dt);
//
//				}
//
//				cout<<"Vehicle[0]  :"<<this->vehicleVector[0]->getVelocityKph()<<'\t'<<
//							this->vehicleVector[0]->getPosvel()[0]<<endl;
//
//
//				this->updateVariables(dt);
//				this->updateForces(dt);
//
//				cin>>a;
//
//				this->setAuxBrakePos(a);
//			}

}

void RSTrainSimulator::Start() {
	boost::thread m_Thread;
	m_Thread = boost::thread(&RSTrainSimulator::doIntegration, this);
}

void RSTrainSimulator::Resume() {
	this->resume = true;
	((boost::condition_variable*) run)->notify_one();
}

bool RSTrainSimulator::isLocomotive(int index) {

	RSTrainLocomotive* loco = dynamic_cast<RSTrainLocomotive*>(this->vehicleVector[index]);

	if(loco){
		return true;
	}else{
		return false;
	}
}

double RSTrainSimulator::getCarAirBrakeForce(int index) {

	return this->vehicleVector[index]->getBrakeCylinder()->getAirBrakeForce();
}

double RSTrainSimulator::getLocomotiveAirBrakeForce(int index,
		int brakeCylinderIndex) {

	RSTrainLocomotive* loco = dynamic_cast<RSTrainLocomotive*>(this->vehicleVector[index]);

	return loco->getLocomotiveBrakeCylinder(brakeCylinderIndex)->getAirBrakeForce();
}


void RSTrainSimulator::Pause() {
	this->resume = false;
}

RSTrainBrakePipePressureUpdater* RSTrainSimulator::getBPupdater(){
	return bPupdater;
}

void RSTrainSimulator::setBPupdater(
		RSTrainBrakePipePressureUpdater* bpUpdater) {
	bPupdater = bpUpdater;
}


RSTrainGetter* RSTrainSimulator::getGetterAndLogger() {
	return getterAndLogger;
}

void RSTrainSimulator::setGetterAndLogger(
		RSTrainGetter* getterAndLogger) {
	this->getterAndLogger = getterAndLogger;
}


