/*
 * eLineRoadInfo.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef ELINEROADINFO_H_
#define ELINEROADINFO_H_

#include "pugixml.hpp"
using namespace std;
class eLineRoadInfo;

class eLineRoadInfo {

private:
	int BeginRoadGlobalID;
	int EndRoadGlobalID;
	double BeginLateralOffset;
	double EndLateralOffset;
	double BeginCoordinate;
	double EndCoordinate;

public:
	eLineRoadInfo();
	eLineRoadInfo(pugi::xml_node& node);
	virtual ~eLineRoadInfo();
	double getBeginCoordinate() ;
	void setBeginCoordinate(double beginCoordinate);
	double getBeginLateralOffset() ;
	void setBeginLateralOffset(double beginLateralOffset);
	int getBeginRoadGlobalId() ;
	void setBeginRoadGlobalId(int beginRoadGlobalId);
	double getEndCoordinate() ;
	void setEndCoordinate(double endCoordinate);
	double getEndLateralOffset() ;
	void setEndLateralOffset(double endLateralOffset);
	int getEndRoadGlobalId() ;
	void setEndRoadGlobalId(int endRoadGlobalId);
};

#endif /* ELINEROADINFO_H_ */
