/*
 * RailwayElement.h
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef RAILWAYELEMENT_H_
#define RAILWAYELEMENT_H_

#include <vector>
#include "pugixml.hpp"
#include "eRoad.h"
#include "eRegion.h"
#include "ePhysicalObjects.h"
#include "eIG.h"
#include "eSwitch.h"
using namespace std;

class RailwayElement;
class eRoad;
class eRegion;
class ePhysicalObjects;
class eIG;
class eSwitch;

class RailwayElement {

private:
	vector<eRoad> Road;
	vector<eRegion> Region;
	vector<ePhysicalObjects> PhysicalObjects;
	vector<eIG> IG;
	vector<eSwitch> Switch;
public:
	RailwayElement();
	RailwayElement(pugi::xml_node& node);
	virtual ~RailwayElement();
	vector<eIG>& getIg();
	void setIg(vector<eIG>& ig);
	vector<ePhysicalObjects>& getPhysicalObjects();
	void setPhysicalObjects(vector<ePhysicalObjects>& physicalObjects);
	vector<eRegion>& getRegion();
	void setRegion(vector<eRegion>& region);
	vector<eRoad>& getRoad();
	void setRoad(vector<eRoad>& road);
	vector<eSwitch>& getSwitch();
	void setSwitch(vector<eSwitch>& _switch);

	eRoad& geteRoad(int index);
	eRoad& geteRoadFromGlobalID(int globalID);
	void addeRoad(eRoad eroad);
	void seteRoad(eRoad eroad,int index);
	int getRoadSize();

	eRegion& geteRegion(int index);
	void addeRegion(eRegion eregion);
	void seteRegion(eRegion eregion,int index);
	int getRegionSize();

	ePhysicalObjects& getePhysicalObjects(int index);
	void addePhysicalObjects(ePhysicalObjects ephysicalObjects);
	void setePhysicalObjects(ePhysicalObjects ephysicalObjects,int index);
	int getPhysicalObjectsSize();

	eIG& geteIG(int index);
	void addeIG(eIG eig);
	void seteIG(eIG eig,int index);
	int getIGSize();

	eSwitch& geteSwitch(int index);
	eSwitch& geteSwitchFromGlobalID(int globalID);
	void addeSwitch(eSwitch eswitch);
	void seteSwitch(eSwitch eswitch,int index);
	int getSwitchSize();

};

#endif /* RAILWAYELEMENT_H_ */
