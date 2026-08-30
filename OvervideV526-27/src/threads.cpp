#include "vex.h"

void onepin(){
    Lift.setVelocity(80,percent);
    Clawlift.setVelocity(80,percent);
    Clawlift.setPosition(0,degrees);
    Claw.setVelocity(40, percent);
    Lift.spinToPosition(100,degrees,false);
    Claw.spin(forward);
    Clawlift.spinToPosition(430, degrees,false);
    this_thread::sleep_for(0);
}