/*
 * eVerticalProfile.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef EVERTICALPROFILE_H_
#define EVERTICALPROFILE_H_

#include "pugixml.hpp"
using namespace std;

class eVerticalProfile;

class eVerticalProfile {

private:
	double Length;
	double PrevSCPPosition;
	double NextSCPPosition;
	double Slope;
	double NextRadius;
	double PrevRadius;
	double PrevSlope;
	double NextSlope;
public:
	eVerticalProfile();
	eVerticalProfile(pugi::xml_node& node);
	virtual ~eVerticalProfile();
	double getLength();
	void setLength(double length);
	double getNextRadius();
	void setNextRadius(double nextRadius);
	double getNextScpPosition();
	void setNextScpPosition(double nextScpPosition);
	double getNextSlope();
	void setNextSlope(double nextSlope);
	double getPrevRadius();
	void setPrevRadius(double prevRadius);
	double getPrevScpPosition();
	void setPrevScpPosition(double prevScpPosition);
	double getPrevSlope();
	void setPrevSlope(double prevSlope);
	double getSlope();
	void setSlope(double slope);
};

#endif /* EVERTICALPROFILE_H_ */
