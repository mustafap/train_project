/*
 * RSTrainLocomotiveControlValve.h
 *
 *  Created on: 8 Tem 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINLOCOMOTIVECONTROLVALVE_H_
#define RSTRAINLOCOMOTIVECONTROLVALVE_H_
#include "RSTrainControlValve.h"
/*
 *
 */

class RSTrainLocomotiveControlValve;
class RSTrainControlValve;
class RSTrainVehicle;
class RSTrainLocomotive;

/**
 * RSTrainLocomotiveControlValve
 *
 * Derived class from RSTrainControlValve
 * Control valve for locomotive objects, this class adds moderable control to the controller
 */
class RSTrainLocomotiveControlValve : public RSTrainControlValve {

private:

	/**
	 * Locomotive parent
	 */
	RSTrainLocomotive* locomotive_parent;

	/**
	 * Moderable pressure value
	 */
	double moderablePressure;

	/**
	 * Moderable decrease pressure rate
	 */
	double decreasePressureRate;

	/**
	 * Modearable increase pressure rate
	 */
	double increasePressureRate;

	/**
	 * Moderable maximum pressure rate
	 */
	double maxIncreasePressureRate;

	/**
	 * Moderable maximum pressure
	 */
	double maxModerablePressure;
public:

	/**
	 * Contructor of RSTrainLocomotiveControlValve
	 * @param parent
	 */
	RSTrainLocomotiveControlValve(RSTrainVehicle* parent);

	/**
	 * Destructor of RSTrainLocomotiveControlValve
	 */
	virtual ~RSTrainLocomotiveControlValve();

	/**
	 * Calculates Pressures such as brake cylinder pressure, auxilary reservoir pressure
	 * Also calculates moderable pressure
	 * @param dt
	 */
	void CalcPressures(double dt);

	/**
	 * Returns brake cylinder pressure by checking the purger state and by comparing control valve pressure and moderable pressure
	 * @return
	 */
	double getBcPressure();

	/**
	 * Calculates moderable pressure
	 * @param dt
	 */
	void CalcModerablePressure(double dt);

	/**
	 * Calculates moderable pressure for given change rate
	 * @param dt
	 * @param rate
	 */
	void CalcModerablePressureForGivenRate(double dt,double rate);


	double getDecreasePressureRate();
	void setDecreasePressureRate(double decreasePressureRate);

	double getIncreasePressureRate();
	void setIncreasePressureRate(double increasePressureRate);

	double getMaxIncreasePressureRate();
	void setMaxIncreasePressureRate(double maxIncreasePressureRate);

	double getMaxModerablePressure();
	void setMaxModerablePressure(double maxModerablePressure);

	double getModerablePressure();
	void setModerablePressure(double moderablePressure);
};

#endif /* RSTRAINLOCOMOTIVECONTROLVALVE_H_ */
