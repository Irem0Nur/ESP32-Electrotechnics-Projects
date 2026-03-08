void setup() {
  pinMode(35,INPUT);
  pinMode(34,INPUT);
  pinMode(32,INPUT);
  Serial.begin(115200);

}

void loop() {
  float V1= analogRead(34) *3.300 / 4095.0;
  float V2= analogRead(35) *3.300 / 4095.0;
  float V3= analogRead(32) *3.300 / 4095.0;
  float V_R1 = 3.300 - V1;
  float V_R2 = V1 - V2;
  float V_R3 = V2-V3;

  float R1=1000;
  float R2=560;
  float R3=2200;
  float Res=R1+R2+R3;
  double I=3.300/Res;

  double I1=V_R1/R1;
  double I2=V_R2/R2;
  double I3=V_R3/R3;

  double P_R1=V_R1*I1;
  double P_R2=V_R2*I2;
  double P_R3=V_R3*I3;

  Serial.print(" V_R1= "); Serial.print(V_R1);
  Serial.print(" \n");
  Serial.print(" V_R2= "); Serial.print(V_R2);
  Serial.print("\n");
  Serial.print(" V_R3= "); Serial.print(V_R3);
  Serial.print("\n");
  Serial.print("\n");
  Serial.print(" Va= "); Serial.print(analogRead(34));
  Serial.print(" \n");
  Serial.print(" Vb= "); Serial.print(analogRead(35));
  Serial.print(" \n");
  Serial.print(" \n");
  Serial.print(" I= "); Serial.print(I,9);
  Serial.print(" \n");
  Serial.print(" I_R1= "); Serial.print(I1,9);
  Serial.print(" \n");
  Serial.print(" I_R2= "); Serial.print(I2,9);
  Serial.print(" \n");
  Serial.print(" I_R3= "); Serial.print(I3,9);
  Serial.print(" \n");
  Serial.print(" \n");
  Serial.print(" P_R1= "); Serial.print(P_R1,9);
  Serial.print(" \n");
  Serial.print(" P_R2= "); Serial.print(P_R2,9);
  Serial.print(" \n");
  Serial.print(" P_R3= "); Serial.print(P_R3,9);
  Serial.print(" \n");
  Serial.print(" \n");
  delay(2000);


  
  

 

   


}