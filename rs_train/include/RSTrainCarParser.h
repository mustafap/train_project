/*
 * RSTrainCarParser.h
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINCARPARSER_H_
#define RSTRAINCARPARSER_H_

#include "RSTrainParser.h"

class RSTrainCarParser;
class RSTrainCar;

/**
 * RSTrainCarParser
 *
 * Car creator of the system
 * The parser class is capable of read the given xml file and create corresponding car and return it.
 * The class has a singleton pattern design because it is not necessary to create more than one.
 */
class RSTrainCarParser: public RSTrainParser<RSTrainCar> {

private:
	/**
	 * Static instance of the parser class itself.
	 */
	static RSTrainCarParser* instance;

	/**
	 * Private constructor of the parser class.
	 */
	RSTrainCarParser();
public:

	/**
	 * Destructor of the parser.
	 */
	virtual ~RSTrainCarParser();

	/**
	 * Returns the static instance of the car parser object
	 * @return car parser
	 */
	static RSTrainCarParser* getInstance();

	/**
	 * Reads given xml file, creates corresponding car object and returns it.
	 * @param xmlFileName
	 * @return car
	 */
	RSTrainCar* spawnFromXML(string xmlFileName);
};

#endif /* RSTRAINCARPARSER_H_ */
