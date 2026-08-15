#include "main.h"
#include "2900winclide/global.h"
#include "2900winclide/devices.hpp"
#include "2900winclide/subsystems.hpp"
#include "2900winclide/pid.hpp"
#include "lemlib/api.hpp"  // IWYU pragma: keep

subsystems::drivetrain drivetrain = subsystems::drivetrain(LEFT_MOTOR_1,
														   LEFT_MOTOR_2,
														   RIGHT_MOTOR_1,
														   RIGHT_MOTOR_2,
														   IMU1);

subsystems::lift lift = subsystems::lift(cascade_left,
										 cascade_right,
										 arm_left,
										 arm_right,
										 claw);
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	chassis.calibrate();
	chassis.setPose(0,0,0);
	pros::delay(100);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.	
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);


  
	while (true) {
			drivetrain.driverFunctions();
			lift.driverFunctions();
		pros::delay(20);                               // Run for 20 ms then update
	}
}