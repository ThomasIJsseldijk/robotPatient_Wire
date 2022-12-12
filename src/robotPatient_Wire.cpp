/**
 * @file robotPatient_wire.cpp
 * @author Thomas IJsseldijk (fhm.ijsseldijk@student.han.nl)
 * @ Modified by: Your name
 * @version 0.1
 * @date 07-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "robotPatient_Wire.h"

/**
 * @brief Construct a new robotPatient Wire::robotPatient Wire object
 *
 */
robotPatient_Wire::robotPatient_Wire()
{
}
/**
 * @brief Destroy the robotPatient Wire::robotPatient Wire object
 *
 */
robotPatient_Wire::~robotPatient_Wire()
{
}
/**
 * @brief
 *
 * @param channel
 * @param slaveAdress
 */
void robotPatient_Wire::begin(port channel, byte slaveAdress)
{

    dataWire = new TwoWire(channel.sercom, channel.sdaPin, channel.sclPin);
    dataWire->begin(slaveAdress);
    // pinPeripheral(channel.sdaPin, channel.sercomType);
    // pinPeripheral(channel.sclPin, channel.sercomType);
}
/**
 * @brief
 *
 * @param channel
 */
void robotPatient_Wire::begin(port channel)
{

    dataWire = new TwoWire(channel.sercom, channel.sdaPin, channel.sclPin);
    dataWire->begin();
    pinPeripheral(channel.sdaPin, channel.sercomType);
    pinPeripheral(channel.sclPin, channel.sercomType);
}
/**
 * @brief
 *
 * @param slave_addres
 * @param data
 */
void robotPatient_Wire::send(byte slave_addres, byte data[])
{
    dataWire->beginTransmission(slave_addres);
    dataWire->write(data, sizeof(data));
    dataWire->endTransmission(true);
}

/**
 * @brief
 *
 * @param slave_addres
 * @param buffer
 * @param amountOfBytes
 */
void robotPatient_Wire::read(byte slave_addres, byte buffer[], int amountOfBytes)
{

    dataWire->requestFrom(slave_addres, amountOfBytes, true);
    dataWire->readBytes(buffer, amountOfBytes);
}

void robotPatient_Wire::onReceive(void (*onreceive)(int))
{
    dataWire->onReceive(onreceive);
}
void robotPatient_Wire::onRequest(void (*onrequest)())
{
    dataWire->onRequest(onrequest);
}