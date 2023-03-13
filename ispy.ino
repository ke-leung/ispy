/* Codebase for I SPY project

Necessary components:
Touch sensor implementation
Reward System implementation
 - LED feedback


*/

// Libraries

// Pin Definition

// pin of led define here
#define oneMinute 45525
#define twoishMinutes 65500
#define fourSeconds 3035
#define tenSeconds 7588
#define touchSensor 2
#define redLed 6
#define blueLed 9
#define greenLed 10
#define yellowLed 11                                                                                                          
const int ledArray[4] = {redLed,blueLed,greenLed,yellowLed};
long randomTime; 
void setup()
{
  // serial monitor to help with debugging
  Serial.begin(9600);
  // led array for random selection
  //long randomTime = random(oneMinute, twoishMinutes); //between 1 and 5 minutes 
  
  // timer set up
  // noInterrupts(); // disable interrupts 
  // TCCR1A = 0; // initialize timer 1 
  // TCCR1B = 0; // initialize timer 1
  // TCNT1 = randomTime; //preload timer
  // TCCR1B |= (1 << CS10)|(1 << CS12); // 1024 prescaler
  // TIMSK1 |= (1 << TOIE1); // enable timer overflow interrupt ISR
  // interrupts(); // enable all interrupts 
  
  // set led OUTPUT
  pinMode(touchSensor, INPUT);
  pinMode(redLed, OUTPUT);                    
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);  
}

void breatheStringLight()
{
  // select a random string
  int randomString = ledArray[random(4)]; 
  Serial.println("led color picked: ");
  Serial.println(randomString);
  // breathe the random string
  for(int i=0; i<256; i++)
        {
            analogWrite(randomString, i);
            delay(3);                               // change delay time can breath faster or slower
        }
        delay(25);
        for(int i=254; i>=0; i--)
        {
            analogWrite(randomString, i);
            delay(3);                               // change delay time can breath faster or slower
        }
        delay(100);
}
 
void breatheAllLights()
{
   for(int i=0; i<256; i++)
    {
        analogWrite(redLed, i);
        analogWrite(blueLed, i);
        analogWrite(greenLed, i);
        analogWrite(yellowLed, i);
        delay(1);                               // change delay time can breath faster or slower
    }
    delay(50);
        
    for(int i=254; i>=0; i--)
    {                                         
        analogWrite(redLed, i);
        analogWrite(blueLed, i);
        analogWrite(greenLed, i);
        analogWrite(yellowLed, i);

        delay(1);                               // change delay time can breath faster or slower
    }
    delay(500);
}


// ISR for the timer
// ISR(TIMER1_OVF_vect){
// //   set up timer overflow
//   TCNT1 = randomTime;
//   breatheStringLight(); 
//   randomTime = random(oneMinute, twoishMinutes); //between 1 and 5 minutes
  
// }

void loop()
{
  // Serial.print("random time: ");
  // Serial.println(randomTime);
  // Serial.print(randomTime);
  // Serial.println(digitalRead(touchSensor));
  // Serial.print("timer: ");
  // Serial.println(TCNT1);
  // Serial.print(" timer: ",TCNT1);  

  if(digitalRead(touchSensor) == HIGH)
  {
    //Serial.println("reads high"    );  
    //Serial.print(analogRead(redLed));
    breatheStringLight();                           
    breatheAllLights();
  }
  //delay(100);
}

 
