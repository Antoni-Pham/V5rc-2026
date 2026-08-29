#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:

motor LeftFront = motor(PORT11, ratio6_1, true);
motor LeftBack = motor(PORT12, ratio6_1, true);
motor RightFront = motor(PORT13, ratio6_1, false);
motor RightBack = motor(PORT14, ratio6_1, false);
motor Lift1 = motor(PORT7, ratio6_1, true);
motor Lift2 = motor(PORT8, ratio6_1, false);
motor Intake = motor(PORT20, ratio6_1, true);
motor Claw = motor(PORT10, ratio18_1, true);
motor Clawlift = motor(PORT9, ratio18_1, false);
inertial Inertialsensor = PORT21;

motor_group Lift = motor_group(Lift1, Lift2);

controller Controller1 = controller(primary);

void vexcodeInit( void ) {
  // nothing to initialize
}