
#ifndef RSTRAINLOCOMOTIVE_H_
#define RSTRAINLOCOMOTIVE_H_

#include "RSTrainVehicle.h"
class RSTrainLocomotive;
class RSTrainVehicle;
class RSTrainLocomotiveControlValve;
class RSTrainBrakeCylinder;
class RSTrainTractionForceCalculator;
class RSTrainDynamicBrakeForceCalculator;
/**
 * Locomotive Class
 * Class for locomotives
 */
class RSTrainLocomotive: public RSTrainVehicle {
/**

 */
private:
	/**
	 * throttle value for the locomotive, between 1-14
	 */
	int throttle;

	/**
	 * dynamic brake value for the locomotive, between 1-10
	 */
	int dynamicBrake;

	/**
	 * brake valve value for the locomotive , between 1-5
	 */
	int brakeValve;

	/**
	 * Auxilary valve value for the locomotive, between 1-4
	 */
	int auxBrake;

	/**
	 * Brake cylinder count for the locomotive, this value is initialized by RSTrainLocomotiveParser class, depending on given xml file
	 */
	int brakeCylinderCount;

	/**
	 * Direction indicator
	 */
	int direction;

	/**
	 * Purger state of the locomotive
	 */
	bool purger;

	/**
	 * Motor active state of the locomotive
	 */
	bool motorActive;

	/**
	 * Compressore active state of the locomotive
	 */
	bool compressorActive;

	/**
	 * Main reservoir pressure of the locomotive
	 */
	double mainReservoirPressure;

	/**
	 * Main pipe pressure of the locomotive
	 */
	double mainPipePressure;

	/**
	 * Traction force value of the locomotive, this value is controlled by RSTrainTrainForceCalculator object
	 */
	double tractionForce;

	/**
	 * Dynamic brake force value of the locomotive, this value is controlled by RSTrainDynamicBrakeForceCalculator object
	 */
	double dynamicBrakeForce;

	/**
	 * Traction force calculator, supporter object to calculate the traction force
	 *
	 */
	RSTrainTractionForceCalculator* tractionForceCalculator;

	/**
	 * Dynamic brake force calculator, supporter object to calculate the dynamic brake force
	 */
	RSTrainDynamicBrakeForceCalculator* dynamicBrakeForceCalculator;

	/**
	 * Control valve container for the locomotive, number of control valves is equal to number of brake cylinders
	 */
	vector<RSTrainControlValve*> controlValves;

	/**
	 * Brake cylinder container for the locomotive, number of brake cylinders must be given in the xml file
	 */
	vector<RSTrainBrakeCylinder*> brakeCylinders;
public:

	/**
	 * Contructor of RSTrainLocomotive object
	 */
	RSTrainLocomotive();

	/**
	 * Destructor of RSTrainLocomotive object
	 */
	virtual ~RSTrainLocomotive();

	/**
	 * Getter
	 * @return
	 */
	int getAuxBrake() ;

	/**
	 * Setter
	 * @param auxBrake
	 */
	void setAuxBrake(int auxBrake);

	/**
	 * Getter
	 * @return
	 */
	int getBrakeValve() ;

	/**
	 * Setter
	 * @param brakeValve
	 */
	void setBrakeValve(int brakeValve);

	/**
	 * Compressor Active State
	 * @return
	 */
	bool isCompressorActive() ;

	/**
	 * Sets Compressor Active State
	 * @param compressorActive
	 */
	void setCompressorActive(bool compressorActive);

	/**
	 * Getter
	 * @return
	 */
	int getDirection() ;

	/**
	 * Setter
	 * @param direction
	 */
	void setDirection(int direction);

	/**
	 * Getter
	 * @return
	 */
	int getDynamicBrake() ;

	/**
	 * Setter
	 * @param dynamicBrake
	 */
	void setDynamicBrake(int dynamicBrake);

	/**
	 * Getter
	 * @return
	 */
	double getMainPipePressure() ;

	/**
	 * Setter
	 * @param mainPipePressure
	 */
	void setMainPipePressure(double mainPipePressure);

	/**
	 * Getter
	 * @return
	 */
	double getMainReservoirPressure() ;

	/**
	 * Setter
	 * @param mainReservoirPressure
	 */
	void setMainReservoirPressure(double mainReservoirPressure);

	/**
	 * Motor Active State
	 * @return
	 */
	bool isMotorActive() ;

	/**
	 * Sets motor active state
	 * @param motorActive
	 */
	void setMotorActive(bool motorActive);

	/**
	 * Purger state
	 * @return
	 */
	bool isPurger() ;

	/**
	 * Sets purger state
	 * @param purger
	 */
	void setPurger(bool purger);

	/**
	 * Getter
	 * @return
	 */
	int getThrottle() ;

	/**
	 * Setter
	 * @param throttle
	 */
	void setThrottle(int throttle);

	/**
	 * Getter
	 * @return
	 */
	int getBrakeCylinderCount() const;

	/**
	 * Setter
	 * @param brakeCylinderCount
	 */
	void setBrakeCylinderCount(int brakeCylinderCount);

	/**
	 * Returns Traction force created by engines
	 * @return traction force
	 */
	double getTractionForce();

	/**
	 * Returns Dynamic brake force calculated by dynamic brake force calculator
	 * @return dynamic brake force
	 */
	double getDynamicBrakeForce() ;

	/**
	 * Adds a control valve object (RSTrainLocomotiveControlValve) into the control valve container
	 * @param controlvalve
	 */
	void addLocomotiveControlValve(RSTrainControlValve* controlvalve);

	/**
	 * Returns the control valve object for given index
	 * @param index
	 * @return control valve
	 */
	RSTrainControlValve* getLocomotiveControlValve(int index);

	/**
	 * Adds a brake cylinder object (RSTrainBrakeCylinder) into the brake cylinder container
	 * @param brakeCylinder
	 */
	void addLocomotiveBrakeCylinder(RSTrainBrakeCylinder* brakeCylinder);

	/**
	 * Returns the brake cylinder object for given index
	 * @param index
	 * @return brake cylinder
	 */
	RSTrainBrakeCylinder* getLocomotiveBrakeCylinder(int index);

	/**
	 * Calculates the rolling resistance of locomotive.
	 * Calculation is  done by rolling resistance calculator
	 * It depents on velocity, mass, number of axles
	 * updates rollingresistanceforce
	 */
	void calcLocomotiveRollingResistance();

	/**
	 * Calculates traction force depending on throttle notch.
	 * Calculation is done by traction force calculator
	 */
	void calcTractionForce();

	/**
	 * Calculates effective forces ,including traction, dynamic brake and air brake forces, and compares with adherance
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
	 * Adds all the forces to calculate the total force
	 */
	void calcTotalForce();

	/**
	 * Calculates dynamic brake force depending on the dynamic brake notch
	 * Calculation is done by dynamic brake force calculator
	 */
	void calcDynamicBrakeForce();

	/**
	 * Calculates Brake Force depending on brake pipe pressure by updating control valve and brake cylinder values
	 * @param dt
	 */
	void calcPipeBreakForce(double dt);

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
	vector<RSTrainControlValve*>& getControlValves();

};

#endif /* RSTRAINLOCOMOTIVE_H_ */
