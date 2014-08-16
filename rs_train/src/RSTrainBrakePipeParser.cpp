/*
 * RSTrainBrakePipeParser.cpp
 *
 *  Created on: 16 Tem 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainBrakePipeParser.h"
#include "RSTrainBrakePipePressureUpdater.h"
#include "pugixml.hpp"
#include <iostream>
#include <string>
using namespace std;

RSTrainBrakePipeParser* RSTrainBrakePipeParser::instance = 0;

RSTrainBrakePipeParser::RSTrainBrakePipeParser() :
		RSTrainParser() {
	// TODO Auto-generated constructor stub

}

RSTrainBrakePipeParser* RSTrainBrakePipeParser::getInstance() {

	if (RSTrainBrakePipeParser::instance == 0) {
		return new RSTrainBrakePipeParser();
	} else {
		return RSTrainBrakePipeParser::instance;
	}
}
RSTrainBrakePipeParser::~RSTrainBrakePipeParser() {
	// TODO Auto-generated destructor stub
}

RSTrainBrakePipePressureUpdater* RSTrainBrakePipeParser::spawnFromXML(
		string xmlFileName) {

	pugi::xml_document doc;

	if (!doc.load_file(xmlFileName.c_str())) {
		cout << "XML-File Load Error :" << xmlFileName << endl;
		return 0;
	}

	RSTrainBrakePipePressureUpdater* bp = new RSTrainBrakePipePressureUpdater();

	pugi::xml_node BrakePipe = doc.child("BrakePipe");

	double nominalPressure =
			BrakePipe.child("nominalPressure").text().as_double();
	bp->setNominalPressure(nominalPressure);

	double minPressure = BrakePipe.child("minPressure").text().as_double();
	bp->setMinPressure(minPressure);

	double maxPressure = BrakePipe.child("maxPressure").text().as_double();
	bp->setMaxPressure(maxPressure);

	double overLoadPressure =
			BrakePipe.child("overLoadPressure").text().as_double();
	bp->setOverLoadPressure(overLoadPressure);

	double pressureLapReleaseRate =
			BrakePipe.child("pressureLapReleaseRate").text().as_double();
	bp->setPressureLapReleaseRate(pressureLapReleaseRate);

	double pressureLapServiceRate =
			BrakePipe.child("pressureLapServiceRate").text().as_double();
	bp->setPressureLapServiceRate(pressureLapServiceRate);

	double pressureReleaseRate =
			BrakePipe.child("pressureReleaseRate").text().as_double();
	bp->setPressureReleaseRate(pressureReleaseRate);

	double pressureServiceRate =
			BrakePipe.child("pressureServiceRate").text().as_double();
	bp->setPressureServiceRate(pressureServiceRate);

	double k = BrakePipe.child("k").text().as_double();
	bp->setK(k);

	return bp;
}

