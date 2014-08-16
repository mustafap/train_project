/*
 * ePhysicalObjects.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "ePhysicalObjects.h"
ePhysicalObjects::ePhysicalObjects() {
	this->GlobalID=0;
	this->Name="";
	this->RoadInfo = ePointRoadInfo();
	this->Type=0;
	this->Value="";

}

ePhysicalObjects::ePhysicalObjects(pugi::xml_node& node) {
	//GlobalID
	this->GlobalID = node.child("GlobalID").text().as_int();
	//Name
	this->Name = node.child("Name").text().as_string();
	//RoadInfo
	pugi::xml_node RoadInfoNode = node.child("RoadInfo");
	this->RoadInfo = ePointRoadInfo(RoadInfoNode);
	//Type
	this->Type = node.child("Type").text().as_int();
	//Value
	this->Value = node.child("Value").text().as_string();
}

ePhysicalObjects::~ePhysicalObjects() {

}

int ePhysicalObjects::getGlobalId()  {
	return GlobalID;
}

void ePhysicalObjects::setGlobalId(int globalId) {
	GlobalID = globalId;
}

string ePhysicalObjects::getName()  {
	return Name;
}

void ePhysicalObjects::setName( string name) {
	Name = name;
}

ePointRoadInfo ePhysicalObjects::getRoadInfo()  {
	return RoadInfo;
}

void ePhysicalObjects::setRoadInfo( ePointRoadInfo roadInfo) {
	RoadInfo = roadInfo;
}

int ePhysicalObjects::getType()  {
	return Type;
}

void ePhysicalObjects::setType(int type) {
	Type = type;
}

string ePhysicalObjects::getValue()  {
	return Value;
}

void ePhysicalObjects::setValue( string value) {
	Value = value;
}
