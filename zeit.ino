void timebuilder() {
  clearDot();
  itis(); // ES ISCH
  minutes();
}

void minutes() {
  switch (m) {
    case 0:
      houres(h);
      break;
    case 1:
      houres(h);
      min1();
      break;
    case 2:
      houres(h);
      min2();
      break;
    case 3:
      houres(h);
      min3();
      break;
    case 4:
      houres(h);
      min4();
      break;
    case 5:
      houres(h);
      m5();
      after();
      break;
    case 6:
      houres(h);
      m5();
      after();
      min1();
      break;
    case 7:
      houres(h);
      m5();
      after();
      min2();
      break;
    case 8:
      houres(h);
      m5();
      after();
      min3();
      break;
    case 9:
      houres(h);
      m5();
      after();
      min4();
      break;
    case 10:
      houres(h);
      m10();
      after();
      break;
    case 11:
      houres(h);
      m10();
      after();
      min1();
      break;
    case 12:
      houres(h);
      m10();
      after();
      min2();
      break;
    case 13:
      houres(h);
      m10();
      after();
      min3();
      break;
    case 14:
      houres(h);
      m10();
      after();
      min4();
      break;
    case 15:
      houres(h);
      m15();
      after();
      break;
    case 16:
      houres(h);
      m15();
      after();
      min1();
      break;
    case 17:
      houres(h);
      m15();
      after();
      min2();
      break;
    case 18:
      houres(h);
      m15();
      after();
      min3();
      break;
    case 19:
      houres(h);
      m15();
      after();
      min4();
      break;
    case 20:
      houres(h);
      m20();
      after();
      break;
    case 21:
      houres(h);
      m20();
      after();
      min1();
      break;
    case 22:
      houres(h);
      m20();
      after();
      min2();
      break;
    case 23:
      houres(h);
      m20();
      after();
      min3();
      break;
    case 24:
      houres(h);
      m20();
      after();
      min4();
      break;
    case 25:
     houres(h);
      m5();
      before();
      half();
      break;
    case 26:
     houres(h);
      m5();
      before();
      half();
      min1();
      break;
    case 27:
     houres(h);
      m5();
      before();
      half();
      min2();
      break;
    case 28:
     houres(h);
      m5();
      before();
      half();
      min3();
      break;
    case 29:
     houres(h);
      m5();
      before();
      half();
      min4();
      break;
    case 30:
     houres(h);
      half();
      break;
    case 31:
     houres(h);
      half();
      min1();
      break;
    case 32:
     houres(h);
      half();
      min2();
      break;
    case 33:
     houres(h);
      half();
      min3();
      break;
    case 34:
     houres(h);
      half();
      min4();
      break;
    case 35:
     houres(h);
      half();
      m5();
      after();
      break;
    case 36:
     houres(h);
      half();
      m5();
      after();
      min1();
      break;
    case 37:
     houres(h);
      half();
      m5();
      after();
      min2();
      break;
    case 38:
     houres(h);
      half();
      m5();
      after();
      min3();
      break;
    case 39:
     houres(h);
      half();
      m5();
      after();
      min4();
      break;
    case 40:
     houres(h);
      m20();
      before();
      break;
    case 41:
     houres(h);
      m20();
      before();
      min1();
      break;
    case 42:
     houres(h);
      m20();
      before();
      min2();
      break;
    case 43:
     houres(h);
      m20();
      before();
      min3();
      break;
    case 44:
     houres(h);
      m20();
      before();
      min4();
      break;
    case 45:
     houres(h);
      m15();
      before();
      break;
    case 46:
     houres(h);
      m15();
      before();
      min1();
      break;
    case 47:
     houres(h);
      m15();
      before();
      min2();
      break;
    case 48:
     houres(h);
      m15();
      before();
      min3();
      break;
    case 49:
     houres(h);
      m15();
      before();
      min4();
      break;
    case 50:
     houres(h);
      m10();
      before();
      break;
    case 51:
     houres(h);
      m10();
      before();
      min1();
      break;
    case 52:
     houres(h);
      m10();
      before();
      min2();
      break;
    case 53:
     houres(h);
      m10();
      before();
      min3();
      break;
    case 54:
     houres(h);
      m10();
      before();
      min4();
      break;
    case 55:
     houres(h);
      m5();
      before();
      break;
    case 56:
     houres(h);
      m5();
      before();
      min1();
      break;
    case 57:
     houres(h);
      m5();
      before();
      min2();
      break;
    case 58:
     houres(h);
      m5();
      before();
      min3();
      break;
    case 59:
     houres(h);
      m5();
      before();
      min4();
      break;

  }
}


void lokaleZeit()
{
  time_t tT = now();
  time_t tTlocal = CE.toLocal(tT);
  w = weekday(tTlocal);
  d = day(tTlocal);
  mo = month(tTlocal);
  ye = year(tTlocal);
  h = hour(tTlocal);
  m = minute(tTlocal);
  s = second(tTlocal);
}



void printDigits(int digits)
{
  // Utility für digitale Uhrenanzeige: druckt vor Doppelpunkt und führende 0
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

/*-------- NTP code ----------*/

const int NTP_PACKET_SIZE = 48; // NTP-Zeit in den ersten 48 Bytes der Nachricht
byte packetBuffer[NTP_PACKET_SIZE]; //Puffer für eingehende und ausgehende Pakete

time_t getNtpTime()
{
  IPAddress ntpServerIP; // NTP server's ip Adresse

  while (Udp.parsePacket() > 0) ; // alle zuvor empfangenen Pakete verwerfen
  Serial.println("Transmit NTP Request");
  // einen zufälligen Server aus dem Pool holen
  WiFi.hostByName(ntpServerName, ntpServerIP);
  Serial.print(ntpServerName);
  Serial.print(": ");
  Serial.println(ntpServerIP);
  sendNTPpacket(ntpServerIP);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE) {
      Serial.println("Receive NTP Response");
      Udp.read(packetBuffer, NTP_PACKET_SIZE);  // Paket in den Puffer einlesen
      unsigned long secsSince1900;
      // vier Bytes ab Position 40 in eine lange Ganzzahl umwandeln
      secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
    }
  }
  Serial.println("keine NTP Antwort");
  return 0; // gibt 0 zurück, wenn die Zeit nicht ermittelt werden kann.
}

// send an NTP request to the time server at the given address
void sendNTPpacket(IPAddress &address)
{
  // alle Bytes im Puffer auf 0 setzen
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialisieren von Werten, die für die Bildung von NTP-Requests benötigt werden.
  // (siehe URL oben für Details zu den Paketen)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  // alle NTP-Felder wurden jetzt mit Werten versehen
  // Sie können ein Paket senden, das einen Zeitstempel anfordert.:
  Udp.beginPacket(address, 123); //NTP-Requests sollen auf Port 123 erfolgen
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}
