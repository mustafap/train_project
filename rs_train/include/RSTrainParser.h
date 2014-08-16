/*
 * RSTrainParser.h
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINPARSER_H_
#define RSTRAINPARSER_H_
#include <string>
using namespace std;


template<class T>
/**
 * Abstract Base class for parser classes
 * All derived classes must implement pure virtual function of this class
 */
class RSTrainParser {

public:

	virtual ~RSTrainParser() {}

	/**
	 * Pure virtual parser function
	 * @param xmlFileName
	 * @return
	 */
	virtual T* spawnFromXML(string xmlFileName) = 0;
};

#endif /* RSTRAINPARSER_H_ */
