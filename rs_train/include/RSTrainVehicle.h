/**
 *
 */

#ifndef RSTRAINVEHICLE_H_
#define RSTRAINVEHICLE_H_
#include <vector>
using namespace std;

class RSTrainVehicle;
class RSTrainCoupling;
class RailwayElement;
class RSTrainRoadWatcher;
class RSTrainBrakeCylinder;
class RSTrainControlValve;
class RSTrainRollingResistanceCalculator;
/**
 * Abstract Base Class
 * Base Class of RSTrainLocomotive and RSTrainCar
 */
class RSTrainVehicle {

protected:

	/**
	 * Indicator of the freight type of a train
	 */
	int freightType;

	/**
	 * Mass of a vagon or locomotive (Kg)
	 */
	double mass;

	/**
	 * Mass of a vagon or locomotive (Ton)
	 */
	double massInTons;

	/**
	 * Number of Axles of a vagon or locomotive
	 */
	int numberAxles;

	/**
	 * Length of a vagon or locomotive
	 */
	double length;

	/**
	 * Diameter of Wheel of a vagon or locomotive
	 */
	double diameterOfWheel;

	/**
	 * Axularity Reservaur Pressure of a vagon or locomotive
	 */
	double brakePipePresure;

	/**
	 * Front Position of a vagon or locomotive
	 */
	double frontPosition;

	/**
	 * Rear Position of a vagon or locomotive
	 */
	double rearPosition;

	/**
	 * Position of a vagon or locomotive
	 */
	double position;

	/**
	 * Curve of the road of a vagon or locomotive
	 */
	double curve;

	/**
	 * Slope of the road of a vagon or locomotive
	 */
	double slope;

	/**
	 * Angle value of the road of a vagon or locomotive
	 */
	double alfa;

	/**
	 * Coefficient Friction between road and vehicle wheel
	 */
	double coefFriction;

	/**
	 * Adherance Coefficient of a vagon or locomotive
	 */
	double adheranceCoef;

	/**
	 * Velocity of a vagon or locomotive (m/s)
	 */
	double velocity;

	/**
	 * Velocity of the vagon or locomotive (km/h)
	 */
	double velocityKPH;

	/**
	 * Accelaration of a vagon or locomotive (m/s^2)
	 */
	double accelaration;

	/**
	 * Rolling Resistance Force of a vagon or locomotive
	 */
	double rollingResistanceForce;

	/**
	 * Curve Resistance Force of a vagon or locomotive
	 */
	double curveResistanceForce;

	/**
	 * Ramp Resistance Force of a vagon or locomotive
	 */
	double rampResistanceForce;

	/**
	 * Adherance Force of a vagon or locomotive
	 */
	double adheranceForce;

	/**
	 * Brake Force of a vagon or locomotive
	 */
	double brakeForce;

	/**
	 * Total Force of a vagon or locomotive
	 */
	double totalForce;

	/**
	 * Front Coupling pointer
	 * Keeps the front coupling instance connected to the vehicle
	 */
	RSTrainCoupling* frontCoupling;

	/**
	 * Back Coupling pointer
	 * Keeps the rear coupling instance connected to the vehicle
	 */
	RSTrainCoupling* rearCoupling;

	/**
	 * Rail Road Pointer
	 * Keeps the global rail road instance
	 */
	RailwayElement* railRoad;

	/**
	 * Road Watcher Pointer
	 * Keeps the road watcher instance of a vagon or locomotive
	 */
	RSTrainRoadWatcher* watcher;

	/**
	 * Brake Cylinder
	 * Keeps the brake cylinder instance of a vagon
	 */
	RSTrainBrakeCylinder* brakeCylinder;

	/**
	 * Control Valve
	 * Keeps the control valve instance of a vagon
	 */
	RSTrainControlValve* controlValve;

	/**
	 * Rolling Resistance Force Calculator
	 * Keeps the rolling resistance force calculator instance of a locomotive or vagon
	 */
	RSTrainRollingResistanceCalculator* rollingResistanceForceCalculator;
public:
	/**
	 * Position and velocity vector
	 * Keeps the position and velocity information obtained from the integration process
	 */
	vector<double> posvel;

	/**
	 * Constructor of a RSTrainVehicle object
	 */
	RSTrainVehicle();

	/**
	 * Destructor of a RSTrainVehicle object
	 */
	virtual ~RSTrainVehicle();

	/**
	 * Getter Function of accelaration attribute
	 * @return accelaration
	 */
	double getAccelaration();

