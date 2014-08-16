/*
 * eCurve.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eCurve.h"

eCurve::eCurve() {
	this->Length = 0;
	this->TransientBegin = 0;
	this->TransientEnd = 0;
	this->BeginCoordinate = 0;
	this->EndCoordinate = 0;
	this->CurveRadious = 0;
	this->IsLeft = false;
	this->Cant = 0;
	this->Widening = 0;
	this->StartSideFriction = 0;
	this->EndSideFriction = 0;
	this->FOuter = 0;
	this->FInner = 0;
	this->FFlange = 0;

}

eCurve::eCurve(pugi::xml_node& node) {
	//Length
	this->Length = node.child("Length").text().as_double();
	//TransientBegin
	this->TransientBegin = node.child("TransientBegin").text().as_double();
	//TransientEnd
	this->TransientEnd = node.child("TransientEnd").text().as_double();
	//BeginCoordinate
	this->BeginCoordinate = node.child("BeginCoordinate").text().as_double();
	//EndCoordinate
	this->EndCoordinate = node.child("EndCoordinate").text().as_double();
	//CurveRadious
	this->CurveRadious = node.child("CurveRadious").text().as_double();
	//IsLeft
	this->IsLeft = node.child("IsLeft").text().as_bool();
	//Cant
	this->Cant = node.child("Cant").text().as_double();
	//Widening
	this->Widening = node.child("Widening").text().as_double();
	//StartSideFriction
	this->StartSideFriction =
			node.child("StartSideFriction").text().as_double();
	//EndSideFriction
	this->EndSideFriction = node.child("EndSideFriction").text().as_double();
	//FOuter
	this->FOuter = node.child("FOuter").text().as_double();
	//FInner
	this->FInner = node.child("FInner").text().as_double();
	//FFlange
	this->FFlange = node.child("FFlange").text().as_double();
}

eCurve::~eCurve() {

}

double eCurve::getBeginCoordinate() {
	return BeginCoordinate;
}

void eCurve::setBeginCoordinate(double beginCoordinate) {
	BeginCoordinate = beginCoordinate;
}

double eCurve::getCant() {
	return Cant;
}

void eCurve::setCant(double cant) {
	Cant = cant;
}

double eCurve::getCurveRadious() {
	return CurveRadious;
}

void eCurve::setCurveRadious(double curveRadious) {
	CurveRadious = curveRadious;
}

double eCurve::getEndCoordinate() {
	return EndCoordinate;
}

void eCurve::setEndCoordinate(double endCoordinate) {
	EndCoordinate = endCoordinate;
}

double eCurve::getEndSideFriction() {
	return EndSideFriction;
}

void eCurve::setEndSideFriction(double endSideFriction) {
	EndSideFriction = endSideFriction;
}

double eCurve::getFlange() {
	return FFlange;
}

void eCurve::setFlange(double flange) {
	FFlange = flange;
}

double eCurve::getInner() {
	return FInner;
}

void eCurve::setInner(double inner) {
	FInner = inner;
}

double eCurve::getOuter() {
	return FOuter;
}

void eCurve::setOuter(double outer) {
	FOuter = outer;
}

bool eCurve::isIsLeft() {
	return IsLeft;
}

void eCurve::setIsLeft(bool isLeft) {
	IsLeft = isLeft;
}

double eCurve::getLength() {
	return Length;
}

void eCurve::setLength(double length) {
	Length = length;
}

double eCurve::getStartSideFriction() {
	return StartSideFriction;
}

void eCurve::setStartSideFriction(double startSideFriction) {
	StartSideFriction = startSideFriction;
}

double eCurve::getTransientBegin() {
	return TransientBegin;
}

void eCurve::setTransientBegin(double transientBegin) {
	TransientBegin = transientBegin;
}

double eCurve::getTransientEnd() {
	return TransientEnd;
}

void eCurve::setTransientEnd(double transientEnd) {
	TransientEnd = transientEnd;
}

double eCurve::getWidening() {
	return Widening;
}

void eCurve::setWidening(double widening) {
	Widening = widening;
}

