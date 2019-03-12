boolean chrono_trigger()
{
  if((now() - previousTime) >= delayTime)
  {
    return true;
  }
  else
  {
    return false;
  }
}
