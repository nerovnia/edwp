/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#include "../include/zd/init.h"

void init(void) {
  // Основні ділянки відділку залізниці
  uch[0].num = 0;
  uch[0].name = L"Державний кордон (РФ) - Ніжин";

  uch[1].num = 1;
  uch[1].name = L"Конотоп - Ворожба";

  uch[2].num = 2;
  uch[2].name = L"Бахмач-Пас. - Державний кордон (БР)";

  // ЕЧЕ
  eche[0].uch = &uch[0];
  eche[0].num = 14;
  eche[0].km = 519;
  eche[0].pk = 3;

  eche[1].uch = &uch[0];
  eche[1].num = 15;
  eche[1].km = 564;
  eche[1].pk = 7;

  eche[2].uch = &uch[0];
  eche[2].num = 16;
  eche[2].km = 616;
  eche[2].pk = 95;

  eche[3].uch = &uch[0];
  eche[3].num = 17;
  eche[3].km = 659;
  eche[3].pk = 2;

  eche[4].uch = &uch[0];
  eche[4].num = 18;
  eche[4].km = 711;
  eche[4].pk = 6;

  eche[5].uch = &uch[1];
  eche[5].num = 38;
  eche[5].km = 72;
  eche[5].pk = 8;

  // п/ск
  psk[0].name = L"Янпіль";
  psk[0].uch = &uch[0];
  psk[0].km = 540;
  psk[0].pk = 3;

  psk[1].name = L"Кролевець";
  psk[1].uch = &uch[0];
  psk[1].km = 590;
  psk[1].pk = 10;

  psk[2].name = L"Конотоп";
  psk[2].uch = &uch[0];
  psk[2].km = 634;
  psk[2].pk = 5;

  psk[3].name = L"684км";
  psk[3].uch = &uch[0];
  psk[3].km = 684;
  psk[3].pk = 3;

  psk[4].name = L"Степанівка";
  psk[4].uch = &uch[1];
  psk[4].km = 36;
  psk[4].pk = 9;
}