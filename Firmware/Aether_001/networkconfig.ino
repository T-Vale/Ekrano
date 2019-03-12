void networkconfig_configsdcard()
{
  char connInfo_[90];
  File cinfoFile = SD.open("cinfo.txt", FILE_READ);
  byte i = 0;
  if(cinfoFile)
  {
    while(cinfoFile.available())
    {
      connInfo_[i] = cinfoFile.read();
      i++;
    }
    cinfoFile.close();
    dataserverAddress_[0] = converter_number('0', connInfo_[0], connInfo_[1], connInfo_[2]);
    dataserverAddress_[1] = converter_number('0', connInfo_[4], connInfo_[5], connInfo_[6]);
    dataserverAddress_[2] = converter_number('0', connInfo_[8], connInfo_[9], connInfo_[10]);
    dataserverAddress_[3] = converter_number('0', connInfo_[12], connInfo_[13], connInfo_[14]);
    dataserverPort = converter_number(connInfo_[16], connInfo_[17], connInfo_[18], connInfo_[19]);
    macAddress_[0] = converter_fromhex(connInfo_[21], connInfo_[22]);
    macAddress_[1] = converter_fromhex(connInfo_[24], connInfo_[25]);
    macAddress_[2] = converter_fromhex(connInfo_[27], connInfo_[28]);
    macAddress_[3] = converter_fromhex(connInfo_[30], connInfo_[31]);
    macAddress_[4] = converter_fromhex(connInfo_[33], connInfo_[34]);
    macAddress_[5] = converter_fromhex(connInfo_[36], connInfo_[37]);
    ipAddress_[0] = converter_number('0', connInfo_[39], connInfo_[40], connInfo_[41]);
    ipAddress_[1] = converter_number('0', connInfo_[43], connInfo_[44], connInfo_[45]);
    ipAddress_[2] = converter_number('0', connInfo_[47], connInfo_[48], connInfo_[49]);
    ipAddress_[3] = converter_number('0', connInfo_[51], connInfo_[52], connInfo_[53]);
    dnsAddress_[0] = converter_number('0', connInfo_[55], connInfo_[56], connInfo_[57]);
    dnsAddress_[1] = converter_number('0', connInfo_[59], connInfo_[60], connInfo_[61]);
    dnsAddress_[2] = converter_number('0', connInfo_[63], connInfo_[64], connInfo_[65]);
    dnsAddress_[3] = converter_number('0', connInfo_[67], connInfo_[68], connInfo_[69]);
    gatewayAddress_[0] = converter_number('0', connInfo_[71], connInfo_[72], connInfo_[73]);
    gatewayAddress_[1] = converter_number('0', connInfo_[75], connInfo_[76], connInfo_[77]);
    gatewayAddress_[2] = converter_number('0', connInfo_[79], connInfo_[80], connInfo_[81]);
    gatewayAddress_[3] = converter_number('0', connInfo_[83], connInfo_[84], connInfo_[85]);
  }
  else
  {
    error_blink(2);
  }
}
