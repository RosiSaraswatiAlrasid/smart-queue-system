#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ================= WIFI =================

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

// ================= FIREBASE =================

String firebaseHost = "https://smart-queue-system-2b6bc-default-rtdb.firebaseio.com";

// ================= PIN =================

const int tombolAmbil = 18;
const int tombolPanggil = 19;

const int buzzer = 5;

const int ledHijau = 23;
const int ledMerah = 4;

// ================= DATA =================

int nomorAntrean = 0;
int nomorDipanggil = 0;

// =================================================

void setup() {

  Serial.begin(115200);

  pinMode(tombolAmbil, INPUT_PULLUP);
  pinMode(tombolPanggil, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  digitalWrite(ledHijau, HIGH);
  digitalWrite(ledMerah, LOW);

  // ================= LCD =================

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("SMART QUEUE");

  lcd.setCursor(0,1);
  lcd.print("CONNECT WIFI");

  // ================= WIFI =================

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {

    delay(200);
  }

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("SYSTEM READY");

  delay(500);

  tampilkanData();
}

// =================================================

void loop() {

  // ================= TOMBOL AMBIL =================

  if(digitalRead(tombolAmbil) == LOW){

    nomorAntrean++;

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("ANTREAN BARU");

    lcd.setCursor(0,1);

    tampilNomor(nomorAntrean);

    // ===== BUZZER =====

    tone(buzzer, 1000);

    delay(25);

    noTone(buzzer);

    // ===== TAMPIL CEPAT =====

    delay(250);

    tampilkanData();

    // ===== ANTI DOUBLE CLICK =====

    while(digitalRead(tombolAmbil) == LOW);
  }

  // ================= TOMBOL PANGGIL =================

  if(digitalRead(tombolPanggil) == LOW){

    if(nomorDipanggil < nomorAntrean){

      nomorDipanggil++;

      digitalWrite(ledHijau, LOW);
      digitalWrite(ledMerah, HIGH);

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("PANGGIL:");

      lcd.setCursor(0,1);

      tampilNomor(nomorDipanggil);

      // ===== BUZZER =====

      tone(buzzer, 1500);

      delay(35);

      noTone(buzzer);

      // ===== FORMAT NOMOR =====

      String nomor;

      if(nomorDipanggil < 10){

        nomor = "A00" + String(nomorDipanggil);

      }
      else if(nomorDipanggil < 100){

        nomor = "A0" + String(nomorDipanggil);

      }
      else{

        nomor = "A" + String(nomorDipanggil);
      }

      // ===== KIRIM FIREBASE =====

      kirimFirebase(nomor);

      // ===== TAMPIL PANGGIL =====

      delay(400);

      digitalWrite(ledHijau, HIGH);
      digitalWrite(ledMerah, LOW);

      tampilkanData();
    }

    // ===== ANTI DOUBLE CLICK =====

    while(digitalRead(tombolPanggil) == LOW);
  }
}

// =================================================

void kirimFirebase(String nomor){

  if(WiFi.status() == WL_CONNECTED){

    HTTPClient http;

    String url = firebaseHost + "/queue/current.json";

    http.begin(url);

    http.addHeader("Content-Type", "application/json");

    String data = "\"" + nomor + "\"";

    http.PUT(data);

    http.end();
  }
}

// =================================================

void tampilkanData(){

  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("TOTAL:");
  lcd.print(nomorAntrean);

  lcd.setCursor(0,1);

  lcd.print("CALL:");

  tampilNomor(nomorDipanggil);
}

// =================================================

void tampilNomor(int nomor){

  if(nomor < 10){

    lcd.print("A00");
  }
  else if(nomor < 100){

    lcd.print("A0");
  }
  else{

    lcd.print("A");
  }

  lcd.print(nomor);
}