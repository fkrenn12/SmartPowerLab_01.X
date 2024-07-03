/*
 * File:   scpi.c
 * Author: fkrenn
 *
 * Created on July 2, 2024, 12:01 PM
 */


#include "xc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mcc_generated_files/mcc.h"

#define IDENTIFICATION_QUERY "*IDN?"
#define RESET_COMMAND "*RST"
#define SELF_TEST_QUERY "*TST?"
#define OK "OK\n"


void upperCase(char *s){
    while (*s) {
    *s = toupper((unsigned char) *s);
    s++;
  }
}

bool mandatedCommand(char* command){
    bool done = false;
    if (strcmp(command,IDENTIFICATION_QUERY)==0){
        printf("HTL-Hollabrunn SmartPowerLab v1.0\n");
        done = true;
    }
    else if (strcmp(command,RESET_COMMAND)==0){
        printf(OK);
        done = true;
    }
    else if (strcmp(command,SELF_TEST_QUERY)==0){
        printf(OK);
        done = true;
    }
    return (done);
}

void scpiParse(char* command) {
    upperCase(command);
    // printf("Command received:<%s>\n",command);
    if (mandatedCommand(command)==false){
        printf("Reply:<%i>\n",ADC1_ConversionResultGet(channel_AN1));
    }
    
}
