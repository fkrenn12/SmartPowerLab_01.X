/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: SmartPowerLab_01                                                                                            */
/* Date:  2024-07-03 08:20                                                                                            */

/* X2C-Version: 6.5.3189                                                                                              */
/* X2C-Edition: Educational                                                                                           */

/* Common includes                                                                                                    */
#include <stddef.h>
#include "TableStruct.h"
/* Generated file includes                                                                                            */
#include "FlashTable.h"
#include "RamTable.h"
#include "X2C.h"

/**********************************************************************************************************************/
/**                                                       Model                                                      **/
/**********************************************************************************************************************/
struct x2cModel x2cModel;

/**********************************************************************************************************************/
/**                                                       Scope                                                      **/
/**********************************************************************************************************************/
SCOPE_MAIN x2cScope;

/* Block function table                                                                                               */
const tBlockFunctions blockFunctionTable[] = {
    FUNCTIONS,
    { 0U, NULL, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Parameter identifier table                                                                                         */
const tParameterTable parameterIdTable[] = {
    PARAMETER_TABLE,
    { 0U, NULL } /* End of table entry */
};

/* Inport Parameter identifier table                                                                                  */
const tIoParamIdEntry inportParamIdTable[] = {
    INPORT_PARAMID_TABLE, 
    { 0U, 0U, NULL } /* End of table entry */
};

/* Outport Parameter identifier table                                                                                 */
const tIoParamIdEntry outportParamIdTable[] = {
    OUTPORT_PARAMID_TABLE, 
    { 0U, 0U, NULL } /* End of table entry */
};

/* Mask Parameter identifier table                                                                                    */
const tMaskParameterEntry maskParamIdTable[] = {
    { 0U, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Extended Mask Parameter identifier table (used by Model API)                                                       */
const tMaskParamExtRecord maskParamExtTable[] = {
    { 0U, 0U, NULL, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Mask Parameter data table (used by Model API)                                                                      */
const tMaskParamDataRecord maskParamDataTable[] = {
    { 0U, 0U, NULL, 0U, 0U } /* End of table entry */
};

/**********************************************************************************************************************/
/** Model Sample Time                                                                                                **/
/**********************************************************************************************************************/
float_CoT getModelSampleTime()
{
    return ((float_CoT)0.001);
}

/**********************************************************************************************************************/
/**                                                  Initialization                                                  **/
/**********************************************************************************************************************/
void X2C_Init(void)
{
    /******************************************************************************************************************/
    /**                                          Initialize Block Parameters                                         **/
    /******************************************************************************************************************/

    /* Block: AutoSwitch                                                                                              */
    /* Thresh_up = 0.5                                                                                                */
    /* Thresh_down = 0.4                                                                                              */
    x2cModel.blocks.bAutoSwitch.Thresh_up = 16384;
    x2cModel.blocks.bAutoSwitch.Thresh_down = 13107;
    x2cModel.blocks.bAutoSwitch.Status = &RamTable_int16[0];

    /* Block: Not                                                                                                     */

    /* Block: SquareGen                                                                                               */
    /* fmax = 10.0                                                                                                    */
    /* LL = 0.0                                                                                                       */
    /* LH = 1.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.bSquareGen.delta_phi = 655;
    x2cModel.blocks.bSquareGen.phi = 0;
    x2cModel.blocks.bSquareGen.level_low = 0;
    x2cModel.blocks.bSquareGen.level_high = 32767;

    /* Block: TypeConv1                                                                                               */

    /* Block: TypeConv2                                                                                               */

    /* Block: uConstant                                                                                               */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.buConstant.K = 0;

    /* Block: uConstant1                                                                                              */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.buConstant1.K = 0;

    /* Block: uConstant2                                                                                              */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.buConstant2.K = 1;


    /* Initialize RAM table content */
    initRamTables();

    /******************************************************************************************************************/
    /**                                              Initialize Inports                                              **/
    /******************************************************************************************************************/
    x2cModel.inports.bInport = false;
    x2cModel.inports.bInport_pot = (int16)0;

    /******************************************************************************************************************/
    /**                                               Link Block Inputs                                              **/
    /******************************************************************************************************************/

    /* Block AutoSwitch                                                                                               */
    x2cModel.blocks.bAutoSwitch.In1 =
        &x2cModel.blocks.buConstant2.Out;
    x2cModel.blocks.bAutoSwitch.Switch =
        &x2cModel.inports.bInport_pot;
    x2cModel.blocks.bAutoSwitch.In3 =
        &x2cModel.blocks.buConstant1.Out;

    /* Block Not                                                                                                      */
    x2cModel.blocks.bNot.In =
        &x2cModel.inports.bInport;

    /* Block SquareGen                                                                                                */
    x2cModel.blocks.bSquareGen.f =
        &x2cModel.inports.bInport_pot;
    x2cModel.blocks.bSquareGen.dc =
        &x2cModel.blocks.buConstant.Out;

    /* Block TypeConv1                                                                                                */
    x2cModel.blocks.bTypeConv1.In =
        &x2cModel.blocks.bAutoSwitch.Out;

    /* Block TypeConv2                                                                                                */
    x2cModel.blocks.bTypeConv2.In =
        &x2cModel.blocks.bSquareGen.u;

    /* Block uConstant                                                                                                */

    /* Block uConstant1                                                                                               */

    /* Block uConstant2                                                                                               */

    /******************************************************************************************************************/
    /**                                                 Link Outports                                                **/
    /******************************************************************************************************************/
    x2cModel.outports.bOutport =
        &x2cModel.inports.bInport;
    x2cModel.outports.bOutport_blink =
        &x2cModel.blocks.bTypeConv2.Out;
    x2cModel.outports.bOutport_cmp =
        &x2cModel.blocks.bTypeConv1.Out;
    x2cModel.outports.bOutport_neg =
        &x2cModel.blocks.bNot.Out;

    /******************************************************************************************************************/
    /**                                           Run Block Init Functions                                           **/
    /******************************************************************************************************************/
    AutoSwitch_FiP16_Init(&x2cModel.blocks.bAutoSwitch);
    Not_Bool_Init(&x2cModel.blocks.bNot);
    SquareGen_FiP16_Init(&x2cModel.blocks.bSquareGen);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.bTypeConv1);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.bTypeConv2);
    uConstant_FiP16_Init(&x2cModel.blocks.buConstant);
    uConstant_Int16_Init(&x2cModel.blocks.buConstant1);
    uConstant_Int16_Init(&x2cModel.blocks.buConstant2);
    Scope_Main_Init(&x2cScope);

    /* Initialize TableStruct tables                                                                                  */
    TableStruct->TFncTable = blockFunctionTable;
    TableStruct->TParamTable = parameterIdTable;
    TableStruct->inportParamTable = inportParamIdTable;
    TableStruct->outportParamTable = outportParamIdTable;
    TableStruct->maskParameterTable = maskParamIdTable;
}

/**********************************************************************************************************************/
/**                                            Run Block Update Functions                                            **/
/**********************************************************************************************************************/
void X2C_Update(void)
{
    X2C_Update_1();

}

/* X2C_Update for blocks with 1*Ts                                                                                    */
void X2C_Update_1(void)
{
    AutoSwitch_FiP16_Update(&x2cModel.blocks.bAutoSwitch);
    SquareGen_FiP16_Update(&x2cModel.blocks.bSquareGen);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.bTypeConv1);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.bTypeConv2);
    Not_Bool_Update(&x2cModel.blocks.bNot);
    Scope_Main_Update(&x2cScope);
}

