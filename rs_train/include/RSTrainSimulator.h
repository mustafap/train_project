/*
 * RSTrainSimulator.h
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINSIMULATOR_H_
#define RSTRAINSIMULATOR_H_
#include <vector>
#include "RSTrainDynamicModel.h"
using namespace std;

class RSTrainSimulator;
class RSTrainVehicle;
class RSTrainCoupling;
class RailwayElement;
class RSTrainDynamicModel;
class RSTrainBrakePipePressureUpdater;
class RSTrainLocomotive;
class RSTrainGetter;

/**
 * RSTrainSimulator
 *
 * Main control class for all system
 * This class is capable of control all system by the user, after creation process.
 */
class RSTrainSimulator {
private:

	/**
	 * Keeps timing range between two consecutive step
	 */
	double range;

	/**
	 * Resume/Pause flag of the running system
	 */
	bool resume;

	/**
	 * Time variable of the system
	 */
	double time;

	/**
	 * Adaptive timing variable, this variable is manipulated by integrator
	 */
	double dt;

	/**
	 * Thread lock instance
	 */
	void* run;

	/**
	 * Vehicle container
	 */
	vector<RSTrainVehicle*> vehicleVector;

	/**
	 * Locomotive container
	 */
	vector<RSTrainLocomotive*> locomotives;

	/**
	 * Main locomotive instance
	 */
	RSTrainLocomotive* mainLocomotive;

	RSTrainLocomotive* runforLocomotive;

	/**
	 * Vehicle number on the system
	 */
	int vehicleNumber;

	/**
	 * Previously created vehicle instance
	 */
	RSTrainVehicle* prevVehicle;

	/**
	 * Coupling container
	 */
	vector<RSTrainCoupling*> couplingVector;

	/**
	 * Rail road on which the train is going to move
	 */
	RailwayElement* railwayelement;

	/**
	 * Dynamic model of the system
	 * This instance must be created for the integrator
	 */
	RSTrainDynamicModel dynamicModel;

	/**
	 * Controls the brake pipe values for all locomotives or vagons
	 */
	RSTrainBrakePipePressureUpdater* bPupdater;

	RSTrainGetter* getterAndLogger;


public:

	/**
	 * Constructor of the RSTrainSimulator object
	 */
	RSTrainSimulator();

	/**
	 * Destructor of the RSTrainSimulator object
	 */
	virtual ~RSTrainSimulator();


	/**
	 * Getter
	 * @return vehicle container
	 */
	vector<RSTrainVehicle*>& getVehicleVector() ;

	/**
	 * Getter
	 * @return coupling container
	 */
	vector<RSTrainCoupling*>& getCouplingVector();

	/**
	 * Getter
	 * @return dt
	 */
	double getDt();

	/**
	 * Getter
	 * @return vehicle number
	 */
	double getVehicleNumber();

	/**
	 * Sets the freight type of the vehicle by given index
	 * freightType [0  = good, 1 = passanger]
	 * @param index
	 * @param freightType
	 */
	void setFreightType(int index, int freightType);

	/**
	 * Sets the mass of the vehicle by given index
	 * Mass value must be in kg
	 * @param index
	 * @param mass
	 */
	void setMass(int index, double mass);

	/**
	 * Getter
	 * @return range
	 */
	double getRange() ;

	/**
	 * Getter
	 * @return time
	 */
	double getTime() ;

	RSTrainBrakePipePressureUpdater* getBPupdater();
	void setBPupdater(RSTrainBrakePipePressureUpdater* bpUpdater);

	RSTrainGetter* getGetterAndLogger();
	void setGetterAndLogger(RSTrainGetter* getterAndLogger);

	/**
	 * Sets the brake cylinder purge fault of a locomotive.
	 * Locomotive must be indicated by vehicleIndex [0 , vehicleNumber - 1].
	 * Brake cylinder must be indicated by brakeCylinderIndex [0 , brakeCylinderCount - 1].
	 * State of the fault must be indicated by bool variable, enable [ true = purge fault on , false = purge fault off].
	 * @param vehicleIndex
	 * @param brakeCylinderIndex
	 * @param enable
	 */
	void setLocomotiveBCPurgeFault(int vehicleIndex, int brakeCylinderIndex, bool enable);

	/**
	 * Sets the brake cylinder enable fault of a locomotive.
	 * Locomotive must be indicated by vehicleIndex [0 , vehicleNumber - 1].
	 * Brake cylinder must be indicated by brakeCylinderIndex [0 , brakeCylinderCount - 1].
	 * State of the fault must be indicated by bool variable, enable [true = enable fault on, false = enable fault off].
	 * @param vehicleIndex
	 * @param brakeCylinderIndex
	 * @param enable
	 */
	void setLocomotiveBCEnabled(int vehicleIndex, int brakeCylinderIndex, bool enable);

