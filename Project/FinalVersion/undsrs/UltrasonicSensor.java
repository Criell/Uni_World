//Author: Sophie Hood
//last updated: 9/9/18

package undsrs;
import lejos.hardware.Button;
import lejos.hardware.ev3.EV3;
import lejos.hardware.ev3.LocalEV3;
import lejos.hardware.lcd.LCD;
import lejos.hardware.port.Port;
import lejos.robotics.SampleProvider;
import lejos.utility.Delay;
import lejos.hardware.sensor.EV3UltrasonicSensor;

public class UltrasonicSensor 
{
	// Member variables
	private EV3UltrasonicSensor ultSense;
	float[] sample;
	SampleProvider dis;
	private RobotControlSystem rcs;
	private float allowableDistance = (float) 0.1;
	
	//sets up the ultrasonic sensor
	public  UltrasonicSensor(Port port, RobotControlSystem mainRCS) 
	{
		rcs = mainRCS;
		//instance of Ultrasonic sensor
		ultSense = new EV3UltrasonicSensor(port);
			
		//get measurement
		dis = ultSense.getDistanceMode();

		//store samples
		sample = new float[dis.sampleSize()];

	}

	//returns distance to nearest object in meters
	public float findDis() 
	{
		dis.fetchSample(sample, 0);
		return sample[0];
	}


	//returns true if distance is shorter then the allowable distance
	public boolean checkDis() 
	{
		return allowableDistance >= findDis();	
	}

	
	/*
	 * TESTING
	 */
	public void test() {
		System.out.println("Testing ultrasonic sensor");
	    
	    boolean complete = false;
	    
	    rcs.pilot.forward();
	    
	    while (!complete) 
	    {    
	    	Delay.msDelay(100);
	    	
	       //checking distance	    
	       if (this.checkDis()) 
	       {
			  rcs.pilot.stop();
			  rcs.pilot.rotate(90);
			  System.out.println("Object found");
			  rcs.pilot.forward();
		   }
		   
	       if(Button.UP.isDown()) {
	    	   rcs.pilot.stop();
	    	   return;
	       }
	       
	       complete = Button.ESCAPE.isDown();
	       
	       
	       
	    }
	    
	    this.ultSense.close();
	  
//	    System.exit(0);
		
	}
}

