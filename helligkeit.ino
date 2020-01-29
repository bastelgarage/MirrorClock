void helligkeit() {
  if (aktuellertimer - messtimer > timerinterval) {
    messtimer = millis();
    if (hellmodus == 0) {                    // keine messung auf manuellem modus (1)
      luxSensor = lightMeter.readLightLevel();
    }
  }
  lux = luxSensor;
  lux = map(lux, 0, 10, 40, 255);

  if (lux > 255) {
    lux = 255;
  }


  if (hellmodus == 0) {
    strip.SetBrightness(lux);
    strip.Show();
  }
  if (hellmodus == 1) {
    if (  aktivmenu == 1) {
    setlux();
    menuanzeigeM();
    }
    strip.SetBrightness(luxkorr);
    strip.Show();
  }
}

void heller() {
  menutimer = millis();
  clearDot();
  if (luxstufe <= 4) {
    luxstufe = luxstufe + 1;
  }
  menuanzeigeM();
  setlux();
}

void dunkler() {
  menutimer = millis();
  clearDot();
  if (luxstufe >= 2) {
    luxstufe = luxstufe - 1;
  }
  setlux();
  menuanzeigeM();
}


void setlux() { //manuell
  switch (luxstufe) {
    case 1 :
      luxkorr = 30;
      break;
    case 2 :
      luxkorr = 60;
      break;
    case 3 :
      luxkorr = 100;
      break;
    case 4 :
      luxkorr = 150;
      break;
    case 5 :
      luxkorr = 255;
      break;
    default:
      luxkorr = 30;
      break;
  }
}

