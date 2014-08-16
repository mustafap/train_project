/*
 * eCSwitch.cpp
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eCSwitch.h"

eCSwitch::eCSwitch() {
	this->ConnectedItemId1 = 0;
	this->ConnectedItemId2 = 0;
	this->ConnectedItemId3 = 0;
	this->LateralOffset1 = 0;
	this->LateralOffset2 = 0;
	this->LateralOffset3 = 0;
	this->ParallelLength = 0;
	this->DeviatedLength = 0;
	this->CurveRadius = 0;
	this->DeviatedCurveRadius = 0;
	this->DeviatedCurveSideIsLeft = false;
	this->NotDeviatedCurveSideIsLeft = false;
	this->LateralDisplacement = 0;
	this->SwitchSideIsLeft = false;
	this->Coordinate1 = 0;
	this->Coordinate2 = 0;
	this->Coordinate3 = 0;
	this->Slope12 = 0;
	this->Slope13 = 0;

}

eCSwitch::eCSwitch(pugi::xml_node& node) {
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
	//ParallelLength
	this->ParallelLength = node.child("ParallelLength").text().as_double();
	//DeviatedLength
	this->DeviatedLength = node.child("DeviatedLength").text().as_double();
	//CurveRadius
	this->CurveRadius = node.child("CurveRadius").text().as_double();
	//DeviatedCurveRadius
	this->DeviatedCurveRadius =
			node.child("DeviatedCurveRadius").text().as_double();
	//DeviatedCurveSideIsLeft
	this->DeviatedCurveSideIsLeft =
			node.child("DeviatedCurveSideIsLeft").text().as_bool();
	//NotDeviatedCurveSideIsLeft
	this->NotDeviatedCurveSideIsLeft =
			node.child("NotDeviatedCurveSideIsLeft").text().as_bool();
	//LateralDisplacement
	this->LateralDisplacement =
			node.child("LateralDisplacement").text().as_double();
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

eCSwitch::~eCSwitch() {
}

int eCSwitch::getConnectedItemId1() {
	return ConnectedItemId1;
}

void eCSwitch::setConnectedItemId1(int connectedItemId1) {
	ConnectedItemId1 = connectedItemId1;
}

int eCSwitch::getConnectedItemId2() {
	return ConnectedItemId2;
}

void eCSwitch::setConnectedItemId2(int connectedItemId2) {
	ConnectedItemId2 = connectedItemId2;
}

int eCSwitch::getConnectedItemId3() {
	return ConnectedItemId3;
}

void eCSwitch::setConnectedItemId3(int connectedItemId3) {
	ConnectedItemId3 = connectedItemId3;
}

double eCSwitch::getCoordinate1() {
	return Coordinate1;
}

void eCSwitch::setCoordinate1(double coordinate1) {
	Coordinate1 = coordinate1;
}

double eCSwitch::getCoordinate2() {
	return Coordinate2;
}

void eCSwitch::setCoordinate2(double coordinate2) {
	Coordinate2 = coordinate2;
}

double eCSwitch::getCoordinate3() {
	return Coordinate3;
}

void eCSwitch::setCoordinate3(double coordinate3) {
	Coordinate3 = coordinate3;
}

double eCSwitch::getCurveRadius() {
	return CurveRadius;
}

void eCSwitch::setCurveRadius(double curveRadius) {
	CurveRadius = curveRadius;
}

double eCSwitch::getDeviatedCurveRadius() {
	return DeviatedCurveRadius;
}

void eCSwitch::setDeviatedCurveRadius(double deviatedCurveRadius) {
	DeviatedCurveRadius = deviatedCurveRadius;
}

bool eCSwitch::isDeviatedCurveSideIsLeft() {
	return DeviatedCurveSideIsLeft;
}

void eCSwitch::setDeviatedCurveSideIsLeft(bool deviatedCurveSideIsLeft) {
	DeviatedCurveSideIsLeft = deviatedCurveSideIsLeft;
}

double eCSwitch::getDeviatedLength() {
	return DeviatedLength;
}

void eCSwitch::setDeviatedLength(double deviatedLength) {
	DeviatedLength = deviatedLength;
}

double eCSwitch::getLateralDisplacement() {
	return LateralDisplacement;
}

void eCSwitch::setLateralDisplacement(double lateralDisplacement) {
	LateralDisplacement = lateralDisplacement;
}

double eCSwitch::getLateralOffset1() {
	return LateralOffset1;
}

void eCSwitch::setLateralOffset1(double lateralOffset1) {
	LateralOffset1 = lateralOffset1;
}

double eCSwitch::getLateralOffset2() {
	return LateralOffset2;
}

void eCSwitch::setLateralOffset2(double lateralOffset2) {
	LateralOffset2 = lateralOffset2;
}

double eCSwitch::getLateralOffset3() {
	return LateralOffset3;
}

void eCSwitch::setLateralOffset3(double lateralOffset3) {
	LateralOffset3 = lateralOffset3;
}

bool eCSwitch::isNotDeviatedCurveSideIsLeft() {
	return NotDeviatedCurveSideIsLeft;
}

void eCSwitch::setNotDeviatedCurveSideIsLeft(bool notDeviatedCurveSideIsLeft) {
	NotDeviatedCurveSideIsLeft = notDeviatedCurveSideIsLeft;
}

double eCSwitch::getParallelLength() {
	return ParallelLength;
}

void eCSwitch::setParallelLength(double parallelLength) {
	ParallelLength = parallelLength;
}

double eCSwitch::getSlope12() {
	return Slope12;
}

void eCSwitch::setSlope12(double slope12) {
	Slope12 = slope12;
}

double eCSwitch::getSlope13() {
	return Slope13;
}

void eCSwitch::setSlope13(double slope13) {
	Slope13 = slope13;
}

bool eCSwitch::isSwitchSideIsLeft() {
	return SwitchSideIsLeft;
}

void eCSwitch::setSwitchSideIsLeft(bool switchSideIsLeft) {
	SwitchSideIsLeft = switchSideIsLeft;
}
