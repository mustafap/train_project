/*
 * RSTrainRailwayElementParser.cpp
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainRailwayElementParser.h"
#include "RailwayElement.h"
#include <iostream>
using namespace std;

RSTrainRailwayElementParser* RSTrainRailwayElementParser::instance = 0;

RSTrainRailwayElementParser::RSTrainRailwayElementParser() {

}

RSTrainRailwayElementParser* RSTrainRailwayElementParser::getInstance() {
	if(RSTrainRailwayElementParser::instance==0)
		return new RSTrainRailwayElementParser();
	else
		return RSTrainRailwayElementParser::instance;
}


RSTrainRailwayElementParser::~RSTrainRailwayElementParser() {
}


RailwayElement* RSTrainRailwayElementParser::spawnFromXML(string xmlFileName) {

	pugi::xml_document doc;
	if(!doc.load_file(xmlFileName.c_str()))
		cout<<"File was not Found !!"<<endl;

	pugi::xml_node RailwayElementNode = doc.child("RailwayElement");
	RailwayElement* railwayelement = new RailwayElement(RailwayElementNode);
	return railwayelement;
}
