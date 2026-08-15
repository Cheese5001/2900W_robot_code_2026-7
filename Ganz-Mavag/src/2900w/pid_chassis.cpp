#include "lemlib/api.hpp" // IWYU pragma: keep
#include "2900winclide/subsystems.hpp"
#include "2900winclide/global.h"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "2900winclide/pid.hpp"

extern subsystems::drivetrain drivetrain;

lemlib::Drivetrain drivetrainsetup(
    &drivetrain.getLeftDrive(), 
    &drivetrain.getRightDrive(), 
    10, 
    lemlib::Omniwheel::OLD_325,
    360,
    2
);

lemlib::OdomSensors sensors (
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &drivetrain.getIMU()
);

lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

lemlib::Chassis chassis(drivetrainsetup,
     linearController, 
     angularController, 
     sensors);