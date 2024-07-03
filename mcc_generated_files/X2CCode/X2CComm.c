/* ************************************************************************** */
/** X2CComm.c

  @Company
    Microchip Technology

  @Summary
    Implements the X2C Lin protocol connection with MCC Peripheral drivers.

 */
/* ************************************************************************** */

#include "X2CComm.h"

static void sendSerial (tSerial* serial, uint8 data);
static uint8 receiveSerial (tSerial* serial);
static uint8 isReceiveDataAvailable (tSerial*  serial);
static uint8 isSendReady (tSerial* serial);

/**
 * @brief Link serial functions to X2C
 * 
 * @param[in] serial Serial interface object.
 */
void initX2CSerial (tSerial* serial)
{
  serial->send = (void (*)(tInterface*, uint8))sendSerial;
  serial->receive = (uint8 (*)(tInterface*))receiveSerial;
  serial->isReceiveDataAvailable = (uint8 (*)(tInterface*))isReceiveDataAvailable;
  serial->isSendReady = (uint8 (*)(tInterface*))isSendReady;
}

/** 
  @brief
    Puts the data to the hardware layer. (UART)
   @param[in] serial Serial interface object. (Not used)
   @param[in] data Data to send 
 */
static void sendSerial (tSerial* serial, uint8 data)
{
}

/** 
  @brief
   Get serial data from hardware. Reset the hardware in case of error. (UART2)
  @param[in] serial Serial interface object. (Not used)
  @return
    Return with the received data
 */
static uint8 receiveSerial (tSerial* serial)
{

}

/** 
  @brief  Check data availability (UART).
  @param[in] serial Serial interface object. (Not used)
  @return
    True -> Serial data ready to read.
    False -> No data.
 */
static uint8 isReceiveDataAvailable (tSerial* serial)
{

}

/** 
  @brief
   Check output buffer. (UART)
  @param[in] serial Serial interface object. (Not used)
  @return    
    True -> Transmit buffer is not full, at least one more character can be written.
    False -> Transmit buffer is full.
 */
static uint8 isSendReady (tSerial* serial)
{
}
/* *****************************************************************************
 End of File
 */