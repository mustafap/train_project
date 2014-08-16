/*
 * RSTrainDynamicBrakeForceCalculator.h
 *
 *  Created on: 15 Tem 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINDYNAMICBRAKEFORCECALCULATOR_H_
#define RSTRAINDYNAMICBRAKEFORCECALCULATOR_H_

class RSTrainDynamicBrakeForceCalculator;
class RSTrainLocomotive;

/**
 * RSTrainDynamicBrakeForceCalculator
 *
 * Supporter class to calculate dynamic brake force of a locomotive
 */
class RSTrainDynamicBrakeForceCalculator {

private:

	/**
	 * Parent locomotive
	 */
	RSTrainLocomotive* parent;
public:

	/**
	 * Constructor of RSTrainDynamicBrakeForceCalculator
	 * @param parent
	 */
	RSTrainDynamicBrakeForceCalculator(RSTrainLocomotive* parent);

	/**
	 * Destructor of RSTrainDynamicBrakeForceCalculator
	 */
	virtual ~RSTrainDynamicBrakeForceCalculator();

	/**
	 * Getter
	 * @return parent
	 */
	RSTrainLocomotive* getParent();

	/**
	 * Setter
	 * @param parent
	 */
	void setParent(RSTrainLocomotive* parent);

	/**
	 * Calculates dynamic brake force and returns calculated value
	 * @return dynamic brake force
	 */
	double CalculateDynamicBrakeForce();

};

#endif /* RSTRAINDYNAMICBRAKEFORCECALCULATOR_H_ */
