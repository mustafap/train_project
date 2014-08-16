/*
 * eSignal.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef ESIGNAL_H_
#define ESIGNAL_H_

#include <string>
#include "pugixml.hpp"
#include "ePointRoadInfo.h"
using namespace std;

class eSignal;
class ePointRoadInfo;

class eSignal {

private:
	int GlobalID;
	string Type;
	string Name;
	bool IsAtsAvailable;
	int Direction;
	int State;
	ePointRoadInfo RoadInfo;

public:
	eSignal();
	eSignal(pugi::xml_node& node);
	virtual ~eSignal();
	int getDirection();
	void setDirection(int direction);
	int getGlobalId();
	void setGlobalId(int globalId);
	bool isIsAtsAvailable();
	void setIsAtsAvailable(bool isAtsAvailable);
	string getName();
	void setName(string name);
	ePointRoadInfo getRoadInfo();
	void setRoadInfo(ePointRoadInfo roadInfo);
	int getState();
	void setState(int state);
	string getType();
	void setType(string type);
};

#endif /* ESIGNAL_H_ */
