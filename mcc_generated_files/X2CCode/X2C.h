/**
 * @file
 * @brief Generated model file.
 * 
 * Date:  2024-07-03 08:20
 * 
 * X2C-Version: 6.5.3189
 * X2C-Edition: Educational
 */
/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: SmartPowerLab_01                                                                                            */
/* Date:  2024-07-03 08:20                                                                                            */

/* X2C-Version: 6.5.3189                                                                                              */
/* X2C-Edition: Educational                                                                                           */

#ifndef X2C_H
#define X2C_H

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************************************************/
/**     Includes                                                                                                     **/
/**********************************************************************************************************************/
/* Common includes                                                                                                    */
#include "TypeConv_FiP16_Bool.h"
#include "uConstant_FiP16.h"
#include "Not_Bool.h"
#include "SquareGen_FiP16.h"
#include "uConstant_Int16.h"
#include "AutoSwitch_FiP16.h"
#include "Scope_Main.h"
#include "CommonFcts.h"

/**********************************************************************************************************************/
/**     Defines                                                                                                      **/
/**********************************************************************************************************************/
#define FUNCTIONS \
    TYPECONV_FIP16_BOOL_FUNCTIONS , \
    UCONSTANT_FIP16_FUNCTIONS , \
    NOT_BOOL_FUNCTIONS , \
    SQUAREGEN_FIP16_FUNCTIONS , \
    UCONSTANT_INT16_FUNCTIONS , \
    AUTOSWITCH_FIP16_FUNCTIONS , \
    SCOPE_MAIN_FUNCTIONS

#define PARAMETER_TABLE \
    { 1U, &x2cModel.blocks.bAutoSwitch } , \
    { 2U, &x2cModel.blocks.bNot } , \
    { 3U, &x2cModel.blocks.bSquareGen } , \
    { 4U, &x2cModel.blocks.bTypeConv1 } , \
    { 5U, &x2cModel.blocks.bTypeConv2 } , \
    { 6U, &x2cModel.blocks.buConstant } , \
    { 7U, &x2cModel.blocks.buConstant1 } , \
    { 8U, &x2cModel.blocks.buConstant2 } , \
    { 15U, &x2cScope }

#define INPORT_PARAMID_TABLE \
    { 9U, 1U, &x2cModel.inports.bInport } , \
    { 10U, 2U, &x2cModel.inports.bInport_pot } 

#define OUTPORT_PARAMID_TABLE \
    { 11U, 1U, &x2cModel.outports.bOutport } , \
    { 12U, 1U, &x2cModel.outports.bOutport_blink } , \
    { 13U, 1U, &x2cModel.outports.bOutport_cmp } , \
    { 14U, 1U, &x2cModel.outports.bOutport_neg } 


/**********************************************************************************************************************/
/**                                            Model structure definition                                            **/
/**********************************************************************************************************************/
struct x2cModel {
/*  Control Blocks                                                                                                    */
    struct {
        AUTOSWITCH_FIP16 bAutoSwitch;
        NOT_BOOL bNot;
        SQUAREGEN_FIP16 bSquareGen;
        TYPECONV_FIP16_BOOL bTypeConv1;
        TYPECONV_FIP16_BOOL bTypeConv2;
        UCONSTANT_FIP16 buConstant;
        UCONSTANT_INT16 buConstant1;
        UCONSTANT_INT16 buConstant2;
    } blocks;
/*  Inports                                                                                                           */
    struct {
        bool bInport;
        int16 bInport_pot;
    } inports;
/*  Outports                                                                                                          */
    struct {
        bool* bOutport;
        bool* bOutport_blink;
        bool* bOutport_cmp;
        bool* bOutport_neg;
    } outports;
};

/**********************************************************************************************************************/
/**     Externals                                                                                                    **/
/**********************************************************************************************************************/
extern struct x2cModel x2cModel;

extern const tBlockFunctions blockFunctionTable[];
extern const tParameterTable parameterIdTable[];
extern const tIoParamIdEntry inportParamIdTable[];
extern const tIoParamIdEntry outportParamIdTable[];
extern const tMaskParameterEntry maskParamIdTable[];
extern const tMaskParamExtRecord maskParamExtTable[];
extern const tMaskParamDataRecord maskParamDataTable[];


/**********************************************************************************************************************/
/**     Prototypes                                                                                                   **/
/**********************************************************************************************************************/
void X2C_Init(void);
void X2C_Update(void);
void X2C_Update_1(void);

#ifdef __cplusplus
}
#endif

#endif
