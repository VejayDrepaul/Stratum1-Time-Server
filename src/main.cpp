#include <Arduino.h>
#include <Adafruit_GPS.h>
#include "../include/seven_segment.hpp"

#define GPSSerial Serial1

// Connect to the GPS on the hardware port
Adafruit_GPS GPS(&GPSSerial);

// Set GPSECHO to 'false' to turn off echoing the GPS data to the Serial console
// Set to 'true' if you want to debug and listen to the raw GPS sentences
#define GPSECHO false

uint32_t timer = millis();

void setup()
{
    Serial.begin(115200);
    Serial.println("Adafruit GPS library basic parsing test!");
    GPS.begin(9600);                              // 9600 NMEA is the default baud rate for Adafruit MTK GPS's- some use 4800
    GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); // turn on RMC (recommended minimum) and GGA (fix data) including altitude
    GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);    // 1 Hz update rate
    GPS.sendCommand(PGCMD_ANTENNA);               // Request updates on antenna status, comment out to keep quiet

    // set seven segment pins
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(DP, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
}

void loop() // run over and over again
{
    // read data from the GPS in the 'main loop'
    char c = GPS.read();
    // if you want to debug, this is a good time to do it!
    if (GPSECHO)
        if (c)
            Serial.print(c);
    // if a sentence is received, we can check the checksum, parse it...
    if (GPS.newNMEAreceived())
    {
        // a tricky thing here is if we print the NMEA sentence, or data
        // we end up not listening and catching other sentences!
        // so be very wary if using OUTPUT_ALLDATA and trying to print out data
        Serial.print(GPS.lastNMEA());   // this also sets the newNMEAreceived() flag to false
        if (!GPS.parse(GPS.lastNMEA())) // this also sets the newNMEAreceived() flag to false
            return;                     // we can fail to parse a sentence in which case we should just wait for another
    }

    // approximately every 2 seconds or so, print out the current stats
    if (millis() - timer > 2000)
    {
        timer = millis(); // reset the timer
        Serial.print("\nTime: ");
        if (GPS.hour < 10)
        {
            Serial.print('0');
        }
        Serial.print(GPS.hour, DEC);
        Serial.print(':');
        if (GPS.minute < 10)
        {
            Serial.print('0');
        }
        Serial.print(GPS.minute, DEC);
        Serial.print(':');
        if (GPS.seconds < 10)
        {
            Serial.print('0');
        }
        Serial.print(GPS.seconds, DEC);
        Serial.print('.');
        if (GPS.milliseconds < 10)
        {
            Serial.print("00");
        }
        else if (GPS.milliseconds > 9 && GPS.milliseconds < 100)
        {
            Serial.print("0");
        }
        Serial.println(GPS.milliseconds);
        Serial.print("Date: ");
        Serial.print(GPS.day, DEC);
        Serial.print('/');
        Serial.print(GPS.month, DEC);
        Serial.print("/20");
        Serial.println(GPS.year, DEC);
        Serial.print("Fix: ");
        Serial.print((int)GPS.fix);
        Serial.print(" quality: ");
        Serial.println((int)GPS.fixquality);
        if (GPS.fix)
        {
            Serial.print("Location: ");
            Serial.print(GPS.latitude, 4);
            Serial.print(GPS.lat);
            Serial.print(", ");
            Serial.print(GPS.longitude, 4);
            Serial.println(GPS.lon);
            Serial.print("Speed (knots): ");
            Serial.println(GPS.speed);
            Serial.print("Angle: ");
            Serial.println(GPS.angle);
            Serial.print("Altitude: ");
            Serial.println(GPS.altitude);
            Serial.print("Satellites: ");
            Serial.println((int)GPS.satellites);
            Serial.print("Antenna status: ");
            Serial.println((int)GPS.antenna);
        }
    }
}