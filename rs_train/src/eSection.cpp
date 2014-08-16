/*
 * eSection.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eSection.h"

eSection::eSection() {
	this->isCurve = false;
}

eSection::eSection(pugi::xml_node& node) {
	//Tangent
	pugi::xml_node TangentNode = node.child("Tangent");
	if (TangentNode.empty()) {
		this->isCurve = true;
	} else {
		this->isCurve = false;
		this->setTangent(eTangent(TangentNode));
	}

	//Curve
	pugi::xml_node CurveNode = node.child("Curve");
	if (CurveNode.empty()) {
		this->isCurve = false;
	} else {
		this->isCurve = true;
		this->setCurve(eCurve(CurveNode));
	}
}

eSection::~eSection() {
	this->Curve.clear();
	this->Tangent.clear();
}

eCurve eSection::getCurve() {
	return Curve[0];
}

void eSection::setCurve(eCurve curve) {

	if (this->Curve.size())
		this->Curve[0] = curve;
	else
		this->Curve.push_back(curve);
}

eTangent eSection::getTangent() {
	return Tangent[0];
}

void eSection::setTangent(eTangent tangent) {

	if (this->Tangent.size())
		this->Tangent[0] = tangent;
	else
		this->Tangent.push_back(tangent);
}

bool eSection::isIsCurve() const {
	return isCurve;
}

void eSection::setIsCurve(bool isCurve) {
	this->isCurve = isCurve;
}
