/*
 * RSTrainRoadWatcher.h
 *
 *  Created on: 23 Mar 2014
 *      Author: Cihan UYANIK
 */

#ifndef RSTRAINROADWATCHER_H_
#define RSTRAINROADWATCHER_H_
#include <string>
#include <iostream>
using namespace std;


class RSTrainVehicle;
class RailwayElement;
class eRoad;
class eVerticalProfile;
class eSection;
class eSwitch;
class eBSwitch;
class eCSwitch;
class eVSwitch;
class eSSwitch;

/**
 * RSTrainRoadWatcher
 *
 * Rail road watcher class
 *
 * Calculates the displacement of a vagon or locomotive for every time step and
 * watches the physical changes on the rail road, depending on the positional changes
 */
class RSTrainRoadWatcher {

private:

	/**
	 * Parent object
	 */
	RSTrainVehicle* vehicleToWatch;

	/**
	 * Rail Road
	 */
	RailwayElement* globalRailway;

	/**
	 * Current Road Index
	 */
	int currentRoadIndex;

	/**
	 * Current Road instance
	 */
	eRoad* currentRoad;

	/**
	 * Current Vertical Profile Index
	 */
	int currentVerticalProfileIndex;

	/**
	 * Current Vertical Profile instance
	 */
	eVerticalProfile* currentVerticalProfile;

	/**
	 * Current Section Index
	 */
	int currentSectionIndex;

	/**
	 * Current Section instance
	 */
	eSection* currentSection;

	/**
	 * Read position of the parent vehicle on the road
	 */
	double roadRearPosition;

	/**
	 * Front position of the parent vehicle on the road
	 */
	double roadFrontPosition;

	/**
	 * Road position (mid) of the parent vehicle on the road
	 */
	double roadPosition;

	/**
	 * Sectional position of the vehicle
	 */
	double sectionPosition;

	/**
	 * Vertical profile position of the vehicle
	 */
	double verticalProfilePosition;

	/**
	 * Instant displacement of the vehicle
	 */
	double instantDisplacement;

	/**
	 * Previous Total Displacement of the vehicle
	 */
	double prevTotalDisplacement;

	/**
	 * Completed road length
	 */
	double completedRoadLength;

	/**
	 * Completed sectional length
	 */
	double completedSectionsLength;

	/**
	 * Completed vertical profile length
	 */
	double completedVerticalProfileLength;


	eSwitch* currentSwitch;
	string currentSwitchType;
	double SwitchPosition;

	eBSwitch* currentBSwitch;
	int BSwitchCurrentConnectedItemNumber;
	int BSwitchSlopeSign;
	int BSwitchActiveSection;
	int BSwitchNextConnectItemNumber;


	eCSwitch* currentCSwitch;
	int CSwitchSlopeSign;

	eVSwitch* currentVSwitch;
	int VSwitchSlopeSign;

	eSSwitch* currentSSwitch;
	int SSwitchSlopeSign;

public:

	/**
	 * Default Constructor of RSTrainRoadWatcher
	 */
	RSTrainRoadWatcher();

	/**
	 * Constructor of RSTrainRoadWatcher
	 * @param vehicletowatch
	 * @param globalrailway
	 */
	RSTrainRoadWatcher(RSTrainVehicle* vehicletowatch,
			RailwayElement* globalrailway);

	/**
	 * Destructor of RSTrainRoadWatcher
	 */
	virtual ~RSTrainRoadWatcher();

	/**
	 * Getter
	 * @return
	 */
	RailwayElement* getGlobalRailway();

	/**
	 * Setter
	 * @param globalRailway
	 */
	void setGlobalRailway(RailwayElement* globalRailway);

	/**
	 * Getter
	 * @return
	 */
	RSTrainVehicle* getVehicleToWatch();

	/**
	 * Setter
	 * @param vehicleToWatch
	 */
	void setVehicleToWatch(RSTrainVehicle* vehicleToWatch);

	/**
	 * Getter
	 * @return
	 */
	eRoad* getCurrentRoad();

	/**
	 * Setter
	 * @param currentRoad
	 */
	void setCurrentRoad(eRoad* currentRoad);

	/**
	 * Getter
	 * @return
	 */
	int getCurrentRoadIndex();

	/**
	 * Setter
	 * @param currentRoadIndex
	 */
	void setCurrentRoadIndex(int currentRoadIndex);

	/**
	 * Getter
	 * @return
	 */
	eSection* getCurrentSection();

	/**
	 * Setter
	 * @param currentSection
	 */
	void setCurrentSection(eSection* currentSection);

	/**
	 * Getter
	 * @return
	 */
	int getCurrentSectionIndex();

	/**
	 * Setter
	 * @param currentSectionIndex
	 */
	void setCurrentSectionIndex(int currentSectionIndex);

	/**
	 * Getter
	 * @return
	 */
	eVerticalProfile* getCurrentVerticalProfile();

