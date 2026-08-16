#include "2900winclide/subsystems.hpp"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"
#include <cmath>
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

        void lift::setControlLiftVoltage(double voltage){
          cascade_motor_1.move_voltage(floor(voltage));
          cascade_motor_2.move_voltage(floor(voltage));
        }
        
        void lift::setControlArmVoltage(double voltage){
          arm_motor_1.move_voltage(floor(voltage));
          arm_motor_2.move_voltage(floor(voltage));
        }

        void lift::setMacroArmRotation(double voltage){
          arm_motor_1.move_voltage(floor(voltage));
          arm_motor_2.move_voltage(floor(voltage));
        }

        void lift::setClawState(bool state){
          CLAW.set_value(state);
        }

        void lift::arm_position(ARM_MODE pos){
          currentMode = pos;
        }
        void lift::driverFunctions(){
          if (Controller.get_digital(DIGITAL_L1)){
              voltage_arm = 12000;
              }
          else if(Controller.get_digital(DIGITAL_L2)){
              voltage_arm = -12000;
          }
          else{
            voltage_arm = 0;
            armMotors.brake();
          }

          if (Controller.get_digital(DIGITAL_R1)){
            voltage_lift = 12000;
          }
          else if (Controller.get_digital(DIGITAL_R2)){
            voltage_lift = -12000;
          }
          else{
            voltage_lift = 0;
            CascadeMotors.brake();
          }

          if(Controller.get_digital(DIGITAL_A)){
            CLAW.extend();
          }
          else if(Controller.get_digital(DIGITAL_B)){
            CLAW.retract();
          }
        };

        
}