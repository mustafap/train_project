/*
 * RSTrainGetter.cpp
 *
 *  Created on: 11 Agu 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainGetter.h"
#include "RSTrainSimulator.h"
#include "RSTrainVehicle.h"
#include "RSTrainCar.h"
#include "RSTrainLocomotive.h"
#include "RSTrainBrakeCylinder.h"
#include "RSTrainBrakePipePressureUpdater.h"
#include "RSTrainControlValve.h"
#include "RSTrainLocomotiveControlValve.h"
#include "RSTrainCoupling.h"
#include "RSTrainRoadWatcher.h"
#include <iostream>
using namespace std;

double getVelocity(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];
	return vec->getVelocityKph();
}

double getAccelaration(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];
	return vec->getAccelaration();

}

double getBrakePipePresure(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	return vec->getBrakePipePresure();
}

double getFrontPosition(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	return vec->getFrontPosition();
}

double getRearPosition(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	return vec->getRearPosition();
}

double getPosition(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	return vec->getPosition();

}

double getRollingResistanceForce(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	return vec->getRollingResistanceForce();
}

double getCurveResistanceForce(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	return vec->getCurveResistanceForce();

}

double getRampResistanceForce(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	return vec->getRampResistanceForce();

}

double getSlope(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	return vec->getSlope();

}

double getAdheranceForce(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	return vec->getAdheranceForce();

}

double getBrakeForce(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		return (loc->getLocomotiveBrakeCylinder(BCI)->getAirBrakeForce());

	} else {

		return vec->getBrakeCylinder()->getAirBrakeForce();

	}

}

double getTotalForce(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	return vec->getTotalForce();
}

double getThrottlePosition(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		return loc->getThrottle();

	} else {

		return -1;
	}
}

double getDynamicBrakePosition(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		return loc->getDynamicBrake();

	} else {
		return -1;
	}
}

double getBrakeValvePosition(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		return loc->getBrakeValve();

	} else {
		return -1;
	}
}

double getAuxilaryBrakePosition(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		return loc->getAuxBrake();

	} else {
		return -1;
	}

}

double getBrakeCylinderCount(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		return loc->getBrakeCylinderCount();

	} else {
		return -1;
	}

}

double getTractionForce(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		return loc->getTractionForce();

	} else {
		return -1;
	}

}

double getDynamicBrakeForce(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		return loc->getDynamicBrakeForce();

	} else {
		return -1;
	}

}

double getCouplingDistance(RSTrainSimulator* p, int CI, int BCI) {

	RSTrainCoupling* coup = p->getCouplingVector()[CI];

	return coup->getDistance();
}

double getCouplingForce(RSTrainSimulator* p, int CI, int BCI) {

	RSTrainCoupling* coup = p->getCouplingVector()[CI];

	return coup->getCouplingForce();

}

double getCouplingKinc(RSTrainSimulator* p, int CI, int BCI) {

	RSTrainCoupling* coup = p->getCouplingVector()[CI];

	return coup->getKinc();

}

double getCouplingKdec(RSTrainSimulator* p, int CI, int BCI) {

	RSTrainCoupling* coup = p->getCouplingVector()[CI];

	return coup->getKdec();

}

double getAuxiliaryReservoirPressure(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainControlValve* cv = loc->getLocomotiveControlValve(BCI);

		return cv->getArPressure();

	} else {

		return vec->getControlValve()->getArPressure();
	}
}

double getBrakeCylinderPressure(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainControlValve* cv = loc->getLocomotiveControlValve(BCI);

		return cv->getBcPressure();

	} else {

		return vec->getControlValve()->getBcPressure();
	}
}

double getControlValveFlowConstant(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainControlValve* cv = loc->getLocomotiveControlValve(BCI);

		return cv->getFlowConstant();

	} else {

		return vec->getControlValve()->getFlowConstant();
	}
}

double getARPressureBPPressureDifference(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainControlValve* cv = loc->getLocomotiveControlValve(BCI);

		return cv->getDiff();

	} else {

		return vec->getControlValve()->getDiff();
	}
}

double getBrakeCylinderFaultState(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainControlValve* cv = loc->getLocomotiveControlValve(BCI);

		return cv->getFaultState();

	} else {

		return vec->getControlValve()->getFaultState();
	}
}

double getBrakeCylinderDX(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainBrakeCylinder* bc = loc->getLocomotiveBrakeCylinder(BCI);

		return bc->getDx();

	} else {

		return vec->getControlValve()->getFaultState();
	}
}

double getModerablePressure(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainControlValve* cv = loc->getLocomotiveControlValve(BCI);

		RSTrainLocomotiveControlValve* lcv =
				dynamic_cast<RSTrainLocomotiveControlValve*>(cv);

		return lcv->getModerablePressure();

	} else {

		return -1;
	}

}

double getModerableDecreasePressureRate(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainControlValve* cv = loc->getLocomotiveControlValve(BCI);

		RSTrainLocomotiveControlValve* lcv =
				dynamic_cast<RSTrainLocomotiveControlValve*>(cv);

		return lcv->getDecreasePressureRate();

	} else {

		return -1;
	}

}

double getModerableIncreasePressureRate(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainControlValve* cv = loc->getLocomotiveControlValve(BCI);

		RSTrainLocomotiveControlValve* lcv =
				dynamic_cast<RSTrainLocomotiveControlValve*>(cv);

		return lcv->getIncreasePressureRate();
	} else {

		return -1;
	}
}

double getModerableMaxIncreasePressureRate(RSTrainSimulator* p, int VI,
		int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainControlValve* cv = loc->getLocomotiveControlValve(BCI);

		RSTrainLocomotiveControlValve* lcv =
				dynamic_cast<RSTrainLocomotiveControlValve*>(cv);

		return lcv->getMaxIncreasePressureRate();

	} else {

		return -1;
	}

}

double getModerableMaxPressure(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	if (p->isLocomotive(VI)) {

		RSTrainLocomotive* loc = dynamic_cast<RSTrainLocomotive*>(vec);

		RSTrainControlValve* cv = loc->getLocomotiveControlValve(BCI);

		RSTrainLocomotiveControlValve* lcv =
				dynamic_cast<RSTrainLocomotiveControlValve*>(cv);

		return lcv->getMaxModerablePressure();

	} else {

		return -1;
	}

}

double getCurrentRoadIndex(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	RSTrainRoadWatcher* w = vec->getWatcher();

	return w->getCurrentRoadIndex();

}

double getCurrentVerticalProfileIndex(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	RSTrainRoadWatcher* w = vec->getWatcher();

	return w->getCurrentVerticalProfileIndex();

}

double getCurrentSectionIndex(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	RSTrainRoadWatcher* w = vec->getWatcher();

	return w->getCurrentSectionIndex();

}

double getSectionPosition(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	RSTrainRoadWatcher* w = vec->getWatcher();

	return w->getSectionPosition();

}

double getVerticalProfilePosition(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	RSTrainRoadWatcher* w = vec->getWatcher();

	return w->getVerticalProfilePosition();

}

double getCompletedRoadLength(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	RSTrainRoadWatcher* w = vec->getWatcher();

	return w->getCompletedRoadLength();
}

double getCompletedSectionsLength(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	RSTrainRoadWatcher* w = vec->getWatcher();

	return w->getCompletedSectionsLength();
}

double getCompletedVerticalProfilesLength(RSTrainSimulator* p, int VI,
		int BCI) {

	RSTrainVehicle* vec = p->getVehicleVector()[VI];

	RSTrainRoadWatcher* w = vec->getWatcher();

	return w->getCompletedVerticalProfileLength();
}

double getBrakePipeNominalPressure(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainBrakePipePressureUpdater* bp = p->getBPupdater();

	return bp->getNominalPressure();

}

double getBrakePipeMinPressure(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainBrakePipePressureUpdater* bp = p->getBPupdater();

	return bp->getMinPressure();

}

double getBrakePipeMaxPressure(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainBrakePipePressureUpdater* bp = p->getBPupdater();

	return bp->getMaxPressure();
}

double getBrakePipeOverLoadPressure(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainBrakePipePressureUpdater* bp = p->getBPupdater();

	return bp->getOverLoadPressure();

}

double getBrakePipePressureLapReleaseRate(RSTrainSimulator* p, int VI,
		int BCI) {

	RSTrainBrakePipePressureUpdater* bp = p->getBPupdater();

	return bp->getPressureLapReleaseRate();

}

double getBrakePipePressureLapServiceRate(RSTrainSimulator* p, int VI,
		int BCI) {

	RSTrainBrakePipePressureUpdater* bp = p->getBPupdater();

	return bp->getPressureLapServiceRate();

}

double getBrakePipePressureReleaseRate(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainBrakePipePressureUpdater* bp = p->getBPupdater();

	return bp->getPressureReleaseRate();

}

double getBrakePipePressureServiceRate(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainBrakePipePressureUpdater* bp = p->getBPupdater();

	return bp->getPressureServiceRate();

}

double getBrakePipeFaultState(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainBrakePipePressureUpdater* bp = p->getBPupdater();

	return bp->getFaultState(VI);

}

double getBrakePipeLeakage(RSTrainSimulator* p, int VI, int BCI) {

	RSTrainBrakePipePressureUpdater* bp = p->getBPupdater();

	return bp->getLeakage(VI);

}

double getSimulationTime(RSTrainSimulator* p, int VI, int BCI) {

	return p->getTime();

}

double getSimulationTimeRange(RSTrainSimulator* p, int VI, int BCI) {

	return p->getRange();
}

double getSimulationVehicleNumber(RSTrainSimulator* p, int VI, int BCI) {

	return p->getVehicleNumber();
}

RSTrainGetter::RSTrainGetter(RSTrainSimulator* parent) {

	this->parent = parent;

	//Add variables names
	this->VELOCITYKPH = "velocityKPH";
	this->ACCELERATION = "acceleration";
	this->BRAKEPIPEPRESSURE = "brakePipePresure";
	this->FRONTPOSITION = "frontPosition";
	this->REARPOSITION = "rearPosition";
	this->POSITION = "position";
	this->SLOPE = "slope";
	this->ROLLINGRESISTANCEFORCE = "rollingResistanceForce";
	this->CURVERESISTANCEFORCE = "curveResistanceForce";
	this->RAMPRESISTANCEFORCE = "rampResistanceForce";
	this->ADHERANCEFORCE = "adheranceForce";
	this->BRAKEFORCE = "brakeForce";
	this->TOTALFORCE = "totalForce";
	this->THROTTLEPOSITION = "throttle";
	this->DYNAMICBRAKEPOSITION = "dynamicBrake";
	this->BRAKEVALVEPOSITION = "brakeValve";
	this->AUXILARYBRAKEPOSITION = "auxBrake";
	this->BRAKECYLINDERCOUNT = "brakeCylinderCount";
	this->TRACTIONFORCE = "tractionForce";
	this->DYNAMICBRAKEFORCE = "dynamicBrakeForce";
	this->COUPLINGDISTANCE = "couplingDistance";
	this->COUPLINGFORCE = "couplingForce";
	this->COUPLINGINCREMENTALCONSTANT = "couplingKinc";
	this->COUPLINGDECREMENTALCONSTANT = "couplingKdec";
	this->AUXILIARYRESERVOIRPRESSURE = "ARPressure";
	this->BRAKECYLINDERPRESSURE = "BCPressure";
	this->CONTROLVALVEFLOWCONSTANT = "ContValveFlowConstant";
	this->ARPRESSURE_BPPRESSURE_DIFFERENCE = "ARpress-BPpress";
	this->BRAKECYLINDERFAULT = "brakeCylinderFaultState";
	this->MODERABLEPRESSURE = "moderablePressure";
	this->MODERABLEDECREASEPRESSURERATE = "moderableDecPreRate";
	this->MODERABLEINCREASEPRESSURERATE = "moderalbeIncPreRate";
	this->MODERABLEMAXINCREASEPRESSURERATE = "moderalbeMaxIncPreRate";
	this->MODERABLEMAXPRESSURE = "moderalbeMaxPress";
	this->ROADINDEX = "currentRoadIndex";
	this->VERTICALPROFILEINDEX = "currentVerticalProfileIndex";
	this->SECTIONINDEX = "currentSectionIndex";
	this->SECTIONPOSITION = "sectionPosition";
	this->VERTICALPROFILEPOSITION = "verticalProfilePosition";
	this->COMPLETEDROADLENGTH = "completedRoadLength";
	this->COMPLETEDSECTIONSLENGTH = "completedSectionsLength";
	this->COMPLETEDVERTICALPROFILESLENGTH = "completedVerticalProfileLength";
	this->BRAKEPIPENOMINALPRESSURE = "BPNominalPressure";
	this->BRAKEPIPEMINPRESSURE = "BPminPressure";
	this->BRAKEPIPEMAXPRESSURE = "BPmaxPressure";
	this->BRAKEPIPEOVERLOADPRESSURE = "BPoverLoadPressure";
	this->BRAKEPIPEPRESSURELAPRELEASERATE = "pressureLapReleaseRate";
	this->BRAKEPIPEPRESSURELAPSERVICERATE = "pressureLapServiceRate";
	this->BRAKEPIPEPRESSURERELEASERATE = "pressureReleaseRate";
	this->BRAKEPIPEPRESSURESERVICERATE = "pressureServiceRate";
	this->BRAKEPIPEFAULTSTATE = "brakePipeFaultState";
	this->TIME = "time";
	this->TIMERANGE = "timeRange";
	this->VEHICLENUMBER = "vehicleNumber";
	this->BRAKECYLINDERSPRINGMOVEMENT = "brakeCylinderDX";

	//Add Functions to the map object
	this->func[VELOCITYKPH] = getVelocity;
	this->func[ACCELERATION] = getAccelaration;
	this->func[BRAKEPIPEPRESSURE] = getBrakePipePresure;
	this->func[FRONTPOSITION] = getFrontPosition;
	this->func[REARPOSITION] = getRearPosition;
	this->func[POSITION] = getPosition;
	this->func[ROLLINGRESISTANCEFORCE] = getRollingResistanceForce;
	this->func[CURVERESISTANCEFORCE] = getCurveResistanceForce;
	this->func[RAMPRESISTANCEFORCE] = getRampResistanceForce;
	this->func[SLOPE] = getSlope;
	this->func[ADHERANCEFORCE] = getAdheranceForce;
	this->func[BRAKEFORCE] = getBrakeForce;
	this->func[TOTALFORCE] = getTotalForce;
	this->func[THROTTLEPOSITION] = getThrottlePosition;
	this->func[DYNAMICBRAKEPOSITION] = getDynamicBrakePosition;
	this->func[BRAKEVALVEPOSITION] = getBrakeValvePosition;
	this->func[AUXILARYBRAKEPOSITION] = getAuxilaryBrakePosition;
	this->func[BRAKECYLINDERCOUNT] = getBrakeCylinderCount;
	this->func[TRACTIONFORCE] = getTractionForce;
	this->func[DYNAMICBRAKEFORCE] = getDynamicBrakeForce;
	this->func[COUPLINGDISTANCE] = getCouplingDistance;
	this->func[COUPLINGFORCE] = getCouplingForce;
	this->func[COUPLINGINCREMENTALCONSTANT] = getCouplingKinc;
	this->func[COUPLINGDECREMENTALCONSTANT] = getCouplingKdec;
	this->func[AUXILIARYRESERVOIRPRESSURE] = getAuxiliaryReservoirPressure;
	this->func[BRAKECYLINDERPRESSURE] = getBrakeCylinderPressure;
	this->func[CONTROLVALVEFLOWCONSTANT] = getControlValveFlowConstant;
	this->func[ARPRESSURE_BPPRESSURE_DIFFERENCE] =
			getARPressureBPPressureDifference;
	this->func[BRAKECYLINDERFAULT] = getBrakeCylinderFaultState;
	this->func[MODERABLEPRESSURE] = getModerablePressure;
	this->func[MODERABLEDECREASEPRESSURERATE] =
			getModerableDecreasePressureRate;
	this->func[MODERABLEINCREASEPRESSURERATE] =
			getModerableIncreasePressureRate;
	this->func[MODERABLEMAXINCREASEPRESSURERATE] =
			getModerableMaxIncreasePressureRate;
	this->func[MODERABLEMAXPRESSURE] = getModerableMaxPressure;
	this->func[ROADINDEX] = getCurrentRoadIndex;
	this->func[VERTICALPROFILEINDEX] = getCurrentVerticalProfileIndex;
	this->func[SECTIONINDEX] = getCurrentSectionIndex;
	this->func[SECTIONPOSITION] = getSectionPosition;
	this->func[VERTICALPROFILEPOSITION] = getVerticalProfilePosition;
	this->func[COMPLETEDROADLENGTH] = getCompletedRoadLength;
	this->func[COMPLETEDSECTIONSLENGTH] = getCompletedSectionsLength;
	this->func[COMPLETEDVERTICALPROFILESLENGTH] =
			getCompletedVerticalProfilesLength;
	this->func[BRAKEPIPENOMINALPRESSURE] = getBrakePipeNominalPressure;
	this->func[BRAKEPIPEMINPRESSURE] = getBrakePipeMinPressure;
	this->func[BRAKEPIPEMAXPRESSURE] = getBrakePipeMaxPressure;
	this->func[BRAKEPIPEOVERLOADPRESSURE] = getBrakePipeOverLoadPressure;
	this->func[BRAKEPIPEPRESSURELAPRELEASERATE] =
			getBrakePipePressureLapReleaseRate;
	this->func[BRAKEPIPEPRESSURELAPSERVICERATE] =
			getBrakePipePressureLapServiceRate;
	this->func[BRAKEPIPEPRESSURERELEASERATE] = getBrakePipePressureReleaseRate;
	this->func[BRAKEPIPEPRESSURESERVICERATE] = getBrakePipePressureServiceRate;
	this->func[BRAKEPIPEFAULTSTATE] = getBrakePipeFaultState;
	this->func[BRAKEPIPELEAKAGE] = getBrakePipeLeakage;
	this->func[TIME] = getSimulationTime;
	this->func[TIMERANGE] = getSimulationTimeRange;
	this->func[VEHICLENUMBER] = getSimulationVehicleNumber;
	this->func[BRAKECYLINDERSPRINGMOVEMENT] = getBrakeCylinderDX;

	this->logFileName = "Log_variables.txt";
	this->Logger.open(logFileName.c_str());

}

RSTrainGetter::~RSTrainGetter() {
	// TODO Auto-generated destructor stub

	this->Logger.close();
}

double RSTrainGetter::GetAndLog(string variableName, int V_index, int BC_index,
		bool log_on_off) {

	double value = func[variableName](parent, V_index, BC_index);

	if (log_on_off) {

		if (parent->isLocomotive(V_index)) {
			Logger << variableName << " - " << parent->getTime() << " - L"
					<< V_index << " - B" << BC_index << " - " << value << endl;
		} else {
			Logger << variableName << " - " << parent->getTime() << " - V"
					<< V_index << " - " << value << endl;
		}

	}

	return value;
}
