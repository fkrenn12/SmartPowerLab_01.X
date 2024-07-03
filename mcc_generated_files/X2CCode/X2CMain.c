/* ************************************************************************** */
/** X2CMain.c

  @Company
    Microchip Technology

  @Summary
 Implementation of X2C In and Outport connections

 */
/* ************************************************************************** */
#include <xc.h>
#include "X2CMain.h"


#include "X2C.h"
#ifndef X2C_H
#warning "Please generate the code from the model!"
#endif
#include "../mcc.h"

void UpdateInports(void) {
    // Pass the peripheral values to model Inports
    x2cModel.inports.bInport = PORTAbits.RA4;  
    x2cModel.inports.bInport_pot = ADC1_ConversionResultGet(channel_AN1) << 5;
}

void UpdateOutports(void) {
    // Pass model outports to peripherals e.g.:  
    LATBbits.LATB6 = *x2cModel.outports.bOutport_blink;
    LATBbits.LATB7 = *x2cModel.outports.bOutport_cmp;
    LATBbits.LATB8 = *x2cModel.outports.bOutport_neg;
    LATBbits.LATB9 = *x2cModel.outports.bOutport; 
    // LATBbits.LATB9 = ~LATBbits.LATB9;
}

//Interrupt handler to call model update
void TMR1_CallBack(void){
    UpdateInports();
    X2C_Update();
    UpdateOutports();
}

/* *****************************************************************************
 End of File
 */
