const float a0 = 0.070938;
const float a1 = 0.000899733;
const float a2 = -0.000000026745;

float calibrateADC(float raw) {
  return a0 + a1 * raw + a2 * raw * raw;
}

#define NUM_NODES 6
#define NUM_SAMPLES 100
#define VREF 3.30
#define ADC_MAX 4095.0
#define N_RESISTORS 6


int adcPins[NUM_NODES] = {36, 39, 34, 35, 32, 33};


void setup() {
  Serial.begin(115200);
  delay(3000);
  Serial.println("STARTING...");
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
}

void loop() {

  for (int k = 0; k < NUM_NODES; k++) {

    long sum = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
      sum += analogRead(adcPins[k]);
      delay(2);
    }

    float adcMean = sum / (float)NUM_SAMPLES;
    float Vmeasured = adcMean * VREF / ADC_MAX;
    float Vtheory = VREF * (1.0f - (float)k / N_RESISTORS);
    float Vcal = calibrateADC(adcMean);

    Serial.print("node");
    Serial.print(k);
    Serial.print(": adc=");
    Serial.print(adcMean, 2);

    Serial.print(" | V_measured=");
    Serial.print(Vmeasured, 4);

    Serial.print(" | V_theory=");
    Serial.print(Vtheory, 4);

    Serial.print(" | V_calibrated=");
    Serial.println(Vcal, 4);
  }

  Serial.println("----------------------------------");
  delay(2000);
}


