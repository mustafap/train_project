/*
 * RSTrainRollingResistanceCalculator.h
 *
 *  Created on: 15 Tem 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINROLLINGRESISTANCECALCULATOR_H_
#define RSTRAINROLLINGRESISTANCECALCULATOR_H_

/**
 * RSTrainRollingResistanceCalculator
 *
 * Abstract base class to calculate rolling resistance of a vehicle
 * Derived class from this class must implement pure virtual functions
 */
class RSTrainRollingResistanceCalculator {
public:

	/**
	 * Constructor of RSTrainRollingResistanceCalculator
	 */
	RSTrainRollingResistanceCalculator(){};

	/**
	 * Destructor of RSTrainRollingResistanceCalculator
	 */
	virtual ~RSTrainRollingResistanceCalculator(){}

	/**
	 * Pure virtual function to calculate rolling resistance
	 * @return
	 */
	virtual double CalculateRollingResistance() =0;
};

#endif /* RSTRAINROLLINGRESISTANCECALCULATOR_H_ */
