/*
 * RSTrainRailwayElementParser.h
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINRAILWAYELEMENTPARSER_H_
#define RSTRAINRAILWAYELEMENTPARSER_H_

#include "RSTrainParser.h"
#include "RailwayElement.h"

class RSTrainRailwayElementParser;
class RailwayElement;

/**
 * RSTrainRailwayElementParser
 *
 * RailwayElement creator of the system
 * The parser class is capable of read the given xml file and create corresponding rail road and return it.
 * The class has a singleton pattern design because it is not necessary to create more than one.
 */
class RSTrainRailwayElementParser: public RSTrainParser<RailwayElement> {
private:
	/**
	 * Static instance of the parser class itself.
	 */
	static RSTrainRailwayElementParser* instance;
	/**
	 * Private constructor of the parser class.
	 */
	RSTrainRailwayElementParser();
public:

	/**
	 * Destructor of the parser.
	 */
	virtual ~RSTrainRailwayElementParser();

	/**
	 * Returns the static instance of the rail road parser object
	 * @return rail road
	 */
	static RSTrainRailwayElementParser* getInstance();

	/**
	 * Reads given xml file, creates corresponding railroad object and returns it.
	 * @param xmlFileName
	 * @return car
	 */
	RailwayElement* spawnFromXML(string xmlFileName);

};

#endif /* RSTRAINRAILWAYELEMENTPARSER_H_ */
