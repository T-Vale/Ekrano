void serverhtml_running()
{
  set_analogValues_();
  EthernetClient client = serverServer.available();
  
  byte a = 0;
  byte b = 0;
  char sextet[6];
  byte datareceivedsize = 40;
  char datareceived[datareceivedsize];
  boolean getdata = false;
  boolean readtime = false;
  boolean readdelay = false;
  boolean readsconn = false;
  boolean readdata = false;
  boolean readprog = false;
  
  boolean datatoprint = false;
  time_t t = now();
  
  sextet[0] = ' ';
  sextet[1] = ' ';
  sextet[2] = ' ';
  sextet[3] = ' ';
  sextet[4] = ' ';
  sextet[5] = ' ';
  
  if (client) 
  {
    boolean currentLineIsBlank = true;
    while (client.connected()) 
    {
      if (client.available()) 
      {
        char c = client.read();
        sextet[5] = c;
        if((readtime || readdelay || readsconn || readdata || readprog) && b < datareceivedsize)
        {
          datareceived[b] = c;
          b++;
        }
        if(sextet[2] == 'G' && sextet[3] == 'E' && sextet[4] == 'T' && sextet[5] == ' ')
        {
          getdata = true;
        }
        if(sextet[1] == 't' && sextet[2] == 'i' && sextet[3] == 'm' && sextet[4] == 'e' && sextet[5] == '=' && getdata)
        {
          readtime = true;
          readdelay = false;
          readsconn = false;
          readdata = false;
          readprog = false;
        }     
        if(sextet[0] == 'd' && sextet[1] == 'e' && sextet[2] == 'l' && sextet[3] == 'a' && sextet[4] == 'y' && sextet[5] == '=' && getdata)
        {
          readdelay = true;
          readtime = false;
          readsconn = false;
          readdata = false;
          readprog = false;
        }
        if(sextet[0] == 's' && sextet[1] == 'c' && sextet[2] == 'o' && sextet[3] == 'n' && sextet[4] == 'n' && sextet[5] == '=' && getdata)
        {
          readdelay = false;
          readtime = false;
          readsconn = true;
          readdata = false;
          readprog = false;
        }
        if(sextet[0] == 'l' && sextet[1] == 'd' && sextet[2] == 'a' && sextet[3] == 't' && sextet[4] == 'a' && sextet[5] == '=' && getdata)
        {
          readdelay = false;
          readtime = false;
          readsconn = false;
          readdata = true;
          readprog = false;
        }
        if(sextet[1] == 'p' && sextet[2] == 'r' && sextet[3] == 'o' && sextet[4] == 'g' && sextet[5] == '=' && getdata)
        {
          readdelay = false;
          readtime = false;
          readsconn = false;
          readdata = false;
          readprog = true;
        }
        
        if(((sextet[1] == ' ' && sextet[2] == 'H' && sextet[3] == 'T' && sextet[4] == 'T' && sextet[5] == 'P') || sextet[5] == ';') && getdata)
        {
          if (readtime)
          {
            setTime(converter_number('0', '0', datareceived[8], datareceived[9]), converter_number('0', '0', datareceived[10], datareceived[11]), 
            converter_number('0', '0', datareceived[12], datareceived[13]), converter_number('0', '0', datareceived[6], datareceived[7]), 
            converter_number('0', '0', datareceived[4], datareceived[5]), converter_number(datareceived[0], datareceived[1], datareceived[2], datareceived[3]));
            firstConnection = false;
            t = now();
            previousTime = t;
            readtime = false;
          }
          if (readdelay)
          {
            delayTime = converter_number(datareceived[0], datareceived[1], datareceived[2], datareceived[3]);
            readdelay = false;
          }
          if (readsconn)
          {
            if (datareceived[0] == '1')
            {
              serverConnecting = true;
            }
            else
            {
              serverConnecting = false;
            }
            readsconn = false;
          }
          if (readdata)
          {
            readdata = false;
            ldatalines = converter_number(datareceived[0], datareceived[1], datareceived[2], datareceived[3]);
            datatoprint = true;
          }
          if (readprog)
          {
            byte adcNumber = 0;
            readprog = false;
            adcNumber = converter_number('0', '0', '0', datareceived[0]);
            adcActValue_[adcNumber][0] = converter_number(datareceived[2], datareceived[3], datareceived[4], datareceived[5]);
            adcActPinout_[adcNumber * 2] = converter_number('0', datareceived[7], datareceived[8], datareceived[9]);
            adcActValue_[adcNumber][1] = converter_number(datareceived[11], datareceived[12], datareceived[13], datareceived[14]);
            adcActPinout_[adcNumber * 2 + 1] = converter_number('0', datareceived[16], datareceived[17], datareceived[18]);
            adcActValue_[adcNumber][2] = converter_number('0', datareceived[20], datareceived[21], datareceived[22]);
          }
          
          b = 0;
          if (sextet[5] != ';')
          {
            getdata = false;
          } 
        }
        sextet[0] = sextet[1];
        sextet[1] = sextet[2];
        sextet[2] = sextet[3];
        sextet[3] = sextet[4];
        sextet[4] = sextet[5];
        sextet[5] = ' ';
        
        if (c == '\n' && currentLineIsBlank) 
        {
          client.println(F("HTTP/1.1 200 OK"));
          client.println(F("Content-Type: text/xml"));
          client.println();
          client.print(F("<Devices-Detail-Response>\n<MACAddress>"));
          client.print(macAddress_[0], HEX);
          client.print(F(":"));
          client.print(macAddress_[1], HEX);
          client.print(F(":"));
          client.print(macAddress_[2], HEX);
          client.print(F(":"));
          client.print(macAddress_[3], HEX);
          client.print(F(":"));
          client.print(macAddress_[4], HEX);
          client.print(F(":"));
          client.print(macAddress_[5], HEX);
          client.print(F("</MACAddress>\n<Time>"));
          client.print(year(t));
          client.print(F("-"));
          client.print(month(t));
          client.print(F("-"));
          client.print(day(t));
          client.print(F(" "));
          client.print(hour(t));
          client.print(F(":"));
          client.print(minute(t));
          client.print(F(":"));
          client.print(second(t));
          client.print(F("</Time>\n<ConnectingServer>"));
          if (serverConnecting)
          {
            client.print('1');
          }
          else
          {
            client.print('0');
          } 
          client.print(F("</ConnectingServer>\n<WritesFailed>"));
          client.print(commFailed);
          client.print(F("</WritesFailed>\n<ReadsFailed>"));
          client.print(fails);
          client.print(F("</ReadsFailed>\n<Delay>"));
          client.print(delayTime);
          client.print(F("</Delay>\n<Error>"));
          for(int z = 0; z < 6; z++)
          {
            client.print(errorCode_[z]);
          }
          client.print(F("</Error>\n<DigitalOutput>"));
          for(int f = 0; f < 7; f++)
          {
            client.print(actuationPinoutState_[f]);
          }
          client.println(F("</DigitalOutput>"));
          
          if(datatoprint)
          {
            File dataFile = SD.open("data.txt", FILE_READ);
            char o = 10; //line feed
            long r = 0;
            client.println(F("<LastData>"));
            
            if (dataFile)
            {
              long readindex = dataFile.size() - ldatalines * (DATAOUTPUTSIZE - 1);
              if (readindex < 0)
              {
                readindex = 0;
              }
              dataFile.seek(readindex);
              client.print(F("<Data"));
              client.print(r);
              client.print(F(">\n"));
              while (dataFile.available()) 
              {
                o = dataFile.read();
                if(o == 10) //line feed
                {
                  client.print(F("</Data"));
                  client.print(r);
                  r++;
                  client.print(F(">\n<Data"));
                  client.print(r);
                  client.print(F(">\n"));
                }
                else
                { 
                  client.print(o);
                }
              }
              client.print(F("</Data"));
              client.print(r);
              client.print(F(">\n"));
            }
            dataFile.close();
            client.println(F("</LastData>\n"));
            datatoprint = false;
            ldatalines = 0;
          }
          else
          {
            for(int analogChannel = 0; analogChannel < 6; analogChannel++) 
            {
              client.print(F("<ADC"));
              client.print(analogChannel);
              client.print(F(">\n<Value>"));
              client.print(analogValues_[analogChannel]);
              client.print(F("</Value>\n<ThresMin>"));
              client.print(adcThreshold_[analogChannel][0]);
              client.print(F("</ThresMin>\n<ThresMax>"));
              client.print(adcThreshold_[analogChannel][1]);
              client.print(F("</ThresMax>\n<ActuationMin>"));
              client.print(adcActValue_[analogChannel][0]);
              client.print(F("</ActuationMin>\n<ActuationMax>"));
              client.print(adcActValue_[analogChannel][1]);
              client.print(F("</ActuationMax>\n<Hysteresis>"));
              client.print(adcActValue_[analogChannel][2]);
              client.print(F("</Hysteresis>\n<IOPinout>"));
              client.print(adcActPinout_[analogChannel * 2], BIN);
              client.print(F(":"));
              client.print(adcActPinout_[analogChannel * 2 + 1], BIN);
              client.print(F("</IOPinout>\n</ADC"));
              client.print(analogChannel);  
              client.print(F(">\n"));
            }
          }
          client.println(F("\n</Devices-Detail-Response>"));
          break;
        }
        if (c == '\n') 
        {
          currentLineIsBlank = true;
        } 
        else if (c != '\r') 
        {
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    client.stop();
  }
}
