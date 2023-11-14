#include <Wire.h>
#include <Zumo32U4.h>


Zumo32U4ProximitySensors proxSensor;
Zumo32U4Motors motor;
Zumo32U4ButtonA buttonA;
Zumo32U4OLED display;


void setup() {
  proxSensor.initThreeSensors();
  proxSensor.setBrightnessLevels(50,500);//første er level, næste er count brightness
  buttonA.getSingleDebouncedRelease();
  while(buttonA.getSingleDebouncedRelease() == true){
    //waitForPress();
    proxSensor.read();
    int proxRight = proxSensor.countsRightWithRightLeds ();
    display.clear();
    display.gotoXY(0,0); //levels aflæses før press A, når det er sat i whileloop i setup
    display.print(proxRight); 
  }
  buttonA.getSingleDebouncedPress	(); //den er god at have med, fordi loopet starter først når der er trykket 
  motor.setSpeeds(100,100);
  // put your setup code here, to run once:

}



void loop() {
  proxSensor.read();
  int proxRight = proxSensor.countsRightWithRightLeds ();
  display.clear();
  display.gotoXY(0,0);
  display.print(proxRight);
  if (proxRight >=30){
    motor.setSpeeds(50,80);// lav hastighed giver mindre overslag i ønsket distance (proportionel regulering)
   
    

    
  }
  else if (proxRight <30){
    motor.setSpeeds(80,50);
    
    
  }
  else if (proxRight == 30){
    motor.setSpeeds(50,50);
    
  }
  // put your main code here, to run repeatedly:

}
