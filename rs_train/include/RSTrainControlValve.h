/*
 * RSTrainControlValve.h
 *
 *  Created on: 26 May 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINCONTROLVALVE_H_
#define RSTRAINCONTROLVALVE_H_

class RSTrainControlValve;
class RSTrainVehicle;

/**
 * RSTrainControlValve
 *
 * The class that controls brake cylinder pressures depending on brake pipe pressure for an induvidial vagon or locomotive
 */
class RSTrainControlValve {

protected:

	/**
	 * Parent vehicle
	 */
	RSTrainVehicle* parent;

	/**
	 * Auxilary Reservoir Pressure
	 */
	double ARPressure;

	/**
	 * Brake Cylinder Pressure
	 */
	double BCPressure;

	/**
	 * Brake Pipe Pressure
	 */
	double BPPressure;

	/**
	 * Bool variable to control whether auxilary reservoir pressure is equal to brake pipe pressure
	 */
	bool isEqualied;

	/**
	 * Bool variable to check whether control valve is triggered or not
	 */
	bool triggered;

	/**
	 * FlotConstant for control valve (ATM/sec)
	 */
	double flowConstant;

	double flowConstantPassanger;

	double flowConstantGood;
	/**
	 * Difference variable between auxilary reservoir and brake pipe pressure
	 */
	double diff;

	/**
	 * Error pressure value
	 */
	double err;

	/**
	 * Pressure flow direction variable
	 */
	int direction;

	/**
	 * Flow direction GOUP
	 */
	int GOUP;

	/**
	 * Flow direction GODOWN
	 */
	int GODOWN;

	/**
	 * Fault State of the control valve
	 */
	int faultState;

	/**
	 * Calculates the difference between auxilary reservoir and brake pipe pressure
	 */
	void CalcDifferences();

	/**
	 * Check whether the difference condition is satisfied or not
	 */
	void CheckDifference();
public:

	/**
	 * Constructor of RSTrainControlValve
	 * @param parent
	 */
	RSTrainControlValve(RSTrainVehicle* parent);

	/**
	 * Destructor of RSTrainControlValve
	 */
	virtual ~RSTrainControlValve();

	/**
	 * Getter
	 * @return
	 */
	double getArPressure();

	/**
	 * Setter
	 * @param arPressure
	 */
	void setArPressure(double arPressure);

	/**
	 * Returns Brake Cylinder Pressure
	 * @return
	 */
	virtual double getBcPressure();

	/**
	 * Getter
	 * @return
	 */
	double getBpPressure();

	/**
	 * Setter
	 * @param bpPressure
	 */
	void setBpPressure(double bpPressure);

	/**
	 * Setter
	 * @param bcPressure
	 */
	void setBcPressure(double bcPressure);

	/**
	 * Getter
	 * @return
	 */
	RSTrainVehicle* getParent();

	/**
	 * Setter
	 * @param parent
	 */
	void setParent(RSTrainVehicle* parent);

	/**
	 * Calculates Pressures such as brake cylinder pressure, auxilary reservoir pressure
	 * @param dt
	 */
	virtual void CalcPressures(double dt);

	/**
	 * Fault state setter
	 * @param faultState
	 */
	void setFaultState(int faultState);

	/**
	 * Fault state getter
	 * @return
	 */
	int getFaultState();

	double getDiff();
	double getFlowConstant();
};

#endif /* RSTRAINCONTROLVALVE_H_ */
