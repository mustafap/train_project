/*
 * RSTrainCar.h
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINCAR_H_
#define RSTRAINCAR_H_

#include "RSTrainVehicle.h"
class RSTrainCar;
class RSTrainVehicle;

/**
 * RSTrainCar
 * Represents vagon object of a train
 * This class are derived from RSTrainVehicle class and pure virtual functions must be implemented
 */
class RSTrainCar: public RSTrainVehicle {

private:

public:

	/**
	 * Constructor of RSTrainCar object
	 */
	RSTrainCar();

	/**
	 * Destructor of RSTrainCar object
	 */
	virtual ~RSTrainCar();


	/**
	 * Calculates the rolling resistance force for car. output is in N.
	 * Depends on mass, velocity
	 */
	void calcCarRollingResistence();

	/**
	 * Calculates total force on the vagon
	 */
	void calcTotalForce();

	/**
	 * Calculates effective forces ,including  air brake forces, and compares with adherance
	 * force to decide whether the calculated force must be applied to the vagon or not.
	 */
	void calcEffectiveForceWithAdherance();

	/**
	 * Adds the coupling forces, obtained from frontCoupling and rearCoupling, to the total force
	 */
	void calcCouplingForcesOnTheVehicle();

	/**
	 * Adds physical forces - rolling resistance force, curve resistance force, ramp resistance force- to the total force
	 */
	void calcPhysicalForcesOnTheVehicle();

	/**
	 * Calculates Brake Force depending on brake pipe pressure by updating control valve and brake cylinder values
	 * @param dt
	 */
	void calcPipeBrakeForce(double dt);

	/**
	 * Updates variables of a car such as velocity, coefficient of friction
	 * @param dt
	 */
	void updateVariables(double dt);



	/**
	 * Calculates all forces such as ramp resistance, curve resistance etc.
	 * @param dt
	 */
	void calcForce(double dt);
};

#endif /* RSTRAINCAR_H_ */
