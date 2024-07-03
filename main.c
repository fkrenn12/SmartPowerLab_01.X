/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33EP256MC502
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
#include "hardware.h" // for hardware initializing outside mcc
#include <string.h>
#include <stdio.h>
#include "scpi.h"

#define RX_BUFSIZE 254
#define CR 13
#define LF 10

uint8_t commandBuffer[RX_BUFSIZE];

void UART_Receive_Handler(void)
{
    char char_received = 0;
    uint8_t used_nmbr = RX_BUFSIZE - UART1_ReceiveBufferSizeGet();
    if (used_nmbr > 0 && used_nmbr < RX_BUFSIZE){
        for (unsigned int i=0;i<=(used_nmbr-1);i++){
            char_received = UART1_Peek(i);
            if (char_received==CR || char_received==LF){
                // read inclusive CR or LF
                UART1_ReadBuffer(commandBuffer,used_nmbr);
                commandBuffer[used_nmbr-1] = 0;  // remove CR, LF
                // TODO: remove all control chars
                if (strlen(commandBuffer)){
                    scpiParse(commandBuffer);
                }
            }
        }
    } 
}

void TMR2_Handler(void)
{
    static int counter = 0;   
    LED2_Toggle();
    counter++;
}
/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TMR2_SetInterruptHandler(TMR2_Handler);
    // UART1_SetRxInterruptHandler(UART_Receive_Handler);
    while (1)
    {
        // Add your application code
        UART_Receive_Handler();
    }
    return 1; 
}
/**
 End of File
*/

