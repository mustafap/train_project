/*
 * eCSwitch.h
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef ECSWITCH_H_
#define ECSWITCH_H_

#include "pugixml.hpp"
using namespace std;

class eCSwitch;

class eCSwitch {

private:
	int ConnectedItemId1;
	int ConnectedItemId2;
	int ConnectedItemId3;
	double LateralOffset1;
	double LateralOffset2;
	double LateralOffset3;
	double ParallelLength;
	double DeviatedLength;
	double CurveRadius;
	double DeviatedCurveRadius;
	bool DeviatedCurveSideIsLeft;
	bool NotDeviatedCurveSideIsLeft;
	double LateralDisplacement;
	bool SwitchSideIsLeft;
	double Coordinate1;
	double Coordinate2;
	double Coordinate3;
	double Slope12;
	double Slope13;
public:
	eCSwitch();
	eCSwitch(pugi::xml_node& node);
	virtual ~eCSwitch();
	int getConnectedItemId1() ;
	void setConnectedItemId1(int connectedItemId1);
	int getConnectedItemId2() ;
	void setConnectedItemId2(int connectedItemId2);
	int getConnectedItemId3() ;
	void setConnectedItemId3(int connectedItemId3);
	double getCoordinate1() ;
	void setCoordinate1(double coordinate1);
	double getCoordinate2() ;
	void setCoordinate2(double coordinate2);
	double getCoordinate3() ;
	void setCoordinate3(double coordinate3);
	double getCurveRadius() ;
	void setCurveRadius(double curveRadius);
	double getDeviatedCurveRadius() ;
	void setDeviatedCurveRadius(double deviatedCurveRadius);
	bool isDeviatedCurveSideIsLeft() ;
	void setDeviatedCurveSideIsLeft(bool deviatedCurveSideIsLeft);
	double getDeviatedLength() ;
	void setDeviatedLength(double deviatedLength);
	double getLateralDisplacement() ;
	void setLateralDisplacement(double lateralDisplacement);
	double getLateralOffset1() ;
	void setLateralOffset1(double lateralOffset1);
	double getLateralOffset2() ;
	void setLateralOffset2(double lateralOffset2);
	double getLateralOffset3() ;
	void setLateralOffset3(double lateralOffset3);
	bool isNotDeviatedCurveSideIsLeft() ;
	void setNotDeviatedCurveSideIsLeft(bool notDeviatedCurveSideIsLeft);
	double getParallelLength() ;
	void setParallelLength(double parallelLength);
	double getSlope12() ;
	void setSlope12(double slope12);
	double getSlope13() ;
	void setSlope13(double slope13);
	bool isSwitchSideIsLeft() ;
	void setSwitchSideIsLeft(bool switchSideIsLeft);
};

#endif /* ECSWITCH_H_ */
