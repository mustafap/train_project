/*
 * eBlock.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eBlock.h"

eBlock::eBlock() {
	this->GlobalID = 0;
	this->Name="";
	this->Type=0;
	this->State=0;
	this->RoadInfo=eLineRoadInfo();

}


eBlock::eBlock(pugi::xml_node& node) {
	//GlobalID
	this->GlobalID = node.child("GlobalID").text().as_int();
	//Name
	this->Name = node.child("Name").text().as_string();
	//Type
	this->Type = node.child("Type").text().as_int();
	//State
	this->State = node.child("State").text().as_int();
	//RoadInfo
	pugi::xml_node RoadInfoNode = node.child("RoadInfo");
	this->RoadInfo = eLineRoadInfo(RoadInfoNode);

}


eBlock::~eBlock() {

}

int eBlock::getGlobalId()  {
	return GlobalID;
}

void eBlock::setGlobalId(int globalId) {
	GlobalID = globalId;
}

string eBlock::getName()  {
	return Name;
}

void eBlock::setName( string name) {
	Name = name;
}

eLineRoadInfo eBlock::getRoadInfo()  {
	return RoadInfo;
}

void eBlock::setRoadInfo( eLineRoadInfo roadInfo) {
	RoadInfo = roadInfo;
}

int eBlock::getState()  {
	return State;
}

void eBlock::setState(int state) {
	State = state;
}

int eBlock::getType()  {
	return Type;
}


void eBlock::setType(int type) {
	Type = type;
}



