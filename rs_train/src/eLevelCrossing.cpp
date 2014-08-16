/*
 * eLevelCrossing.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eLevelCrossing.h"

eLevelCrossing::eLevelCrossing() {
	this->GlobalID=0;
	this->Type=0;
	this->State=0;
	this->Width=0;
	this->BarrierCount=0;
	this->RoadInfo = eLineRoadInfo();

}

eLevelCrossing::eLevelCrossing(pugi::xml_node& node) {
	//GlobalID
	this->GlobalID = node.child("GlobalID").text().as_int();
	//Name
	this->Name = node.child("Name").text().as_string();
	//Type
	this->Type = node.child("Type").text().as_int();
	//State
	this->State = node.child("State").text().as_int();
	//Width
	this->Width = node.child("Width").text().as_double();
	//BarrierCount
	this->BarrierCount = node.child("BarrierCount").text().as_int();
	//RoadInfo
	pugi::xml_node RoadInfoNode = node.child("RoadInfo");
	this->RoadInfo = eLineRoadInfo(RoadInfoNode);
}

eLevelCrossing::~eLevelCrossing() {
	// TODO Auto-generated destructor stub
}

int eLevelCrossing::getBarrierCount()  {
	return BarrierCount;
}

void eLevelCrossing::setBarrierCount(int barrierCount) {
	BarrierCount = barrierCount;
}

int eLevelCrossing::getGlobalId()  {
	return GlobalID;
}

void eLevelCrossing::setGlobalId(int globalId) {
	GlobalID = globalId;
}

 eLineRoadInfo eLevelCrossing::getRoadInfo()  {
	return RoadInfo;
}

void eLevelCrossing::setRoadInfo( eLineRoadInfo roadInfo) {
	RoadInfo = roadInfo;
}

int eLevelCrossing::getState()  {
	return State;
}

void eLevelCrossing::setState(int state) {
	State = state;
}

int eLevelCrossing::getType()  {
	return Type;
}

void eLevelCrossing::setType(int type) {
	Type = type;
}

double eLevelCrossing::getWidth()  {
	return Width;
}



void eLevelCrossing::setWidth(double width) {
	Width = width;
}

string eLevelCrossing::getName() {
	return Name;
}

void eLevelCrossing::setName(string name) {
	Name = name;
}
