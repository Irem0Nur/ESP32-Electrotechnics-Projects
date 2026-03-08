const int analogInPin = 34; // ESP32 için ADC1 kanalı

// Kalibrasyon Katsayıları (2nd Order Polynomial)
const float a0 = 0.070938;
const float a1 = 0.000899733;
const float a2 = -0.000000026745;

void setup() {
  // ESP32 kullanıyorsan 115200 idealdir
  Serial.begin(115200);
  delay(1000);
  Serial.println("Sistem baslatiliyor...");
}

void loop() {
  // Ham değeri oku (0 - 4095 arası)
  int sensorValue = analogRead(analogInPin);

  // Kalibrasyon Formülü Uygulama: a0 + a1*x + a2*x^2
  // x*x işlemi pow(x, 2) fonksiyonundan daha hızlı çalışır.
  float calibratedValue = a0 + (a1 * sensorValue) + (a2 * sensorValue * sensorValue);

  // Seri Port Ekranına Yazdır
  Serial.print("Ham Deger: ");
  Serial.print(sensorValue);
  Serial.print("  =>  Kalibre Edilmis Deger: ");
  Serial.println(calibratedValue, 4); // Virgülden sonra 4 basamak göster

  delay(500); // Okumayı kolaylaştırmak için yarım saniye bekle
}