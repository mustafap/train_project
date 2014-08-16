/*
 * RailwayElement.cpp
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "RailwayElement.h"

RailwayElement::RailwayElement() {

}

RailwayElement::RailwayElement(pugi::xml_node& node) {
	//Switch
	for(pugi::xml_node SwitchNode =node.child("Switch") ; SwitchNode ; SwitchNode=SwitchNode.next_sibling("Switch") )
	{
		eSwitch eswitch(SwitchNode);
		this->Switch.push_back(eswitch);
	}

	//Road
	for(pugi::xml_node RoadNode = node.child("Road") ; RoadNode ; RoadNode=RoadNode.next_sibling("Road") )
	{
		eRoad eroad(RoadNode);
		this->Road.push_back(eroad);
	}

	//Region
	for(pugi::xml_node RegionNode = node.child("Region") ; RegionNode ; RegionNode= RegionNode.next_sibling("Region") )
	{
		eRegion eregion(RegionNode);
		this->Region.push_back(eregion);
	}

	//PhysicalObjects
	for(pugi::xml_node PhysicalObjectsNode = node.child("PhysicalObjects") ; PhysicalObjectsNode ; PhysicalObjectsNode= PhysicalObjectsNode.next_sibling("PhysicalObjects") )
	{
		ePhysicalObjects ephysicalObjects(PhysicalObjectsNode);
		this->PhysicalObjects.push_back(ephysicalObjects);
	}

	//IG
	for(pugi::xml_node IGNode = node.child("IG") ; IGNode ; IGNode=IGNode.next_sibling("IG") )
	{
		eIG eig(IGNode);
		this->IG.push_back(eig);
	}
}

RailwayElement::~RailwayElement() {
}

vector<eIG>& RailwayElement::getIg() {
	return IG;
}

void RailwayElement::setIg(vector<eIG>& ig) {
	IG = ig;
}

vector<ePhysicalObjects>& RailwayElement::getPhysicalObjects() {
	return PhysicalObjects;
}

void RailwayElement::setPhysicalObjects(
		vector<ePhysicalObjects>& physicalObjects) {
	PhysicalObjects = physicalObjects;
}

vector<eRegion>& RailwayElement::getRegion() {
	return Region;
}

void RailwayElement::setRegion(vector<eRegion>& region) {
	Region = region;
}

vector<eRoad>& RailwayElement::getRoad() {
	return Road;
}

void RailwayElement::setRoad(vector<eRoad>& road) {
	Road = road;
}

vector<eSwitch>& RailwayElement::getSwitch() {
	return Switch;
}



void RailwayElement::setSwitch(vector<eSwitch>& _switch) {
	Switch = _switch;
}

eRoad& RailwayElement::geteRoad(int index) {
	return this->Road[index];
}

void RailwayElement::addeRoad(eRoad eroad) {
	this->Road.push_back(eroad);
}

void RailwayElement::seteRoad(eRoad eroad, int index) {
	this->Road[index] = eroad;
}

eRegion& RailwayElement::geteRegion(int index) {
	return this->Region[index];
}

void RailwayElement::addeRegion(eRegion eregion) {
	this->Region.push_back(eregion);
}

void RailwayElement::seteRegion(eRegion eregion, int index) {
	this->Region[index]=eregion;
}

ePhysicalObjects& RailwayElement::getePhysicalObjects(int index) {
	return this->PhysicalObjects[index];
}

void RailwayElement::addePhysicalObjects(ePhysicalObjects ephysicalObjects) {
	this->PhysicalObjects.push_back(ephysicalObjects);
}

void RailwayElement::setePhysicalObjects(ePhysicalObjects ephysicalObjects,
		int index) {
	this->PhysicalObjects[index] = ephysicalObjects;
}

eIG& RailwayElement::geteIG(int index) {
	return this->IG[index];
}

void RailwayElement::addeIG(eIG eig) {
	this->IG.push_back(eig);
}

void RailwayElement::seteIG(eIG eig, int index) {
	this->IG[index] = eig;
}

eSwitch& RailwayElement::geteSwitch(int index) {
	return this->Switch[index];
}

void RailwayElement::addeSwitch(eSwitch eswitch) {
	this->Switch.push_back(eswitch);
}



void RailwayElement::seteSwitch(eSwitch eswitch, int index) {
	this->Switch[index] = eswitch;
}

int RailwayElement::getRoadSize() {
	return this->Road.size();
}

int RailwayElement::getRegionSize() {
	return this->Region.size();
}

int RailwayElement::getPhysicalObjectsSize() {
	return this->PhysicalObjects.size();
}

int RailwayElement::getIGSize() {
	return this->IG.size();
}

int RailwayElement::getSwitchSize() {
	return this->Switch.size();
}

eSwitch& RailwayElement::geteSwitchFromGlobalID(int globalID) {

	int size = this->Switch.size();
	int eSwitchIndex = 0;
	for(int i=0; i<size;i++)
	{
		int globalid = this->Switch[i].getGlobalId();
		if(globalid == globalID){
			eSwitchIndex = i;
			break;
		}
	}

	return this->Switch[eSwitchIndex];

}

eRoad& RailwayElement::geteRoadFromGlobalID(int globalID) {

	int size = this->Road.size();

	int eRoadIndex = 0;

	for(int i =0;i<size;i++){

		int globalid = this->Road[i].getGlobalId();

		if(globalid == globalID){

			eRoadIndex = i;
			break;
		}
	}

	return this->Road[eRoadIndex];
}
