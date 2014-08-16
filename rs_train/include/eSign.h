/*
 * eSign.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef ESIGN_H_
#define ESIGN_H_

#include <string>
#include "ePointRoadInfo.h"
#include "pugixml.hpp"
using namespace std;

class eSign;
class ePointRoadInfo;

class eSign {

private:
	int GlobalID;
	string Name;
	string Type;
	int Direction;
	ePointRoadInfo RoadInfo;

public:
	eSign();
	eSign(pugi::xml_node& node);
	virtual ~eSign();
	int getDirection();
	void setDirection(int direction);
	int getGlobalId();
	void setGlobalId(int globalId);
	ePointRoadInfo getRoadInfo();
	void setRoadInfo(ePointRoadInfo roadInfo);
	string getType();
	void setType(string type);
	string getName();
	void setName(string name);
};

#endif /* ESIGN_H_ */
