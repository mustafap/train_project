/*
 * RSTrainCarRollingResistanceCalculator.h
 *
 *  Created on: 15 Tem 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINCARROLLINGRESISTANCECALCULATOR_H_
#define RSTRAINCARROLLINGRESISTANCECALCULATOR_H_

#include "RSTrainRollingResistanceCalculator.h"
/*
 *
 */
class RSTrainCarRollingResistanceCalculator;
class RSTrainRollingResistanceCalculator;
class RSTrainCar;

/**
 * RSTrainCarRollingResistanceCalculator
 *
 * Derived class from RSTrainRollingResistanceCalculator
 * Supporter class to calculate rolling resistance of a car object
 * This class must implement pure virtual functions inherited from RSTrainRollingResistanceCalculator
 */
class RSTrainCarRollingResistanceCalculator :public RSTrainRollingResistanceCalculator{
private:

	/**
	 * Parent object
	 */
	RSTrainCar* parent;
public:


	/**
	 * Constructor of RSTrainCarRollingResistanceCalculator
	 * @param parent
	 */
	RSTrainCarRollingResistanceCalculator(RSTrainCar* parent);

	/**
	 * Destructor of RSTrainCarRollingResistanceCalculator
	 */
	virtual ~RSTrainCarRollingResistanceCalculator();

	/**
	 * Getter
	 * @return
	 */
	RSTrainCar* getParent();

	/**
	 * Setter
	 * @param parent
	 */
	void setParent(RSTrainCar* parent);

	/**
	 * Calculates rolling resistance for a car and returns calculated value
	 * @return
	 */
	double CalculateRollingResistance();

};

#endif /* RSTRAINCARROLLINGRESISTANCECALCULATOR_H_ */
