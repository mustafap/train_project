/*
 * RSTrainCoupling.h
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINCOUPLING_H_
#define RSTRAINCOUPLING_H_

class RSTrainCoupling;
class RSTrainVehicle;

/**
 * RSTrainCoupling
 *
 * Represent connection between two successive vagon
 */
class RSTrainCoupling {

private:



	/**
	 * Front vehicle instance
	 */
	RSTrainVehicle* frontVehicle;

	/**
	 * Back vehicle instance
	 */
	RSTrainVehicle* backVehicle;

public:

    /** had to move these variables from private to public did not compile
    /**
     * Previous Distance
     */
    double prevDistance;

    /**
     * Current Distance
     */
    double distance;

    /**
     * Coupling Force
     */
    double couplingForce;

    /**
     * Incremental / Decremantal spring constant
     */
    double Kinc , Kdec;

	/**
	 * Constructor of RSTrainCoupling
	 */



	RSTrainCoupling();

	/**
	 * Destructor of RSTrainCoupling
	 */
	virtual ~RSTrainCoupling();

	/**
	 * Getter
	 * @return
	 */
	RSTrainVehicle* getBackVehicle();

	/**
	 * Setter
	 * @param backVehicle
	 */
	void setBackVehicle( RSTrainVehicle* backVehicle);

	/**
	 * Getter
	 * @return
	 */
	double getCouplingForce();

	/**
	 * Setter
	 * @param couplingForce
	 */
	void setCouplingForce(double couplingForce);

	/**
	 * Getter
	 * @return
	 */
	double getDistance();

	/**
	 * Setter
	 * @param distance
	 */
	void setDistance(double distance);

	/**
	 * Getter
	 * @return
	 */
	RSTrainVehicle* getFrontVehicle();

	/**
	 * Setter
	 * @param frontVehicle
	 */
	void setFrontVehicle( RSTrainVehicle* frontVehicle);

	/**
	 * Calculates distance between two related vehicle
	 */
	virtual void calcDistance();

	/**
	 * Calculates compression or tension force on the coupling
	 */
	virtual void calcCouplingForce();

	double getKdec();
	double getKinc();
};

#endif /* RSTRAINCOUPLING_H_ */
