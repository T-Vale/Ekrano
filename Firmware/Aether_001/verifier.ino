boolean verifier_number(char u)
{
  return (u >= 48 && u <= 57);
}

boolean verifier_dataInput()
{
  boolean verified = true;
  for(byte o = 0; o < DATAINPUTBODYSIZE; o++)
  {
    if(!(o == 14 || o == 19 || o == 24 || o == 29 || o == 34 || o == 39 || o == 44 || o == 49 || o == 54 || o == 59 || o == 64 || o == 69 || o == 74))
    {
      verified &= verifier_number(dataInput_[o]);
    }
  }
  return verified;
}
