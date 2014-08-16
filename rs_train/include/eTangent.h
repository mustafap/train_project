/*
 * eTangent.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef ETANGENT_H_
#define ETANGENT_H_

#include "pugixml.hpp"
using namespace std;

class eTangent;

class eTangent {

private:
	double Length;
	double BeginCoordinate;
	double EndCoordinate;
	double FOuter;
	double FInner;
	double FFlange;
public:
	eTangent();
	eTangent(pugi::xml_node& node);
	virtual ~eTangent();
	double getBeginCoordinate();
	void setBeginCoordinate(double beginCoordinate);
	double getEndCoordinate();
	void setEndCoordinate(double endCoordinate);
	double getFlange();
	void setFlange(double flange);
	double getInner();
	void setInner(double inner);
	double getOuter();
	void setOuter(double outer);
	double getLength();
	void setLength(double length);
};

#endif /* ETANGENT_H_ */
