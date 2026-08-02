using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:

extern motor LeftFront;
extern motor LeftBack;
extern motor RightFront;
extern motor RightBack;
extern motor Lift1;
extern motor Lift2;
extern motor Intake;
extern motor Claw;
extern motor Clawlift;

extern motor_group LeftDrive;
extern motor_group RightDrive;
extern motor_group Lift;

extern inertial Gyro;

controller Controller1 = controller(primary);

void  vexcodeInit( void );