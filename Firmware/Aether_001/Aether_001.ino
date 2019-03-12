#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
#include <Time.h>
#include "NetworkSettings.h"
#include "ChronoSettings.h"
#include "DataSettings.h"

void setup()
{
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  if(analogRead(A5) != 1023)
  {
    delayTime = analogRead(A5);
  }
  if(!SD.begin(4))
  {
    error_blink(2);
  }
  SD.remove("backup.txt");
  networkconfig_configsdcard();
  Ethernet.begin(macAddress_, ipAddress_, dnsAddress_, gatewayAddress_);
  serverServer.begin();
  set_initParam_();
}

void loop()
{  
  if(chrono_trigger())
  {
    if(!firstConnection)
    {
      set_dataOutput_();
      sd_writing(false);
    }
    if(serverConnecting)
    {
      dataserverclient_connecting();
      delay(50);
      dataserverclient_disconnecting();
    }
    previousTime = now();
  }
  actuation_toactoornottoact();
  serverhtml_running();
  delay(1000);
}
