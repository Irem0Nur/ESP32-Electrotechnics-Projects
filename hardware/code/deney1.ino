const int PIN_0 = 34;
const int PIN_1 = 35;
const int PIN_2 = 32;
const int PIN_3 = 33;

const float VREF = 3.300f;
const int ADC_MAX = 4095;

// V_calibrated(x) = a0 + a1*x + a2*x^2
const float a0 = -0.00938f;
const float a1 = 0.000676f;
const float a2 = 0.00000004148f;  // 4.148 x 10^-8

float calibrateADC(int raw) {
  float x = (float)raw;
  return a0 + a1 * x + a2 * x * x;
}
void setup() {
  pinMode(PIN_0, INPUT);
  pinMode(PIN_1, INPUT);
  pinMode(PIN_2, INPUT);
  pinMode(PIN_3, INPUT);
  Serial.begin(115200);

  // SADECE Çözünürlük ayarı (0-4095 aralığını kesinleştirir)
  analogReadResolution(12);
}
void loop() {

  int adcPins[] = { PIN_0, PIN_1, PIN_2, PIN_3 };

  for (int k = 0; k < 4; ++k) {
    int ham_value = analogRead(adcPins[k]);
    float V_measaured = (float)ham_value * VREF / ADC_MAX;
    float V_calibrated = calibrateADC(ham_value);

    Serial.print("NODE ");
    Serial.println(k);
    Serial.println("Ham ADC (x)     V_Measaured          V_Calibrated");
    Serial.print(ham_value);
    Serial.print("               ");
    Serial.print(V_measaured, 4);
    Serial.print("               ");
    Serial.println(V_calibrated, 4);
    Serial.println("\n");

  }
   Serial.println("------------------------------------");

  delay(2000);
}