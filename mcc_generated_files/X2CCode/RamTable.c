/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Date:  2024-07-03 08:20                                                                                            */

/* X2C-Version: 6.5.3189                                                                                              */
/* X2C-Edition: Educational                                                                                           */

#include "RamTable.h"

int16 RamTable_int16[1];

static const int16 RamTable_int16_init[1] = {0}; 

void initRamTables()
{
    uint16 i;

    for (i = 0; i < 1; i++)
    {
        RamTable_int16[i] = RamTable_int16_init[i];
    }
}
