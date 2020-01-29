
void clearDot() {
  strip.ClearTo(black);
  for (int i = 0; i < PixelCount; i++)
  {
    pixelpos[i] = 0;
  }
  strip.Show();
}

void pixeltest() {
  for (int i = 0; i < PixelCount; i++) {
    strip.SetPixelColor(i, HslColor((0) / 360.0f, 1.0f, 0.25f));
    strip.Show();
    delay(50); // Delay for a period of time (in milliseconds).
    clearDot();
  }
  for (int i = 0; i < PixelCount; i++) {
    strip.SetPixelColor(i, HslColor((120) / 360.0f, 1.0f, 0.25f));
    strip.Show();
    delay(50); // Delay for a period of time (in milliseconds).
    clearDot();
  }
  for (int i = 0; i < PixelCount; i++) {
    strip.SetPixelColor(i, HslColor((240) / 360.0f, 1.0f, 0.25f));
    strip.Show();
    delay(50); // Delay for a period of time (in milliseconds).
    clearDot();
  }
}

// farbwechsel
void neo(int led) {
  switch (aktivcolor) {
    case 1: //up
      strip.SetPixelColor(led, HslColor((150) / 360.0f, 1.0f, 0.25f));
      break;
    case 2: //up
      strip.SetPixelColor(led, HslColor((130) / 360.0f, 1.0f, 0.25f));
      break;
    case 3: //up
      strip.SetPixelColor(led, HslColor((30) / 360.0f, 1.0f, 0.25f));
      break;
    case 4: //up
      strip.SetPixelColor(led, HslColor((0) / 360.0f, 1.0f, 0.25f));
      break;
    case 5: //up
      strip.SetPixelColor(led, white);
      break;
    case 6: //up
      strip.SetPixelColor(led, HslColor((100) / 360.0f, 1.0f, 0.25f));
      break;
    case 7: //up
      strip.SetPixelColor(led, HslColor((190) / 360.0f, 1.0f, 0.25f));
      break;
    case 8: //up
      strip.SetPixelColor(led, HslColor((300) / 360.0f, 1.0f, 0.25f));
      break;
    case 9: //up
      strip.SetPixelColor(led, HslColor((50) / 360.0f, 1.0f, 0.25f));
      break;
    case 0: //up
      strip.SetPixelColor(led, HslColor((327) / 360.0f, 1.0f, 0.25f));
      break;
    case 77: //up
      // 0-360 sind farben - position pixel
      if (millis() - regenbogentimer  > regenbogeninterval) {
        regenbogentimer = millis();
        regenbogenfarbe = (regenbogenfarbe + 1);
        if (regenbogenfarbe == 360) {
          regenbogenfarbe = 0;
        }
      }
      strip.SetPixelColor(led, HslColor((regenbogenfarbe - led) / 360.0f, 1.0f, 0.25f));
      break;
    case 88: //up
      // 0-360 sind farben - position pixel
      if (millis() - regenbogentimer  > regenbogeninterval) {
        regenbogentimer = millis();
        regenbogenfarbe = (regenbogenfarbe + 1);
        if (regenbogenfarbe == 360) {
          regenbogenfarbe = 0;
        }
      }
      strip.SetPixelColor(led, HslColor((regenbogenfarbe) / 360.0f, 1.0f, 0.25f));
      break;
    case 99: //RGB Farbe einfrieren
      strip.SetPixelColor(led, HslColor((regenbogenfarbe) / 360.0f, 1.0f, 0.25f));
      break;
  }
  pixelpos[led] = 1;  // eine 1 in das Array schreiben fals die LED an ist für regenbogen
  //rainbow();
}


void wort() {
  if (aktivmenu == 0) {
    timebuilder();
  }

  delay(5);
  strip.Show();
  delay(10);
  neustart = false;
}
