/*
 * eBSwitch.cpp
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eBSwitch.h"

eBSwitch::eBSwitch() {
	this->ConnectedItemId1 = 0;
	this->ConnectedItemId2 = 0;
	this->ConnectedItemId3 = 0;
	this->LateralOffset1 = 0;
	this->LateralOffset2 = 0;
	this->LateralOffset3 = 0;
	this->TangentLength = 0;
	this->CurveLength = 0;
	this->HeadAngle = 0;
	this->AlphaValue = 0;
	this->LateralDisplacement = 0;
	this->CurveRadius = 0;
	this->SwitchSideIsLeft = false;
	this->Coordinate1 = 0;
	this->Coordinate2 = 0;
	this->Coordinate3 = 0;
	this->Slope12 = 0;
	this->Slope13 = 0;
}

eBSwitch::eBSwitch(pugi::xml_node& node) {
	//ConnectedItemId1
	this->ConnectedItemId1 = node.child("ConnectedItemId1").text().as_int();
	//ConnectedItemId2
	this->ConnectedItemId2 = node.child("ConnectedItemId2").text().as_int();
	//ConnectedItemId3
	this->ConnectedItemId3 = node.child("ConnectedItemId3").text().as_int();
	//LateralOffset1
	this->LateralOffset1 = node.child("LateralOffset1").text().as_double();
	//LateralOffset2
	this->LateralOffset2 = node.child("LateralOffset2").text().as_double();
	//LateralOffset3
	this->LateralOffset3 = node.child("LateralOffset3").text().as_double();
	//TangentLength
	this->TangentLength = node.child("TangentLength").text().as_double();
	//CurveLength
	this->CurveLength = node.child("CurveLength").text().as_double();
	//HeadAngle
	this->HeadAngle = node.child("HeadAngle").text().as_double();
	//AlphaValue
	this->AlphaValue = node.child("AlphaValue").text().as_double();
	//LateralDisplacement
	this->LateralDisplacement =
			node.child("LateralDisplacement").text().as_double();
	//CurveRadius
	this->CurveRadius = node.child("CurveRadius").text().as_double();
	//SwitchSideIsLeft
	this->SwitchSideIsLeft = node.child("SwitchSideIsLeft").text().as_bool();
	//Coordinate1
	this->Coordinate1 = node.child("Coordinate1").text().as_double();
	//Coordinate2
	this->Coordinate2 = node.child("Coordinate2").text().as_double();
	//Coordinate3
	this->Coordinate3 = node.child("Coordinate3").text().as_double();
	//Slope12
	this->Slope12 = node.child("Slope12").text().as_double();
	//Slope13
	this->Slope13 = node.child("Slope13").text().as_double();

}

eBSwitch::~eBSwitch() {
}

double eBSwitch::getAlphaValue() {
	return AlphaValue;
}

void eBSwitch::setAlphaValue(double alphaValue) {
	AlphaValue = alphaValue;
}

int eBSwitch::getConnectedItemId1() {
	return ConnectedItemId1;
}

void eBSwitch::setConnectedItemId1(int connectedItemId1) {
	ConnectedItemId1 = connectedItemId1;
}

int eBSwitch::getConnectedItemId2() {
	return ConnectedItemId2;
}

void eBSwitch::setConnectedItemId2(int connectedItemId2) {
	ConnectedItemId2 = connectedItemId2;
}

int eBSwitch::getConnectedItemId3() {
	return ConnectedItemId3;
}

void eBSwitch::setConnectedItemId3(int connectedItemId3) {
	ConnectedItemId3 = connectedItemId3;
}

double eBSwitch::getCoordinate1() {
	return Coordinate1;
}

void eBSwitch::setCoordinate1(double coordinate1) {
	Coordinate1 = coordinate1;
}

double eBSwitch::getCoordinate2() {
	return Coordinate2;
}

void eBSwitch::setCoordinate2(double coordinate2) {
	Coordinate2 = coordinate2;
}

double eBSwitch::getCoordinate3() {
	return Coordinate3;
}

void eBSwitch::setCoordinate3(double coordinate3) {
	Coordinate3 = coordinate3;
}

double eBSwitch::getCurveLength() {
	return CurveLength;
}

void eBSwitch::setCurveLength(double curveLength) {
	CurveLength = curveLength;
}

double eBSwitch::getCurveRadius() {
	return CurveRadius;
}

void eBSwitch::setCurveRadius(double curveRadius) {
	CurveRadius = curveRadius;
}

double eBSwitch::getHeadAngle() {
	return HeadAngle;
}

void eBSwitch::setHeadAngle(double headAngle) {
	HeadAngle = headAngle;
}

double eBSwitch::getLateralDisplacement() {
	return LateralDisplacement;
}

void eBSwitch::setLateralDisplacement(double lateralDisplacement) {
	LateralDisplacement = lateralDisplacement;
}

double eBSwitch::getLateralOffset1() {
	return LateralOffset1;
}

void eBSwitch::setLateralOffset1(double lateralOffset1) {
	LateralOffset1 = lateralOffset1;
}

double eBSwitch::getLateralOffset2() {
	return LateralOffset2;
}

void eBSwitch::setLateralOffset2(double lateralOffset2) {
	LateralOffset2 = lateralOffset2;
}

double eBSwitch::getLateralOffset3() {
	return LateralOffset3;
}

void eBSwitch::setLateralOffset3(double lateralOffset3) {
	LateralOffset3 = lateralOffset3;
}

double eBSwitch::getSlope12() {
	return Slope12;
}

void eBSwitch::setSlope12(double slope12) {
	Slope12 = slope12;
}

double eBSwitch::getSlope13() {
	return Slope13;
}

void eBSwitch::setSlope13(double slope13) {
	Slope13 = slope13;
}

bool eBSwitch::isSwitchSideIsLeft() {
	return SwitchSideIsLeft;
}

void eBSwitch::setSwitchSideIsLeft(bool switchSideIsLeft) {
	SwitchSideIsLeft = switchSideIsLeft;
}

double eBSwitch::getTangentLength() {
	return TangentLength;
}

void eBSwitch::setTangentLength(double tangentLength) {
	TangentLength = tangentLength;
}
