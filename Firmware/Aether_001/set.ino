void set_initParam_()
{
  initParam_[0] = 0 + 48;  // 0
  initParam_[1] = 59;  // ;
  initParam_[2] = converter_numberascii(macAddress_[0], 2);
  initParam_[3] = converter_numberascii(macAddress_[0], 1);
  initParam_[4] = converter_numberascii(macAddress_[0], 0);
  initParam_[5] = converter_numberascii(macAddress_[1], 2);
  initParam_[6] = converter_numberascii(macAddress_[1], 1);
  initParam_[7] = converter_numberascii(macAddress_[1], 0);
  initParam_[8] = converter_numberascii(macAddress_[2], 2);
  initParam_[9] = converter_numberascii(macAddress_[2], 1);
  initParam_[10] = converter_numberascii(macAddress_[2], 0);
  initParam_[11] = converter_numberascii(macAddress_[3], 2);
  initParam_[12] = converter_numberascii(macAddress_[3], 1);
  initParam_[13] = converter_numberascii(macAddress_[3], 0);
  initParam_[14] = converter_numberascii(macAddress_[4], 2);
  initParam_[15] = converter_numberascii(macAddress_[4], 1);
  initParam_[16] = converter_numberascii(macAddress_[4], 0);
  initParam_[17] = converter_numberascii(macAddress_[5], 2);
  initParam_[18] = converter_numberascii(macAddress_[5], 1);
  initParam_[19] = converter_numberascii(macAddress_[5], 0);
  initParam_[20] = 59;
  initParam_[21] = 0 + 48;
  initParam_[22] = 0 + 48;
  initParam_[23] = 0 + 48;
  initParam_[24] = 0 + 48;
  initParam_[25] = 10;  //NL
  initParam_[26] = 0;  //NULL
}

void set_analogValues_()
{
  analogValues_[0] = analogRead(A0);
  analogValues_[1] = analogRead(A1);
  analogValues_[2] = analogRead(A2);
  analogValues_[3] = analogRead(A3);
  analogValues_[4] = analogRead(A4);
  analogValues_[5] = analogRead(A5);
}

void set_dataOutput_()
{
  set_analogValues_();
  time_t t = now();
  dataOutput_[0] = converter_numberascii(year(t), 3);
  dataOutput_[1] = converter_numberascii(year(t), 2);
  dataOutput_[2] = converter_numberascii(year(t), 1);
  dataOutput_[3] = converter_numberascii(year(t), 0);
  dataOutput_[4] = converter_numberascii(month(t), 1);
  dataOutput_[5] = converter_numberascii(month(t), 0);
  dataOutput_[6] = converter_numberascii(day(t), 1);
  dataOutput_[7] = converter_numberascii(day(t), 0);
  dataOutput_[8] = converter_numberascii(hour(t), 1);
  dataOutput_[9] = converter_numberascii(hour(t), 0);
  dataOutput_[10] = converter_numberascii(minute(t), 1);
  dataOutput_[11] = converter_numberascii(minute(t), 0);
  dataOutput_[12] = converter_numberascii(second(t), 1);
  dataOutput_[13] = converter_numberascii(second(t), 0);
  dataOutput_[14] = 59;
  dataOutput_[15] = converter_numberascii(analogValues_[0], 3);
  dataOutput_[16] = converter_numberascii(analogValues_[0], 2);
  dataOutput_[17] = converter_numberascii(analogValues_[0], 1);
  dataOutput_[18] = converter_numberascii(analogValues_[0], 0);
  dataOutput_[19] = 59;
  dataOutput_[20] = converter_numberascii(analogValues_[1], 3);
  dataOutput_[21] = converter_numberascii(analogValues_[1], 2);
  dataOutput_[22] = converter_numberascii(analogValues_[1], 1);
  dataOutput_[23] = converter_numberascii(analogValues_[1], 0);
  dataOutput_[24] = 59;
  dataOutput_[25] = converter_numberascii(analogValues_[2], 3);
  dataOutput_[26] = converter_numberascii(analogValues_[2], 2);
  dataOutput_[27] = converter_numberascii(analogValues_[2], 1);
  dataOutput_[28] = converter_numberascii(analogValues_[2], 0);
  dataOutput_[29] = 59;
  dataOutput_[30] = converter_numberascii(analogValues_[3], 3);
  dataOutput_[31] = converter_numberascii(analogValues_[3], 2);
  dataOutput_[32] = converter_numberascii(analogValues_[3], 1);
  dataOutput_[33] = converter_numberascii(analogValues_[3], 0);
  dataOutput_[34] = 59;
  dataOutput_[35] = converter_numberascii(analogValues_[4], 3);
  dataOutput_[36] = converter_numberascii(analogValues_[4], 2);
  dataOutput_[37] = converter_numberascii(analogValues_[4], 1);
  dataOutput_[38] = converter_numberascii(analogValues_[4], 0);
  dataOutput_[39] = 59;
  dataOutput_[40] = converter_numberascii(analogValues_[5], 3);
  dataOutput_[41] = converter_numberascii(analogValues_[5], 2);
  dataOutput_[42] = converter_numberascii(analogValues_[5], 1);
  dataOutput_[43] = converter_numberascii(analogValues_[5], 0);
  dataOutput_[44] = 10; //NL
  dataOutput_[45] = 0;  //NULL
}

void set_adcThreshold()
{
  adcThreshold_[0][0] = converter_number(dataInput_[20], dataInput_[21], dataInput_[22], dataInput_[23]);
  adcThreshold_[0][1] = converter_number(dataInput_[25], dataInput_[26], dataInput_[27], dataInput_[28]);
  adcThreshold_[1][0] = converter_number(dataInput_[30], dataInput_[31], dataInput_[32], dataInput_[33]);
  adcThreshold_[1][1] = converter_number(dataInput_[35], dataInput_[36], dataInput_[37], dataInput_[38]);
  adcThreshold_[2][0] = converter_number(dataInput_[40], dataInput_[41], dataInput_[42], dataInput_[43]);
  adcThreshold_[2][1] = converter_number(dataInput_[45], dataInput_[46], dataInput_[47], dataInput_[48]);
  adcThreshold_[3][0] = converter_number(dataInput_[50], dataInput_[51], dataInput_[52], dataInput_[53]);
  adcThreshold_[3][1] = converter_number(dataInput_[55], dataInput_[56], dataInput_[57], dataInput_[58]);
  adcThreshold_[4][0] = converter_number(dataInput_[60], dataInput_[61], dataInput_[62], dataInput_[63]);
  adcThreshold_[4][1] = converter_number(dataInput_[65], dataInput_[66], dataInput_[67], dataInput_[68]);
  adcThreshold_[5][0] = converter_number(dataInput_[70], dataInput_[71], dataInput_[72], dataInput_[73]);
  adcThreshold_[5][1] = converter_number(dataInput_[75], dataInput_[76], dataInput_[77], dataInput_[78]);
}
