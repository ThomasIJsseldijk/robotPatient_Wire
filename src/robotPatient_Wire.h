/**
 * @file robotPatient_Wire.h
 * @author Thomas IJsseldijk (fhm.ijsseldijk@student.han.nl)
 * @brief
 * @version 0.1
 * @date 07-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef ROBOTPATIENT_WIRE_H
#define ROBOTPATIENT_WIRE_H

#define sensorHub
//#define mainBoard



#include <arduino.h>
#include <Wire.h>
#include <wiring_private.h>
#include <array>



class robotPatient_Wire
{
private:

typedef struct port
{

    uint8_t sdaPin;
    uint8_t sclPin;
    SERCOM *sercom;
    EPioType sercomType;

} port;

public:


    TwoWire *dataWire;
    robotPatient_Wire();
    ~robotPatient_Wire();
    void begin(port channel);
    void begin(port channel, byte slaveAdress);
    void send(byte slaveAddress, byte data[]);
    void read(byte slaveAddress, byte buffer[], int amountOfBytes);
    void onReceive(void (*onrecieve)(int));
    void onRequest(void (*onrequest)());
    

    #if defined sensorHub

    port backbone = {26, 27, &sercom3, PIO_SERCOM};
    port sensorA = {13, 11, &sercom1, PIO_SERCOM};
    port sensorB = {28, 38, &sercom2, PIO_SERCOM};

    #elif defined mainBoard

    port backbone = {12,13, &sercom2, PIO_SERCOM};

    #else
    #error "please define sensorHub or mainBoard!"
    #endif

};


#endif