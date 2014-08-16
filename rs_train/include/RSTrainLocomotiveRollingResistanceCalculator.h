/*
 * RSTrainLocomotiveRollingResistanceCalculator.h
 *
 *  Created on: 15 Tem 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINLOCOMOTIVEROLLINGRESISTANCECALCULATOR_H_
#define RSTRAINLOCOMOTIVEROLLINGRESISTANCECALCULATOR_H_

#include "RSTrainRollingResistanceCalculator.h"


class RSTrainLocomotiveRollingResistanceCalculator;
class RSTrainRollingResistanceCalculator;
class RSTrainLocomotive;

/**
 * RSTrainLocomotiveRollingResistanceCalculator
 *
 * Derived class from RSTrainRollingResistanceCalculator
 * Supporter class to calculate rolling resistance of a locomotive object
 * This class must implement pure virtual functions inherited from RSTrainRollingResistanceCalculator
 */
class RSTrainLocomotiveRollingResistanceCalculator : public RSTrainRollingResistanceCalculator{

private:

	/**
	 * Parent object
	 */
	RSTrainLocomotive* parent;
public:

	/**
	 * Constructor of RSTrainLocomotiveRollingResistanceCalculator
	 * @param parent
	 */
	RSTrainLocomotiveRollingResistanceCalculator(RSTrainLocomotive* parent);

	/**
	 * Destructor of RSTrainLocomotiveRollingResistanceCalculator
	 */
	virtual ~RSTrainLocomotiveRollingResistanceCalculator();

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
	 * Calculates rolling resistance for a locomotive and returns calculated value
	 * @return
	 */
	double CalculateRollingResistance();

};

#endif /* RSTRAINLOCOMOTIVEROLLINGRESISTANCECALCULATOR_H_ */
