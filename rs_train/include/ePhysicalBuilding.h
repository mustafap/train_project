/*
 * ePhysicalBuilding.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EPHYSICALBUILDING_H_
#define EPHYSICALBUILDING_H_
#include <string>
#include "pugixml.hpp"
#include "eLineRoadInfo.h"
using namespace std;

class ePhysicalBuilding;
class eLineRoadInfo;

class ePhysicalBuilding {

private:
	int GlobalID;
	int Type;
	string Name;
	double Width;
	eLineRoadInfo RoadInfo;

public:
	ePhysicalBuilding();
	ePhysicalBuilding(pugi::xml_node& node);
	virtual ~ePhysicalBuilding();
	int getGlobalId() ;
	void setGlobalId(int globalId);
	string getName() ;
	void setName( string name);
	eLineRoadInfo getRoadInfo() ;
	void setRoadInfo( eLineRoadInfo roadInfo);
	int getType() ;
	void setType(int type);
	double getWidth() ;
	void setWidth(double width);
};

#endif /* EPHYSICALBUILDING_H_ */
