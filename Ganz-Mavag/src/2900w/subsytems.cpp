#include "2900winclide/subsystems.hpp"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"

namespace subsystems{
        lift::lift(int cascade_lift_1_port,int cascade_lift_2_port,int arm_1_port,int arm_2_port,char claw_solo_port)
        : cascade_motor_1(pros::Motor(cascade_lift_1_port, pros::v5::MotorGearset::blue, pros::v5::MotorEncoderUnits::degrees)),
          cascade_motor_2(pros::Motor(cascade_lift_2_port, pros::v5::MotorGearset::blue, pros::v5::MotorEncoderUnits::degrees)),
          arm_motor_1(pros::Motor(arm_1_port, pros::v5::MotorGearset::green, pros::v5::MotorEncoderUnits::degrees)),
          arm_motor_2(pros::Motor(arm_2_port, pros::v5::MotorGearset::green, pros::v5::MotorEncoderUnits::degrees)),
          CLAW((pros::adi::Pneumatics(claw_solo_port, false, false)))
        {
          CascadeMotors.append(cascade_motor_2);

          armMotors.append(arm_motor_2);
        }

        void setLiftState(double voltage){
          cascade_motor_1.move_voltage(floor(voltage));
            
        }
    }