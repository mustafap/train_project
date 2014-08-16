/*
 * eSSwitch.cpp
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eSSwitch.h"

eSSwitch::eSSwitch() {
	this->ConnectedItemId1 = 0;
	this->ConnectedItemId3 = 0;
	this->LateralOffset1 = 0;
	this->LateralOffset3 = 0;
	this->Length = 0;
	this->CurveRadius = 0;
	this->AlphaValue = 0;
	this->LateralDisplacement = 0;
	this->SwitchSideIsLeft = false;
	this->Coordinate1 = 0;
	this->Coordinate3 = 0;
	this->Slope13 = 0;
}

eSSwitch::eSSwitch(pugi::xml_node& node) {
	//ConnectedItemId1
	this->ConnectedItemId1 = node.child("ConnectedItemId1").text().as_int();
	//ConnectedItemId3
	this->ConnectedItemId3 = node.child("ConnectedItemId3").text().as_int();
	//LateralOffset1
	this->LateralOffset1 = node.child("LateralOffset1").text().as_double();
	//LateralOffset3
	this->LateralOffset3 = node.child("LateralOffset3").text().as_double();
	//Length
	this->Length = node.child("Length").text().as_double();
	//CurveRadius
	this->CurveRadius = node.child("CurveRadius").text().as_double();
	//AlphaValue
	this->AlphaValue = node.child("AlphaValue").text().as_double();
	//LateralDisplacement
	this->LateralDisplacement =
			node.child("LateralDisplacement").text().as_double();
	//SwitchSideIsLeft
	this->SwitchSideIsLeft = node.child("SwitchSideIsLeft").text().as_bool();
	//Coordinate1
	this->Coordinate1 = node.child("Coordinate1").text().as_double();
	//Coordinate3
	this->Coordinate3 = node.child("Coordinate3").text().as_double();
	//Slope13
	this->Slope13 = node.child("Slope13").text().as_double();

}

eSSwitch::~eSSwitch() {
}

double eSSwitch::getAlphaValue() {
	return AlphaValue;
}

void eSSwitch::setAlphaValue(double alphaValue) {
	AlphaValue = alphaValue;
}

int eSSwitch::getConnectedItemId1() {
	return ConnectedItemId1;
}

void eSSwitch::setConnectedItemId1(int connectedItemId1) {
	ConnectedItemId1 = connectedItemId1;
}

int eSSwitch::getConnectedItemId3() {
	return ConnectedItemId3;
}

void eSSwitch::setConnectedItemId3(int connectedItemId3) {
	ConnectedItemId3 = connectedItemId3;
}

double eSSwitch::getCoordinate1() {
	return Coordinate1;
}

void eSSwitch::setCoordinate1(double coordinate1) {
	Coordinate1 = coordinate1;
}

double eSSwitch::getCoordinate3() {
	return Coordinate3;
}

void eSSwitch::setCoordinate3(double coordinate3) {
	Coordinate3 = coordinate3;
}

double eSSwitch::getCurveRadius() {
	return CurveRadius;
}

void eSSwitch::setCurveRadius(double curveRadius) {
	CurveRadius = curveRadius;
}

double eSSwitch::getLateralDisplacement() {
	return LateralDisplacement;
}

void eSSwitch::setLateralDisplacement(double lateralDisplacement) {
	LateralDisplacement = lateralDisplacement;
}

double eSSwitch::getLateralOffset1() {
	return LateralOffset1;
}

void eSSwitch::setLateralOffset1(double lateralOffset1) {
	LateralOffset1 = lateralOffset1;
}

double eSSwitch::getLateralOffset3() {
	return LateralOffset3;
}

void eSSwitch::setLateralOffset3(double lateralOffset3) {
	LateralOffset3 = lateralOffset3;
}

double eSSwitch::getLength() {
	return Length;
}

void eSSwitch::setLength(double length) {
	Length = length;
}

double eSSwitch::getSlope13() {
	return Slope13;
}

void eSSwitch::setSlope13(double slope13) {
	Slope13 = slope13;
}

bool eSSwitch::isSwitchSideIsLeft() {
	return SwitchSideIsLeft;
}

void eSSwitch::setSwitchSideIsLeft(bool switchSideIsLeft) {
	SwitchSideIsLeft = switchSideIsLeft;
}
