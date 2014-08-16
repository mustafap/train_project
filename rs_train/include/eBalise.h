/*
 * eBalise.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EBALISE_H_
#define EBALISE_H_

#include <string>
#include "pugixml.hpp"
#include "ePointRoadInfo.h"
using namespace std;

class eBalise;
class ePointRoadInfo;

class eBalise {

private:
	int GlobalID;
	string Type;
	string Name;
	int Direction;
	int State;
	ePointRoadInfo RoadInfo;

public:
	eBalise();
	eBalise(pugi::xml_node& node);
	virtual ~eBalise();
	int getDirection() ;
	void setDirection(int direction);
	int getGlobalId() ;
	void setGlobalId(int globalId);
	string getName() ;
	void setName( string name);
	ePointRoadInfo getRoadInfo() ;
	void setRoadInfo( ePointRoadInfo roadInfo);
	int getState() ;
	void setState(int state);
	string getType() ;
	void setType( string type);
};

#endif /* EBALISE_H_ */
