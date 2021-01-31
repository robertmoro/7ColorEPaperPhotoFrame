#ifndef BMP_H
#define BMP_H

#include <SD.h>

class Bmp
{
  public:
    Bmp(File* file);
    void readPixelData(byte* buf, int len);
    byte readPixelData();
    bool available();
    unsigned long position();

  private:
    long readLong();
};

#endif /* BMP_H */
