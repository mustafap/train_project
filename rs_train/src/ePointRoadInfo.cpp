/*
 * ePointRoadInfo.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "ePointRoadInfo.h"

ePointRoadInfo::ePointRoadInfo() {
	//Init. Variables
	this->Coordinate=0;
	this->LateralOffset=0;
	this->RoadGlobalID=0;

}

ePointRoadInfo::ePointRoadInfo(pugi::xml_node& node) {

	//RoadGloadID
	this->RoadGlobalID = node.child("RoadGlobalID").text().as_int();
	//LateralOffset
	this->LateralOffset = node.child("LateralOffset").text().as_double();
	//Coordinate
	this->Coordinate = node.child("Coordinate").text().as_double();
}

ePointRoadInfo::~ePointRoadInfo() {

}

double ePointRoadInfo::getCoordinate()  {
	return Coordinate;
}

void ePointRoadInfo::setCoordinate(double coordinate) {
	Coordinate = coordinate;
}

double ePointRoadInfo::getLateralOffset()  {
	return LateralOffset;
}

void ePointRoadInfo::setLateralOffset(double lateralOffset) {
	LateralOffset = lateralOffset;
}

int ePointRoadInfo::getRoadGlobalId()  {
	return RoadGlobalID;
}


void ePointRoadInfo::setRoadGlobalId(int roadGlobalId) {
	RoadGlobalID = roadGlobalId;
}



