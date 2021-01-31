#include "bmp.h"

#include <SPI.h>

File* _file;

Bmp::Bmp(File* file)
{
  _file = file;

  // Skip to the pixel data
  // First get the pointer to the pixel data
  file->seek(10);
  long startOfPixelArray = readLong();
  file->seek(startOfPixelArray);
}

void Bmp::readPixelData(byte* buf, int len)
{
  _file->read(buf, len);
}

byte Bmp::readPixelData()
{
  return _file->read();
}

bool Bmp::available()
{
  return _file != 0 && _file->available();
}

unsigned long Bmp::position()
{
  return _file->position();
}

long Bmp::readLong()
{
  int index = 0;
  byte b[4];
  while (_file->available() && index < 4)
  {
    b[index] = _file->read();
    index++;
  }
  long result;

  result = b[3];
  result << 8;
  result |= b[2];
  result << 8;
  result |= b[1];
  result << 8;
  result |= b[0];

  return result;
}
