/*
 * RSTrainBrakePipeParser.h
 *
 *  Created on: 16 Tem 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINBRAKEPIPEPARSER_H_
#define RSTRAINBRAKEPIPEPARSER_H_

#include "RSTrainParser.h"


class RSTrainBrakePipeParser;
class RSTrainBrakePipePressureUpdater;

/**
 * RSTrainBrakePipeParser
 *
 * Brake pipe pressure update creator of the system
 * The parser class is capable of read the given xml file and create corresponding pipe updater and return it.
 * The class has a singleton pattern design because it is not necessary to create more than one.
 */
class RSTrainBrakePipeParser: public RSTrainParser<RSTrainBrakePipePressureUpdater> {

private:
	/**
	 * Static instance of the parser class itself.
	 */
	static RSTrainBrakePipeParser* instance;

	/**
	 * Private constructor of the parser class.
	 */
	RSTrainBrakePipeParser();
public:

	/**
	 * Destructor of the parser.
	 */
	virtual ~RSTrainBrakePipeParser();

	/**
	 * Returns the static instance of the pipeparser object
	 * @return pipeparser
	 */
	static RSTrainBrakePipeParser* getInstance();

	/**
	 * Reads given xml file, creates corresponding pipe pressure updater object and returns it.
	 * @param xmlFileName
	 * @return brake pipe pressure updater
	 */
	RSTrainBrakePipePressureUpdater* spawnFromXML(string xmlFileName);
};

#endif /* RSTRAINBRAKEPIPEPARSER_H_ */
