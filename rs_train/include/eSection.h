/*
 * eSection.h
 *
 *  Created on: 22 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef ESECTION_H_
#define ESECTION_H_

#include <vector>
#include "pugixml.hpp"
#include "eTangent.h"
#include "eCurve.h"
using namespace std;

class eSection;
class eTangent;
class eCurve;

class eSection {

private:
	vector<eTangent> Tangent;
	vector<eCurve> Curve;
	bool isCurve;
public:
	eSection();
	eSection(pugi::xml_node& node);
	virtual ~eSection();
	eCurve getCurve();
	void setCurve(eCurve curve);
	eTangent getTangent();
	void setTangent(eTangent tangent);
	bool isIsCurve() const;
	void setIsCurve(bool isCurve);
};

#endif /* ESECTION_H_ */
