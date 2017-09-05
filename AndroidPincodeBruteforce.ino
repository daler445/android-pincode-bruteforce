#include <Keyboard.h>

int firstnum = 1;
int maxnum = 9999;
int count = 0;
int i = 0;

int led = 17;

void setup() {
  delay(2000);
  Keyboard.begin();
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  String three = "000";
  String two = "00";
  String one = "0";
  int j = 0;
  for (int k = 0; k<=maxnum; k++) {
    if (j == 5) {
      delay(3000);
      Keyboard.write(KEY_RETURN);
      delay(30000); 
      j = 0; 
      digitalWrite(led, LOW);
      Keyboard.write(KEY_RETURN);
    }
    
    if (i<10) {
      Keyboard.println(three + i);
    }
    else if ((i >= 10) and (i < 100)) {
      Keyboard.println(two + i);
    }
    else if ((i >= 100) and (i < 10000)) {
      Keyboard.println(one + i);
    }
    else {
      Keyboard.println(i);
    }
    delay(2000);
    Keyboard.write(KEY_RETURN);
    Keyboard.releaseAll();
    delay(2000);
    j++; 
    i++;
    digitalWrite(led, HIGH);
  }
  
}
