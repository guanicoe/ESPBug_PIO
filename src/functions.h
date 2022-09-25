#include "Arduino.h"



bool progmemToSPIFFS(const char* adr, int len, String path) {
    File f = SPIFFS.open(path, "w+");
    if (!f) return false;

    for (int i = 0; i < len; f.write(pgm_read_byte_near(adr + i++)));
    f.close();
    return true;
}

bool writeFile(String path, String& buf) {
    if (path.charAt(0) != SLASH) path = String(SLASH) + path;
    File f = SPIFFS.open(path, "w+");
    if (!f) return false;

    for (uint32_t i = 0, len = buf.length(); i < len; f.write(buf.charAt(i++)));
    f.close();

    return true;
}


// for reading Strings from the PROGMEM
String str(const char* ptr) {
    char keyword[strlen_P(ptr)];

    strcpy_P(keyword, ptr);
    return String(keyword);
}

char *strconstcpy(char *dest, const char *src) {
  // Check if the byte is not a null terminator.
  // Only then copy the corresponding byte from
  // the source.
  for (char *_dest = dest; *_dest && ( *_dest++ = *src++ ););
}

String getFilename(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
