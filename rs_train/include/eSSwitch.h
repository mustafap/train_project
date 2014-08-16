/*
 * eSSwitch.h
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef ESSWITCH_H_
#define ESSWITCH_H_

#include "pugixml.hpp"
using namespace std;

class eSSwitch;

class eSSwitch {
private:
	int ConnectedItemId1;
	int ConnectedItemId3;
	double LateralOffset1;
	double LateralOffset3;
	double Length;
	double CurveRadius;
	double AlphaValue;
	double LateralDisplacement;
	bool SwitchSideIsLeft;
	double Coordinate1;
	double Coordinate3;
	double Slope13;
public:
	eSSwitch();
	eSSwitch(pugi::xml_node& node);
	virtual ~eSSwitch();
	double getAlphaValue();
	void setAlphaValue(double alphaValue);
	int getConnectedItemId1();
	void setConnectedItemId1(int connectedItemId1);
	int getConnectedItemId3();
	void setConnectedItemId3(int connectedItemId3);
	double getCoordinate1();
	void setCoordinate1(double coordinate1);
	double getCoordinate3();
	void setCoordinate3(double coordinate3);
	double getCurveRadius();
	void setCurveRadius(double curveRadius);
	double getLateralDisplacement();
	void setLateralDisplacement(double lateralDisplacement);
	double getLateralOffset1();
	void setLateralOffset1(double lateralOffset1);
	double getLateralOffset3();
	void setLateralOffset3(double lateralOffset3);
	double getLength();
	void setLength(double length);
	double getSlope13();
	void setSlope13(double slope13);
	bool isSwitchSideIsLeft();
	void setSwitchSideIsLeft(bool switchSideIsLeft);
};

#endif /* ESSWITCH_H_ */
