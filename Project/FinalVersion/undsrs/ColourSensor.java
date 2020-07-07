package undsrs;

import lejos.hardware.port.Port;
import lejos.hardware.sensor.EV3ColorSensor;
import lejos.hardware.Button;
import lejos.hardware.Sound;
import lejos.hardware.ev3.LocalEV3;
import lejos.robotics.Color;
import lejos.utility.Delay;


public class ColourSensor
{
	// Member variables
	private int lastColour;
	private EV3ColorSensor sensor;
	private RobotControlSystem rcs;
	
	// Creates a new Survivor detection component with a port
	public ColourSensor(Port port, RobotControlSystem mainRCS)
	{
		rcs = mainRCS;
		sensor = new EV3ColorSensor(port);
		lastColour = -1;
	}
	
	// Returns true if a red or black detected and makes a sound
	// False and no sound if other colour detected
	public boolean detect()
	{
		int currentColour = sensor.getColorID();
		
		// A border has been found
		if(currentColour == Color.BLACK && lastColour != Color.BLACK)
		{
			System.out.println("Border detected");
			Sound.beep();
			return true;
		}
		
		// A survivor has been found
		if(currentColour == Color.RED && lastColour != Color.RED)
		{
			// Different beep sequence
			System.out.println("Survivor detected");
			Sound.beepSequence();
			return true;
		}
		
		lastColour = currentColour;
		return false;
	}
	
	public void test() {
		rcs.pilot.forward();
		boolean complete = false;
		while(!complete)
	    {
			Delay.msDelay(50);
	    	if(this.detect())
	    	{
	    		// Has detected border/person will beep
	    		complete = false;
	    		rcs.pilot.stop();
//	    		this.sensor.close();
	    		return;
			}
	    	
	    	
		}
		
		return;
	    
//	    System.exit(0);
	}
	

}
