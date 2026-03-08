void setup() {
  pinMode(35,INPUT);
  Serial.begin(115200);

}

void loop() {
  float V1= analogRead(35) *3.300 / 4095.0;
  float V2= analogRead(35) *3.300 / 4095.0;
  float V3= analogRead(35) *3.300 / 4095.0;

  float V_R1 = 3.300 - V1;
  float V_R2 = 3.300 - V1;
  float V_R3 = 3.300 - V1;
 

  Serial.print(" V_R1= "); Serial.print(V_R1);
  Serial.print(" \t");
  Serial.print(" V_R2= "); Serial.print(V_R2);
  Serial.print("\t");
  Serial.print(" V_R3= "); Serial.print(V_R3);
  Serial.print("\n");
 
  delay(2000);

   


}