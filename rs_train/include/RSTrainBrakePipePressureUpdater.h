/*
 * RSTrainBrakePipePressureUpdater.h
 *
 *  Created on: 17 Nis 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTrainBrakePipePressureUpdater_H_
#define RSTrainBrakePipePressureUpdater_H_

#include <vector>
using namespace std;

class RSTrainBrakePipePressureUpdater;
class RSTrainVehicle;
class RSTrainLocomotive;

/**
 * RSTrainBrakePipePressureUpdater
 *
 * Calculates and Updates pipe pressure values all vehicles
 */
class RSTrainBrakePipePressureUpdater {

public:

	/**
	 * Default Constructor of the RSTrainBrakePipePressureUpdater
	 */
	RSTrainBrakePipePressureUpdater();

	/**
	 * Constructor of the RSTrainBrakePipePressureUpdater
	 * @param vehicle vector instance
	 */
	RSTrainBrakePipePressureUpdater(vector<RSTrainVehicle*>*);

	/**
	 * Destructor of the RSTrainBrakePipeUpdater
	 */
	virtual ~RSTrainBrakePipePressureUpdater();

	/**
	 * Initializes the vehicles to be updated
	 * @param vehicles
	 */
	void InitVehicles(vector<RSTrainVehicle*>* vehicles);

	/**
	 * Calculates brake pipe pressures of the vehicles for given time step.
	 * @param dt
	 */
	void calcBrakePipePressures(double dt);

	/**
	 * Replaces the brake pipe pressures with the new ones.
	 */
	void updateBrakePipePressures();

	/**
	 * Calculates the main locomotive pipe pressures for given time step.
	 * @param dt
	 */
	void calcFirstLocomotivePressure(double dt);

	/**
	 * Calculates the main locomotive pipe pressures for given time step and change rate.
	 * @param dt
	 * @param rate
	 */
	void calcFirstLocomotivePressureForGivenState(double dt,double rate);

	void calcRunforLocomotiveBrakePipePressure(double dt);

	void calcRunforLocomotivePressureForGivenState(double dt,double rate);

	/**
	 * Sets brake pipe fault state
	 * Faulty car must be indicated by car_index [0, vehicleNumber - 1]
	 * Fault state must be indicate by int variable, faultState [0,4]
	 * @param car_index
	 * @param faultState
	 */
	void setBrakePipeFault(int car_index,int faultState);

	/**
	 * Sets emergency brake state
	 * @param emergencyBrake
	 */
	void setEmergencyBrake(bool emergencyBrake);

	/**
	 * Getter
	 * @return current state
	 */
	int getCurrentState();

	/**
	 * Setter
	 * @param currentState
	 */
	void setCurrentState(int currentState);

	/**
	 * Emergency brake active or not
	 * @return
	 */
	bool isEmergencyBrake();

	/**
	 * Sets Leakage value for given car
	 * @param index
	 * @param leakage
	 */
	void setLeakage(int index, double leakage);

	/**
	 * Getter
	 * @return
	 */
	double getMaxPressure();

	/**
	 * Setter
	 * @param maxPressure
	 */
	void setMaxPressure(double maxPressure);

	/**
	 * Getter
	 * @return
	 */
	double getMinPressure();

	/**
	 * Setter
	 * @param minPressure
	 */
	void setMinPressure(double minPressure);

	/**
	 * Getter
	 * @return
	 */
	double getNominalPressure();

	/**
	 * Setter
	 * @param nominalPressure
	 */
	void setNominalPressure(double nominalPressure);

	/**
	 * Getter
	 * @return
	 */
	double getOverLoadPressure();

	/**
	 * Setter
	 * @param overLoadPressure
	 */
	void setOverLoadPressure(double overLoadPressure);

	/**
	 * Getter
	 * @return
	 */
	double getPressureLapReleaseRate();

	/**
	 * Setter
	 * @param pressureLapReleaseRate
	 */
	void setPressureLapReleaseRate(double pressureLapReleaseRate);

	/**
	 * Getter
	 * @return
	 */
	double getPressureLapServiceRate();

	/**
	 * Setter
	 * @param pressureLapServiceRate
	 */
	void setPressureLapServiceRate(double pressureLapServiceRate);

	/**
	 * Getter
	 * @return
	 */
	double getPressureReleaseRate();

	/**
	 * Setter
	 * @param pressureReleaseRate
	 */
	void setPressureReleaseRate(double pressureReleaseRate);

	/**
	 * Getter
	 * @return
	 */
	double getPressureServiceRate();

	/**
	 * Setter
	 * @param pressureServiceRate
	 */
	void setPressureServiceRate(double pressureServiceRate);

	/**
	 * Returns fault state of the car indicated by index.
	 * @param index
	 * @return
	 */
	int getFaultState(int index);

	/**
	 * Returns leakage value of the car indicated by index.
	 * @param index
	 * @return
	 */
	double getLeakage(int index);

	/**
	 * Getter
	 * @return
	 */
	double getK();

	/**
	 * Setter
	 * @param k
	 */
	void setK(double k);

	RSTrainLocomotive* getRunforLocomotive();
	void setRunforLocomotive(RSTrainLocomotive* runforLocomotive);



private:

	/**
	 * Pressure container
	 */
	vector<double> Pressures;

	int size;
	/**
	 * Vehicle Container instance
	 */
	vector<RSTrainVehicle*>*  Vehicles;

	/**
	 * Main Locomotive instance
	 */
	RSTrainLocomotive* firstLocomotive;

	RSTrainLocomotive* runforLocomotive;

	/**
	 * Nominal Pressure of the pipe
	 */
	double nominalPressure;

	/**
	 * Minimum Pressure of the pipe
	 */
	double minPressure;

	/**
	 * Maximum Pressure of the pipe
	 */
	double maxPressure;

	/**
	 * Over Load Pressure of the pipe
	 */
	double overLoadPressure;

	/**
	 * Pressure Lap Release Rate of the pipe
	 */
	double pressureLapReleaseRate;

	/**
	 * Pressure Lap Service Rate of the pipe
	 */
	double pressureLapServiceRate;

	/**
	 * Pressure Release Rate of the pipe
	 */
	double pressureReleaseRate;

	/**
	 * Pressure Service Rate of the pipe
	 */
	double pressureServiceRate;

	/**
	 * Pipe fault state array of the system
	 */
	int* pipeState;

	/**
	 * Leakage fault state arrary of the system
	 */
	double* leakage;

	/**
	 * Current fault state
	 */
	int currentState;

	/**
	 * Emergency brake state
	 */
	bool emergencyBrake;

	/**
	 * Pressure transmission rate
	 */
	double k;

	/**
	 * instant pressure change
	 */
	double dP;


	double p1;
	double p2;
};

#endif /* RSTrainBrakePipePressureUpdater_H_ */
