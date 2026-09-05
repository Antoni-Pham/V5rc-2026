#include "vex.h"
using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(LeftFront, LeftBack),
//Right Motors:
motor_group(RightFront, RightBack),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT21,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
2.75,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.75,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
356.67,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT22,     -PORT22,

//LB:      //RB: 
PORT22,     -PORT22,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
6.0625,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 1;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  chassis.Gyro.calibrate();
  while(chassis.Gyro.isCalibrating()){
    vex::this_thread::sleep_for(10);
  }
  current_auton_selection = 1;
  while(!auto_started){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch(current_auton_selection){
      case 0:
        
        break;
      case 1:
        Brain.Screen.printAt(5, 140, "Auton red1 blue1");
        break;
      case 2:
        Brain.Screen.printAt(5, 140, "Auton red2 blue2");
        break;
      case 3:
        Brain.Screen.printAt(5, 140, "Auton red1 blue1 and pin");
        break;
      case 4:
        Brain.Screen.printAt(5, 140, "Auton red2 blue2 and pin");
        break;
      case 5:
        Brain.Screen.printAt(5, 140, "Auton red1 blue1 and pin and center");
        break;
      case 6:
        Brain.Screen.printAt(5, 140, "Auton 7");
        break;
      case 7:
        Brain.Screen.printAt(5, 140, "Auton 8");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  auto_started = true;                                      
  switch(current_auton_selection){ 
    case 0:
      
      break;
    case 1:         
      Red1Blue1Auto();
      break;
    case 2:
      Red2Blue2Auto();
      break;
    case 3:
      Red1Blue1AutoandPin();
      break;
    case 4:
      Red2Blue2AutoandPin();
      break;
    case 5:
      Red1Blue1AutoandPinandCenter();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {

  // User control code here, inside the loop
//   vex::this_thread::sleep_for(5000);
// switch(current_auton_selection){ 
//     case 0:
      
//       break;
//     case 1:         
//       Red1Blue1Auto();
//       break;
//     case 2:
//       Red2Blue2Auto();
//       break;
//     case 3:
//       swing_test();
//       break;
//     case 4:
//       full_test();
//       break;
//     case 5:
//       odom_test();
//       break;
//     case 6:
//       tank_odom_test();
//       break;
//     case 7:
//       holonomic_odom_test();
//       break;
//  }
  bool scoring = false;
  bool clawLiftOn = false;
  bool brainTimerOn = false;
  bool liftOn = false;
  bool buttonL1Pressed = false;
  bool buttonL2Pressed = false;
  bool intakeOn = false;
  bool scoringUsed = false;
  bool runningSequence = false;

  Lift.setStopping(hold);
  Lift.setVelocity(80.0, percent);
  Lift.setMaxTorque(100.0, percent);
  Claw.setVelocity(100.0, percent);
  Claw.setStopping(coast);
  Clawlift.setVelocity(80.0, percent);
  Lift.setMaxTorque(100.0, percent);
  Clawlift.setStopping(coast);
  Intake.setVelocity(100.0, percent);
  Intake.setStopping(coast);

  Lift.spinToPosition(135.0, degrees, true);
  Clawlift.spin(reverse);
  Claw.stop();
  Intake.stop();
  Clawlift.setStopping(hold);
  Brain.Timer.clear();
  brainTimerOn = true;
          while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_arcade();

    if (Brain.Timer.value() > 1.5 && brainTimerOn == true){
      Clawlift.stop();
      Clawlift.setPosition(0, degrees);
      brainTimerOn = false;
      scoring = false;
    }
    if (runningSequence == true && Lift.position(degrees) < 145.0){
        Brain.Timer.clear();
        brainTimerOn = true;
        Clawlift.spin(reverse);
        Claw.stop();
        Intake.stop();
        Clawlift.setStopping(hold);
        runningSequence = false;
    }
    if (scoringUsed == false){
      if(!Controller1.ButtonL1.pressing() && buttonL1Pressed){
        buttonL1Pressed = false;
      }
      if(!Controller1.ButtonL2.pressing() && buttonL2Pressed){
        Intake.spin(forward);
        buttonL1Pressed = false;
        buttonL2Pressed = false;
      }
      if(Controller1.ButtonL1.pressing() && !intakeOn && !buttonL1Pressed){
        buttonL1Pressed = true;
        Claw.spin(forward);
        Intake.spin(forward);
        intakeOn = true;
      } else if(Controller1.ButtonL1.pressing() && intakeOn && !buttonL1Pressed){
        buttonL1Pressed = true;
        Intake.stop();
        Claw.stop();
        intakeOn = false;
      } else if(Controller1.ButtonL2.pressing() && !buttonL2Pressed){
        buttonL2Pressed = true;
        Intake.spin(reverse);
        buttonL1Pressed = true;
      }
    
      if (Controller1.ButtonR2.pressing() && !brainTimerOn && !scoring){
        scoringUsed = true;
        buttonL1Pressed = false;
        intakeOn = false;
        Lift.spinToPosition(135.0, degrees, false);
        Clawlift.setStopping(hold);
        Clawlift.spinToPosition(540, degrees, false);
        Claw.spin(forward);
      } 
    }
    if (scoringUsed == true){
      if (!Controller1.ButtonL1.pressing() && !Controller1.ButtonL2.pressing() && clawLiftOn == true){
        Clawlift.stop();
        clawLiftOn = false;
      }
      if(Controller1.ButtonL1.pressing()){
        Clawlift.spin(forward);
        clawLiftOn = true;
      } else if(Controller1.ButtonL2.pressing()){
        Clawlift.spin(reverse);
        clawLiftOn = true;
      }
      if(Lift.position(degrees) <= 5 && Controller1.ButtonR1.pressing())
      {
        Lift.stop();
        liftOn = false;
      }
      if (!Controller1.ButtonR2.pressing() && !Controller1.ButtonR1.pressing() && liftOn == true){
        Lift.stop();
        liftOn = false;
      }
      if (Controller1.ButtonR2.pressing() && liftOn == false){
        Lift.spin(forward);
        liftOn = true;
      } else if (Controller1.ButtonR1.pressing() && liftOn == false){
        Intake.stop();
        if (Lift.position(degrees) > 5){
          Lift.spin(reverse);
          liftOn = true;
        } 
     }
     if (Controller1.ButtonX.pressing()){
       scoring = true;
       scoringUsed = false;
       chassis.drive_with_voltage(0.0, 0.0);
       Claw.spin(reverse);
       wait(0.4, seconds);
       Lift.spin(forward);
       wait(0.3, seconds);
       Clawlift.spin(forward);
       wait(0.4, seconds);
       Clawlift.stop();
       Claw.stop();
       wait(0.2, seconds);
       Lift.stop();
       waitUntil((Controller1.Axis3.position() > 50.0));
       chassis.drive_with_voltage(3.0, 3.0);
       wait(0.2, seconds);
       chassis.drive_with_voltage(0.0, 0.0);
       Lift.spinToPosition(105.0, degrees, false);

       runningSequence = true;
      }

      if (Controller1.ButtonA.pressing()){
        scoring = true;
        scoringUsed = false;
        Lift.spinToPosition(105.0, degrees, false);
        runningSequence = true;
      } 
    }

    vex::wait(20, msec); // Sleep the task for a short amount of time to
                         // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    vex::wait(100, msec);
  }
}
