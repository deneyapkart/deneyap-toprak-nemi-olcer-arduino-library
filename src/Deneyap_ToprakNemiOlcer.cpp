/*
*****************************************************************************
@file         Deneyap_ToprakNemiOlcer.cpp
@mainpage     Deneyap Soil Moisture Sensor ICM7555CBA Arduino library 
              source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.0.1
@date         June 22, 2022
@brief        Includes functions to control Deneyap Soil Moisture Sensor 
              ICM7555CBA Arduino library

Library includes: 
--> Configuration functions
--> Data manipulation functions
--> I2C communication functions
*****************************************************************************
*/
#include "Deneyap_ToprakNemiOlcer.h"

/* Device Status Functions ---------------------------------------------------*/

/**
 * @brief  Configures I2C connection with user defined address and port
 * @param  address: I2C address of the device, port: I2C port number (0 or 1)
 * @retval connection status (1 --> connected, 0 --> not connected)
 */
bool SoilMoisture::begin(uint8_t address, TwoWire &port) {
    Wire.begin();
#if defined(ARDUINO_DYM)
    Wire.setClock(100000);
#else
    Wire.setClock(50000);
#endif
    _i2cAddress = address;
    _i2cPort = &port;
    _dataPacket = {0};

    return isConnected();
}

/**
 * @brief  Checks whether I2C connection established
 * @param  None
 * @retval connection status (1 --> connected, 0 --> not connected)
 */
bool SoilMoisture::isConnected() {
    _i2cPort->beginTransmission(_i2cAddress);

    if (_i2cPort->endTransmission() == 0)
        return true;
    return false;
}

/**
 * @brief  Requests firmware version of the device
 * @param  None
 * @retval Device firmware version
 */
uint16_t SoilMoisture::getFwVersion() {
    _dataPacket.command = SOIL_MOISTURE_REQUEST_FW_VERSION;
    _dataPacket.dataSize = 0;
    return I2C_ReadFirmwareData16bit(&_dataPacket);
}

/**
 * @brief  Sets (changes) I2C address of the device
 * @param  address: I2C address to be set
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */

bool SoilMoisture::setI2Caddress(uint8_t newAddress) {
    _dataPacket.command = SOIL_MOISTURE_CHANGE_ADDR;
    _dataPacket.dataSize = 1;
    _dataPacket.data[0] = newAddress;

    bool status = I2C_SendDataPacket(&_dataPacket);

    if (status == true) {
        _i2cAddress = newAddress;
        return true;
    }
    else {
        return false;
    }
}

/* I2C Data Manipulation Functions -------------------------------------------*/

/**
 * @brief  Reads the SOIL_MOISTURE pin
 * @param  None
 * @retval uint16_t : SOIL_MOISTURE pin value
 */
uint16_t SoilMoisture::ReadSoilMoisture() {
    _dataPacket.command = (uint8_t)READ_SOIL_MOISTURE;
    _dataPacket.dataSize = 0;
    return I2C_ReadData16bit(&_dataPacket);
}

/* I2C Data Transaction Funstions --------------------------------------------*/

/**
 * @brief  Reads 8bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 8bit data
 */
uint8_t SoilMoisture::I2C_ReadData8bit(SoilMoisture_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(1)) != 0)
        return _i2cPort->read();
    return 0;
}

/**
 * @brief  Reads 16bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 16bit data
 */
uint16_t SoilMoisture::I2C_ReadData16bit(SoilMoisture_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(2)) != 0) {
        uint16_t i2cData = _i2cPort->read();
        i2cData |= (_i2cPort->read() << 8);
        return i2cData;
    }
    return 0;
}

/**
 * @brief  Reads 16bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 16bit data
 */
uint16_t SoilMoisture::I2C_ReadFirmwareData16bit(SoilMoisture_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(2)) != 0) {
        i2cData2 = _i2cPort->read();
        i2cData1 = _i2cPort->read();
        Serial.print("v"); Serial.print(i2cData1); Serial.print("."); Serial.print(i2cData2);
    }
    return 0;
}

/**
 * @brief  Sends data packet based on a custom defined protocol
 * @param  dataPacket: includes all related data
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */
bool SoilMoisture::I2C_SendDataPacket(SoilMoisture_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->write(dataPacket->dataSize);

    for (uint8_t i = 0; i < _dataPacket.dataSize; i++)
        _i2cPort->write(_dataPacket.data[i]);

    if (_i2cPort->endTransmission() == 0)
        return true;
    return false;
}
