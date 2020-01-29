/*******************************************************************************************
 *******************************************************************************************
 **                                www.bastelgarage.ch                                    **
 ** Der Onlineshop mit Videoanleitungen und kompletten Bausätzen für Anfänger und Profis! **
 *******************************************************************************************
 *******************************************************************************************
 ** Autor: Alf Müller                                                                     **
 ** Datum: Mai 2018                                                                   **
 ** Version: 1.0                                                                          **
 *******************************************************************************************
*/
//Youtube zum file:
/************************( Importieren der genutzten Bibliotheken )************************/

#include <ESP8266WiFi.h>                    //https://github.com/esp8266/Arduino
#include "WiFiManager.h"                    //https://github.com/tzapu/WiFiManager
#include <Timezone.h>                       //https://github.com/JChristensen/Timezone
#include <TimeLib.h>                        //https://github.com/PaulStoffregen/Time
#include <WiFiUdp.h>
#include <NeoPixelBrightnessBus.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <Wire.h>
#include <BH1750.h>                         //https://github.com/claws/BH1750



int h, m, s, w, mo, ye, d, htemp, hplus, luxSensor, taste;           // variablen für die lokale Zeit
long messtimer = 0;
long timerinterval = 1000;
long aktuellertimer = 1000;
long menuinterval = 6000;
long menutimer = 0;
int aktivmenu = 0;
int menupunkt;

// - BH1750 - //
BH1750 lightMeter;
uint16_t lux;
int hellmodus = 0;                          // 0= Auto, 1=Manuell Auto, 2 = Manuell
int luxkorr = 0;
int luxstufe = 2;


// - IRremoteESP8266. - //
//const int RECV_PIN = 14;
const int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

// - NeoPixelBus. - //
const uint16_t PixelCount = 114;
const uint8_t PixelPin = 2;
#define colorSaturation 255
NeoPixelBrightnessBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);
bool neustart = true;
int aktivcolor = 1;

const uint8_t c_MinBrightness = 45;
const uint8_t c_MaxBrightness = 255;
uint8_t brightness;

RgbColor black(0);
RgbColor white(200, 200, 200);
int regenbogenfarbe= 0;
int long regenbogentimer;
int regenbogeninterval = 100;

int pixelpos[114];

// NTP Serverpool für die Schweiz:
static const char ntpServerName[] = "ch.pool.ntp.org";    //Finde lokale Server unter http://www.pool.ntp.org/zone/ch
const int timeZone = 0;                     // 0 wenn mit <Timezone.h> gearbeitet wird sonst stimmt es nachher nicht
WiFiUDP Udp;
unsigned int localPort = 8888;              // lokaler Port zum Abhören von UDP-Paketen

time_t getNtpTime();
void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);

// - Timezone. - //
// Bearbeiten Sie diese Zeilen entsprechend Ihrer Zeitzone und Sommerzeit.
// TimeZone Einstellungen Details https://github.com/JChristensen/Timezone
TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 120};     //Central European Time (Frankfurt, Paris)
TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 60};       //Central European Time (Frankfurt, Paris)
Timezone CE(CEST, CET);

RgbColor color;
uint8_t pos;

void setup() {
  Serial.begin(115200);
  strip.Begin();
  pixeltest();
  sym_showwifi();
  strip.Show();
  WiFiManager wifiManager;
  //wifiManager.resetSettings();            //mit diesem befehl kannst die gespeicherten werte löschen
  wifiManager.autoConnect("23erPlatine");
  Serial.println("verbunden!");
  Udp.begin(localPort);
  Serial.print("lokaler Port: ");
  Serial.println(Udp.localPort());
  Serial.println("Warten auf die Synchronisation");
  setSyncProvider(getNtpTime);
  setSyncInterval(86400);                    // Anzahl der Sekunden zwischen dem erneuten Synchronisieren ein. 86400 = 1 Tag

  irrecv.enableIRIn();  // Start the receiver
  Wire.begin(D4, D3);                       // (D3,SCL) und (D4,SDA) pins
  lightMeter.begin();
  
}

time_t prevDisplay = 0; // wenn die Digitaluhr angezeigt wurde

void loop()
{
  aktuellertimer = millis();
  if (timeStatus() != timeNotSet) {             // wenn die Zeit über NTP gesetzt wurde
    lokaleZeit();
    wort();
  }
  Serial.print("regenbogenfarbe");
  Serial.println(regenbogenfarbe);
  
  helligkeit();
  if (aktuellertimer - menutimer > menuinterval) {
    aktivmenu = 0;
  }

  if (irrecv.decode(&results)) {
    if (results.value == 0XFFFFFFFF) {
      results.value = key_value;
    }
    translateIR(&results);
    key_value = results.value;
    irrecv.resume();
  }
  delay(5);
}
