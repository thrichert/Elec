#include "robin.h"
#include <xc.h>

#define NSLEEP_CONFIG   TRISEbits.TRISE1
#define PH_CONFIG       TRISEbits.TRISE2
#define EN_CONFIG       TRISEbits.TRISE3

#define NSLEEP          LATEbits.LATE1
#define PH              LATEbits.LATE2
#define EN              LATEbits.LATE3

void	ConfigureHBridge(void)
{
    NSLEEP_CONFIG = 0;
    PH_CONFIG = 0;
    EN_CONFIG = 0;
}

void	OpenEV(void)
{
        int count;
        // state "REVERSE"

        NSLEEP = 1;
        count = 0;
        while (count++ < 5000);
        PH = 1;
        EN = 1;
        count = 0;
        while(count++ < 10000);
//	Delay_16ms();
       brakeEV();
       count = 0;

        NSLEEP = 0;
 //           brakeEV();
}

void	brakeEV(void)
{
        EN = 0;
}

void	CloseEV(void)
{
   int count;
   // state "FORWARD"

   NSLEEP = 1;
   count = 0;
   while (count++ < 5000);
   PH = 0;
   EN = 1;
   count = 0;
   while(count++ < 10000);
// Delay_16ms();
   brakeEV();
   count = 0;

   NSLEEP = 0;
 //           brakeEV();
}

int     main(void)
{
   int count;

   ConfigureHBridge();
   count = 0;
   NSLEEP = 1;
   while (1)
   {
        OpenEV();
        while (count++ < 10000);
        count = 0;
       CloseEV();
        while (count++ < 10000);
        count = 0;
   }
}
