/*
 * eCurve.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef ECURVE_H_
#define ECURVE_H_

#include "pugixml.hpp"
using namespace std;

class eCurve;

class eCurve {

private:
	double Length;
	double TransientBegin;
	double TransientEnd;
	double BeginCoordinate;
	double EndCoordinate;
	double CurveRadious;
	bool IsLeft;
	double Cant;
	double Widening;
	double StartSideFriction;
	double EndSideFriction;
	double FOuter;
	double FInner;
	double FFlange;
public:
	eCurve();
	eCurve(pugi::xml_node& node);
	virtual ~eCurve();
	double getBeginCoordinate();
	void setBeginCoordinate(double beginCoordinate);
	double getCant();
	void setCant(double cant);
	double getCurveRadious();
	void setCurveRadious(double curveRadious);
	double getEndCoordinate();
	void setEndCoordinate(double endCoordinate);
	double getEndSideFriction();
	void setEndSideFriction(double endSideFriction);
	double getFlange();
	void setFlange(double flange);
	double getInner();
	void setInner(double inner);
	double getOuter();
	void setOuter(double outer);
	bool isIsLeft();
	void setIsLeft(bool isLeft);
	double getLength();
	void setLength(double length);
	double getStartSideFriction();
	void setStartSideFriction(double startSideFriction);
	double getTransientBegin();
	void setTransientBegin(double transientBegin);
	double getTransientEnd();
	void setTransientEnd(double transientEnd);
	double getWidening();
	void setWidening(double widening);
};

#endif /* ECURVE_H_ */
