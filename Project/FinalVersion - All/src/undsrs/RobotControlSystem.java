package undsrs;

import lejos.hardware.Button;
import lejos.hardware.ev3.LocalEV3;
import lejos.hardware.lcd.LCD;
import lejos.hardware.motor.EV3LargeRegulatedMotor;
import lejos.hardware.motor.Motor;
import lejos.hardware.port.MotorPort;
import lejos.hardware.port.Port;
import lejos.hardware.sensor.EV3ColorSensor;
import lejos.hardware.sensor.EV3TouchSensor;
import lejos.hardware.sensor.EV3UltrasonicSensor;
import lejos.robotics.chassis.Chassis;
import lejos.robotics.chassis.Wheel;
import lejos.robotics.chassis.WheeledChassis;
import lejos.robotics.navigation.MovePilot;
import lejos.utility.Delay;

public class RobotControlSystem {
	
	public MovePilot pilot;
	
	public UltrasonicSensor ultrasonicSensor;
	public ColourSensor colourSensor;
	
	public Port s1;
	public Port s2;
	public Port s3;
	public Port s4;

	
	public RobotControlSystem() {
		
		//Initialize the differential pilot for movement control
		EV3LargeRegulatedMotor motor1 = new EV3LargeRegulatedMotor( MotorPort.A);
		EV3LargeRegulatedMotor motor2 = new EV3LargeRegulatedMotor( MotorPort.D);
		
		Wheel wheel1 = WheeledChassis.modelWheel(motor1, 5.6).offset(-5.5);
		Wheel wheel2 = WheeledChassis.modelWheel(motor2, 5.6).offset(5.5);
		Chassis chassis = new WheeledChassis(new Wheel[]{wheel1, wheel2}, WheeledChassis.TYPE_DIFFERENTIAL); 
		pilot = new MovePilot(chassis);
		
		pilot.setLinearSpeed(10);
		pilot.setAngularSpeed(30);
		
		//Initialize the sensors
		s1 = LocalEV3.get().getPort("S1");
//		s2 = LocalEV3.get().getPort("S2");
//		s3 = LocalEV3.get().getPort("S3");
		s4 = LocalEV3.get().getPort("S4");
		
		ultrasonicSensor = new UltrasonicSensor(s4, this);
		colourSensor = new ColourSensor(s1,this);
		
	}
	
	public void halt() {
		System.out.println("HALT BUTTON PRESSED");
		this.pilot.stop();
	}
	
	
	/*
	 * TESTING
	 * 
	 * TODO: move to testing suite??
	 * 
	 */
	
	public void testMovement() {
		pilot.travel(50);
		pilot.stop();
		pilot.rotate(90);
		Delay.msDelay(1000);		
		pilot.travel(-50);
		pilot.stop();
	}
	
	public boolean testHaltButton() {
		this.pilot.forward();
		
		while(Button.ENTER.isUp()) {
			Delay.msDelay(20);
		}
		
		this.halt();
		
		while(Button.ENTER.isUp()) {
			if(Button.RIGHT.isDown()) {
				return false;
			}
			Delay.msDelay(20);
		}
		
		Delay.msDelay(200);
		
		return testHaltButton();
	}
	
	public void milestoneOneTest() {
		
		System.out.println("Ready to test");
	
		while(true) {
			if(Button.UP.isDown()) {
				ultrasonicSensor.test();
				System.out.println("Ultrasonic test finished");
				System.out.println("Waiting for next test...");
			}
			
			if(Button.LEFT.isDown()) {
				colourSensor.test();
				System.out.println("Colour test finished");
				System.out.println("Waiting for next test...");
			}
			
			if(Button.RIGHT.isDown()) {
				testHaltButton();
				System.out.println("Halt test finished");
				System.out.println("Waiting for next test...");
			}
			
			if(Button.ESCAPE.isDown()) {
				System.exit(0);
			}
			
			Delay.msDelay(200);
		}
	}

}
