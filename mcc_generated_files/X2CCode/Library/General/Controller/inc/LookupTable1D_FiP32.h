/*
 * Copyright (c) 2013, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
 * All rights reserved.
 */
/*
 * This file is licensed according to the BSD 3-clause license as follows:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the "Linz Center of Mechatronics GmbH" and "LCM" nor
 *       the names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL "Linz Center of Mechatronics GmbH" BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * This file is part of X2C. http://x2c.lcm.at/
 * $LastChangedRevision: 2584 $
 */
/* USERCODE-BEGIN:Description                                                                                         */
/* Description: One dimensional look-up table with selectable number of entries */
/* USERCODE-END:Description                                                                                           */
#ifndef LOOKUPTABLE1D_FIP32_H
#define LOOKUPTABLE1D_FIP32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(LOOKUPTABLE1D_FIP32_ISLINKED)
#define LOOKUPTABLE1D_FIP32_ID ((uint16)498)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          ID;
    int32           *x;
    int32           Out;
const  int32        *Table;
    int8            sfrX;
    uint32          maskX;
    uint16          idxOffsetX;
    int32           gainX;
    int8            gainXsfr;
    int32           offsetX;
    int32           minX;
    int32           maxX;
} LOOKUPTABLE1D_FIP32;
#else
typedef struct {
    uint16          ID;
    INT32_PTR       x;
    int32           Out;
const  INT32_PTR    Table;
    int8            sfrX;
    uint32          maskX;
    uint16          idxOffsetX;
    int32           gainX;
    int8            gainXsfr;
    int32           offsetX;
    int32           minX;
    int32           maxX;
} LOOKUPTABLE1D_FIP32;
#endif

#define LOOKUPTABLE1D_FIP32_FUNCTIONS { \
    LOOKUPTABLE1D_FIP32_ID, \
    (void (*)(void*))LookupTable1D_FiP32_Update, \
    (void (*)(void*))LookupTable1D_FiP32_Init, \
    (tLoadImplementationParameter)LookupTable1D_FiP32_Load, \
    (tSaveImplementationParameter)LookupTable1D_FiP32_Save, \
    (void* (*)(const void*, uint16))LookupTable1D_FiP32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void LookupTable1D_FiP32_Update(LOOKUPTABLE1D_FIP32 *pTLookupTable1D_FiP32);
void LookupTable1D_FiP32_Init(LOOKUPTABLE1D_FIP32 *pTLookupTable1D_FiP32);
uint8 LookupTable1D_FiP32_Load(const LOOKUPTABLE1D_FIP32 *pTLookupTable1D_FiP32, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 LookupTable1D_FiP32_Save(LOOKUPTABLE1D_FIP32 *pTLookupTable1D_FiP32, const uint8 data[], uint16 dataLength);
void* LookupTable1D_FiP32_GetAddress(const LOOKUPTABLE1D_FIP32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
