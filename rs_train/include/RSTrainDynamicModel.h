/*
 * RSTrainDynamicModel.h
 *
 *  Created on: 21 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINDYNAMICMODEL_H_
#define RSTRAINDYNAMICMODEL_H_
#include <vector>
using namespace std;
class RSTrainDynamicModel;
class RSTrainVehicle;

/**
 * RSTrainDynamicModel
 *
 * Dynamic model of a vagon or locomotive
 * The object of the class is used by integrator
 */
class RSTrainDynamicModel {

private:

	/**
	 * Vehicle instance that is going to be integrated
	 */
	RSTrainVehicle* vehicle;

public:

	/**
	 * Constructor of RSTrainDynamicModel
	 */
	RSTrainDynamicModel();

	/**
	 * Destructor of RSTrainDynamicModel
	 */
	virtual ~RSTrainDynamicModel();

	/**
	 * Getter
	 * @return
	 */
	RSTrainVehicle* getVehicle() ;

	/**
	 * Setter
	 * @param vehicle
	 */
	void setVehicle( RSTrainVehicle* vehicle);

	/**
	 * Operator function which is going to be used by Integrator
	 * @param states
	 * @param d_states
	 * @param
	 */
	void operator()(const vector<double>& states,vector<double>& d_states,const double /*t*/);
};

#endif /* RSTRAINDYNAMICMODEL_H_ */
