void sd_writing(boolean dataBackup)
{  
  File dataFile;
  if(dataBackup == false)
  {
    dataFile = SD.open("data.txt", FILE_WRITE);
  }
  else
  {
    dataFile = SD.open("backup.txt", FILE_WRITE);
  }
  if (dataFile)
  {
    for(byte j = 0; j < DATAOUTPUTSIZE - 1; j++)
    {
      dataFile.print(dataOutput_[j]);
    }
    dataFile.close();
  }
}

void sd_backupprinter()
{
  File dataFile = SD.open("backup.txt", FILE_READ);
  char line_[DATAOUTPUTSIZE];
  int regNum = (dataFile.size() / (DATAOUTPUTSIZE - 1)) + 1;
  if(regNum > 9999)
  {
    regNum = 9999;
  }
  initParam_[21] = converter_numberascii(regNum, 3);
  initParam_[22] = converter_numberascii(regNum, 2);
  initParam_[23] = converter_numberascii(regNum, 1);
  initParam_[24] = converter_numberascii(regNum, 0);
  serverClient.println((INITPARAMSIZE - 1) + dataFile.size() + (DATAOUTPUTSIZE - 1));
  if (dataFile)
  {
    for(byte l = 0; l < INITPARAMSIZE - 1; l++)
    {
      serverClient.print(initParam_[l]);
    }
    while (dataFile.available()) 
    {
      for(byte i = 0; i < DATAOUTPUTSIZE - 1; i++)
      {
        line_[i] = dataFile.read();
      }
      line_[DATAOUTPUTSIZE - 1] = 0;
      serverClient.print(line_);
    }
    for(byte h = 0; h < DATAOUTPUTSIZE - 1; h++)
    {
      serverClient.print(dataOutput_[h]);
    }
    serverClient.println();
  }
  dataFile.close();
}
