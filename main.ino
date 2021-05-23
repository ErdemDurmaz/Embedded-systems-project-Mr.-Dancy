distance= distance/58;
  Serial.print(distance);
  Serial.println("cm");
This is the code regarding ultrasonic sensor , and how it works
 if(distance<20){
          obstacleDetected = true;
          Serial.println ("There You GO, a partner! LETS DANCE");
        }else{
          obstacleDetected = false;
          Serial.println ("Well looking for someone to dance is there anyone?");
        }
  
Second part Regarding dance and how otto reacts when there is  entity
 if(obstacleDetected){ 
               Otto.sing(S_surprise); 
               Otto.playGesture(OttoFretful); 
               Otto.playGesture(OttoFretful);
               Otto.sing(S_fart3); 
               Otto.walk(3,1600,1); 
               Otto.turn(34,1300,-1);                
             delay(50); 
             obstacleDetector(); 
             }        
         else{ 
            Otto.walk(1,1000,-1); 
            obstacleDetector(); 
        }        
   
  }  

This is the code which makes calibration with EEPROM memory also with global variables, pin locations on the shell.
#define N_SERVOS 4
#define EEPROM_TRIM true  //Activate for calibration



#define TRIM_RR 0
#define TRIM_RL 40
#define TRIM_YR 4
#define TRIM_YL -7

#define PIN_RR 2
#define PIN_RL 3
#define PIN_YR 4
#define PIN_YL 5

#define INTERVALTIME 10.0 

  #define ECHOPIN 9        // Pin to receive echo pulse
  #define TRIGPIN 8        // Pin to send trigger pulse

///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//
///////////////////////////////////////////////////////////////////
//-- Movement parameters
int T=1000;              //Initial duration of movement
int moveId=0;            //Number of movement
int moveSize=15;         //Asociated with the height of some movements
//---------------------------------------------------------
bool obstacleDetected = false;
///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup(){
