#-------------------------------------------------
#
# Project created by QtCreator 2014-08-16T10:51:08
#
#-------------------------------------------------

QT       -= core gui

TARGET = rs_train
TEMPLATE = lib

DEFINES += RS_TRAIN_LIBRARY

SOURCES += \
    src/eBalise.cpp \
    src/eBlock.cpp \
    src/eBSwitch.cpp \
    src/eCSwitch.cpp \
    src/eCurve.cpp \
    src/eIG.cpp \
    src/eLevelCrossing.cpp \
    src/eLineRoadInfo.cpp \
    src/eMagnet.cpp \
    src/ePhysicalBuilding.cpp \
    src/ePhysicalObjects.cpp \
    src/ePointRoadInfo.cpp \
    src/eRegion.cpp \
    src/eRoad.cpp \
    src/eSection.cpp \
    src/eSign.cpp \
    src/eSignal.cpp \
    src/eSSwitch.cpp \
    src/eSwitch.cpp \
    src/eTangent.cpp \
    src/eVerticalProfile.cpp \
    src/eVSwitch.cpp \
    src/pugixml.cpp \
    src/RailwayElement.cpp \
    src/RSTrainBrakeCylinder.cpp \
    src/RSTrainBrakePipeParser.cpp \
    src/RSTrainBrakePipePressureUpdater.cpp \
    src/RSTrainCar.cpp \
    src/RSTrainCarParser.cpp \
    src/RSTrainCarRollingResistanceCalculator.cpp \
    src/RSTrainControlValve.cpp \
    src/RSTrainCoupling.cpp \
    src/RSTrainDynamicBrakeForceCalculator.cpp \
    src/RSTrainDynamicModel.cpp \
    src/RSTrainGetter.cpp \
    src/RSTrainLocomotive.cpp \
    src/RSTrainLocomotiveControlValve.cpp \
    src/RSTrainLocomotiveParser.cpp \
    src/RSTrainLocomotiveRollingResistanceCalculator.cpp \
    src/RSTrainParser.cpp \
    src/RSTrainRailwayElementParser.cpp \
    src/RSTrainRoadWatcher.cpp \
    src/RSTrainRunforLocomotiveCoupling.cpp \
    src/RSTrainSimulator.cpp \
    src/RSTrainTractionForceCalculator.cpp \
    src/RSTrainVehicle.cpp \
    src/Test.cpp

HEADERS += \
    include/eBalise.h \
    include/eBlock.h \
    include/eBSwitch.h \
    include/eCSwitch.h \
    include/eCurve.h \
    include/eIG.h \
    include/eLevelCrossing.h \
    include/eLineRoadInfo.h \
    include/eMagnet.h \
    include/ePhysicalBuilding.h \
    include/ePhysicalObjects.h \
    include/ePointRoadInfo.h \
    include/eRegion.h \
    include/eRoad.h \
    include/eSection.h \
    include/eSign.h \
    include/eSignal.h \
    include/eSSwitch.h \
    include/eSwitch.h \
    include/eTangent.h \
    include/eVerticalProfile.h \
    include/eVSwitch.h \
    include/pugiconfig.hpp \
    include/pugixml.hpp \
    include/RailwayElement.h \
    include/RSTrainBrakeCylinder.h \
    include/RSTrainBrakePipeParser.h \
    include/RSTrainBrakePipePressureUpdater.h \
    include/RSTrainCar.h \
    include/RSTrainCarParser.h \
    include/RSTrainCarRollingResistanceCalculator.h \
    include/RSTrainControlValve.h \
    include/RSTrainCoupling.h \
    include/RSTrainDynamicBrakeForceCalculator.h \
    include/RSTrainDynamicModel.h \
    include/RSTrainGetter.h \
    include/RSTrainLocomotive.h \
    include/RSTrainLocomotiveControlValve.h \
    include/RSTrainLocomotiveParser.h \
    include/RSTrainLocomotiveRollingResistanceCalculator.h \
    include/RSTrainParser.h \
    include/RSTrainRailwayElementParser.h \
    include/RSTrainRoadWatcher.h \
    include/RSTrainRollingResistanceCalculator.h \
    include/RSTrainRunforLocomotiveCoupling.h \
    include/RSTrainSimulator.h \
    include/RSTrainTractionForceCalculator.h \
    include/RSTrainVehicle.h


INCLUDEPATH += "include"

unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix|win32: LIBS += -lboost_system

unix|win32: LIBS += -lboost_thread
