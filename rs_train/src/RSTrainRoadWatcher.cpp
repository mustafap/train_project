/*
 * RSTrainRoadWatcher.cpp
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#include "RSTrainRoadWatcher.h"
#include "RSTrainVehicle.h"
#include "RailwayElement.h"
#include "eSwitch.h"
#include "eBSwitch.h"
#include "eCSwitch.h"
#include "eVSwitch.h"
#include "eSSwitch.h"
#include <iostream>
using namespace std;

RSTrainRoadWatcher::RSTrainRoadWatcher() {
	this->vehicleToWatch = 0;
	this->globalRailway = 0;
	this->roadPosition = 0;
	this->instantDisplacement = 0;
	this->currentRoad = 0;
	this->currentRoadIndex = 0;
	this->currentSection = 0;
	this->currentSectionIndex = 0;
	this->currentVerticalProfile = 0;
	this->currentVerticalProfileIndex = 0;
	this->completedRoadLength = 0;
	this->completedSectionsLength = 0;
	this->completedVerticalProfileLength = 0;
	this->prevTotalDisplacement = 0;
	this->verticalProfilePosition = 0;
	this->sectionPosition = 0;
}

RSTrainRoadWatcher::RSTrainRoadWatcher(RSTrainVehicle* vehicletowatch,
		RailwayElement* globalrailway) {

	this->vehicleToWatch = vehicletowatch;
	this->globalRailway = globalrailway;

	this->currentRoad = &(this->globalRailway->geteRoad(0));
	this->currentRoadIndex = 0;

	this->currentSection = &(this->currentRoad->geteSection(0));
	this->currentSectionIndex = 0;

	this->currentVerticalProfile = &(this->currentRoad->geteVerticalProfile(0));
	this->currentVerticalProfileIndex = 0;

	this->currentSwitch  = 0 ;
	this->SwitchPosition = 0;
	this->currentBSwitch = 0;
	this->currentCSwitch = 0;
	this->currentVSwitch = 0;
	this->currentSSwitch = 0;
	this->BSwitchActiveSection = 0;
	this->BSwitchCurrentConnectedItemNumber = 0;
	this->BSwitchNextConnectItemNumber = 0;

	this->BSwitchSlopeSign = 1;

	this->roadPosition = 0;
	this->instantDisplacement = 0;
	this->completedRoadLength = 0;
	this->completedSectionsLength = 0;
	this->completedVerticalProfileLength = 0;
	this->verticalProfilePosition = 0;
	this->sectionPosition = 0;
	this->prevTotalDisplacement = 0;

}

RSTrainRoadWatcher::~RSTrainRoadWatcher() {
}

RailwayElement* RSTrainRoadWatcher::getGlobalRailway() {
	return globalRailway;
}

void RSTrainRoadWatcher::setGlobalRailway(RailwayElement* globalRailway) {
	this->globalRailway = globalRailway;
}

RSTrainVehicle* RSTrainRoadWatcher::getVehicleToWatch() {
	return vehicleToWatch;
}

void RSTrainRoadWatcher::setVehicleToWatch(RSTrainVehicle* vehicleToWatch) {
	this->vehicleToWatch = vehicleToWatch;
}

bool RSTrainRoadWatcher::isSectionCurve() {
	return this->currentSection->isIsCurve();
}

bool RSTrainRoadWatcher::isSectionTangent() {
	return !(this->currentSection->isIsCurve());
}

double RSTrainRoadWatcher::getSectionLength() {
	if (this->isSectionCurve())
		return this->currentSection->getCurve().getLength();
	else
		return this->currentSection->getTangent().getLength();
}

double RSTrainRoadWatcher::getSectionBeginCoordinate() {
	if (this->isSectionCurve())
		return this->currentSection->getCurve().getBeginCoordinate();
	else
		return this->currentSection->getTangent().getBeginCoordinate();
}

double RSTrainRoadWatcher::getSectionEndCoordinate() {
	if (this->isSectionCurve())
		return this->currentSection->getCurve().getEndCoordinate();
	else
		return this->currentSection->getTangent().getEndCoordinate();
}

double RSTrainRoadWatcher::getSectionFOuter() {
	if (this->isSectionCurve())
		return this->currentSection->getCurve().getOuter();
	else
		return this->currentSection->getTangent().getOuter();
}

double RSTrainRoadWatcher::getSectionFInner() {
	if (this->isSectionCurve())
		return this->currentSection->getCurve().getInner();
	else
		return this->currentSection->getTangent().getInner();
}

double RSTrainRoadWatcher::getSectionFFlange() {
	if (this->isSectionCurve())
		return this->currentSection->getCurve().getFlange();
	else
		return this->currentSection->getTangent().getFlange();
}

double RSTrainRoadWatcher::getSectionCurveRadius() {

	if(currentRoad != 0){

		if (this->isSectionCurve())
			return this->currentSection->getCurve().getCurveRadious();
		else
			return 0;

	}

	if(currentSwitch != 0){

		if (currentSwitchType == "ST_B") {

			if(BSwitchActiveSection == 2){

				return this->currentBSwitch->getCurveRadius();

			}else{
				return 0;
			}

		}
		if (currentSwitchType == "ST_C") {

		}
		if (currentSwitchType == "ST_V") {

		}
		if (currentSwitchType == "ST_S") {

		}



	}

}

double RSTrainRoadWatcher::getVerticalProfileLength() {
	return this->currentVerticalProfile->getLength();
}

double RSTrainRoadWatcher::getVerticalProfileSlope() {

	if(currentRoad != 0){
		return this->currentVerticalProfile->getSlope();
	}

	if(currentSwitch != 0){

		if(currentSwitchType == "ST_B"){

			if(this->BSwitchActiveSection == 1){

				return (this->BSwitchSlopeSign)*(this->currentBSwitch->getSlope12());
			}
			if(this->BSwitchActiveSection == 2){

				return (this->BSwitchSlopeSign)*(this->currentBSwitch->getSlope13());
			}

		}
		if(currentSwitchType == "ST_C"){

		}
		if(currentSwitchType == "ST_V"){

		}
		if(currentSwitchType == "ST_S"){

		}

	}

}

eRoad* RSTrainRoadWatcher::getCurrentRoad() {
	return currentRoad;
}

void RSTrainRoadWatcher::setCurrentRoad(eRoad* currentRoad) {
	this->currentRoad = currentRoad;
}

int RSTrainRoadWatcher::getCurrentRoadIndex() {
	return currentRoadIndex;
}

void RSTrainRoadWatcher::setCurrentRoadIndex(int currentRoadIndex) {

	// take the index of current road
	this->currentRoadIndex = currentRoadIndex;

	// assisgn the current road
	this->setCurrentRoad(&(this->globalRailway->geteRoadFromGlobalID(currentRoadIndex)));
}

eSection* RSTrainRoadWatcher::getCurrentSection() {
	return currentSection;
}

void RSTrainRoadWatcher::setCurrentSection(eSection* currentSection) {
	this->currentSection = currentSection;
}

int RSTrainRoadWatcher::getCurrentSectionIndex() {
	return currentSectionIndex;
}

void RSTrainRoadWatcher::setCurrentSectionIndex(int currentSectionIndex) {
	this->currentSectionIndex = currentSectionIndex;
	this->setCurrentSection(
			&(this->currentRoad->geteSection(currentSectionIndex)));
}

eVerticalProfile* RSTrainRoadWatcher::getCurrentVerticalProfile() {
	return currentVerticalProfile;
}

void RSTrainRoadWatcher::setCurrentVerticalProfile(
		eVerticalProfile* currentVerticalProfile) {
	this->currentVerticalProfile = currentVerticalProfile;
}

int RSTrainRoadWatcher::getCurrentVerticalProfileIndex() {
	return currentVerticalProfileIndex;

}

void RSTrainRoadWatcher::setCurrentVerticalProfileIndex(
		int currentVerticalProfileIndex) {
	this->currentVerticalProfileIndex = currentVerticalProfileIndex;
	this->setCurrentVerticalProfile(
			&(this->currentRoad->geteVerticalProfile(
					currentVerticalProfileIndex)));
}

double RSTrainRoadWatcher::getRoadPosition() {
	return roadPosition;
}

void RSTrainRoadWatcher::setRoadPosition(double roadPosition) {
	this->roadPosition = roadPosition;
}

double RSTrainRoadWatcher::getCompletedRoadLength() {
	return completedRoadLength;
}

void RSTrainRoadWatcher::setCompletedRoadLength(double completedRoadLength) {
	this->completedRoadLength = completedRoadLength;
}

double RSTrainRoadWatcher::getCompletedSectionsLength() {
	return completedSectionsLength;
}

void RSTrainRoadWatcher::setCompletedSectionsLength(
		double completedSectionsLength) {
	this->completedSectionsLength = completedSectionsLength;
}

double RSTrainRoadWatcher::getCompletedVerticalProfileLength() {
	return completedVerticalProfileLength;
}

void RSTrainRoadWatcher::setCompletedVerticalProfileLength(
		double completedVerticalProfileLength) {
	this->completedVerticalProfileLength = completedVerticalProfileLength;
}

double RSTrainRoadWatcher::getInstantDisplacement() {
	return instantDisplacement;
}

void RSTrainRoadWatcher::setInstantDisplacement(double instantDisplacement) {
	this->instantDisplacement = instantDisplacement;
}

double RSTrainRoadWatcher::getPrevTotalDisplacement() {
	return prevTotalDisplacement;
}

void RSTrainRoadWatcher::setPrevTotalDisplacement(
		double prevTotalDisplacement) {
	this->prevTotalDisplacement = prevTotalDisplacement;
}

double RSTrainRoadWatcher::getRoadFrontPosition() {
	return roadFrontPosition;
}

void RSTrainRoadWatcher::setRoadFrontPosition(double roadFrontPosition) {
	this->roadFrontPosition = roadFrontPosition;
}

double RSTrainRoadWatcher::getRoadRearPosition() {
	return roadRearPosition;
}

void RSTrainRoadWatcher::setRoadRearPosition(double roadRearPosition) {
	this->roadRearPosition = roadRearPosition;
}

double RSTrainRoadWatcher::getSectionPosition() {
	return sectionPosition;
}

void RSTrainRoadWatcher::setSectionPosition(double sectionPosition) {
	this->sectionPosition = sectionPosition;
}

double RSTrainRoadWatcher::getVerticalProfilePosition() {
	return verticalProfilePosition;
}

void RSTrainRoadWatcher::setVerticalProfilePosition(
		double verticalProfilePosition) {
	this->verticalProfilePosition = verticalProfilePosition;
}

void RSTrainRoadWatcher::Init() {

	cout<<"InitRoad: "<<currentRoad->getGlobalId()<<endl;
	// initialize the section
	this->InitSection();

	// initialize the vertical profile
	this->InitVerticalProfile();

	// update the vehicle dependen on the road position and road characteristic
	this->updateVehicle();

}

void RSTrainRoadWatcher::InitSection() {

	this->sectionPosition = 0;
	this->completedSectionsLength = 0;
	this->currentSectionIndex = 0;

	// take section number
	int SectionSize = this->currentRoad->getSectionSize();

	// find the beginning section
	for (int i = 0; i < SectionSize; i++) {

		// take the current section
		this->currentSection = &(this->currentRoad->geteSection(i));

		// increase the completed section value
		this->completedSectionsLength += this->getSectionLength();

		// if completed section size is greater than the initial position
		if (this->completedSectionsLength > this->roadPosition) {

			this->currentSectionIndex = i;

			// decrease the completed section value by the current section length
			// current section has not been completed yet
			this->completedSectionsLength -= this->getSectionLength();

			// find the current section position
			this->sectionPosition = this->roadPosition
					- this->completedSectionsLength;

			// break the loop, because section has been found
			break;
		}
	}
}

void RSTrainRoadWatcher::InitVerticalProfile() {

	// same explanations as in InitSection() function

	this->verticalProfilePosition = 0;
	this->completedVerticalProfileLength = 0;
	this->verticalProfilePosition = 0;

	int VerticalProfileSize = this->currentRoad->getVerticalProfileSize();

	for (int i = 0; i < VerticalProfileSize; i++) {
		this->currentVerticalProfile = &(this->currentRoad->geteVerticalProfile(
				i));
		this->completedVerticalProfileLength +=
				(this->getVerticalProfileLength());
		if (this->completedVerticalProfileLength > this->roadPosition) {
			this->currentVerticalProfileIndex = i;
			this->completedVerticalProfileLength -=
					this->getVerticalProfileLength();
			this->verticalProfilePosition = this->roadPosition
					- this->completedVerticalProfileLength;
			break;
		}
	}
}

void RSTrainRoadWatcher::updatePositions() {

	//Find displacement from previous displacement
	this->instantDisplacement = this->vehicleToWatch->posvel[0]
			- this->prevTotalDisplacement;
	this->prevTotalDisplacement = this->vehicleToWatch->posvel[0];
	//Add displacement to the localposition
	//Check road, length update road if required
	if(currentRoad != 0){

		this->updateRoad();

	}else{

		this->updateSwitch();
	}


}

void RSTrainRoadWatcher::updateRoad() {

	// calculates the new position of the vehicle
	double newRoadPosition = this->roadPosition + this->instantDisplacement;

	// if the new position is greater than the current road length, update the road information
	if (newRoadPosition > this->currentRoad->getLength()) {

		int FolRoad = this->currentRoad->getNextConnectedRoadId();

		this->roadPosition = newRoadPosition - this->currentRoad->getLength();

		if (FolRoad != -1) {

			this->currentRoad = &(this->globalRailway->geteRoadFromGlobalID(
					FolRoad));
			// it is required to initialize the sections and vertical profile, because road has changed

			// init road
			this->Init();

			this->currentSwitch = 0;

		} else {

			initSwitch();

			this->currentRoad = 0;


		}

		// find the position on the new road





	} else { // if the new position is smaller than the road length

		// assign new position as road position
		this->roadPosition = newRoadPosition;

		// update the section and vertical profile information
		this->updateSection();
		this->updateVerticalProfile();
	}
	//Check localPosition and switch information to update change the road instante to the new one
	//update localPostion for new road
	//update Section
	//update verticalProfile

}

void RSTrainRoadWatcher::initSwitch() {


	int FolSwID = this->currentRoad->getNextConnectedSwitchId();

	this->currentSwitch = &(this->globalRailway->geteSwitchFromGlobalID(FolSwID));

	cout<<"InitSwitch: "<<this->currentSwitch->getGlobalId()<<endl;

	this->currentSwitchType = this->currentSwitch->getType();

	if(currentSwitchType == "ST_B"){

		//Take B switch member
		this->currentBSwitch = &(this->currentSwitch->getBSwitch()[0]);

		//Decide position of current road

		if(this->currentBSwitch->getConnectedItemId1() == this->currentRoad->getGlobalId()){
			this->BSwitchCurrentConnectedItemNumber = 1;
		}

		if(this->currentBSwitch->getConnectedItemId2() == this->currentRoad->getGlobalId()){
			this->BSwitchCurrentConnectedItemNumber = 2;
		}

		if(this->currentBSwitch->getConnectedItemId3() == this->currentRoad->getGlobalId()){
			this->BSwitchCurrentConnectedItemNumber = 3;
		}


		if(this->BSwitchCurrentConnectedItemNumber  == 1){

			this->BSwitchSlopeSign = 1;

			string BSwitchState1 = this->currentSwitch->getState1();

			if(BSwitchState1 == "SS_SET"){
				//curve Section
				this->BSwitchActiveSection = 2;
				this->BSwitchNextConnectItemNumber = 3;
			}else{
				// tangent Section
				this->BSwitchActiveSection = 1;
				this->BSwitchNextConnectItemNumber = 2;
			}

		}

		if(this->BSwitchCurrentConnectedItemNumber == 2){

			this->BSwitchSlopeSign = -1;

			//tangent Section
			this->BSwitchActiveSection = 1;

			this->BSwitchNextConnectItemNumber = 1;


		}

		if(this->BSwitchCurrentConnectedItemNumber == 3){

			this->BSwitchSlopeSign = -1;

			// curve section
			this->BSwitchActiveSection = 2;

			this->BSwitchNextConnectItemNumber = 1;
		}



	}

	if(currentSwitchType == "ST_C"){

		this->currentCSwitch = &(this->currentSwitch->getCSwitch()[0]);

		// do specific implications for the switch type

	}
	if(currentSwitchType == "ST_V"){

		this->currentVSwitch = &(this->currentSwitch->getVSwitch()[0]);

		// do specific implications for the switch type

	}
	if(currentSwitchType == "ST_S"){

		this->currentSSwitch = &(this->currentSwitch->getSSwitch()[0]);

		// do specific implications for the switch type

	}


}


void RSTrainRoadWatcher::updateSwitch() {

	if (this->currentSwitchType == "ST_B") {

		double newSwitchPosition = this->roadPosition
				+ this->instantDisplacement;

		if (BSwitchActiveSection == 1) {

			if (newSwitchPosition > this->currentBSwitch->getTangentLength()) {

				this->roadPosition = newSwitchPosition
						- this->currentBSwitch->getTangentLength();

				if (this->BSwitchNextConnectItemNumber == 1) {

					int FolRoad = this->currentBSwitch->getConnectedItemId1();

					this->currentRoad =
							&(this->globalRailway->geteRoadFromGlobalID(FolRoad));

					this->Init();

					this->currentSwitch = 0;
				}

				if (this->BSwitchNextConnectItemNumber == 2) {

					int FolRoad = this->currentBSwitch->getConnectedItemId2();

					this->currentRoad =
							&(this->globalRailway->geteRoadFromGlobalID(FolRoad));

					this->Init();

					this->currentSwitch = 0;
				}

				if (this->BSwitchNextConnectItemNumber == 3) {

					int FolRoad = this->currentBSwitch->getConnectedItemId3();

					this->currentRoad =
							&(this->globalRailway->geteRoadFromGlobalID(FolRoad));

					this->Init();

					this->currentSwitch = 0;
				}

			} else {

				this->roadPosition = newSwitchPosition;
			}

		}

		if (BSwitchActiveSection == 2) {

			if (newSwitchPosition > this->currentBSwitch->getCurveLength()) {

				this->roadPosition = newSwitchPosition
						- this->currentBSwitch->getCurveLength();

				if (this->BSwitchNextConnectItemNumber == 1) {

					int FolRoad = this->currentBSwitch->getConnectedItemId1();

					this->currentRoad =
							&(this->globalRailway->geteRoadFromGlobalID(FolRoad));

					this->Init();

					this->currentSwitch = 0;
				}

				if (this->BSwitchNextConnectItemNumber == 2) {

					int FolRoad = this->currentBSwitch->getConnectedItemId2();

					this->currentRoad =
							&(this->globalRailway->geteRoadFromGlobalID(FolRoad));

					this->Init();

					this->currentSwitch = 0;
				}

				if (this->BSwitchNextConnectItemNumber == 3) {

					int FolRoad = this->currentBSwitch->getConnectedItemId3();

					this->currentRoad =
							&(this->globalRailway->geteRoadFromGlobalID(FolRoad));

					this->Init();

					this->currentSwitch = 0;
				}

			} else {

				this->roadPosition = newSwitchPosition;
			}

		}

	}
	if (this->currentSwitchType == "ST_C") {

	}
	if (this->currentSwitchType == "ST_V") {

	}
	if (this->currentSwitchType == "ST_S") {

	}
}

void RSTrainRoadWatcher::updateSection() {


	// calculate new section position
	double newSectionPosition = this->sectionPosition
			+ this->instantDisplacement;


	// if new section position is greater than the section length
	if (newSectionPosition > this->getSectionLength()) {
		// update completed section value, because section has been completed
		this->completedSectionsLength += this->getSectionLength();

		// update position on the new section
		this->sectionPosition = newSectionPosition - this->getSectionLength();

		// increase section index
		this->currentSectionIndex++;

		// take the new section
		this->currentSection = &(this->currentRoad->geteSection(
				this->currentSectionIndex));
	} else // if new section length is smaller than section length
	{
		// update sectional position
		this->sectionPosition = newSectionPosition;
	}

}

void RSTrainRoadWatcher::updateVerticalProfile() {

	// same as in the updateSection() function

	double newVerticalProfilePosition = this->verticalProfilePosition
			+ this->instantDisplacement;
	if (newVerticalProfilePosition > this->getVerticalProfileLength()) {
		this->completedVerticalProfileLength +=
				this->getVerticalProfileLength();
		this->verticalProfilePosition = newVerticalProfilePosition
				- this->getVerticalProfileLength();
		this->currentVerticalProfileIndex++;
		this->currentVerticalProfile = &(this->currentRoad->geteVerticalProfile(
				this->currentVerticalProfileIndex));
		//update Vertical Profile Informations on vehicle
	} else {
		this->verticalProfilePosition = newVerticalProfilePosition;
	}
}

void RSTrainRoadWatcher::updateVehicle() {

	// take the length of the vehicle
	double length = this->vehicleToWatch->getLength();

	// find front position of the vagon
	this->roadFrontPosition = this->roadPosition + length / 2;
	this->vehicleToWatch->setFrontPosition(this->roadFrontPosition);

	// fin back position of the vagon
	this->roadRearPosition = this->roadPosition - length / 2;
	this->vehicleToWatch->setRearPosition(this->roadRearPosition);

	// update slope information of the vehicle
	this->vehicleToWatch->setSlope((this->getVerticalProfileSlope())/1000);

	// update curve value of the vehicle
	this->vehicleToWatch->setCurve(this->getSectionCurveRadius());

}


void RSTrainRoadWatcher::update() {

	this->updatePositions();
	this->updateVehicle();
	//Update positions depending on the vehicle movement
	//Iterate VerticalProfile depending on Local position data
	//Iterate Section depending on Local position data
}

