void menuein(int menuwert) {
  aktivmenu = 1;
  switch (menuwert) {
    case 1:            // Menu Helligkeit
      menutimer = millis(); // menuanzeige für 8 sekunden weiterführen wenn was gedrückt wurde
      menuanzeigeA();
      break;
    case 2:            // Menu Helligkeit
      menutimer = millis(); // menuanzeige für 8 sekunden weiterführen wenn was gedrückt wurde
      menuanzeigeM();
      break;
  }
}

void menuanzeigeA() { // automatische helligkeit
  clearDot();
  sym_aa();
  hellmodus = 0;
  delay(5);
  strip.Show();
  delay(10);
}

void menuanzeigeM() { // Manueller helligkeit
  clearDot();
  hellmodus = 1;
  sym_mm();
  sym_stufe();
  delay(5);
  strip.Show();
  delay(10);
}



