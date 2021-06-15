#include <SPI.h>
#include <SD.h>

const int chipSelect = 10; //Para nuestro modelo de shield

void initSD() {

  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
  }
  Serial.println("card initialized.");
}

void writeSD(String datos){
  
   String dataString = datos;
   File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
  }
}
