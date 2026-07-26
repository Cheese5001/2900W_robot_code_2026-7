#include "2900winclide/subsystems.hpp"


namespace subsystems
{
    drivetrain::drivetrain(int left_1_port, int left_2_port, 
                           int right_1_port, int right_2_port, 
                           int imu_1_port)
        : left_1(pros::Motor(left_1_port, pros::v5::MotorGear::blue, pros::v5::MotorUnits::degrees)),
          left_2(pros::Motor(left_2_port, pros::v5::MotorGear::blue, pros::v5::MotorUnits::degrees)),
          
          right_1(pros::Motor(right_1_port, pros::v5::MotorGear::blue, pros::v5::MotorUnits::degrees)),
          right_2(pros::Motor(right_2_port, pros::v5::MotorGear::blue, pros::v5::MotorUnits::degrees)),
          imu_1(pros::Imu(imu_1_port))
    {
        // adds the rest of the motors to the group
        leftDrive.append(left_2);
        rightDrive.append(right_2);

    }
    void drivetrain::driverFunctions()
    {
        int left_input = Controller.get_analog(ANALOG_LEFT_Y);
        int right_input = Controller.get_analog(ANALOG_RIGHT_Y);

        int left_output = linearToCubed(left_input, 127, 1);
        int right_output = linearToCubed(left_input, 127, 1);

        
    }
    void drivetrain::setDriveVoltage(double left_voltage, double right_voltage){

    }

}