/*
 * eIG.h
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EIG_H_
#define EIG_H_

#include <vector>
#include <iostream>
#include <string>
#include "pugixml.hpp"
using namespace std;

class eIG;

class eIG {

private:
	int RouteID;
	string TerrainName;
	int FeatureID;
public:
	eIG();
	eIG(pugi::xml_node& node);
	virtual ~eIG();

	int getFeatureId();
	void setFeatureId(int featureId);

	int getRouteId();
	void setRouteId(int routeId);

	string getTerrainName();
	void setTerrainName(string terrainName);
};

#endif /* EIG_H_ */
