void setup() {
  pinMode(35,INPUT);
  pinMode(34,INPUT);
  pinMode(32,INPUT);
  pinMode(33, INPUT);
  pinMode(25, INPUT);
  Serial.begin(115200);

}

void loop() {
  float V1= analogRead(34) *3.300 / 4095.0;
  float V2= analogRead(35) *3.300 / 4095.0;
  float V3= analogRead(32) *3.300 / 4095.0;
  float V4= analogRead(33) *3.300 / 4095.0;
  float V5= analogRead(25) *3.300 / 4095.0;
  float V_R1 = 3.300 - V1;
  float V_R2 = V1 - V2;
  float V_R3 = V2-V3;
  float V_R4 = V2-V4;
  float V_R56 = V3-V4;
  float V_R7 = V4-V5;

  Serial.print(" V_R1= "); Serial.print(V_R1);
  Serial.print(" \n");
  Serial.print(" V_R2= "); Serial.print(V_R2);
  Serial.print("\n");
  Serial.print(" V_R3= "); Serial.print(V_R3);
  Serial.print("\n");
  Serial.print(" V_R4= "); Serial.print(V_R4);
  Serial.print("\n");
  Serial.print(" V_R56= "); Serial.print(V_R56);
  Serial.print("\n");
  Serial.print(" V_R7= "); Serial.println(V_R7);
   Serial.print("\n");
   delay(5000);
 

   


}