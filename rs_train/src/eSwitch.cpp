/*
 * eSwitch.cpp
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eSwitch.h"

eSwitch::eSwitch() {
	this->GlobalID = 0;
	this->Type = "";
	this->State1 = "";
	this->State2 = "";
}

eSwitch::eSwitch(pugi::xml_node& node) {
	//GlobalID
	this->GlobalID = node.child("GlobalID").text().as_int();
	//Type
	this->Type = node.child("Type").text().as_string();
	//State1
	this->State1 = node.child("State1").text().as_string();
	//State2
	this->State2 = node.child("State2").text().as_string();

	//BSwitch
	pugi::xml_node BSwitchNode = node.child("BSwitch");
	if (!BSwitchNode.empty()) {
		eBSwitch ebswitch(BSwitchNode);
		this->seteBSwitch(ebswitch);
	}

	//CSwitch
	pugi::xml_node CSwitchNode = node.child("CSwitch");
	if (!CSwitchNode.empty()) {
		eCSwitch ecswitch(CSwitchNode);
		this->seteCSwitch(ecswitch);
	}

	//SSwitch
	pugi::xml_node SSwitchNode = node.child("SSwitch");
	if (!SSwitchNode.empty()) {
		eSSwitch esswitch(SSwitchNode);
		this->seteSSwitch(esswitch);
	}

	//VSwitch
	pugi::xml_node VSwitchNode = node.child("VSwitch");
	if (!VSwitchNode.empty()) {
		eVSwitch evswitch(VSwitchNode);
		this->seteVSwitch(evswitch);
	}
}

eSwitch::~eSwitch() {
}

vector<eBSwitch>& eSwitch::getBSwitch() {
	return BSwitch;
}

void eSwitch::setBSwitch(vector<eBSwitch>& _switch) {
	BSwitch = _switch;
}

vector<eCSwitch>& eSwitch::getCSwitch() {
	return CSwitch;
}

void eSwitch::setCSwitch(vector<eCSwitch>& _switch) {
	CSwitch = _switch;
}

int eSwitch::getGlobalId() {
	return GlobalID;
}

void eSwitch::setGlobalId(int globalId) {
	GlobalID = globalId;
}

vector<eSSwitch>& eSwitch::getSSwitch() {
	return SSwitch;
}

void eSwitch::setSSwitch(vector<eSSwitch>& _switch) {
	SSwitch = _switch;
}

string& eSwitch::getState1() {
	return State1;
}

void eSwitch::setState1(string& state1) {
	State1 = state1;
}

string& eSwitch::getState2() {
	return State2;
}

void eSwitch::setState2(string& state2) {
	State2 = state2;
}

string& eSwitch::getType() {
	return Type;
}

void eSwitch::setType(string& type) {
	Type = type;
}

vector<eVSwitch>& eSwitch::getVSwitch() {
	return VSwitch;
}

void eSwitch::setVSwitch(vector<eVSwitch>& _switch) {
	VSwitch = _switch;
}

eBSwitch& eSwitch::geteBSwitch() {
	return this->BSwitch[0];
}

void eSwitch::seteBSwitch(eBSwitch _eSwitch) {
	if (this->BSwitch.size())
		this->BSwitch[0] = _eSwitch;
	else
		this->BSwitch.push_back(_eSwitch);
}

eCSwitch& eSwitch::geteCSwitch() {
	return this->CSwitch[0];
}

void eSwitch::seteCSwitch(eCSwitch _eCSwitch) {
	if (this->CSwitch.size())
		this->CSwitch[0] = _eCSwitch;
	else
		this->CSwitch.push_back(_eCSwitch);
}

eSSwitch& eSwitch::geteSSwitch() {
	return this->SSwitch[0];
}

void eSwitch::seteSSwitch(eSSwitch _eSSwitch) {
	if (this->SSwitch.size())
		this->SSwitch[0] = _eSSwitch;
	else
		this->SSwitch.push_back(_eSSwitch);
}

eVSwitch& eSwitch::geteVSwitch() {
	return this->VSwitch[0];
}

void eSwitch::seteVSwitch(eVSwitch _eVSwitch) {
	if (this->VSwitch.size())
		this->VSwitch[0] = _eVSwitch;
	else
		this->VSwitch.push_back(_eVSwitch);
}
