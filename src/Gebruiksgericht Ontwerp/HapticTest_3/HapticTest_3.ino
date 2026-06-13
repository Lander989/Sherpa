#include "OneButton.h"
#include "HapticPattern.h"

HapticPattern motor(5);
OneButton button_1(8, false); // Pin 2, active HIGH (omdat je 5V gebruikt)
OneButton button_2(9, false); // Pin 2, active HIGH (omdat je 5V gebruikt)

bool Status_ON_OFF = false;
bool Status_Start_Stop = false;
int Index = 0;

void setup() {
  Serial.begin(9600);

  
  
  // Koppel de "Long Press" actie aan een functie
  button_1.setPressMs(1200); // Zet de grens op 1000ms
  button_1.attachLongPressStart(handleLongPress);
  button_2.setPressMs(1000); // Zet de grens op 1000ms
  button_2.attachLongPressStart(Start_Stop);
  button_2.attachClick(VolgendeRoute);
  // Optioneel: geef een tikje bij een korte klik (zonder de status te veranderen)
//  button.attachClick([](){ motor.trigger(3); }); 
}

void loop() {
  motor.update();  // Update de trillingen
  button_1.tick();   // Update de knop-logica
  button_2.tick();   // Update de knop-logica

}

// Deze functie wordt automatisch aangeroepen na 1 seconde indrukken
void handleLongPress() {
  Status_ON_OFF = !Status_ON_OFF;
  Status_Start_Stop = false;
  if (Status_ON_OFF) {
    motor.trigger(1); // Aan (Rijzend)
  } else {
    motor.trigger(2); // Uit (Dalend)
    Status_Start_Stop = false;
  }
  
  Serial.print("Status gewijzigd naar: ");
  Serial.println(Status_ON_OFF);
}



void VolgendeRoute()
{
  if (Status_ON_OFF == true && Status_Start_Stop == false)
  {
  motor.trigger(5);
  }
}


void Start_Stop()
{   
  if (Status_ON_OFF == true)
  {
    Status_Start_Stop =! Status_Start_Stop;
    if(Status_Start_Stop){motor.trigger(3);}
    else{motor.trigger(4);}

  }
}