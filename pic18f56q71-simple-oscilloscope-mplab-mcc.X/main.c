 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
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
#include "mcc_generated_files/system/system.h"

#include "sine.h"
#include "oscilloscope.h"

//Implements the clipping detector
//Note: LED is inverted polarity (LOW = ON, HIGH = OFF)
void LED_updateState(void)
{
    if (ADSTATbits.ADUTHR)
    {
        //Over upper threshold
        LED0_SetLow();
    }
    else
    {
        //Under threshold
        LED0_SetHigh();
    }
}

//If defined, the system is in demo mode
#define OSCILLOSCOPE_DEMO_MODE

//Threshold for clipping warning
#define ADC_THRESHOLD_LEVEL 0xE66

int main(void)
{
    SYSTEM_Initialize();

#ifdef OSCILLOSCOPE_DEMO_MODE
    
    //Function Generator Demo Mode
    //Sine, Triangle, Sawtooth, and Square
    
    OPA1_SetPositiveChannel(OPA1_posChannel_DAC1);
    
    //Change waveforms when someone hits a button
    CLC2_CLCI_SetInterruptHandler(&Oscilloscope_changeWaveform);
    
    //Configures the timer to update the waveform
    TMR4_PeriodMatchCallbackRegister(&Oscilloscope_updateWaveform);
#else
    OPA1_SetPositiveChannel(OPA1_posChannel_OPA1IN);
    
    //Switch the gain when the user presses a button
    CLC2_CLCI_SetInterruptHandler(&Oscilloscope_incrementGain);
#endif
    
    //Configure Clipping Detector
    ADC_ConversionDoneCallbackRegister(&LED_updateState);
    
    //Set upper threshold (90% of max)
    ADC_UpperThresholdSet(ADC_THRESHOLD_LEVEL);
    
    //Start ADC Conversion on the output of OPAMP when sampling OPA1IN3+
    ADC_ChannelSelect(ADC_CHANNEL_ANA1);
    ADC_ConversionStart();
    
    //Assign UART TX Priority
    DMA1_SetDMAPriority(1);
    
    //Start the DMA
    DMA1_StartTransfer();
    
    //Sine Generator
    DMA2_SetDMAPriority(0);
    
    // Enable the Global High Interrupts 
    INTERRUPT_GlobalInterruptHighEnable(); 

    // Enable the Global Low Interrupts 
    INTERRUPT_GlobalInterruptLowEnable(); 
        
    while(1)
    {
        
    }    
}