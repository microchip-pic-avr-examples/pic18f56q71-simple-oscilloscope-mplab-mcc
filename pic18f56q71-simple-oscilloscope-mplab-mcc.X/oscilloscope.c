#include "oscilloscope.h"
#include "mcc_generated_files/system/system.h"

#include <xc.h>

static volatile OSCILLOSCOPE_GAIN currentGain = UNITY_GAIN;

//Increments the gain of the OPAMP (1 -> 2 -> 4 -> 8 -> 16 -> 1...)
void Oscilloscope_incrementGain(void)
{
    if (currentGain == GAIN_16)
    {
        currentGain = UNITY_GAIN;
    }
    else
    {
        currentGain++;
    }
    Oscilloscope_setGain(currentGain);
}

//Sets the configuration of OPAMP
void Oscilloscope_setGain(OSCILLOSCOPE_GAIN gain)
{
    switch (gain)
    {
        case UNITY_GAIN:
        {
            //Unity gain
            
            //Enable Unity Gain
            OPA1CON0bits.UG = 1;
            
            //Disable Resistor Ladder
            OPA1CON1 = 0x00;
            
            //NCH = No Connection
            OPA1CON2bits.NCH = 0b000;
            
            //Disable Feedback
            OPA1CON3bits.FMS = 0b00;
            break;
        }
        case GAIN_2:
        {
            //2x
            
            //Configure Resistor Ladder
            OPA1CON1 = 0b0111111;
            
            //NCH = Resistor Ladder (GSEL)
            OPA1CON2bits.NCH = 0b001;
            
            //Enable Feedback
            OPA1CON3bits.FMS = 0b10;
            
            //Disable Unity Gain
            OPA1CON0bits.UG = 0;
            break;
        }
        case GAIN_4:
        {
            //4x
            
            //Configure Resistor Ladder
            OPA1CON1 = 0b1011111;
            
            //NCH = Resistor Ladder (GSEL)
            OPA1CON2bits.NCH = 0b001;
            
            //Enable Feedback
            OPA1CON3bits.FMS = 0b10;
            
            //Disable Unity Gain
            OPA1CON0bits.UG = 0;
            break;
        }
        case GAIN_8:
        {
            //8x
            
            //Configure Resistor Ladder
            OPA1CON1 = 0b1101111;
            
            //NCH = Resistor Ladder (GSEL)
            OPA1CON2bits.NCH = 0b001;
            
            //Enable Feedback
            OPA1CON3bits.FMS = 0b10;
            
            //Disable Unity Gain
            OPA1CON0bits.UG = 0;

            break;
        }
        case GAIN_16:
        {
            //16x
            
            //Configure Resistor Ladder
            OPA1CON1 = 0b1111111;
            
            //NCH = Resistor Ladder (GSEL)
            OPA1CON2bits.NCH = 0b001;
            
            //Enable Feedback
            OPA1CON3bits.FMS = 0b10;
            
            //Disable Unity Gain
            OPA1CON0bits.UG = 0;
            break;
        }
    }
}
