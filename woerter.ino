void itis() { //
  neo(0);
  neo(19);
  neo(39);
  neo(40);
  neo(59);
  neo(60);
}
void m5() { //
  neo(80);
  neo(99);
  neo(100);
}
void m15() { //
  neo(1);
  neo(18);
  neo(21);
  neo(38);
  neo(41);
  neo(58);
}
void m10() { //
  neo(81);
  neo(98);
  neo(101);
}
void m20() { //
  neo(2);
  neo(17);
  neo(22);
  neo(37);
  neo(42);
  neo(57);
}
void before() { //
  neo(82);
  neo(97);
  neo(102);
}
void after() { //
  neo(3);
  neo(16);
}
void half() { //
  neo(36);
  neo(43);
  neo(56);
  neo(63);
  neo(76);
}
void min1() { //
  neo(112);
}
void min2() { //
  neo(112);
  neo(111);
}
void min3() { //
  neo(110);
  neo(111);
  neo(112);
}
void min4() { //
  neo(110);
  neo(111);
  neo(112);
  neo(113);
}
void houres(int htemp) {
  if (h >= 12) {
    htemp = (h - 12);
  }
  if (m > 24){
    htemp = htemp+1;
  }
  
  switch (htemp) {
    case 1:
      neo(4);
      neo(15);
      neo(24);
      break;
    case 2:
      neo(35);
      neo(44);
      neo(55);
      neo(64);
      break;
    case 3:
      neo(84);
      neo(95);
      neo(104);
      break;
    case 4:
      neo(5);
      neo(14);
      neo(25);
      neo(34);
      neo(45);
      break;
    case 5:
      neo(54);
      neo(65);
      neo(74);
      neo(85);
      break;
    case 6:
      neo(6);
      neo(13);
      neo(26);
      neo(33);
      neo(46);
      neo(53);
      break;
    case 7:
      neo(66);
      neo(73);
      neo(86);
      neo(93);
      neo(106);
      break;
    case 8:
      neo(7);
      neo(12);
      neo(27);
      neo(32);
      neo(47);
      break;
    case 9:
      neo(52);
      neo(67);
      neo(72);
      neo(87);
      break;
    case 10:
      neo(8);
      neo(11);
      neo(28);
      neo(31);
      break;
    case 11:
      neo(71);
      neo(88);
      neo(91);
      neo(108);
      break;
    case 12:
      neo(9);
      neo(10);
      neo(29);
      neo(30);
      neo(49);
      neo(50);
      break;
      case 0:
      neo(9);
      neo(10);
      neo(29);
      neo(30);
      neo(49);
      neo(50);
      break;
  }
}