	int getLocomotiveBCFaultState(int vehicleIndex, int brakeCylinderIndex);
	/**
	 * Sets the brake cylinder purge fault of a car.
	 * The car must be indicated by index [0 , vehicleNumber - 1].
	 * State of the fault must be indicated by bool variable, enable [true = purge fault on, false = purge fault off].
	 * @param index
	 * @param enable
	 */
	void setCarBreakCylinderPurgeFault(int index, bool enable);

	/**
	 * Sets the brake cylinder enable fault of a car.
	 * The car must be indicated by index [0 , vehicleNumber - 1].
	 * State of the fault must be indicated by bool variable, enable [true = enable fault on, false = enable fault off].
	 * @param index
	 * @param enable
	 */
	void setCarBCEnabled(int index, bool enable);

	/**
	 * Returns the brake cylinder fault state of the car.
	 * The car or locomotive must be indicated by index [0 , vehicleNumber - 1].
	 * @param index
	 * @return
	 */
	int getCarBCFaultState(int index);

	/**
	 * Sets brake pipe clogged state
	 * The car or locomotive must be indicated by index [0, vehicleNumber - 1].
	 * State of fault must be indicated by bool variable, enable [true = pipe clogged , false = pipe not clogged].
	 * @param index
	 * @param enable
	 */
	void setCarBPCEnabled(int index, bool enable);

	/**
	 * Sets brake pipe disjointed state
	 * The car or locomotive must be indicated by index [0, vehicleNumber - 1].
	 * State of fault must be indicated by bool variable, enable [true = pipe disjointed, false = pipe not disjointed].
	 * @param index
	 * @param enable
	 */
	void setCarBPD(int index, bool enable);

	/**
	 * Sets the leakage value of a faulty pipe.
	 * The car or locomotive must be indicated by index [0, vehicleNumber - 1].
	 * Leakage value must be given by leakage parameter.
	 * @param index
	 * @param leakage
	 */
	void setLeakage(int index, double leakage);

	/**
	 * Returns the brake pipe fault state for given vehicle index.
	 * The car or locomotive must be indicated by index [0 , vehicleNumber - 1].
	 * @param index
	 * @return
	 */
	int getBPFaultState(int index);

	/**
	 * Returns leakage value for given vehicle index.
	 * The car or locomotive must be indicated by index [0, vehicleNumer - 1].
	 * @param index
	 * @return
	 */
	double getBPLeakage(int index);

	/**
	 * Sets Emergency Brake state of a vehicle
	 * The car or locomotive must be indicated by index [0, vehicleNumer - 1].
	 * Emergency Brake state must be indicated by bool variable, enable [true = Emergency Brake on, false = Emergency Brake off]
	 * @param index
	 * @param enable
	 */
	void setCarEBPull(int index, bool enable);

	/**
	 * Sets Throttle Position for a given locomotive
	 * The locomotive must be indicated by index [0, vehicleNumber - 1].
	 * Throttle position must be indicated by int variable, throttlepos [ 0 - 14]
	 * @param index
	 * @param throttlepos
	 */
	void setThrottlePos(int index, int throttlepos);

	/**
	 * Sets Brake Valve position for the main locomotive
	 * The Brake valve position must be indicated by int variable, brakevalvepos [1 , 5]
	 * @param brakevalvepos
	 */
	void setBrakeValvePos(int brakevalvepos);

	/**
	 * Sets Auxilary Brake Valve position for the main locomotive
	 * The auxilary brake valve position must be indicated by int variable, auxbrakepos [0, 4]
	 * @param auxbrakepos
	 */
	void setAuxBrakePos(int auxbrakepos);

	/**
	 * Sets Dynamic Brake Position for the main locomotive
	 * The dynamic brake position must be indicated by int variable, dynamicBrakeState [0,10]
	 * @param dynamicBrakeState
	 */
	void setDynamicBrakePos(int dynamicBrakeState);

	/**
	 * Returns dynamic brake position of the main locomotive
	 * @return dynamic brake position
	 */
	int getDynamicBrakePos();

	/**
	 * Returns dynamic brake force of the main locomotive
	 * @return dynamic brake force
	 */
	double getDynamicBrakeForce();

	double getCarAirBrakeForce(int index);

