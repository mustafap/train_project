/*
 * RSTrainLocomotiveParser.cpp
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainLocomotiveParser.h"
#include "RSTrainLocomotive.h"
#include "pugixml.hpp"
#include <iostream>
using namespace std;
RSTrainLocomotiveParser* RSTrainLocomotiveParser::instance = 0;


RSTrainLocomotiveParser::RSTrainLocomotiveParser()
				:RSTrainParser()
{

}

RSTrainLocomotiveParser* RSTrainLocomotiveParser::getInstance() {
	if( RSTrainLocomotiveParser::instance == 0)
		return new RSTrainLocomotiveParser();
	else
		return RSTrainLocomotiveParser::instance;
}


RSTrainLocomotiveParser::~RSTrainLocomotiveParser() {

}



RSTrainLocomotive* RSTrainLocomotiveParser::spawnFromXML(string xmlFileName) {

	pugi::xml_document doc;
	if(!doc.load_file(xmlFileName.c_str()))
	{
		cout<<"XML-File Load Error : "<<xmlFileName<<endl;
		return 0;
	}

	pugi::xml_node E43000 = doc.child("E43000");

	RSTrainLocomotive* loco = new RSTrainLocomotive();

	double massinkg = E43000.child("MassInKg").text().as_double();
	loco->setMass(massinkg);

	double length = E43000.child("Length").text().as_double();
	loco->setLength(length);

	double diameterofwheel = E43000.child("DiameterOfWheel").text().as_double();
	loco->setDiameterOfWheel(diameterofwheel);

	int numberofaxles = E43000.child("NumberOfAxles").text().as_int();
	loco->setNumberAxles(numberofaxles);

	int brakeCylinderCount = E43000.child("BrakeCylinderCount").text().as_int();
	loco->setBrakeCylinderCount(brakeCylinderCount);

	return loco;


}
