#pragma once
#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "global.h"

namespace subsystems {
    class drivetrain{

        pros::Motor left_1;
        pros::Motor left_2;


        pros::Motor right_1;
        pros::Motor right_2;

        pros::MotorGroup leftDrive = pros::MotorGroup(left_1);
        pros::MotorGroup rightDrive = pros::MotorGroup(right_1);
        
        //set up IMU
        pros::IMU imu_1;

        bool odomRunning = false;

        public:
        //allows for getting the motor data for lemlib to use
        //motor gorup getters
        pros::MotorGroup& getLeftDrive() { return leftDrive; }
        pros::MotorGroup& getRightDrive() { return rightDrive; }
        
        //imu getter
        pros::IMU& getIMU() { return imu_1; }

        //constructor
        drivetrain(int left_1_port, int left_2_port, 
                    int right_1_port, int right_2_port, 
                    int imu_1_port);


        //driver functions
        void driverFunctions();

        //helpers 
        void setDriveVoltage(double left_voltage, double right_voltage);

        void setBrakeMode(pros::motor_brake_mode_e brake_mode);

        void moveDistance(double inches, double speed, int timeout);

        void moveVelocity(double velocity);
        
        

  
    };

    enum Lift_Mode{
        tall_guy,
        dunk,
        yellow_light,
        get_out

    };

    class lift{
        pros::Motor cascade_motor_1;
        pros::Motor cascade_motor_2;
        pros::Motor arm_motor_1;
        pros::Motor arm_motor_2;
        pros::adi::Pneumatics CLAW;
        pros::MotorGroup CascadeMotors = pros::MotorGroup(cascade_motor_1);
        pros::MotorGroup armMotors = pros::MotorGroup(arm_motor_1);
        int lift_press_count = 0;   

        int arm_press_amount = 0;

        int claw_press_amount = 0;

        Lift_Mode currentMode = get_out;


        public:
        lift(int cascade_lift_1_port,    
            int cascade_lift_2_port,
            int arm_1_port,
            int arm_2_port,
            char claw_solo_port);

        void driverFunctions();
        void setLiftVoltage(double voltage);
        void setArmVoltage(double voltage);
        void setClawState(bool state);
    };
};