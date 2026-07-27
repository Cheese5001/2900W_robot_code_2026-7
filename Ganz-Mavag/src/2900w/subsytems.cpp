#include "2900winclide/subsystems.hpp"

namespace subsytems 
{
        lift::lift(int cascade_lift_1_port,int cascade_lift_2_port,int arm_1_port,int arm_2_port,char claw_solo_port)
        : cascade_motor_1(pros::Motor(cascade_lift_1_port, pros::v5::MotorGearset::blue, pros::v5::MotorEncoderUnits::degrees))
        {

        }
    }