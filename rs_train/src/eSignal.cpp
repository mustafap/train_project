/*
 * eSignal.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eSignal.h"

eSignal::eSignal() {
	this->GlobalID=0;
	this->Type="";
	this->Name="";
	this->IsAtsAvailable=false;
	this->Direction=0;
	this->State=0;
	this->RoadInfo = ePointRoadInfo();

}

eSignal::eSignal(pugi::xml_node& node) {
	//GlobalID
	this->GlobalID = node.child("GlobalID").text().as_int();
	//Type
	this->Type = node.child("Type").text().as_string();
	//Name
	this->Name = node.child("Name").text().as_string();
	//IsAtsAvailable
	this->IsAtsAvailable = node.child("IsAtsAvailable").text().as_bool();
	//Direction
	this->Direction = node.child("Direction").text().as_int();
	//State
	this->State= node.child("State").text().as_int();
	//RoadInfo
	pugi::xml_node RoadInfoNode = node.child("RoadInfo");
	this->RoadInfo = ePointRoadInfo(RoadInfoNode);
}

eSignal::~eSignal() {

}

int eSignal::getDirection() {
	return Direction;
}

void eSignal::setDirection(int direction) {
	Direction = direction;
}

int eSignal::getGlobalId() {
	return GlobalID;
}

void eSignal::setGlobalId(int globalId) {
	GlobalID = globalId;
}

bool eSignal::isIsAtsAvailable() {
	return IsAtsAvailable;
}

void eSignal::setIsAtsAvailable(bool isAtsAvailable) {
	IsAtsAvailable = isAtsAvailable;
}

string eSignal::getName() {
	return Name;
}

void eSignal::setName(string name) {
	Name = name;
}

ePointRoadInfo eSignal::getRoadInfo() {
	return RoadInfo;
}

void eSignal::setRoadInfo(ePointRoadInfo roadInfo) {
	RoadInfo = roadInfo;
}

int eSignal::getState() {
	return State;
}

void eSignal::setState(int state) {
	State = state;
}

string eSignal::getType() {
	return Type;
}

void eSignal::setType(string type) {
	Type = type;
}
