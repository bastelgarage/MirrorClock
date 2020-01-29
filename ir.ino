void translateIR(decode_results *results)
{
  switch (results->value) {
    case 0xFD00FF:            // 1
      taste = 1;
      break;
    case 0xFFA25D:
      taste = 1;
      break;
    case 0xFD807F:            // 2
      taste = 2;
      break;
    case 0xFF629D:
      taste = 2;
      break;
    case 0xFD40BF:            // 3
      taste = 3;
      break;
    case 0xFFE21D:
      taste = 3;
      break;
    case 0xFD20DF:            // 4
      taste = 4;
      break;
    case 0xFF22DD:
      taste = 4;
      break;
    case 0xFDA05F:            // 5
      taste = 5;
      break;
    case 0xFF02FD:
      taste = 5;
      break;
    case 0xFD609F:            // 6
      taste = 6;
      break;
    case 0xFFC23D:
      taste = 6;
      break;
    case 0xFD10EF:            // 7
      taste = 7;
      break;
    case 0xFFE01F:
      taste = 7;
      break;
    case 0xFD906F:            // 8
      taste = 8;
      break;
    case 0xFFA857:
      taste = 8;
      break;
    case 0xFD50AF:            // 9
      taste = 9;
      break;
    case 0xFF906F:
      taste = 9;
      break;
    case 0xFDB04F:            // 0
      taste = 0;
      break;
    case 0xFF9867:
      taste = 0;
      break;
    case 0xFD708F:            // * = 11
      taste = 11;
      break;
    case 0xFF6897:
      taste = 11;
      break;
    case 0xFFB04F:            // # = 12
      taste = 12;
      break;
    case 0x2C739B:
      taste = 12;
      break;
    case 0xFD8877:            // hoch 13
      taste = 13;
      break;
    case 0xFF18E7:
      taste = 13;
      break;
    case 0xFD28D7:            // links = 14
      taste = 14;
      break;
    case 0xFF10EF:
      taste = 14;
      break;
    case 0xFDA857:            // OK = 15
      taste = 15;
      break;
    case 0xFF38C7:
      taste = 15;
      break;
    case 0xFD6897:            // rechts = 16
      taste = 16;
      break;
    case 0xFF5AA5:
      taste = 16;
      break;
    case 0xFD9867:            // runter 17
      taste = 17;
      break;
    case 0xFF4AB5:
      taste = 17;
      break;
  }
  tastecheck();
}

void tastecheck() {
  switch (taste) {
    case 1:               // Farbe 1
      aktivcolor = 1;
      break;
    case 2:               // Farbe 2
      aktivcolor = 2;
      break;
    case 3:               // Farbe 3
      aktivcolor = 3;
      break;
    case 4:               // Farbe 4
      aktivcolor = 4;
      break;
    case 5:               // Farbe 5
      aktivcolor = 5;
      break;
    case 6:               // Farbe 6
      aktivcolor = 6;
      break;
    case 7:               // Farbe 7
      aktivcolor = 7;
      break;
    case 8:               // Farbe 8
      aktivcolor = 8;
      break;
    case 9:               // Farbe 9
      aktivcolor = 9;
      break;
    case 0:               // Farbe 0
      aktivcolor = 0;
      break;
    case 11:               // Farbe RGB alle
      aktivcolor = 88;
      break;
    case 12:               // Farbe Regenbogenfarben
      aktivcolor = 77;
      break;
    case 13:               // Farbe Regenbogenfarben
      if (aktivmenu == 1) {
        heller();
      }
      break;
    case 14:               // Farbe Regenbogenfarben
      menuein(1);
      break;
    case 15:               // OK
      if (aktivcolor == 88) { //wenn rgb läuft
        aktivcolor = 99;
      }
      break;
    case 16:               // Farbe Regenbogenfarben
      menuein(2);
      break;
    case 17:               // Farbe Regenbogenfarben
      if (aktivmenu == 1) {
        dunkler();
      }
      break;
  }
  taste = 99;
}
