/*
 * RSTrainCarParser.cpp
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainCarParser.h"
#include "RSTrainCar.h"
#include "pugixml.hpp"
#include <iostream>
using namespace std;


RSTrainCarParser* RSTrainCarParser::instance = 0;


RSTrainCarParser::RSTrainCarParser()
{
}

RSTrainCarParser* RSTrainCarParser::getInstance() {
	if( RSTrainCarParser::instance == 0)
		return new RSTrainCarParser();
	else
		return RSTrainCarParser::instance;
}

RSTrainCarParser::~RSTrainCarParser() {

}

RSTrainCar* RSTrainCarParser::spawnFromXML(string xmlFileName) {

	pugi::xml_document doc;
	if(!doc.load_file(xmlFileName.c_str()))
	{
		cout<<"XML File Load Error: "<<xmlFileName<<endl;
		return 0;
	}

	pugi::xml_node carNode = doc.child("Car");

	RSTrainCar*  car= new RSTrainCar();

	double massinkg = carNode.child("MassInKg").text().as_double();
	car->setMass(massinkg);

	double length = carNode.child("Length").text().as_double();
	car->setLength(length);

	double diameterofwheel = carNode.child("DiameterOfWheel").text().as_double();
	car->setDiameterOfWheel(diameterofwheel);

	return car;
}
