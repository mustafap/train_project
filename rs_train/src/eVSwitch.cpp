/*
 * eVSwitch.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eVSwitch.h"

eVSwitch::eVSwitch() {
	this->ConnectedItemId1 = 0;
	this->ConnectedItemId2 = 0;
	this->ConnectedItemId3 = 0;
	this->ConnectedItemId4 = 0;
	this->LateralOffset1 = 0;
	this->LateralOffset2 = 0;
	this->LateralOffset3 = 0;
	this->LateralOffset4 = 0;
	this->AlphaValue = 0;
	this->LateralDisplacement = 0;
	this->CurveRadius = 0;
	this->TangentLongLength = 0;
	this->TangentShortLength = 0;
	this->CurveLength = 0;
	this->Coordinate1 = 0;
	this->Coordinate2 = 0;
	this->Coordinate3 = 0;
	this->Coordinate4 = 0;
	this->Slope12 = 0;
	this->Slope14 = 0;
	this->Slope32 = 0;
	this->Slope34 = 0;
}

eVSwitch::eVSwitch(pugi::xml_node& node) {
	//ConnectedItemId1
	this->ConnectedItemId1 = node.child("ConnectedItemId1").text().as_int();
	//ConnectedItemId2
	this->ConnectedItemId2 = node.child("ConnectedItemId2").text().as_int();
	//ConnectedItemId3
	this->ConnectedItemId3 = node.child("ConnectedItemId3").text().as_int();
	//ConnectedItemId4
	this->ConnectedItemId4 = node.child("ConnectedItemId4").text().as_int();
	//LateralOffset1
	this->LateralOffset1 = node.child("LateralOffset1").text().as_double();
	//LateralOffset2
	this->LateralOffset2 = node.child("LateralOffset2").text().as_double();
	//LateralOffset3
	this->LateralOffset3 = node.child("LateralOffset3").text().as_double();
	//LateralOffset4
	this->LateralOffset4 = node.child("LateralOffset4").text().as_double();
	//AlphaValue
	this->AlphaValue = node.child("AlphaValue").text().as_double();
	//LateralDisplacement
	this->LateralDisplacement =
			node.child("LateralDisplacement").text().as_double();
	//CurveRadius
	this->CurveRadius = node.child("CurveRadius").text().as_double();
	//TangentLongLength
	this->TangentLongLength =
			node.child("TangentLongLength").text().as_double();
	//TangentShortLength
	this->TangentShortLength =
			node.child("TangentShortLength").text().as_double();
	//CurveLength
	this->CurveLength = node.child("CurveLength").text().as_double();
	//Coordinate1
	this->Coordinate1 = node.child("Coordinate1").text().as_double();
	//Coordinate2
	this->Coordinate2 = node.child("Coordinate2").text().as_double();
	//Coordinate3
	this->Coordinate3 = node.child("Coordinate3").text().as_double();
	//Coordinate4
	this->Coordinate4 = node.child("Coordinate4").text().as_double();
	//Slope12
	this->Slope12 = node.child("Slope12").text().as_double();
	//Slope14
	this->Slope14 = node.child("Slope14").text().as_double();
	//Slope32
	this->Slope32 = node.child("Slope32").text().as_double();
	//Slope34
	this->Slope34 = node.child("Slope34").text().as_double();
}

eVSwitch::~eVSwitch() {
}

double eVSwitch::getAlphaValue() {
	return AlphaValue;
}

void eVSwitch::setAlphaValue(double alphaValue) {
	AlphaValue = alphaValue;
}

int eVSwitch::getConnectedItemId1() {
	return ConnectedItemId1;
}

void eVSwitch::setConnectedItemId1(int connectedItemId1) {
	ConnectedItemId1 = connectedItemId1;
}

int eVSwitch::getConnectedItemId2() {
	return ConnectedItemId2;
}

void eVSwitch::setConnectedItemId2(int connectedItemId2) {
	ConnectedItemId2 = connectedItemId2;
}

int eVSwitch::getConnectedItemId3() {
	return ConnectedItemId3;
}

void eVSwitch::setConnectedItemId3(int connectedItemId3) {
	ConnectedItemId3 = connectedItemId3;
}

int eVSwitch::getConnectedItemId4() {
	return ConnectedItemId4;
}

void eVSwitch::setConnectedItemId4(int connectedItemId4) {
	ConnectedItemId4 = connectedItemId4;
}

double eVSwitch::getCoordinate1() {
	return Coordinate1;
}

void eVSwitch::setCoordinate1(double coordinate1) {
	Coordinate1 = coordinate1;
}

double eVSwitch::getCoordinate2() {
	return Coordinate2;
}

void eVSwitch::setCoordinate2(double coordinate2) {
	Coordinate2 = coordinate2;
}

double eVSwitch::getCoordinate3() {
	return Coordinate3;
}

void eVSwitch::setCoordinate3(double coordinate3) {
	Coordinate3 = coordinate3;
}

double eVSwitch::getCoordinate4() {
	return Coordinate4;
}

void eVSwitch::setCoordinate4(double coordinate4) {
	Coordinate4 = coordinate4;
}

double eVSwitch::getCurveLength() {
	return CurveLength;
}

void eVSwitch::setCurveLength(double curveLength) {
	CurveLength = curveLength;
}

double eVSwitch::getCurveRadius() {
	return CurveRadius;
}

void eVSwitch::setCurveRadius(double curveRadius) {
	CurveRadius = curveRadius;
}

double eVSwitch::getLateralDisplacement() {
	return LateralDisplacement;
}

void eVSwitch::setLateralDisplacement(double lateralDisplacement) {
	LateralDisplacement = lateralDisplacement;
}

double eVSwitch::getLateralOffset1() {
	return LateralOffset1;
}

void eVSwitch::setLateralOffset1(double lateralOffset1) {
	LateralOffset1 = lateralOffset1;
}

double eVSwitch::getLateralOffset2() {
	return LateralOffset2;
}

void eVSwitch::setLateralOffset2(double lateralOffset2) {
	LateralOffset2 = lateralOffset2;
}

double eVSwitch::getLateralOffset3() {
	return LateralOffset3;
}

void eVSwitch::setLateralOffset3(double lateralOffset3) {
	LateralOffset3 = lateralOffset3;
}

double eVSwitch::getLateralOffset4() {
	return LateralOffset4;
}

void eVSwitch::setLateralOffset4(double lateralOffset4) {
	LateralOffset4 = lateralOffset4;
}

double eVSwitch::getSlope12() {
	return Slope12;
}

void eVSwitch::setSlope12(double slope12) {
	Slope12 = slope12;
}

double eVSwitch::getSlope14() {
	return Slope14;
}

void eVSwitch::setSlope14(double slope14) {
	Slope14 = slope14;
}

double eVSwitch::getSlope32() {
	return Slope32;
}

void eVSwitch::setSlope32(double slope32) {
	Slope32 = slope32;
}

double eVSwitch::getSlope34() {
	return Slope34;
}

void eVSwitch::setSlope34(double slope34) {
	Slope34 = slope34;
}

double eVSwitch::getTangentLongLength() {
	return TangentLongLength;
}

void eVSwitch::setTangentLongLength(double tangentLongLength) {
	TangentLongLength = tangentLongLength;
}

double eVSwitch::getTangentShortLength() {
	return TangentShortLength;
}

void eVSwitch::setTangentShortLength(double tangentShortLength) {
	TangentShortLength = tangentShortLength;
}
