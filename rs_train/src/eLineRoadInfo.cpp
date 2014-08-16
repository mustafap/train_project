/*
 * eLineRoadInfo.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eLineRoadInfo.h"

eLineRoadInfo::eLineRoadInfo() {
	//Init variables
	this->BeginCoordinate = 0;
	this->BeginLateralOffset=0;
	this->BeginRoadGlobalID=0;
	this->EndCoordinate=0;
	this->EndLateralOffset=0;
	this->EndRoadGlobalID=0;
}

eLineRoadInfo::eLineRoadInfo(pugi::xml_node& node) {
	//BeginCoordinate
	this->BeginCoordinate = node.child("BeginCoordinate").text().as_double();
	//BeginLateralOffset
	this->BeginLateralOffset = node.child("BeginLateralOffset").text().as_double();
	//BeginRoadGlobalID
	this->BeginRoadGlobalID = node.child("BeginRoadGlobalID").text().as_int();
	//EndCoordinate
	this->EndCoordinate = node.child("EndCoordinate").text().as_double();
	//EndLateralOffset
	this->EndLateralOffset = node.child("EndLateralOffset").text().as_double();
	//EndRoadGlobalID
	this->EndRoadGlobalID = node.child("EndRoadGlobalID").text().as_int();
}
eLineRoadInfo::~eLineRoadInfo() {

}

double eLineRoadInfo::getBeginCoordinate()  {
	return BeginCoordinate;
}

void eLineRoadInfo::setBeginCoordinate(double beginCoordinate) {
	BeginCoordinate = beginCoordinate;
}

double eLineRoadInfo::getBeginLateralOffset()  {
	return BeginLateralOffset;
}

void eLineRoadInfo::setBeginLateralOffset(double beginLateralOffset) {
	BeginLateralOffset = beginLateralOffset;
}

int eLineRoadInfo::getBeginRoadGlobalId()  {
	return BeginRoadGlobalID;
}

void eLineRoadInfo::setBeginRoadGlobalId(int beginRoadGlobalId) {
	BeginRoadGlobalID = beginRoadGlobalId;
}

double eLineRoadInfo::getEndCoordinate()  {
	return EndCoordinate;
}

void eLineRoadInfo::setEndCoordinate(double endCoordinate) {
	EndCoordinate = endCoordinate;
}

double eLineRoadInfo::getEndLateralOffset()  {
	return EndLateralOffset;
}

void eLineRoadInfo::setEndLateralOffset(double endLateralOffset) {
	EndLateralOffset = endLateralOffset;
}

int eLineRoadInfo::getEndRoadGlobalId()  {
	return EndRoadGlobalID;
}



void eLineRoadInfo::setEndRoadGlobalId(int endRoadGlobalId) {
	EndRoadGlobalID = endRoadGlobalId;
}



