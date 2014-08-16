/*
 * eBSwitch.h
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EBSWITCH_H_
#define EBSWITCH_H_

#include "pugixml.hpp"
using namespace std;

class eBSwitch;

class eBSwitch {
private:
	int ConnectedItemId1;
	int ConnectedItemId2;
	int ConnectedItemId3;
	double LateralOffset1;
	double LateralOffset2;
	double LateralOffset3;
	double TangentLength;
	double CurveLength;
	double HeadAngle;
	double AlphaValue;
	double LateralDisplacement;
	double CurveRadius;
	bool SwitchSideIsLeft;
	double Coordinate1;
	double Coordinate2;
	double Coordinate3;
	double Slope12;
	double Slope13;
public:
	eBSwitch();
	eBSwitch(pugi::xml_node& node);
	virtual ~eBSwitch();
	double getAlphaValue() ;
	void setAlphaValue(double alphaValue);
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
	double getCurveLength() ;
	void setCurveLength(double curveLength);
	double getCurveRadius() ;
	void setCurveRadius(double curveRadius);
	double getHeadAngle() ;
	void setHeadAngle(double headAngle);
	double getLateralDisplacement() ;
	void setLateralDisplacement(double lateralDisplacement);
	double getLateralOffset1() ;
	void setLateralOffset1(double lateralOffset1);
	double getLateralOffset2() ;
	void setLateralOffset2(double lateralOffset2);
	double getLateralOffset3() ;
	void setLateralOffset3(double lateralOffset3);
	double getSlope12() ;
	void setSlope12(double slope12);
	double getSlope13() ;
	void setSlope13(double slope13);
	bool isSwitchSideIsLeft() ;
	void setSwitchSideIsLeft(bool switchSideIsLeft);
	double getTangentLength() ;
	void setTangentLength(double tangentLength);
};

#endif /* EBSWITCH_H_ */
