/**
 * NCO1 Generated Driver File
 * 
 * @file nco1.c
 * 
 * @ingroup  nco1
 * 
 * @brief This is the generated driver implementation file for the NCO1 driver.
 *
 * @version NCO1 Driver Version 2.0.1
*/
/*
© [2022] Microchip Technology Inc. and its subsidiaries.

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


#include <xc.h>
#include "../nco1.h"
#include "../../system/interrupt.h"

void NCO1_Initialize(void){

    //NPWS 1_clk; NCKS LFINTOSC; 
    NCO1CLK = 0x2;
    //NCOACC 0x0; 
    NCO1ACCU = 0x0;
    //NCOACC 0x0; 
    NCO1ACCH = 0x0;
    //NCOACC 0x0; 
    NCO1ACCL = 0x0;
    //NCOINC 0; 
    NCO1INCU = 0x0;
    //NCOINC 33; 
    NCO1INCH = 0x21;
    //NCOINC 8; 
    NCO1INCL = 0x8;
    //NEN enabled; NPOL active_hi; NPFM PFM_mode; 
    NCO1CON = 0x81;
}
 
void __interrupt(irq(NCO1),base(8)) NCO1_ISR()
{
   // Clear the NCO interrupt flag
    PIR6bits.NCO1IF = 0;
}

bool NCO1_GetOutputStatus(void) 
{
	return (NCO1CONbits.OUT);
}
/**
 End of File
*/