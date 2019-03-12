void actuation_digitalmanager()
{  
  if(actuationPinoutState_[0])
  {
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2, LOW);
  }
  if(actuationPinoutState_[1])
  {
    digitalWrite(3, HIGH);
  }
  else
  {
    digitalWrite(3, LOW);
  }
  if(actuationPinoutState_[2])
  {
    digitalWrite(5, HIGH);
  }
  else
  {
    digitalWrite(5, LOW);
  }
  if(actuationPinoutState_[3])
  {
    digitalWrite(6, HIGH);
  }
  else
  {
    digitalWrite(6, LOW);
  }
  if(actuationPinoutState_[4])
  {
    digitalWrite(7, HIGH);
  }
  else
  {
    digitalWrite(7, LOW);
  }
  if(actuationPinoutState_[5])
  {
    digitalWrite(8, HIGH);
  }
  else
  {
    digitalWrite(8, LOW);
  }
  if(actuationPinoutState_[6])
  {
    digitalWrite(9, HIGH);
  }
  else
  {
    digitalWrite(9, LOW);
  }
}

void actuation_digitalboss()
{
  actuationPinoutState_[0] = false;
  actuationPinoutState_[1] = false;
  actuationPinoutState_[2] = false;
  actuationPinoutState_[3] = false;
  actuationPinoutState_[4] = false;
  actuationPinoutState_[5] = false;
  actuationPinoutState_[6] = false;

  for(byte c = 0; c < 12; c++) //12 estados de minimos e maximos
  {
    if((adcActPinout_[c] & 1) == 1)
    {
      actuationPinoutState_[0] = actuationPinoutState_[0]|actuationState_[c];
    }
    if((adcActPinout_[c] & 2) == 2)
    {
      actuationPinoutState_[1] = actuationPinoutState_[1]|actuationState_[c];
    }
    if((adcActPinout_[c] & 4) == 4)
    {
      actuationPinoutState_[2] = actuationPinoutState_[2]|actuationState_[c];
    }
    if((adcActPinout_[c] & 8) == 8)
    {
      actuationPinoutState_[3] = actuationPinoutState_[3]|actuationState_[c];
    }
    if((adcActPinout_[c] & 16) == 16)
    {
      actuationPinoutState_[4] = actuationPinoutState_[4]|actuationState_[c];
    }
    if((adcActPinout_[c] & 32) == 32)
    {
      actuationPinoutState_[5] = actuationPinoutState_[5]|actuationState_[c];
    }
    if((adcActPinout_[c] & 64) == 64)
    {
      actuationPinoutState_[6] = actuationPinoutState_[6]|actuationState_[c];
    }
  }
  actuation_digitalmanager();
}

void actuation_toactoornottoact()
{
  set_analogValues_();
  for(byte a = 0; a < 6; a++)
  {
    if(!actuationState_[a * 2])
    {
      if(analogValues_[a] <= adcActValue_[a][0])
      {
        actuationState_[a * 2] = true;
      }
    }
    else
    {
      if(analogValues_[a] >= int(adcActValue_[a][0] + adcActValue_[a][2]))
      {
        actuationState_[a * 2] = false;
      }
    }
    if(!actuationState_[a * 2 + 1])
    {
      if(analogValues_[a] >= adcActValue_[a][1])
      {
        actuationState_[a * 2 + 1] = true;
      }
    }
    else
    {
      if(analogValues_[a] <= int(adcActValue_[a][1] - adcActValue_[a][2]))
      {
        actuationState_[a * 2 + 1] = false;
      }
    }
  } 
  actuation_digitalboss();
}
