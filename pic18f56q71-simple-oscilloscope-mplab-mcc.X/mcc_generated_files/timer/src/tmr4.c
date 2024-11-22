/**
 * TMR4 Generated Driver File
 *
 * @file tmr4.c
 * 
 * @ingroup  tmr4
 * 
 * @brief Driver implementation for the TMR4 module.
 *
 * @version Driver Version 4.0.0
 *
 * @version Package Version 5.0.0
 */

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "../tmr4.h"
#include "../../system/interrupt.h"

static void (*TMR4_PeriodMatchCallback)(void);
static void TMR4_DefaultPeriodMatchCallback(void);

/**
  Section: TMR4 APIs
*/

void TMR4_Initialize(void)
{
    T4CLKCON = (5 << _T4CLKCON_T4CS_POSN);  // T4CS MFINTOSC_500KHz

    T4HLT = (0 << _T4HLT_T4MODE_POSN)   // T4MODE Software control
        | (0 << _T4HLT_T4CKSYNC_POSN)   // T4CKSYNC Not Synchronized
        | (0 << _T4HLT_T4CKPOL_POSN)   // T4CKPOL Rising Edge
        | (0 << _T4HLT_T4PSYNC_POSN);  // T4PSYNC Not Synchronized

    T4RST = (0 << _T4RST_T4RSEL_POSN);  // T4RSEL T4CKIPPS pin

    T4PR = 0x1;    // Period 0.000128s; Frequency 15625Hz; Count 1

    T4TMR = 0x0;

    TMR4_PeriodMatchCallback = TMR4_DefaultPeriodMatchCallback;
    
    PIR10bits.TMR4IF = 0;   
    PIE10bits.TMR4IE = 1;

    T4CON = (5 << _T4CON_T4CKPS_POSN)   // T4CKPS 1:32
        | (1 << _T4CON_TMR4ON_POSN)   // TMR4ON on
        | (0 << _T4CON_T4OUTPS_POSN);  // T4OUTPS 1:1
}

void TMR4_Deinitialize(void)
{
    T4CONbits.TMR4ON = 0;
    
    PIR10bits.TMR4IF = 0;	   
    PIE10bits.TMR4IE = 0;		
    
    T4CON = 0x0;
    T4CLKCON = 0x0;
    T4HLT = 0x0;
    T4RST = 0x0;
    T4PR = 0xFF;
    T4TMR =0x0;
}

void TMR4_Start(void)
{   
    T4CONbits.TMR4ON = 1;
}

void TMR4_Stop(void)
{   
    T4CONbits.TMR4ON = 0;
}

void TMR4_ModeSet(TMR4_HLT_MODE mode)
{  
    T4HLTbits.T4MODE = mode;
}

void TMR4_ExtResetSourceSet(TMR4_HLT_EXT_RESET_SOURCE reset)
{   
    T4RSTbits.T4RSEL = reset;
}

uint8_t TMR4_CounterGet(void)
{
    return T4TMR;
}

void TMR4_CounterSet(uint8_t count)
{  
    T4TMR = count;
}

void TMR4_PeriodSet(uint8_t periodVal)
{
    T4PR = periodVal;
}

uint8_t TMR4_PeriodGet(void)
{
    return T4PR;
}

uint8_t TMR4_MaxCountGet(void)
{
    return TMR4_MAX_COUNT;
}

void TMR4_TMRInterruptEnable(void)
{
    PIE10bits.TMR4IE = 1;
}

void TMR4_TMRInterruptDisable(void)
{
    PIE10bits.TMR4IE = 0;
}

void __interrupt(irq(TMR4),base(8)) TMR4_ISR(void)
{
    // The ticker is set to 1 -> The callback function gets called every time this ISR executes.
    if(NULL != TMR4_PeriodMatchCallback)
    {
        TMR4_PeriodMatchCallback();
    }
   PIR10bits.TMR4IF = 0;
}

void TMR4_PeriodMatchCallbackRegister(void (* callbackHandler)(void))
{
   TMR4_PeriodMatchCallback = callbackHandler;
}

static void TMR4_DefaultPeriodMatchCallback(void)
{
    // Default callback function
}


