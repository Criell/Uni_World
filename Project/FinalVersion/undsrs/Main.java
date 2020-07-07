package undsrs;

import lejos.hardware.ev3.LocalEV3;
import lejos.hardware.lcd.LCD;
import lejos.hardware.motor.EV3LargeRegulatedMotor;
import lejos.hardware.motor.Motor;
import lejos.hardware.port.MotorPort;
import lejos.hardware.sensor.EV3TouchSensor;
import lejos.hardware.sensor.EV3UltrasonicSensor;
import lejos.hardware.motor.BasicMotor;
import lejos.utility.Delay;
import lejos.hardware.port.Port;
import lejos.hardware.sensor.EV3ColorSensor;
import lejos.hardware.Button;
import lejos.hardware.Sound;
import lejos.robotics.Color;
import lejos.robotics.filter.AbstractFilter;
import lejos.robotics.SampleProvider;

public class Main {

	public static void main(String[] args) {
		RobotControlSystem rcs;
		rcs = new RobotControlSystem();	
		
		rcs.milestoneOneTest();
		
	} 

}
