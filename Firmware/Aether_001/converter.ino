int converter_numberascii(int number, int nhouse)
{
  return int(number / math_expo(10,nhouse)) - (int(number / math_expo(10,nhouse + 1)) * 10) + 48;
}

unsigned long converter_number(char i3, char i2, char i1, char i0)
{
  return ((long(i3) - 48) * 1000 + (long(i2) - 48) * 100 + (long(i1) - 48) * 10 + (long(i0) - 48));
}

int converter_fromhex(char j1, char j0)
{
  return (converter_hextech(j1) * 16 + converter_hextech(j0));
}

int converter_hextech(char j)
{
  if(int(j) >= 97)
  {
    return (int(j) - 87);
  }
  else if(int(j) >= 65)
  {
    return (int(j) - 55);
  }
  else
  {
    return (int(j) - 48);
  }
}
