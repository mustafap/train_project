/*
 * eVSwitch.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EVSWITCH_H_
#define EVSWITCH_H_

#include "pugixml.hpp"
using namespace std;

class eVSwitch;

class eVSwitch {

private:
	int ConnectedItemId1;
	int ConnectedItemId2;
	int ConnectedItemId3;
	int ConnectedItemId4;
	double LateralOffset1;
	double LateralOffset2;
	double LateralOffset3;
	double LateralOffset4;
	double AlphaValue;
	double LateralDisplacement;
	double CurveRadius;
	double TangentLongLength;
	double TangentShortLength;
	double CurveLength;
	double Coordinate1;
	double Coordinate2;
	double Coordinate3;
	double Coordinate4;
	double Slope12;
	double Slope14;
	double Slope32;
	double Slope34;
public:
	eVSwitch();
	eVSwitch(pugi::xml_node& node);
	virtual ~eVSwitch();
	double getAlphaValue();
	void setAlphaValue(double alphaValue);
	int getConnectedItemId1();
	void setConnectedItemId1(int connectedItemId1);
	int getConnectedItemId2();
	void setConnectedItemId2(int connectedItemId2);
	int getConnectedItemId3();
	void setConnectedItemId3(int connectedItemId3);
	int getConnectedItemId4();
	void setConnectedItemId4(int connectedItemId4);
	double getCoordinate1();
	void setCoordinate1(double coordinate1);
	double getCoordinate2();
	void setCoordinate2(double coordinate2);
	double getCoordinate3();
	void setCoordinate3(double coordinate3);
	double getCoordinate4();
	void setCoordinate4(double coordinate4);
	double getCurveLength();
	void setCurveLength(double curveLength);
	double getCurveRadius();
	void setCurveRadius(double curveRadius);
	double getLateralDisplacement();
	void setLateralDisplacement(double lateralDisplacement);
	double getLateralOffset1();
	void setLateralOffset1(double lateralOffset1);
	double getLateralOffset2();
	void setLateralOffset2(double lateralOffset2);
	double getLateralOffset3();
	void setLateralOffset3(double lateralOffset3);
	double getLateralOffset4();
	void setLateralOffset4(double lateralOffset4);
	double getSlope12();
	void setSlope12(double slope12);
	double getSlope14();
	void setSlope14(double slope14);
	double getSlope32();
	void setSlope32(double slope32);
	double getSlope34();
	void setSlope34(double slope34);
	double getTangentLongLength();
	void setTangentLongLength(double tangentLongLength);
	double getTangentShortLength();
	void setTangentShortLength(double tangentShortLength);
};

#endif /* EVSWITCH_H_ */
