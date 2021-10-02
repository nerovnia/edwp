/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#include "include/init.h"

void init_main_menu(void) {
  /* Init menu */
  m.mi = m_mi;
  m.size = 9;
  m.header = L"Пошкодження";
  m.sel_it = 0;
  m_mi[0].name = L"... на к/м      ";
  m_mi[1].name = L"... на АБ       ";
  m_mi[2].name = L"... на ПЕ       ";
  m_mi[3].name = L"... на ПЛ-10кВ  ";
  m_mi[4].name = L"... на ПЛ-0.4кВ ";
  m_mi[5].name = L"... на ПЛ-0.23кВ";
  m_mi[6].name = L"... на КЛ-10кВ  ";
  m_mi[7].name = L"... на КЛ-0.4кВ ";
  m_mi[8].name = L"... на КЛ-0.23кВ";  
}