	/**
	 * Setter
	 * @param currentVerticalProfile
	 */
	void setCurrentVerticalProfile(eVerticalProfile* currentVerticalProfile);

	/**
	 * Getter
	 * @return
	 */
	int getCurrentVerticalProfileIndex();

	/**
	 * Setter
	 * @param currentVerticalProfileIndex
	 */
	void setCurrentVerticalProfileIndex(int currentVerticalProfileIndex);

	/**
	 * Getter
	 * @return
	 */
	double getRoadPosition();

	/**
	 * Setter
	 * @param localPosition
	 */
	void setRoadPosition(double localPosition);

	/**
	 * Getter
	 * @return
	 */
	double getCompletedRoadLength() ;

	/**
	 * Setter
	 * @param completedRoadLength
	 */
	void setCompletedRoadLength(double completedRoadLength);

	/**
	 * Getter
	 * @return
	 */
	double getCompletedSectionsLength() ;

	/**
	 * Setter
	 * @param completedSectionsLength
	 */
	void setCompletedSectionsLength(double completedSectionsLength);

	/**
	 * Getter
	 * @return
	 */
	double getCompletedVerticalProfileLength() ;

	/**
	 * Setter
	 * @param completedVerticalProfileLength
	 */
	void setCompletedVerticalProfileLength(
			double completedVerticalProfileLength);

	/**
	 * Getter
	 * @return
	 */
	double getInstantDisplacement() ;

	/**
	 * Setter
	 * @param instantDisplacement
	 */
	void setInstantDisplacement(double instantDisplacement);

	/**
	 * Getter
	 * @return
	 */
	double getPrevTotalDisplacement() ;

	/**
	 * Setter
	 * @param prevTotalDisplacement
	 */
	void setPrevTotalDisplacement(double prevTotalDisplacement);

	/**
	 * Getter
	 * @return
	 */
	double getRoadFrontPosition() ;

	/**
	 * Setter
	 * @param roadFrontPosition
	 */
	void setRoadFrontPosition(double roadFrontPosition);

	/**
	 * Getter
	 * @return
	 */
	double getRoadRearPosition() ;

	/**
	 * Setter
	 * @param roadRearPosition
	 */
	void setRoadRearPosition(double roadRearPosition);

	/**
	 * Getter
	 * @return
	 */
	double getSectionPosition() ;

	/**
	 * Setter
	 * @param sectionPosition
	 */
	void setSectionPosition(double sectionPosition);

	/**
	 * Getter
	 * @return
	 */
	double getVerticalProfilePosition() ;

	/**
	 * Setter
	 * @param verticalProfilePosition
	 */
	void setVerticalProfilePosition(double verticalProfilePosition);



	/**
	 * Initializes the watcher object and find the sections and vertical profiles depending on the road position
	 */
	void Init();

	/**
	 * Initializes the section information
	 */
	void InitSection();

	/**
	 * Initializes the vertical profile information
	 */
	void InitVerticalProfile();

	/**
	 * updates positions depending on instant displacement
	 */

	void initSwitch();

	void updatePositions();

	/**
	 * updates road information of the vehicle
	 */
	void updateRoad();

	void updateSwitch();
	/**
	 * updates section information of the vehicle
	 */
	void updateSection();

	/**
	 * updates vertical profile of the vehicle
	 */
	void updateVerticalProfile();

	/**
	 * updates vehicle information depending on sectional and vertical information
	 */
	void updateVehicle();

	//Supporter Functions
	//Section

	/**
	 * Returns current section length
	 * @return section length
	 */
	double getSectionLength();

	/**
	 * Returns current section begin coordinate
	 * @return current section begin coordinate
	 */
	double getSectionBeginCoordinate();

	/**
	 * Returns current section end coordinate
	 * @return current section end coordinate
	 */
	double getSectionEndCoordinate();

	/**
	 * Returns current section FOuter (??)
	 * @return current section FOuter
	 */
	double getSectionFOuter();

	/**
	 * Returns current section FInner(??)
	 * @return current section FInner
	 */
	double getSectionFInner();

	/**
	 * Returns current section FFlange(??)
	 * @return current section FFlange
	 */
	double getSectionFFlange();

	/**
	 * Returns current section curve radius
	 * @return current section curve radius
	 */
	double getSectionCurveRadius();

	/**
	 * Current section is curve or not
	 * @return bool variable
	 */
	bool isSectionCurve();

	/**
	 * Current section is tangent or not
	 * @return bool variable
	 */
	bool isSectionTangent();

	/**
	 * Returns current vertical profile length
	 * @return current vertical profile length
	 */
	double getVerticalProfileLength();

	/**
	 * Returns current vertical profile slope
	 * @return current vertical profile slope
	 */
	double getVerticalProfileSlope();


	/**
	 * Updates road positions and vehicle information depending on sectional and vertical profile information
	 */
	void update();

};

#endif /* RSTRAINROADWATCHER_H_ */
