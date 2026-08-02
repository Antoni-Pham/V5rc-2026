#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:

motor LeftFront = motor(PORT13, ratio6_1, false);
motor LeftBack = motor(PORT14, ratio6_1, false);
motor RightFront = motor(PORT11, ratio6_1, true);
motor RightBack = motor(PORT12, ratio6_1, true);
motor Lift1 = motor(PORT18, ratio18_1, true);
motor Lift2 = motor(PORT19, ratio18_1, false);
motor Intake = motor(PORT20, ratio6_1, true);
motor Claw = motor(PORT4, ratio18_1, true);
motor Clawlift = motor(PORT3, ratio18_1, true);

motor_group LeftDrive = motor_group(LeftFront, LeftBack);
motor_group RightDrive = motor_group(RightFront, RightBack);
motor_group Lift = motor_group(Lift1, Lift2);

inertial Gyro = inertial(PORT21);

controller Controller1 = controller(primary);

void vexcodeInit( void ) {
  // nothing to initialize
}