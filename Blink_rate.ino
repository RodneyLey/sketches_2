int LDR=A0; //LDR analog input will be connected to arduino analog pin.
int LED=3; // LED is connected to PWM pin 3 of arduino.
int i=0; //starting brightness for led will be 0 
void setup(){
  pinMode(LDR, INPUT);   //LDR is our input
  pinMode(LED, OUTPUT);  //LED is our output
  Serial.begin(9600);       //setting the baud rate for communication
}

void loop(){
  int LDRvalue=analogRead(LDR);
  Serial.println(LDRvalue);
  if(LDRvalue<=25){      //when the value of LDR goes below 100 in the room, led will turn ON.
    for(i=0;i<=255;i++){  //increasing the brightness of led, PWM range is from (0-255)
      analogWrite(LED,i); //LED will turn ON and brightness will increase from 0-255 in 60seconds
      delay(39.2); //60seconds or 60000/255=235 but for video purpose I make it fast to 10seconds
    }
    for(i=255;i>=0;i--){   // fading out
      analogWrite(LED,i);
      delay(10);    // fast 
    }
  }
  else{
    analogWrite(LED,LOW);
  }
  }