	/**
	 * Setter Function of accelaration attribute
	 * @param accelaration
	 */
	void setAccelaration(double accelaration);

	/**
	 * Getter Function of adheranceForce attribute
	 * @return adheranceForce
	 */
	double getAdheranceForce();

	/**
	 * Getter Function of Auxilary Pressure attribute
	 * @return ARPressure
	 */
	double getArPressure();


	RSTrainCoupling* getRearCoupling();
	void setRearCoupling(RSTrainCoupling* rearCoupling);

	double getBcPressure();

	double getBrakeForce();
	void setBrakeForce(double brakeForce);

	double getBrakePipePresure();
	void setBrakePipePresure(double brakePipePresure);

	double getCoefFriction();
	void setCoefFriction(double coefFriction);

	double getCurve();
	void setCurve(double curve);

	double getCurveResistanceForce();
	void setCurveResistanceForce(double curveResistanceForce);

	int getFreightType();
	void setFreightType(int freightType);

	RSTrainCoupling* getFrontCoupling();
	void setFrontCoupling(RSTrainCoupling* frontCoupling);

	double getFrontPosition();
	void setFrontPosition(double frontPosition);

	double getLength();
	void setLength(double length);

	double getMass();
	void setMass(double mass);

	double getMassInTons();
	void setMassInTons(double massInTons);

	int getNumberAxles();
	void setNumberAxles(int numberAxles);

	double getPosition();
	void setPosition(double position);

	RailwayElement* getRailRoad();
	void setRailRoad(RailwayElement* railRoad);

	double getRampResistanceForce();
	void setRampResistanceForce(double rampResistanceForce);

	double getRearPosition();
	void setRearPosition(double rearPosition);

	double getRollingResistanceForce();
	void setRollingResistanceForce(double rollingResistanceForce);

	double getSlope();
	void setSlope(double slope);

	double getVelocity();
	void setVelocity(double velocity);

	double getVelocityKph();
	void setVelocityKph(double velocityKph);

	double getAdheranceCoef();
	void setAdheranceCoef(double adheranceCoef);

	double getAlfa();
	void setAlfa(double alfa);

	double getTotalForce();
	void setTotalForce(double totalForce);

	double getDiameterOfWheel();
	void setDiameterOfWheel(double diameterOfWheel);

	vector<double>& getPosvel();
	void setPosvel(vector<double>& posvel);

	RSTrainRoadWatcher* getWatcher();
	void setWatcher(RSTrainRoadWatcher* watcher);

	RSTrainBrakeCylinder* getBrakeCylinder();
	void setBrakeCylinder(RSTrainBrakeCylinder* brakeCylinder);

	RSTrainControlValve* getControlValve();
	void setControlValve(RSTrainControlValve* controlValve);

	RSTrainRollingResistanceCalculator* getRollingResistanceForceCalculator();
	void setRollingResistanceForceCalculator(
			RSTrainRollingResistanceCalculator* rollingResistanceForceCalculator);

	/**
	 * Initializes the position of a vagon or locomotive on the given
	 * road specified with roadindex
	 * @param roadindex : index of the road
	 * @param position (m): position of
	 */
	void InitPosition(int roadindex, double position);

	/**
	 * Initializes the speed of a vagon or locomotive
	 * @param speed (m/s)
	 */
	void InitSpeed(double speed);

	/**
	 * Calculates Alfa value of the road depending on the slope value
	 */
	void calcAlfa();

	/**
	 * Calculates Curve Resistance depending on the curve value and updates
	 * the Curve Resistance Force, sign depends on velocity
	 */
	void calcCurveResistance();

	/**
	 * Calculates Ramp Resistance depending on the Alfa value and updates
	 * the Ramp Resistance Force
	 */
	void calcRampResistance();

	/**
	 * Calculates Adherance Coefficient depending on velocity and coefficient friction
	 */
	void calcAhreranceCoef();

	/**
	 * Calculates Adherance force depending on adherance coefficient
	 */
	void calcAdheranceForce();

	/**
	 * Updates the value for coefFriction
	 */
	void calcCoefFriction();

	/**
	 * Pure virtual function to update variables, derived classes have to implement this method
	 * @param dt
	 */
	virtual void updateVariables(double dt)=0;

	/**
	 * Pure virtual function to calculate forces, derived classes have to implement this method
	 * @param dt
	 */
	virtual void calcForce(double dt) = 0;

};

#endif /* RSTRAINVEHICLE_H_ */
