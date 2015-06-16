#include <Stepper.h>
 
#define STEPS 100  //how much step a circle
 
Stepper stepper(STEPS, 2, 3, 4, 5);
 
int previous = 0;
 
void setup()
{
  // Set the step motor speed of 90 per minute
  stepper.setSpeed(90);
}
 
void loop()
{
  int val = analogRead(0);
  stepper.step(val - previous);
  previous = val;
}
