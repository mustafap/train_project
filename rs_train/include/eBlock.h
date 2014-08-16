/*
 * eBlock.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EBLOCK_H_
#define EBLOCK_H_

#include <string>
#include "pugixml.hpp"
#include "eLineRoadInfo.h"
using namespace std;

class eBlock;
class eLineRoadInfo;

class eBlock {

private:
	int GlobalID;
	string Name;
	int Type;
	int State;
	eLineRoadInfo RoadInfo;

public:
	eBlock();
	eBlock(pugi::xml_node& node);
	virtual ~eBlock();
	int getGlobalId() ;
	void setGlobalId(int globalId);
	string getName() ;
	void setName( string name);
	eLineRoadInfo getRoadInfo() ;
	void setRoadInfo( eLineRoadInfo roadInfo);
	int getState() ;
	void setState(int state);
	int getType() ;
	void setType(int type);
};

#endif /* EBLOCK_H_ */
