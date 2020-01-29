void sym_showwifi() {
  neo(44);
  neo(45);
  neo(53);
  neo(54);
}

void sym_mm() { //  male ein M für Manuell oben links
  neo(0);
  neo(1);
  neo(2);
  neo(3);
  neo(4);
  neo(18);
  neo(22);
  neo(38);
  neo(40);
  neo(41);
  neo(42);
  neo(43);
  neo(44);
}
void sym_aa() { //  male ein A für Auto oben links

  neo(1);
  neo(2);
  neo(3);
  neo(4);
  neo(17);
  neo(19);
  neo(20);
  neo(22);
  neo(37);
  neo(39);
  neo(41);
  neo(42);
  neo(43);
  neo(44);
}
void sym_schminken() {
  neo(0);
  neo(1);
  neo(2);
  neo(3);
  neo(4);
  neo(5);
  neo(6);
  neo(7);
  neo(8);
  neo(9);
  neo(10);
  neo(19);
  neo(20);
  neo(29);
  neo(39);
  neo(40);
  neo(49);
  neo(50);
  neo(59);
  neo(60);
  neo(69);
  neo(70);
  neo(79);
  neo(80);
  neo(89);
  neo(90);
  neo(99);
  neo(100);
  neo(101);
  neo(102);
  neo(103);
  neo(104);
  neo(105);
  neo(106);
  neo(107);
  neo(108);
  neo(109);
  neo(110);
  neo(111);
  neo(112);
  neo(113);
  neo(114);
  strip.SetBrightness(50);
}

void sym_stufe() {
  switch (luxstufe) {
    case 1 :            // 1
      neo(69);
      break;
    case 2 :            // 2
      neo(69);
      neo(70);
      neo(71);
      break;
    case 3 :            // 3
      neo(69);
      neo(70);
      neo(71);
      neo(87);
      neo(88);
      neo(89);
      break;
    case 4 : // 4
      neo(69);
      neo(70);
      neo(71);
      neo(87);
      neo(88);
      neo(89);
      neo(90);
      neo(91);
      neo(92);
      neo(93);
      break;
    case 5 :            // 5
      neo(69);
      neo(70);
      neo(71);
      neo(87);
      neo(88);
      neo(89);
      neo(90);
      neo(91);
      neo(92);
      neo(93);
      neo(105);
      neo(109);
      neo(108);
      neo(107);
      neo(106);
      break;
  }
}

