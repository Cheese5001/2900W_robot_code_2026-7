#include "2900winclide/subsystems.hpp"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"

namespace subsystems{
        lift::lift(int cascade_lift_1_port,int cascade_lift_2_port,int arm_1_port,int arm_2_port,char claw_solo_port)
        : cascade_motor_1(pros::Motor(cascade_lift_1_port, pros::v5::MotorGearset::blue, pros::v5::MotorEncoderUnits::degrees)),
          cascade_motor_2(pros::Motor(cascade_lift_2_port, pros::v5::MotorGearset::blue, pros::v5::MotorEncoderUnits::degrees)),
          arm_motor_1(pros::Motor(arm_1_port, pros::v5::MotorGearset::blue, pros::v5::MotorEncoderUnits::degrees)),
          arm_motor_2(pros::Motor(arm_2_port, pros::v5::MotorGearset::blue, pros::v5::MotorEncoderUnits::degrees)),
          claw((pros::adi::Pneumatics(claw_solo_port, false, false)))
        {

        }

        void setLiftState(double lift_voltage, double arm_voltage, bool claw_solanoid_state){
            
        }
    }