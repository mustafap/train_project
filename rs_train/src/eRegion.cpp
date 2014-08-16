/*
 * eRegion.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eRegion.h"

eRegion::eRegion() {
	this->GlobalID=0;
	this->Type=0;
	this->Name="";
	this->RoadInfo = eLineRoadInfo();


}

eRegion::eRegion(pugi::xml_node& node) {
	//GlobalID
	this->GlobalID = node.child("GlobalID").text().as_int();
	//Type
	this->Type = node.child("Type").text().as_int();
	//Name
	this->Name = node.child("Name").text().as_string();
	//RoadInfo
	pugi::xml_node RoadInfoNode = node.child("RoadInfo");
	this->RoadInfo = eLineRoadInfo(RoadInfoNode);
}


eRegion::~eRegion() {
	// TODO Auto-generated destructor stub
}

int eRegion::getGlobalId()  {
	return GlobalID;
}

void eRegion::setGlobalId(int globalId) {
	GlobalID = globalId;
}

string eRegion::getName()  {
	return Name;
}

void eRegion::setName( string name) {
	Name = name;
}

eLineRoadInfo eRegion::getRoadInfo()  {
	return RoadInfo;
}

void eRegion::setRoadInfo( eLineRoadInfo roadInfo) {
	RoadInfo = roadInfo;
}

int eRegion::getType()  {
	return Type;
}



void eRegion::setType(int type) {
	Type = type;
}


