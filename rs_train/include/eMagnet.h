/*
 * eMagnet.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EMAGNET_H_
#define EMAGNET_H_

#include "pugixml.hpp"
#include "ePointRoadInfo.h"
using namespace std;

class eMagnet;
class ePointRoadInfo;

class eMagnet {

private:
	int GlobalID;
	string Type;
	string Name;
	int Direction;
	int State;
	ePointRoadInfo RoadInfo;

public:
	eMagnet();
	eMagnet(pugi::xml_node& node);
	virtual ~eMagnet();
	int getDirection();
	void setDirection(int direction);
	int getGlobalId();
	void setGlobalId(int globalId);
	string getName();
	void setName(string name);
	ePointRoadInfo getRoadInfo();
	void setRoadInfo(ePointRoadInfo roadInfo);
	int getState();
	void setState(int state);
	string getType();
	void setType(string type);
};

#endif /* EMAGNET_H_ */
