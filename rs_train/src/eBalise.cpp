/*
 * eBalise.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eBalise.h"

eBalise::eBalise() {
	this->GlobalID=0;
	this->Type="";
	this->Name="";
	this->Direction=0;
	this->State=0;
	this->RoadInfo = ePointRoadInfo();

}

eBalise::eBalise(pugi::xml_node& node) {
	//GlobalID
	this->GlobalID = node.child("GlobalID").text().as_int();
	//Type
	this->Type = node.child("Type").text().as_string();
	//Name
	this->Name = node.child("Name").text().as_string();
	//Direction
	this->Direction = node.child("Direction").text().as_int();
	//State
	this->State = node.child("State").text().as_int();
	//RoadInfo
	pugi::xml_node RoadInfoNode = node.child("RoadInfo");
	this->RoadInfo = ePointRoadInfo(RoadInfoNode);
}

eBalise::~eBalise() {

}

int eBalise::getDirection()  {
	return Direction;
}

void eBalise::setDirection(int direction) {
	Direction = direction;
}

int eBalise::getGlobalId()  {
	return GlobalID;
}

void eBalise::setGlobalId(int globalId) {
	GlobalID = globalId;
}

string eBalise::getName()  {
	return Name;
}

void eBalise::setName( string name) {
	Name = name;
}

ePointRoadInfo eBalise::getRoadInfo()  {
	return RoadInfo;
}

void eBalise::setRoadInfo( ePointRoadInfo roadInfo) {
	RoadInfo = roadInfo;
}

int eBalise::getState()  {
	return State;
}

void eBalise::setState(int state) {
	State = state;
}

string eBalise::getType()  {
	return Type;
}



void eBalise::setType( string type) {
	Type = type;
}
