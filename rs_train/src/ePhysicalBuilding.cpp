/*
 * ePhysicalBuilding.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "ePhysicalBuilding.h"

ePhysicalBuilding::ePhysicalBuilding() {
	this->GlobalID = 0;
	this->Type=0;
	this->Name="";
	this->Width=0;
	this->RoadInfo = eLineRoadInfo();

}

ePhysicalBuilding::ePhysicalBuilding(pugi::xml_node& node) {
	//GlobalID
	this->GlobalID = node.child("GlobalID").text().as_int();
	//Type
	this->Type = node.child("Type").text().as_int();
	//Name
	this->Name = node.child("Name").text().as_string();
	//Width
	this->Width = node.child("Width").text().as_double();
	//RoadInfo
	pugi::xml_node RoadInfoNode = node.child("RoadInfo");
	this->RoadInfo = eLineRoadInfo(RoadInfoNode);
}

ePhysicalBuilding::~ePhysicalBuilding() {

}


int ePhysicalBuilding::getGlobalId()  {
	return GlobalID;
}

void ePhysicalBuilding::setGlobalId(int globalId) {
	GlobalID = globalId;
}

string ePhysicalBuilding::getName()  {
	return Name;
}

void ePhysicalBuilding::setName( string name) {
	Name = name;
}

eLineRoadInfo ePhysicalBuilding::getRoadInfo()  {
	return RoadInfo;
}

void ePhysicalBuilding::setRoadInfo( eLineRoadInfo roadInfo) {
	RoadInfo = roadInfo;
}

int ePhysicalBuilding::getType()  {
	return Type;
}

void ePhysicalBuilding::setType(int type) {
	Type = type;
}

double ePhysicalBuilding::getWidth()  {
	return Width;
}

void ePhysicalBuilding::setWidth(double width) {
	Width = width;
}


