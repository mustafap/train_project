/*
 * ePhysicalObjects.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EPHYSICALOBJECTS_H_
#define EPHYSICALOBJECTS_H_
#include <string>
#include "ePointRoadInfo.h"
#include "pugixml.hpp"
using namespace std;

class ePointRoadInfo;
class ePhysicalObjects;

class ePhysicalObjects {

private:
	int GlobalID;
	int Type;
	string Name;
	string Value;
	ePointRoadInfo RoadInfo;

public:
	ePhysicalObjects();
	ePhysicalObjects(pugi::xml_node& node);
	virtual ~ePhysicalObjects();
	int getGlobalId() ;
	void setGlobalId(int globalId);
	string getName() ;
	void setName( string name);
	ePointRoadInfo getRoadInfo() ;
	void setRoadInfo( ePointRoadInfo roadInfo);
	int getType() ;
	void setType(int type);
	string getValue() ;
	void setValue( string value);
};

#endif /* EPHYSICALOBJECTS_H_ */
