int dataserverclient_aetherprobe()
{
  byte n = 0;
  time_t timeInitial = now();
  time_t timePassed = 0;
  boolean availableItWas = false;
  while(timePassed < TIMEOUT)
  {
    timePassed = now() - timeInitial;
    if(serverClient.available())
    {
      if((n < DATAINPUTSIZE - 2))
      {
        dataInput_[n] = serverClient.read();
        n++;
      }
      else
      {
        serverClient.flush();
        timePassed = TIMEOUT;
      }
      availableItWas = true;
    }
    else if(!serverClient.available() && availableItWas)
    {
      timePassed = TIMEOUT;
    }
  }
  dataInput_[n] = 10;
  dataInput_[n + 1] = 0;
  return n;
}

void dataserverclient_aetherlistener()
{
  byte n = dataserverclient_aetherprobe();
    
  if(n < DATAINPUTBODYSIZE)
  {
    initParam_[0] = 2 + 48;
    errorCode_[1] = 1;
    rails++;
  }
  else if(!verifier_dataInput())
  {
    initParam_[0] = 1 + 48;
    errorCode_[2] = 1;
  }
  else
  {
    if(firstConnection)
    {
      firstConnection = false;
    }
    digitalWrite(9, LOW);
    setTime(converter_number('0', '0', dataInput_[8], dataInput_[9]), converter_number('0', '0', dataInput_[10], dataInput_[11]), 
            converter_number('0', '0', dataInput_[12], dataInput_[13]), converter_number('0', '0', dataInput_[6], dataInput_[7]), 
            converter_number('0', '0', dataInput_[4], dataInput_[5]), converter_number(dataInput_[0], dataInput_[1], dataInput_[2], dataInput_[3]));
    delayTime = converter_number(dataInput_[15], dataInput_[16], dataInput_[17], dataInput_[18]);
    set_adcThreshold();
    errorCode_[0] = 0;
    errorCode_[1] = 0;  
  }
}

void dataserverclient_connecting()
{
  if(serverClient.connect(dataserverAddress_, dataserverPort))
  {
    serverClient.print(F("POST / HTTP/1.1\n"));
    serverClient.print(F("Content-Length: "));
    if(firstConnection)
    {
      serverClient.println(INITPARAMSIZE - 1);
      for(byte q = 0; q < INITPARAMSIZE - 1; q++)
      {
        serverClient.print(initParam_[q]);
      }
      serverClient.println(); //essencial
      dataserverclient_aetherlistener();
    }
    else
    {
      if(!commFailed)
      {
        initParam_[21] = 0 + 48;
        initParam_[22] = 0 + 48;
        initParam_[23] = 0 + 48;
        initParam_[24] = 1 + 48;
        serverClient.println(INITPARAMSIZE - 1 + DATAOUTPUTSIZE - 1);
        for(byte k = 0; k < INITPARAMSIZE - 1; k++)
        {
          serverClient.print(initParam_[k]);
        }
        for(byte h = 0; h < DATAOUTPUTSIZE - 1; h++)
        {
          serverClient.print(dataOutput_[h]);
        }
        serverClient.println(); //essencial
        dataserverclient_aetherlistener();
      }
      else
      {
        sd_backupprinter();
        commFailed = false;
        dataserverclient_aetherlistener();
        SD.remove("backup.txt");
      }
    }
    errorCode_[0] = 0;
    error_blink(0);
  }
  else
  {
    error_blink(1);
    errorCode_[0] = 1;
    if(!firstConnection)
    {
      sd_writing(true);
      commFailed = true;
      fails++;
    }
  }
}

void dataserverclient_disconnecting()
{
  serverClient.stop();
}
