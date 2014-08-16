/*
 * eIG.cpp
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eIG.h"
#include "pugixml.hpp"
eIG::eIG() {

}

eIG::eIG(pugi::xml_node& node) {

	//RouteID
	this->RouteID = node.child("RouteID").text().as_int();
	//TerrainName
	this->TerrainName = node.child("TerrainName").text().as_string();
	//FeatureID
	this->FeatureID = node.child("FeatureID").text().as_int();
}

eIG::~eIG() {
}

int eIG::getFeatureId(){
	return FeatureID;
}

void eIG::setFeatureId(int featureId) {
	FeatureID = featureId;
}

int eIG::getRouteId() {
	return RouteID;
}

void eIG::setRouteId(int routeId) {
	RouteID = routeId;
}

string eIG::getTerrainName() {
	return TerrainName;
}

void eIG::setTerrainName(string terrainName) {
	TerrainName = terrainName;
}
