/*
 * eMagnet.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eMagnet.h"

eMagnet::eMagnet() {
	this->GlobalID = 0;
	this->Type="";
	this->Name="";
	this->Direction=0;
	this->State=0;
	this->RoadInfo = ePointRoadInfo();
}

eMagnet::eMagnet(pugi::xml_node& node) {
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

eMagnet::~eMagnet() {

}

int eMagnet::getDirection() {
	return Direction;
}

void eMagnet::setDirection(int direction) {
	Direction = direction;
}

int eMagnet::getGlobalId() {
	return GlobalID;
}

void eMagnet::setGlobalId(int globalId) {
	GlobalID = globalId;
}

string eMagnet::getName() {
	return Name;
}

void eMagnet::setName(string name) {
	Name = name;
}

ePointRoadInfo eMagnet::getRoadInfo() {
	return RoadInfo;
}

void eMagnet::setRoadInfo(ePointRoadInfo roadInfo) {
	RoadInfo = roadInfo;
}

int eMagnet::getState() {
	return State;
}

void eMagnet::setState(int state) {
	State = state;
}

string eMagnet::getType() {
	return Type;
}

void eMagnet::setType(string type) {
	Type = type;
}
