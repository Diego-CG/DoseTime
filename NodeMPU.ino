#include "Wire.h" // librería Wire.h
#define MPU 0x69

int16_t  Ic;

void setup()
{
  pinMode(D0,OUTPUT);
 Wire.begin(); // D2(GPIO4)=SDA / D1(GPIO5)=SCL
 Wire.beginTransmission(MPU);
 Wire.write(0x6B);
 Wire.write(0);
 Wire.endTransmission(true);
 Serial.begin(115200);
}

void loop()
{

  Wire.beginTransmission(MPU);
  Wire.write(0x3D); //Pedir el registro 0x3B - corresponde al AcX
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,2,true);   //A partir del 0x3B, se piden 6 registros
  Ic=Wire.read()<<8|Wire.read();
  Serial.print("Valor y ");
     Serial.println(Ic);
if((Ic>6000)||(Ic<-6000)) digitalWrite(D0,HIGH);
else{ digitalWrite(D0,LOW);}

  delay(100);
  

}
