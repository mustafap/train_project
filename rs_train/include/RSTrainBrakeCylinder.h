/*
 * RSTrainBrakeCylinder.h
 *
 *  Created on: 18 Haz 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINBRAKECYLINDER_H_
#define RSTRAINBRAKECYLINDER_H_


class RSTrainBrakeCylinder;
class RSTrainControlValve;
class RSTrainVehicle;

/**
 * RSTrainBrakeCylinder
 *
 * Brake cylinder object for all vehicles
 */
class RSTrainBrakeCylinder {

private:

	/**
	 * Brake Cylinder Pressure
	 */
	double Pbc;

	/**
	 * Area
	 */
	double A;

	/**
	 * Movement in spring
	 */
	double dx;

	/**
	 * compression constant
	 */
	double k;

	/**
	 * First Efficiency
	 */
	double E1;

	/**
	 * Second Efficiency
	 */
	double E2;

	/**
	 * Length
	 */
	double l;

	/**
	 *  ??
	 */
	double u;

	/**
	 *  Force ??
	 */
	double F;

	/**
	 * Brake cylinder force
	 */
	double Fs;

	/**
	 * Compression length
	 */
	double CompLength;

	/**
	 * Velocity
	 */
	double V;

	/**
	 * Parent control valve
	 */
	RSTrainControlValve* controlValve;

	/**
	 * Parent vehicle
	 */
	RSTrainVehicle* parent;

	/**
	 * Checks Compression Condition of the brake cylinder
	 * @return bool
	 */
	bool CheckCompressionCondition();

	/**
	 * Calculates the force ??
	 */
	void CalcF();

	/**
	 * Calculates the brake cylinder force
	 */
	void CalcFs();

	/**
	 * Calculates ??
	 */
	void CalcU();

public:

	/**
	 * Constructor of RSTrainBrakeCylinder.
	 * This constructor has to take the parent vehicle and parent control valve.
	 * @param parent
	 * @param controlValve
	 */
	RSTrainBrakeCylinder(RSTrainVehicle* parent ,RSTrainControlValve* controlValve);

	/**
	 * Destructor of RSTrainBrakeCylinder
	 */
	virtual ~RSTrainBrakeCylinder();

	/**
	 * Calculates Air Brake Force
	 */
	void CalcAirBrakeForce();

	/**
	 * Returns air brakeforce
	 * @return air brake force
	 */
	double getAirBrakeForce();

	double getDx();
};

#endif /* RSTRAINBRAKECYLINDER_H_ */
