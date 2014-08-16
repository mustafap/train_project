/*
 * RSTrainTractionForceCalculator.h
 *
 *  Created on: 15 Tem 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINTRACTIONFORCECALCULATOR_H_
#define RSTRAINTRACTIONFORCECALCULATOR_H_

class RSTrainTractionForceCalculator;
class RSTrainLocomotive;


/**
 * RSTrainTractionForceCalculator
 *
 * Supporter class to calculate traction force for a locomotive object
 */
class RSTrainTractionForceCalculator {

private:

	/**
	 * Parent object
	 */
	RSTrainLocomotive* parent;

public:

	/**
	 * Constructor of RSTrainTractionForceCalculator
	 * @param parent
	 */
	RSTrainTractionForceCalculator(RSTrainLocomotive* parent);

	/**
	 * Destructor of RSTrainTractionForceCalculator
	 */
	virtual ~RSTrainTractionForceCalculator();

	/**
	 * Getter
	 * @return
	 */
	RSTrainLocomotive* getParent();

	/**
	 * Setter
	 * @param parent
	 */
	void setParent(RSTrainLocomotive* parent);

	/**
	 * Calculates traction force for its parent and returns calculates force value
	 * @return
	 */
	double CalculateTractionForce();

};

#endif /* RSTRAINTRACTIONFORCECALCULATOR_H_ */
