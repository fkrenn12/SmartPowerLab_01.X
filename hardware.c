/*
 * File:   hardware.c
 * Author: fkrenn
 *
 * Created on July 1, 2024, 3:44 PM
 */


#include "xc.h"
#include "hardware.h"

// manual coding of ADC initialization 
// NOT needed if mcc generates code
// this is only an example of code not generated from mcc

void ADC_init(void) {
    /* VPot */
    ANSELAbits.ANSA1 = 1; /* AN1: analog input */
    /* VTouch */
    ANSELAbits.ANSA0 = 1; /* AN0: analog input */
    
    /*------------------------------------------------------------------------*/
    /** - Configuration of ADC
     *    - 10 bit mode
     *    - internal RC clock source
     *    - continuous sampling and auto conversion
     *    - channel scan AN0, AN1
     *    .
     */
    /*------------------------------------------------------------------------*/
    AD1CON1bits.AD12B = 0;      /* 10bit mode */
    AD1CON2bits.VCFG = 0b000;   /* AVdd and AVss as voltage reference */
    AD1CON3bits.ADRC = 1;       /* ADC uses internal RC clock */
    AD1CON2bits.CHPS = 0b00;    /* converts CH0 */
    AD1CON2bits.CSCNA = 1;      /* scan channel 0 */
    AD1CON2bits.SMPI = 1;       /* scan 2 channels */
    AD1CHS0bits.CH0NA = 0;      /* channel 0 negative input is Vrefl */
    AD1CHS0bits.CH0SA = 0b0000; /* channel 0 positive input is AN0 */
    AD1CSSLbits.CSS0 = 1;       /* select AN0 for input scan */
    AD1CSSLbits.CSS1 = 1;       /* select AN1 for input scan */
    AD1CON1bits.SIMSAM = 1;     /* simultaneously sampling */
    AD1CON1bits.ASAM = 1;       /* sampling begins after last conversion */
    AD1CON1bits.SSRCG = 0;      /* sample trigger group 0 */
    AD1CON1bits.SSRC = 0b111;   /* internal counter ends sampling and starts conversion (auto conversion) */
    AD1CON3bits.SAMC = 0b00000; /* not used for SSRC = 0b111 */
    AD1CON1bits.FORM = 0b00;    /* integer output (right aligned) */
    AD1CON1bits.ADON = 1;       /* enable ADC */
}
