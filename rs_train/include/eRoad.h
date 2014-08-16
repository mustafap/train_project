/*
 * eRoad.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EROAD_H_
#define EROAD_H_

#include "pugixml.hpp"
#include "eVerticalProfile.h"
#include "eSection.h"
#include "eSign.h"
#include "eSignal.h"
#include "eMagnet.h"
#include "eBalise.h"
#include "eBlock.h"
#include "eLevelCrossing.h"
#include "ePhysicalBuilding.h"
using namespace std;

class eRoad;
class eVerticalProfile;
class eSection;
class eSign;
class eSignal;
class eMagnet;
class eBalise;
class eBlock;
class eLevelCrossing;
class ePhysicalBuilding;

class eRoad {

private:
	int GlobalID;
	double LateralOffsetBegin;
	double LateralOffsetEnd;
	double Length;
	int NextConnectedSwitchID;
	int NextConnectedRoadID;
	int PrevConnectedRoadID;
	int PrevConnectedSwitchID;
	double BeginCoordinate;
	double EndCoordinate;
	bool HasCatenaryLine;
	double CatenaryVoltage;
	bool IsMainLine;
	string Balast;
	string Travers;
	vector<eVerticalProfile> VerticalProfile;
	vector<eSection> Section;
	vector<eSign> Sign;
	vector<eSignal> Signal;
	vector<eMagnet> Magnet;
	vector<eBalise> Balise;
	vector<eBlock> Block;
	vector<eLevelCrossing> LevelCrossing;
	vector<ePhysicalBuilding> PhysicalBuilding;
public:
	eRoad();
	eRoad(pugi::xml_node& node);
	virtual ~eRoad();

	vector<eBalise>& getBalise();
	void setBalise(vector<eBalise>& balise);
	double getBeginCoordinate();
	void setBeginCoordinate(double beginCoordinate);
	vector<eBlock>& getBlock();
	void setBlock(vector<eBlock>& block);
	double getEndCoordinate();
	void setEndCoordinate(double endCoordinate);
	int getGlobalId();
	void setGlobalId(int globalId);
	bool isHasCatenaryLine();
	void setHasCatenaryLine(bool hasCatenaryLine);
	double getLateralOffsetBegin();
	void setLateralOffsetBegin(double lateralOffsetBegin);
	double getLateralOffsetEnd();
	void setLateralOffsetEnd(double lateralOffsetEnd);
	double getLength();
	void setLength(double length);
	vector<eLevelCrossing>& getLevelCrossing();
	void setLevelCrossing(vector<eLevelCrossing>& levelCrossing);
	vector<eMagnet>& getMagnet();
	void setMagnet(vector<eMagnet>& magnet);
	int getNextConnectedRoadId();
	void setNextConnectedRoadId(int nextConnectedRoadId);
	int getNextConnectedSwitchId();
	void setNextConnectedSwitchId(int nextConnectedSwitchId);
	vector<ePhysicalBuilding>& getPhysicalBuilding();
	void setPhysicalBuilding(vector<ePhysicalBuilding>& physicalBuilding);
	int getPrevConnectedRoadId();
	void setPrevConnectedRoadId(int prevConnectedRoadId);
	int getPrevConnectedSwitchId();
	void setPrevConnectedSwitchId(int prevConnectedSwitchId);
	vector<eSection>& getSection();
	void setSection(vector<eSection>& section);
	vector<eSign>& getSign();
	void setSign(vector<eSign>& sign);
	vector<eSignal>& getSignal();
	void setSignal(vector<eSignal>& signal);
	vector<eVerticalProfile>& getVerticalProfile();
	void setVerticalProfile(vector<eVerticalProfile>& verticalProfile);
	string getBalast();
	void setBalast(string balast);
	double getCatenaryVoltage();
	void setCatenaryVoltage(double catenaryVoltage);
	bool isIsMainLine();
	void setIsMainLine(bool isMainLine);
	string getTravers();
	void setTravers(string travers);

	eVerticalProfile& geteVerticalProfile(int index);
	void addeVerticalProfile(eVerticalProfile everticalProfile);
	void seteVerticalProfile(eVerticalProfile everticalProfile,int index);
	int getVerticalProfileSize();

	eSection& geteSection(int index);
	void addeSection(eSection esection);
	void seteSection(eSection esection,int index);
	int getSectionSize();

	eSign& geteSign(int index);
	void addeSign(eSign esign);
	void seteSign(eSign esign,int index);
	int getSignSize();

	eSignal& geteSignal(int index);
	void addeSignal(eSignal esignal);
	void seteSignal(eSignal esignal,int index);
	int getSignalSize();

	eMagnet& geteMagnet(int index);
	void addeMagnet(eMagnet emagnet);
	void seteMagnet(eMagnet emagnet,int index);
	int getMagnetSize();

	eBalise& geteBalise(int index);
	void addeBalise(eBalise ebalise);
	void seteBalise(eBalise ebalise,int index);
	int getBaliseSize();

	eBlock& geteBlock(int index);
	void addeBlock(eBlock eblock);
	void seteBlock(eBlock eblock,int index);
	int getBlockSize();

	eLevelCrossing& geteLevelCrossing(int index);
	void addeLevelCrossing(eLevelCrossing elevelCrossing);
	void seteLevelCrossing(eLevelCrossing elevelCrossing,int index);
	int getLevelCrossingSize();

	ePhysicalBuilding& getePhysicalBuilding(int index);
	void addePhysicalBuilding(ePhysicalBuilding ephysicalBuilding);
	void setePhysicalBuilding(ePhysicalBuilding ephysicalBuilding,int index);
	int getPhysicalBuildingSize();


};

#endif /* EROAD_H_ */
