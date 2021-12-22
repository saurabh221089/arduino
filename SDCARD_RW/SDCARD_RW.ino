#include <SD.h>

File myFile;

void setup()
{
Serial.begin(9600);
Serial.print("Initializing SD card...");
pinMode(10, OUTPUT);
if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
Serial.println("initialization done.");

// writing a file
if (SD.exists("test.txt"))
{
  Serial.println("test.txt exists.");
myFile = SD.open("test.txt", FILE_WRITE);
myFile.println("testing 1, 2, 3.");
myFile.close();
  Serial.println("Writing to file done..");
}
else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

// Open the file for reading
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("Reading contents of 'test.txt' :");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
        Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop()
{
}
