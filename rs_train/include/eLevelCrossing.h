/*
 * eLevelCrossing.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef ELEVELCROSSING_H_
#define ELEVELCROSSING_H_

#include "pugixml.hpp"
#include "eLineRoadInfo.h"
using namespace std;

class eLevelCrossing;
class eLineRoadInfo;

class eLevelCrossing {

private:
	int GlobalID;
	string Name;
	int Type;
	int State;
	double Width;
	int BarrierCount;
	eLineRoadInfo RoadInfo;

public:
	eLevelCrossing();
	eLevelCrossing(pugi::xml_node& node);
	virtual ~eLevelCrossing();
	int getBarrierCount() ;
	void setBarrierCount(int barrierCount);
	int getGlobalId() ;
	void setGlobalId(int globalId);
	eLineRoadInfo getRoadInfo() ;
	void setRoadInfo( eLineRoadInfo roadInfo);
	int getState() ;
	void setState(int state);
	int getType() ;
	void setType(int type);
	double getWidth() ;
	void setWidth(double width);
	string getName();
	void setName(string name);
};

#endif /* ELEVELCROSSING_H_ */
