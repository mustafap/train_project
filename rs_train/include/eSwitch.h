/*
 * eSwitch.h
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef ESWITCH_H_
#define ESWITCH_H_

#include <string>
#include <vector>
#include "pugixml.hpp"
#include "eBSwitch.h"
#include "eCSwitch.h"
#include "eSSwitch.h"
#include "eVSwitch.h"
using namespace std;

class eSwitch;
class eBSwitch;
class eCSwitch;
class eSSwitch;
class eVSwitch;

class eSwitch {

private:
	int GlobalID;
	string Type;
	string State1;
	string State2;
	vector<eBSwitch> BSwitch;
	vector<eCSwitch> CSwitch;
	vector<eSSwitch> SSwitch;
	vector<eVSwitch> VSwitch;

public:
	eSwitch();
	eSwitch(pugi::xml_node& node);
	virtual ~eSwitch();
	vector<eBSwitch>& getBSwitch();
	void setBSwitch(vector<eBSwitch>& _switch);
	vector<eCSwitch>& getCSwitch();
	void setCSwitch(vector<eCSwitch>& _switch);
	int getGlobalId();
	void setGlobalId(int globalId);
	vector<eSSwitch>& getSSwitch();
	void setSSwitch(vector<eSSwitch>& _switch);
	string& getState1();
	void setState1(string& state1);
	string& getState2();
	void setState2(string& state2);
	string& getType();
	void setType(string& type);
	vector<eVSwitch>& getVSwitch();
	void setVSwitch(vector<eVSwitch>& _switch);

	eBSwitch& geteBSwitch();
	void seteBSwitch(eBSwitch _eSwitch);

	eCSwitch& geteCSwitch();
	void seteCSwitch(eCSwitch _eCSwitch);

	eSSwitch& geteSSwitch();
	void seteSSwitch(eSSwitch _eSSwitch);

	eVSwitch& geteVSwitch();
	void seteVSwitch(eVSwitch _eVSwitch);

};

#endif /* ESWITCH_H_ */
