/*
 * eTangent.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eTangent.h"

eTangent::eTangent() {
	this->Length = 0;
	this->BeginCoordinate = 0;
	this->EndCoordinate = 0;
	this->FOuter = 0;
	this->FInner = 0;
	this->FFlange = 0;
}

eTangent::eTangent(pugi::xml_node& node) {
	//Length
	this->Length = node.child("Length").text().as_double();
	//BeginCoordinate
	this->BeginCoordinate = node.child("BeginCoordinate").text().as_double();
	//EndCoordinate
	this->EndCoordinate = node.child("EndCoordinate").text().as_double();
	//FOuter
	this->FOuter = node.child("FOuter").text().as_double();
	//FInner
	this->FInner = node.child("FInner").text().as_double();
	//FFlange
	this->FFlange = node.child("FFlange").text().as_double();
}

eTangent::~eTangent() {
}

double eTangent::getBeginCoordinate() {
	return BeginCoordinate;
}

void eTangent::setBeginCoordinate(double beginCoordinate) {
	BeginCoordinate = beginCoordinate;
}

double eTangent::getEndCoordinate() {
	return EndCoordinate;
}

void eTangent::setEndCoordinate(double endCoordinate) {
	EndCoordinate = endCoordinate;
}

double eTangent::getFlange() {
	return FFlange;
}

void eTangent::setFlange(double flange) {
	FFlange = flange;
}

double eTangent::getInner() {
	return FInner;
}

void eTangent::setInner(double inner) {
	FInner = inner;
}

double eTangent::getOuter() {
	return FOuter;
}

void eTangent::setOuter(double outer) {
	FOuter = outer;
}

double eTangent::getLength() {
	return Length;
}

void eTangent::setLength(double length) {
	Length = length;
}
