void error_blink(byte codenumber)
{
  if(codenumber == 0)
  {
    digitalWrite(9, LOW);
  }
  else if(codenumber == 1)
  {
    digitalWrite(9, HIGH);
  }
  else if(codenumber == 2) 
  {
    while(true)
    {
      digitalWrite(9, HIGH);
      delay(250);
      digitalWrite(9, LOW);
      delay(250);
    }
  }
}
