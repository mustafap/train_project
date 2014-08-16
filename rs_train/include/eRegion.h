/*
 * eRegion.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EREGION_H_
#define EREGION_H_
#include <string>
#include "pugixml.hpp"
#include "eLineRoadInfo.h"
using namespace std;

class eRegion;
class eLineRoadInfo;

class eRegion {

private:
	int GlobalID;
	int Type;
	string Name;
	eLineRoadInfo RoadInfo;

public:
	eRegion();
	eRegion(pugi::xml_node& node);
	virtual ~eRegion();
	int getGlobalId() ;
	void setGlobalId(int globalId);
	string getName() ;
	void setName( string name);
	eLineRoadInfo getRoadInfo() ;
	void setRoadInfo( eLineRoadInfo roadInfo);
	int getType() ;
	void setType(int type);
};

#endif /* EREGION_H_ */
