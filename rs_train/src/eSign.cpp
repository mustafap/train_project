/*
 * eSign.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eSign.h"

eSign::eSign() {
	this->GlobalID = 0;
	this->Type = "";
	this->Direction = 0;
	this->RoadInfo = ePointRoadInfo();
}

eSign::eSign(pugi::xml_node& node) {
	//GlobalID
	this->GlobalID = node.child("GlobalID").text().as_int();
	//Name
	this->Name = node.child("Name").text().as_string();
	//Type
	this->Type = node.child("Type").text().as_string();
	//Direction
	this->Direction = node.child("Direction").text().as_int();
	//RoadInfo
	pugi::xml_node RoadInfoNode = node.child("RoadInfo");
	this->RoadInfo = ePointRoadInfo(RoadInfoNode);
}

eSign::~eSign() {

}

int eSign::getDirection() {
	return Direction;
}

void eSign::setDirection(int direction) {
	Direction = direction;
}

int eSign::getGlobalId() {
	return GlobalID;
}

void eSign::setGlobalId(int globalId) {
	GlobalID = globalId;
}

ePointRoadInfo eSign::getRoadInfo() {
	return RoadInfo;
}

void eSign::setRoadInfo(ePointRoadInfo roadInfo) {
	RoadInfo = roadInfo;
}

string eSign::getType() {
	return Type;
}

void eSign::setType(string type) {
	Type = type;
}

string eSign::getName(){
	return Name;
}

void eSign::setName(string name) {
	Name = name;
}
