/*
 * eVerticalProfile.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eVerticalProfile.h"

eVerticalProfile::eVerticalProfile() {
	this->Length=0;
	this->PrevSCPPosition=0;
	this->NextSCPPosition=0;
	this->Slope=0;
	this->NextRadius=0;
	this->PrevRadius=0;
	this->PrevSlope=0;
	this->NextSlope=0;

}

eVerticalProfile::eVerticalProfile(pugi::xml_node& node) {
	//Length
	this->Length = node.child("Length").text().as_double();
	//PrevSCPPosition
	this->PrevSCPPosition = node.child("PrevSCPPosition").text().as_double();
	//NextSCPPosition
	this->NextSCPPosition = node.child("NextSCPPosition").text().as_double();
	//Slope
	this->Slope = node.child("Slope").text().as_double();
	//NextRadius
	this->NextRadius = node.child("NextRadius").text().as_double();
	//PrevRadius
	this->PrevRadius = node.child("PrevRadius").text().as_double();
	//PrevSlope
	this->PrevSlope = node.child("PrevSlope").text().as_double();
	//NextSlope
	this->NextSlope = node.child("NextSlope").text().as_double();
}

eVerticalProfile::~eVerticalProfile() {
}

double eVerticalProfile::getLength()  {
	return Length;
}

void eVerticalProfile::setLength(double length) {
	Length = length;
}

double eVerticalProfile::getNextRadius()  {
	return NextRadius;
}

void eVerticalProfile::setNextRadius(double nextRadius) {
	NextRadius = nextRadius;
}

double eVerticalProfile::getNextScpPosition()  {
	return NextSCPPosition;
}

void eVerticalProfile::setNextScpPosition(double nextScpPosition) {
	NextSCPPosition = nextScpPosition;
}

double eVerticalProfile::getNextSlope()  {
	return NextSlope;
}

void eVerticalProfile::setNextSlope(double nextSlope) {
	NextSlope = nextSlope;
}

double eVerticalProfile::getPrevRadius()  {
	return PrevRadius;
}

void eVerticalProfile::setPrevRadius(double prevRadius) {
	PrevRadius = prevRadius;
}

double eVerticalProfile::getPrevScpPosition()  {
	return PrevSCPPosition;
}

void eVerticalProfile::setPrevScpPosition(double prevScpPosition) {
	PrevSCPPosition = prevScpPosition;
}

double eVerticalProfile::getPrevSlope()  {
	return PrevSlope;
}

void eVerticalProfile::setPrevSlope(double prevSlope) {
	PrevSlope = prevSlope;
}

double eVerticalProfile::getSlope()  {
	return Slope;
}



void eVerticalProfile::setSlope(double slope) {
	Slope = slope;
}
