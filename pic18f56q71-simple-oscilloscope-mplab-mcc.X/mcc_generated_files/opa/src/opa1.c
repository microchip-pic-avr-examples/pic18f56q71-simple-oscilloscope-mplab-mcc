/**
 * OPA1 Generated Driver File
 * 
 * @file opa1.c
 * 
 * @ingroup  opa1
 * 
 * @brief This is the generated driver implementation file for the OPA1 driver.
 *
 * @version OPA1 Driver Version 1.0.0
*/
/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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
#include "../opa1.h"

/**
  Section: OPA1 Module APIs
*/

void OPA1_Initialize(void)
{
    //GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Disabled; NSS OPA1IN0-; 
    OPA1CON1 = 0x0;

    //NCH No Connection; PCH OPA1IN+; 
    OPA1CON2 = 0x2;

    //FMS No Connection; INTOE Disabled; PSS OPA1IN3+; 
    OPA1CON3 = 0x3;

    //PTRES No reset; OFCST Calibration complete; OFCSEL Factory calibrated value in OPAxOFFSET; 
    OPA1CON4 = 0x0;

    //OREN Disabled; HWCH Basic OPA configuration with user defined feedback; ORPOL Non Inverted; HWCL Basic OPA configuration with user defined feedback; 
    OPA1HWC = 0x0;

    //ORS TMR4_OUT; 
    OPA1ORS = 0x7;

    //EN Enabled; CPON Enabled; UG OPA Output; 
    OPA1CON0 = 0xA8;
}

inline void OPA1_EnableChargePump(void)
{
    OPA1CON0bits.CPON = 1;
}
 
inline void OPA1_DisableChargePump(void)
{
    OPA1CON0bits.CPON = 0;
}

inline void OPA1_EnableSoftwareUnityGain(void)
{
    OPA1CON0bits.UG = 1;
}

inline void OPA1_DisableSoftwareUnityGain(void)
{
    OPA1CON0bits.UG = 0;
}

inline void OPA1_SetPositiveChannel(OPA1_posChannel_select posChannel)
{
    OPA1CON2bits.PCH = posChannel;
}

inline void OPA1_SetPositiveSource(OPA1_posSource_select posSource)
{
    OPA1CON3bits.PSS = posSource;
}

inline void OPA1_SetNegativeChannel(OPA1_negChannel_select negChannel)
{
    OPA1CON2bits.NCH = negChannel;
}

inline void OPA1_SetNegativeSource(OPA1_negSource_select negSource)
{
    OPA1CON1bits.NSS = negSource;
}

void OPA1_SetResistorLadder(OPA1_resistor_select resistorSelection)
{
    OPA1CON1bits.RESON = 1;
    OPA1CON1bits.GSEL = resistorSelection;
}

inline void OPA1_EnableHardwareOverride(void)
{
   OPA1HWCbits.OREN = 1;
}

void OPA1_SetHardwareOverrideSource(uint8_t overrideSource, uint8_t polarity)
{
    OPA1ORS = overrideSource;
    OPA1HWCbits.ORPOL = polarity;
}

inline void OPA1_DisableHardwareOverride(void)
{
    OPA1HWCbits.OREN = 0;
}

inline void OPA1_ManualInputOffsetCalibration(uint8_t offset)
{
    OPA1OFFSET = offset;
}

void OPA1_StartAutomaticOffsetCalibration(void)
{
	OPA1CON4bits.OFCSEL = 2;
    OPA1CON4bits.OFCST = 1;
}

inline bool OPA1_isAutomaticOffsetCalibrationDone(void)
{
    return (OPA1CON4bits.OFCST);
}

inline void OPA1_StartPeakTroughReset(void)
{
    OPA1CON4bits.PTRES = 1;
}

inline void OPA1_StopPeakTroughReset(void)
{
    OPA1CON4bits.PTRES = 0;
}