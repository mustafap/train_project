/*
 * RSTrainLocomotiveParser.h
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINLOCOMOTIVEPARSER_H_
#define RSTRAINLOCOMOTIVEPARSER_H_

#include "RSTrainParser.h"

class RSTrainLocomotiveParser;
class RSTrainLocomotive;

/**
 * RSTrainLocomotiveParser
 *
 * Locomotive creator of the system
 * The parser class is capable of read the given xml file and create corresponding locomotive and return it.
 * The class has a singleton pattern design because it is not necessary to create more than one.
 */
class RSTrainLocomotiveParser: public RSTrainParser<RSTrainLocomotive> {


private:

	/**
	 * Static instance of the parser class itself.
	 */
	static RSTrainLocomotiveParser* instance;

	/**
	 * Private constructor of the parser class.
	 */
	RSTrainLocomotiveParser();

public:

	/**
	 * Destructor of the parser.
	 */
	virtual ~RSTrainLocomotiveParser();

	/**
	 * Returns the static instance of the locomotive parser object
	 * @return locomotive parser
	 */
	static RSTrainLocomotiveParser* getInstance();

	/**
	 * Reads given xml file, creates corresponding car object and returns it.
	 * @param xmlFileName
	 * @return locomotive
	 */
	RSTrainLocomotive* spawnFromXML(string xmlFileName);
};

#endif /* RSTRAINLOCOMOTIVEPARSER_H_ */
