#include "oscilloscope.h"
#include "mcc_generated_files/system/system.h"

#include <xc.h>
#include <stdint.h>

static volatile OSCILLOSCOPE_GAIN currentGain = UNITY_GAIN;
static volatile OSCILLOSCOPE_WAVEFORM currentWave = SINE;
static volatile uint16_t dacValue = 0x0000;
static volatile uint8_t squareDelay = 0x00;

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

//Changes the waveform of the oscilloscope
void Oscilloscope_changeWaveform(void)
{
    if (currentWave == SQUARE)
    {
        currentWave = SINE;
    }
    else
    {
        currentWave++;
    }
    
    Oscilloscope_setWaveform(currentWave);
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

//Sets the test waveform of the oscilloscopes
void Oscilloscope_setWaveform(OSCILLOSCOPE_WAVEFORM wave)
{    
    if (wave == SINE)
    {
        DMA2_StartTransferWithTrigger();
    }
    else
    {
        DMA2_StopTransfer();
        dacValue = 0;
    }
    
    //Update state
    currentWave = wave;
}

//Updates the waveforms created in software
void Oscilloscope_updateWaveform(void)
{
    //Sine is DMA based
    if (currentWave == SINE)
    {
        return;
    }
    
    switch (currentWave)
    {
        case SINE:
            //Created by DMA
            break;
        case TRIANGLE_RISE:
        {
            if (dacValue == 1023)
            {
                currentWave = TRIANGLE_FALL;
                dacValue--;
            }
            else
            {
                dacValue++;
            }
            break;
        }
        case TRIANGLE_FALL:
        {
            if (dacValue == 0)
            {
                currentWave = TRIANGLE_RISE;
                dacValue++;
            }
            else
            {
                dacValue--;
            }

            break;
        }
        case SAWTOOTH:
            dacValue++;
            break;
        case SQUARE:
            if (squareDelay == 20)
            {
                squareDelay = 0;
                if (dacValue == 0)
                {
                    dacValue = 1023;
                }
                else
                {
                    dacValue = 0;
                }
            }
            else
            {
                squareDelay++;
            }
            break;
        default:
            dacValue = 0;
    }
    
    if (dacValue == 1024)
    {
        dacValue = 0;
    }
    
    //Update DAC
    DAC1_SetOutput(dacValue);
}