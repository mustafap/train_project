/*
 * RSTrainRunforLocomotiveCoupling.h
 *
 *  Created on: 15 Aðu 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINRUNFORLOCOMOTIVECOUPLING_H_
#define RSTRAINRUNFORLOCOMOTIVECOUPLING_H_

#include "RSTrainCoupling.h"

class RSTrainRunforLocomotiveCoupling;
class RSTrainCoupling;
class RSTrainVehicle;


class RSTrainRunforLocomotiveCoupling : public RSTrainCoupling{
public:
	RSTrainRunforLocomotiveCoupling();
	virtual ~RSTrainRunforLocomotiveCoupling();

	void calcDistance();
};

#endif /* RSTRAINRUNFORLOCOMOTIVECOUPLING_H_ */