	double getLocomotiveAirBrakeForce(int index, int brakeCylinderIndex);
	/**
	 * Sets emergency brake on
	 */
	void EmergencyBrakeOn();

	/**
	 * Sets emergency brake off
	 */
	void EmergencyBrakeOff();

	/**
	 * Sets purger on of the vehicle for given index.
	 * @param index
	 */
	void PurgerOn(int index);

	/**
	 * Sets purger off of the vehicle for given index.
	 * @param index
	 */
	void PurgerOff(int index);

	/**
	 * Sets the direction of the vehicle.
	 * @param index
	 * @param direction
	 */
	void setDirection(int index, int direction);


	/**
	 * Sets the activation state of a motor.
	 * The locomotive must be indicated by index [0, vehicleNumber - 1].
	 * Motor index must be indicated by motorindex
	 * Activation state must be indicated by bool variable, enable [true = motor active, false = motor deactive].
	 * @param index
	 * @param motorindex
	 * @param enable
	 */
	void setMotorActive(int index, int motorindex, bool enable);

	/**
	 * Sets the activation state of compressor.
	 * The locomotive must be indicated by index [0, vehicleNumber - 1].
	 * Activation state must be indicated by bool variable, enable [true = motor active, false = motor deactive].
	 * @param index
	 * @param enable
	 */
	void setCompressorActive(int index, bool enable);

	/**
	 * Sets the main reservoir pressure.
	 * The locomotive must be indicated by index [0, vehicleNumber - 1].
	 * The pressure value must be indicated by pressure value.
	 * @param index
	 * @param pressure
	 */
	void setMainReservoirPressure(int index, double pressure);

	/**
	 * Sets main pipe pressure
	 * @param index
	 * @param pressure
	 */
	void setMainPipePressure(int index, double pressure);

	/**
	 * Returns brake pipe pressure seen by the vehicle for given index
	 * @param index
	 * @return pipe pressure
 	 */
	double getBrakePipePressure(int index);

	/**
	 * Initialize the rail way element object of the system.
	 * To initialize the rail way element, the user must supply a xml-file which has information about the railroad.
	 * Function input (xmlFileName) must indicate the required xml-file path.
 	 * @param xmlFileName
	 */
	void InitRailwayElement(string xmlFileName);

	/**
	 * Adds a locomotive to the system.
	 * Locotype indicates locomotive type to be created
	 * @param locotype
	 */
	void addLocomotive(int locotype);

	/**
	 * Adds a car to the system.
	 * carType indicates car type to be created
	 * @param carType
	 */
	void addCar(int carType);

	void addRunforLocomotive(int locotype);



	void removeRunforLocomotive();
	/**
	 * Connects the created vehicle to train and creates required couplings and adds all of them into the corresponding
	 * containers
	 * @param vehicle
	 */
	void connectCreatedVehicle(RSTrainVehicle* vehicle);

	void connectRunforLocomotive(RSTrainVehicle* vehicle);

	bool isLocomotive(int index);
	/**
	 * Initializes the positions of the vehicles.
	 * Road index must be supplied via an int parameter, roadindex
	 * Local road position of first vehicle (main locomotive) must be supplied via a double parameter, LocalRoadpositionOfFirstVehicle
	 * @param roadindex
	 * @param LocalRoadpositionOfFirstVehicle
	 */
	void InitPositions(int roadindex, double LocalRoadpositionOfFirstVehicle);

	void InitRunforLocomotivePosition(int roadindex, double LocalRoadposition);

	void InitRunforLocomotiveSpeed(double speed);

	/**
	 * Initializes the break pipe
	 */
	void InitBreakePipe();

	/**
	 * Initiazlies the speed
	 * Given speed parameter must be in unit m/s
	 * @param speed
	 */
	void InitSpeed(double speed);

	/**
	 * Does the integration of the constructed system
	 */
	void doIntegration();

	/**
	 * Updates the forces
	 * Time step range must be given as parameter (sec)
	 * @param dt
	 */
	void updateForces(double dt);

	/**
	 * Updates the variables
	 * Time step range must be given as parameter (sec)
	 * @param dt
	 */
	void updateVariables(double dt);

	/**
	 * Changes the switch state
	 * @param globalID
	 * @param stateNumber
	 * @param stateValue
	 */
	void changeSwitchState(int globalID,int stateNumber,string stateValue);

	/**
	 * Starts the simulation process
	 */
	void Start();

	/**
	 * Resumes the simulation process
	 */
	void Resume();

	/**
	 * Pauses the simulation process
	 */
	void Pause();

};

#endif /* RSTRAINSIMULATOR_H_ */
