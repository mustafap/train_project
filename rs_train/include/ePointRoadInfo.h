/*
 * ePointRoadInfo.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EPOINTROADINFO_H_
#define EPOINTROADINFO_H_

#include "pugixml.hpp"
using namespace std;

class ePointRoadInfo;

class ePointRoadInfo {

private:
	int RoadGlobalID;
	double LateralOffset;
	double Coordinate;

public:
	ePointRoadInfo();
	ePointRoadInfo(pugi::xml_node& node);
	virtual ~ePointRoadInfo();
	double getCoordinate() ;
	void setCoordinate(double coordinate);
	double getLateralOffset() ;
	void setLateralOffset(double lateralOffset);
	int getRoadGlobalId() ;
	void setRoadGlobalId(int roadGlobalId);
};

#endif /* EPOINTROADINFO_H_ */
