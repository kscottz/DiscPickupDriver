#include "WPILib.h"
#include <iostream>

using namespace::std;

class PickUpPrototype : public IterativeRobot
{

	AnalogChannel pickUpPmeter;
	AnalogChannel bumpUpPmeter;
	
	Victor pickUpRoller;
	Victor bumpUpRoller;
	
	static const int PICK_UP_PMETER_CHANNEL = 1;
	static const int BUMP_UP_PMETER_CHANNEL = 2;
	
	static const int PICK_UP_PWM_CHANNEL = 1;
	static const int BUMP_UP_PWM_CHANNEL = 2;
	
	static const int ANALOG_MODULE = 1;	
	
	static const float MAX_VOLTAGE = 5.0f; //the maximum voltage out of the potentiometers
	static const float MIN_VOLTAGE = 0.0f; 	//the minimum voltage
	
	
public:

	PickUpPrototype(void) : 
		pickUpPmeter(ANALOG_MODULE, PICK_UP_PMETER_CHANNEL), 
		bumpUpPmeter(ANALOG_MODULE, BUMP_UP_PMETER_CHANNEL),
		pickUpRoller(PICK_UP_PWM_CHANNEL),
		bumpUpRoller(BUMP_UP_PWM_CHANNEL)
	{
		
	}
	
	void RobotInit(void) {

	}
	
	void DisabledInit(void) {
		pickUpRoller.Set(0);
		bumpUpRoller.Set(0);
	}

	void AutonomousInit(void) {

	}

	void TeleopInit(void) {

	}
	
	void DisabledPeriodic(void)  {
		pickUpRoller.Set(0);
		bumpUpRoller.Set(0);
	}

	void AutonomousPeriodic(void) {

	}

	
	void TeleopPeriodic(void) {
		float pick_up_value = CalibrateVoltage(pickUpPmeter.GetAverageVoltage());
		float bump_up_value = CalibrateVoltage(bumpUpPmeter.GetAverageVoltage());
		
		cout << "Pick up roller set at " << pick_up_value * 100 << "%\t";
		cout << "Bump up roller set at " << bump_up_value * 100 << "%" << endl;
		
		pickUpRoller.Set(pick_up_value);
		bumpUpRoller.Set(bump_up_value);

	}
	
	//this function maps a value in [MIN_VOLTAGE, MAX_VOLTAGE] to one in [0, 1] for the victor to use
	float CalibrateVoltage(float voltage){
		return (voltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE);
	}

};

START_ROBOT_CLASS(PickUpPrototype);
