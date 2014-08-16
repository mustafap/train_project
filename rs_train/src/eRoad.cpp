/*
 * eRoad.cpp
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "eRoad.h"

eRoad::eRoad() {
	this->GlobalID = 0;
	this->LateralOffsetBegin = 0;
	this->LateralOffsetEnd = 0;
	this->Length = 0;
	this->NextConnectedRoadID = 0;
	this->NextConnectedSwitchID = 0;
	this->PrevConnectedRoadID = 0;
	this->PrevConnectedSwitchID = 0;
	this->BeginCoordinate = 0;
	this->EndCoordinate = 0;
	this->HasCatenaryLine = false;
}

eRoad::~eRoad() {
	this->VerticalProfile.clear();
	this->Section.clear();
	this->Sign.clear();
	this->Signal.clear();
	this->Magnet.clear();
	this->Balise.clear();
	this->Block.clear();
	this->LevelCrossing.clear();
	this->PhysicalBuilding.clear();

}

eRoad::eRoad(pugi::xml_node& node) {
	//GlobalID
	this->GlobalID = node.child("GlobalID").text().as_int();
	//LateralOffsetBegin
	this->LateralOffsetBegin =
			node.child("LateralOffsetBegin").text().as_double();
	//LateralOffsetEnd
	this->LateralOffsetEnd = node.child("LateralOffsetEnd").text().as_double();
	//Length
	this->Length = node.child("Length").text().as_double();
	//NextConnectedRoadID
	this->NextConnectedRoadID =
			node.child("NextConnectedRoadID").text().as_int();
	//NextConnectedSwitchID
	this->NextConnectedSwitchID =
			node.child("NextConnectedSwitchID").text().as_int();
	//PrevConnectedRoadID
	this->PrevConnectedRoadID =
			node.child("PrevConnectedRoadID").text().as_int();
	//PrevConnectedSwitchID
	this->PrevConnectedSwitchID =
			node.child("PrevConnectedSwitchID").text().as_int();
	//BeginCoordinate
	this->BeginCoordinate = node.child("BeginCoordinate").text().as_double();
	//EndCoordinate
	this->EndCoordinate = node.child("EndCoordinate").text().as_double();
	//HasCatenaryLine
	this->HasCatenaryLine = node.child("HasCatenaryLine").text().as_bool();
	//CatenaryVoltage
	this->CatenaryVoltage = node.child("CatenaryVoltage").text().as_double();
	//IsMainLine
	this->IsMainLine = node.child("IsMainLine").text().as_bool();
	//Balast
	this->Balast = node.child("Balast").text().as_string();
	//Travers
	this->Travers = node.child("Travers").text().as_string();

	//VerticalProfile
	for (pugi::xml_node VerticalProfileNode = node.child("VerticalProfile");
			VerticalProfileNode;
			VerticalProfileNode = VerticalProfileNode.next_sibling(
					"VerticalProfile")) {
		eVerticalProfile everticalprofile = eVerticalProfile(
				VerticalProfileNode);
		this->VerticalProfile.push_back(everticalprofile);
	}

	//Section
	for (pugi::xml_node SectionNode = node.child("Section"); SectionNode;
			SectionNode = SectionNode.next_sibling("Section")) {
		eSection esection = eSection(SectionNode);
		this->Section.push_back(esection);
	}

	//Sign
	for (pugi::xml_node SignNode = node.child("Sign"); SignNode; SignNode =
			SignNode.next_sibling("Sign")) {
		eSign esign = eSign(SignNode);
		this->Sign.push_back(esign);
	}

	//Signal
	for (pugi::xml_node SignalNode = node.child("Signal"); SignalNode;
			SignalNode = SignalNode.next_sibling("Signal")) {
		eSignal esignal = eSignal(SignalNode);
		this->Signal.push_back(esignal);
	}

	//Magnet
	for (pugi::xml_node MagnetNode = node.child("Magnet"); MagnetNode;
			MagnetNode = MagnetNode.next_sibling("Magnet")) {
		eMagnet emagnet = eMagnet(MagnetNode);
		this->Magnet.push_back(emagnet);
	}

	//Balise
	for (pugi::xml_node BaliseNode = node.child("Balise"); BaliseNode;
			BaliseNode = BaliseNode.next_sibling("Balise")) {
		eBalise ebalise = eBalise(BaliseNode);
		this->Balise.push_back(ebalise);
	}

	//Block
	for (pugi::xml_node BlockNode = node.child("Block"); BlockNode; BlockNode =
			BlockNode.next_sibling("Block")) {
		eBlock eblock = eBlock(BlockNode);
		this->Block.push_back(eblock);
	}

	//LevelCrossing
	for (pugi::xml_node LevelCrossingNode = node.child("LevelCrossing");
			LevelCrossingNode;
			LevelCrossingNode = LevelCrossingNode.next_sibling(
					"LevelCrossing")) {
		eLevelCrossing elevelcrossing = eLevelCrossing(LevelCrossingNode);
		this->LevelCrossing.push_back(elevelcrossing);
	}

	//PhysicalBuilding
	for (pugi::xml_node PhysicalBuildingNode = node.child("PhysicalBuilding");
			PhysicalBuildingNode;
			PhysicalBuildingNode = PhysicalBuildingNode.next_sibling(
					"PhysicalBuilding")) {
		ePhysicalBuilding ephysicalbuilding = ePhysicalBuilding(
				PhysicalBuildingNode);
		this->PhysicalBuilding.push_back(ephysicalbuilding);
	}

}

vector<eBalise>& eRoad::getBalise() {
	return Balise;
}

void eRoad::setBalise(vector<eBalise>& balise) {
	Balise = balise;
}

double eRoad::getBeginCoordinate() {
	return BeginCoordinate;
}

void eRoad::setBeginCoordinate(double beginCoordinate) {
	BeginCoordinate = beginCoordinate;
}

vector<eBlock>& eRoad::getBlock() {
	return Block;
}

void eRoad::setBlock(vector<eBlock>& block) {
	Block = block;
}

double eRoad::getEndCoordinate() {
	return EndCoordinate;
}

void eRoad::setEndCoordinate(double endCoordinate) {
	EndCoordinate = endCoordinate;
}

int eRoad::getGlobalId() {
	return GlobalID;
}

void eRoad::setGlobalId(int globalId) {
	GlobalID = globalId;
}

bool eRoad::isHasCatenaryLine() {
	return HasCatenaryLine;
}

void eRoad::setHasCatenaryLine(bool hasCatenaryLine) {
	HasCatenaryLine = hasCatenaryLine;
}

double eRoad::getLateralOffsetBegin() {
	return LateralOffsetBegin;
}

void eRoad::setLateralOffsetBegin(double lateralOffsetBegin) {
	LateralOffsetBegin = lateralOffsetBegin;
}

double eRoad::getLateralOffsetEnd() {
	return LateralOffsetEnd;
}

void eRoad::setLateralOffsetEnd(double lateralOffsetEnd) {
	LateralOffsetEnd = lateralOffsetEnd;
}

double eRoad::getLength() {
	return Length;
}

void eRoad::setLength(double length) {
	Length = length;
}

vector<eLevelCrossing>& eRoad::getLevelCrossing() {
	return LevelCrossing;
}

void eRoad::setLevelCrossing(vector<eLevelCrossing>& levelCrossing) {
	LevelCrossing = levelCrossing;
}

vector<eMagnet>& eRoad::getMagnet() {
	return Magnet;
}

void eRoad::setMagnet(vector<eMagnet>& magnet) {
	Magnet = magnet;
}

int eRoad::getNextConnectedRoadId() {
	return NextConnectedRoadID;
}

void eRoad::setNextConnectedRoadId(int nextConnectedRoadId) {
	NextConnectedRoadID = nextConnectedRoadId;
}

int eRoad::getNextConnectedSwitchId() {
	return NextConnectedSwitchID;
}

void eRoad::setNextConnectedSwitchId(int nextConnectedSwitchId) {
	NextConnectedSwitchID = nextConnectedSwitchId;
}

vector<ePhysicalBuilding>& eRoad::getPhysicalBuilding() {
	return PhysicalBuilding;
}

void eRoad::setPhysicalBuilding(vector<ePhysicalBuilding>& physicalBuilding) {
	PhysicalBuilding = physicalBuilding;
}

int eRoad::getPrevConnectedRoadId() {
	return PrevConnectedRoadID;
}

void eRoad::setPrevConnectedRoadId(int prevConnectedRoadId) {
	PrevConnectedRoadID = prevConnectedRoadId;
}

int eRoad::getPrevConnectedSwitchId() {
	return PrevConnectedSwitchID;
}

void eRoad::setPrevConnectedSwitchId(int prevConnectedSwitchId) {
	PrevConnectedSwitchID = prevConnectedSwitchId;
}

vector<eSection>& eRoad::getSection() {
	return Section;
}

void eRoad::setSection(vector<eSection>& section) {
	Section = section;
}

vector<eSign>& eRoad::getSign() {
	return Sign;
}

void eRoad::setSign(vector<eSign>& sign) {
	Sign = sign;
}

vector<eSignal>& eRoad::getSignal() {
	return Signal;
}

void eRoad::setSignal(vector<eSignal>& signal) {
	Signal = signal;
}

vector<eVerticalProfile>& eRoad::getVerticalProfile() {
	return VerticalProfile;
}

void eRoad::setVerticalProfile(vector<eVerticalProfile>& verticalProfile) {
	VerticalProfile = verticalProfile;
}

eVerticalProfile& eRoad::geteVerticalProfile(int index) {
	return this->VerticalProfile[index];
}

void eRoad::addeVerticalProfile(eVerticalProfile everticalProfile) {
	this->VerticalProfile.push_back(everticalProfile);
}

void eRoad::seteVerticalProfile(eVerticalProfile everticalProfile, int index) {
	this->VerticalProfile[index] = everticalProfile;
}

eSection& eRoad::geteSection(int index) {
	return this->Section[index];
}

void eRoad::addeSection(eSection esection) {
	this->Section.push_back(esection);
}

void eRoad::seteSection(eSection esection, int index) {
	this->Section[index] = esection;
}

eSign& eRoad::geteSign(int index) {
	return this->Sign[index];
}

void eRoad::addeSign(eSign esign) {
	this->Sign.push_back(esign);
}

void eRoad::seteSign(eSign esign, int index) {
	this->Sign[index] = esign;
}

eSignal& eRoad::geteSignal(int index) {
	return this->Signal[index];
}

void eRoad::addeSignal(eSignal esignal) {
	this->Signal.push_back(esignal);
}

void eRoad::seteSignal(eSignal esignal, int index) {
	this->Signal[index] = esignal;
}

eMagnet& eRoad::geteMagnet(int index) {
	return this->Magnet[index];
}

void eRoad::addeMagnet(eMagnet emagnet) {
	this->Magnet.push_back(emagnet);
}

void eRoad::seteMagnet(eMagnet emagnet, int index) {
	this->Magnet[index] = emagnet;
}

eBalise& eRoad::geteBalise(int index) {
	return this->Balise[index];
}

void eRoad::addeBalise(eBalise ebalise) {
	this->Balise.push_back(ebalise);
}

void eRoad::seteBalise(eBalise ebalise, int index) {
	this->Balise[index] = ebalise;
}

eBlock& eRoad::geteBlock(int index) {
	return this->Block[index];
}

void eRoad::addeBlock(eBlock eblock) {
	this->Block.push_back(eblock);
}

void eRoad::seteBlock(eBlock eblock, int index) {
	this->Block[index] = eblock;
}

eLevelCrossing& eRoad::geteLevelCrossing(int index) {
	return this->LevelCrossing[index];
}

void eRoad::addeLevelCrossing(eLevelCrossing elevelCrossing) {
	this->LevelCrossing.push_back(elevelCrossing);
}

void eRoad::seteLevelCrossing(eLevelCrossing elevelCrossing, int index) {
	this->LevelCrossing[index] = elevelCrossing;
}

ePhysicalBuilding& eRoad::getePhysicalBuilding(int index) {
	return this->PhysicalBuilding[index];
}

void eRoad::addePhysicalBuilding(ePhysicalBuilding ephysicalBuilding) {
	this->PhysicalBuilding.push_back(ephysicalBuilding);
}

void eRoad::setePhysicalBuilding(ePhysicalBuilding ephysicalBuilding,
		int index) {
	this->PhysicalBuilding[index] = ephysicalBuilding;
}

int eRoad::getVerticalProfileSize() {
	return this->VerticalProfile.size();
}

int eRoad::getSectionSize() {
	return this->Section.size();
}

int eRoad::getSignSize() {
	return this->Sign.size();
}

int eRoad::getSignalSize() {
	return this->Signal.size();
}

int eRoad::getMagnetSize() {
	return this->Magnet.size();
}

int eRoad::getBaliseSize() {
	return this->Balise.size();
}

int eRoad::getBlockSize() {
	return this->Block.size();
}

int eRoad::getLevelCrossingSize() {
	return this->LevelCrossing.size();
}

int eRoad::getPhysicalBuildingSize() {
	return this->PhysicalBuilding.size();
}

string eRoad::getBalast() {
	return Balast;
}

void eRoad::setBalast(string balast) {
	Balast = balast;
}

double eRoad::getCatenaryVoltage(){
	return CatenaryVoltage;
}

void eRoad::setCatenaryVoltage(double catenaryVoltage) {
	CatenaryVoltage = catenaryVoltage;
}

bool eRoad::isIsMainLine() {
	return IsMainLine;
}

void eRoad::setIsMainLine(bool isMainLine) {
	IsMainLine = isMainLine;
}

string eRoad::getTravers(){
	return Travers;
}

void eRoad::setTravers(string travers) {
	Travers = travers;
}
