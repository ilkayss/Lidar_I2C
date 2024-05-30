#include <Wire.h>
#include <AFMotor.h>


AF_DCMotor motor1(4);  // Motor 1 -> Sol ön
AF_DCMotor motor2(3);  // Motor 2 -> Sağ ön
AF_DCMotor motor3(1);  // Motor 3 -> Sol arka
AF_DCMotor motor4(2);  // Motor 4 -> Sağ arka


byte BASE_SPEED = 150;


void setup() {
  // put your setup code here, to run once:
  Wire.begin(0x8);      //join i2c bus with address #8
  Wire.onReceive(receiveEvent);  // register event 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  


}

void bekle() {
  // Motorları durdurur.

  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
 
  Serial.println("Dur");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void ileri() {
  // Motorları durdurur.

  motor1.setSpeed(250);
  motor1.run(FORWARD);
  motor2.setSpeed(250);
  motor2.run(FORWARD);
  motor3.setSpeed(250);
  motor3.run(FORWARD);
  motor4.setSpeed(250);
  motor4.run(FORWARD);
}


void receiveEvent(){
  while(Wire.available()){  //loop through all but the last
    byte c = Wire.read();  // receive byte as a character
    Serial.println(c);
    if(c == 1){     //Eger gelen deger 1 ise 
      bekle();        // bekle komutunu cagir ve motorlari durdur.
    }else{
      ileri();
    }
  }
}