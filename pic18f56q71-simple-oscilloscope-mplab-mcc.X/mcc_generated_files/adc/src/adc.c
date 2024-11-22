/**
 * ADC Generated Driver File
 * 
 * @file adc.c
 * 
 * @ingroup  adc
 * 
 * @brief This file contains the API implementations for the ADC driver.
 *
 * @version ADC Driver Version 2.0.0
 * 
 * @version ADC Package Version 2.0.0
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

#include <xc.h>
#include "../adc.h"
#include "../adc_types.h"


static bool adc_busy_status;
static void (*ADC_ConversionDoneCallback)(void);
static void (*ADC_Context1ThresholdCallback)(void);


void ADC_Initialize(void)
{
    ADCON0bits.ADON = ADC_BIT_CLEAR;    
    ADACT = (4 << _ADACT_ADACT_POSITION);	/* ADACT TMR2(4) */
    ADCLK = (31 << _ADCLK_ADCS_POSITION);	/* ADCS FOSC/64(31) */
    ADCGA = (0 << _ADCGA_CGA0_POSITION)	/* CGA0 disabled(0) */
			|(0 << _ADCGA_CGA1_POSITION)	/* CGA1 disabled(0) */
			|(0 << _ADCGA_CGA2_POSITION)	/* CGA2 disabled(0) */
			|(0 << _ADCGA_CGA3_POSITION)	/* CGA3 disabled(0) */
			|(0 << _ADCGA_CGA4_POSITION)	/* CGA4 disabled(0) */
			|(0 << _ADCGA_CGA5_POSITION)	/* CGA5 disabled(0) */
			|(0 << _ADCGA_CGA6_POSITION)	/* CGA6 disabled(0) */
			|(0 << _ADCGA_CGA7_POSITION);	/* CGA7 disabled(0) */
    ADCGB = (0 << _ADCGB_CGB0_POSITION)	/* CGB0 disabled(0) */
			|(0 << _ADCGB_CGB1_POSITION)	/* CGB1 disabled(0) */
			|(0 << _ADCGB_CGB2_POSITION)	/* CGB2 disabled(0) */
			|(0 << _ADCGB_CGB3_POSITION)	/* CGB3 disabled(0) */
			|(0 << _ADCGB_CGB4_POSITION)	/* CGB4 disabled(0) */
			|(0 << _ADCGB_CGB5_POSITION)	/* CGB5 disabled(0) */
			|(0 << _ADCGB_CGB6_POSITION)	/* CGB6 disabled(0) */
			|(0 << _ADCGB_CGB7_POSITION);	/* CGB7 disabled(0) */
    ADCGC = (0 << _ADCGC_CGC0_POSITION)	/* CGC0 disabled(0) */
			|(0 << _ADCGC_CGC1_POSITION)	/* CGC1 disabled(0) */
			|(0 << _ADCGC_CGC2_POSITION)	/* CGC2 disabled(0) */
			|(0 << _ADCGC_CGC3_POSITION)	/* CGC3 disabled(0) */
			|(0 << _ADCGC_CGC4_POSITION)	/* CGC4 disabled(0) */
			|(0 << _ADCGC_CGC5_POSITION)	/* CGC5 disabled(0) */
			|(0 << _ADCGC_CGC6_POSITION)	/* CGC6 disabled(0) */
			|(0 << _ADCGC_CGC7_POSITION);	/* CGC7 disabled(0) */
    ADCGD = (0 << _ADCGD_CGD0_POSITION)	/* CGD0 disabled(0) */
			|(0 << _ADCGD_CGD1_POSITION)	/* CGD1 disabled(0) */
			|(0 << _ADCGD_CGD2_POSITION)	/* CGD2 disabled(0) */
			|(0 << _ADCGD_CGD3_POSITION)	/* CGD3 disabled(0) */
			|(0 << _ADCGD_CGD4_POSITION)	/* CGD4 disabled(0) */
			|(0 << _ADCGD_CGD5_POSITION)	/* CGD5 disabled(0) */
			|(0 << _ADCGD_CGD6_POSITION)	/* CGD6 disabled(0) */
			|(0 << _ADCGD_CGD7_POSITION);	/* CGD7 disabled(0) */
    ADCGE = (0 << _ADCGE_CGE0_POSITION)	/* CGE0 disabled(0) */
			|(0 << _ADCGE_CGE1_POSITION)	/* CGE1 disabled(0) */
			|(0 << _ADCGE_CGE2_POSITION);	/* CGE2 disabled(0) */




    /****************************************
    *         Configure Context-1           *
    ****************************************/
    ADCTX = 0x0;
    ADLTHL = (0 << _ADLTHL_ADLTH_POSITION);	/* ADLTH 0x0(0) */
    ADLTHH = (0 << _ADLTHH_ADLTH_POSITION);	/* ADLTH 0x0(0) */
    ADUTHL = (3 << _ADUTHL_ADUTH_POSITION);	/* ADUTH 0x3(3) */
    ADUTHH = (0 << _ADUTHH_ADUTH_POSITION);	/* ADUTH 0x0(0) */
    ADSTPTL = (0 << _ADSTPTL_ADSTPT_POSITION);	/* ADSTPT 0x0(0) */
    ADSTPTH = (0 << _ADSTPTH_ADSTPT_POSITION);	/* ADSTPT 0x0(0) */
    ADACCL = (0 << _ADACCL_ADACC_POSITION);	/* ADACC 0x0(0) */
    ADACCH = (0 << _ADACCH_ADACC_POSITION);	/* ADACC 0x0(0) */
    ADACCU = (0 << _ADACCU_ADACC_POSITION);	/* ADACC 0x0(0) */
    ADCNT = (0 << _ADCNT_ADCNT_POSITION);	/* ADCNT 0x0(0) */
    ADRPT = (8 << _ADRPT_ADRPT_POSITION);	/* ADRPT 0x8(8) */
    ADRESL = (0 << _ADRESL_ADRES_POSITION);	/* ADRES 0x0(0) */
    ADRESH = (0 << _ADRESH_ADRES_POSITION);	/* ADRES 0x0(0) */
    ADPCH = (0 << _ADPCH_PCH_POSITION);	/* PCH ANA0(0) */
    ADNCH = (59 << _ADNCH_ADNCH_POSITION);	/* ADNCH VSS(59) */
    ADACQL = (0 << _ADACQL_ADACQ_POSITION);	/* ADACQ 0x0(0) */
    ADACQH = (0 << _ADACQH_ADACQ_POSITION);	/* ADACQ 0x0(0) */
    ADCAP = (0 << _ADCAP_ADCAP_POSITION);	/* ADCAP Additional uC disabled(0) */
    ADPREL = (0 << _ADPREL_ADPRE_POSITION);	/* ADPRE 0x0(0) */
    ADPREH = (0 << _ADPREH_ADPRE_POSITION);	/* ADPRE 0x0(0) */
    ADCON0bits.ADCONT = ADC_BIT_CLEAR;
    ADCON1 = (0 << _ADCON1_ADDSEN_POSITION)	/* ADDSEN disabled(0) */
			|(0 << _ADCON1_PCSC_POSITION)	/* PCSC sampling capacitor and external I/O pin(0) */
			|(0 << _ADCON1_ADGPOL_POSITION)	/* ADGPOL digital_low(0) */
			|(0 << _ADCON1_ADIPEN_POSITION)	/* ADIPEN disabled(0) */
			|(0 << _ADCON1_ADPPOL_POSITION);	/* ADPPOL Vss(0) */
    ADCON2 = (0 << _ADCON2_ADMD_POSITION)	/* ADMD Basic_mode(0) */
			|(1 << _ADCON2_ADACLR_POSITION)	/* ADACLR enabled(1) */
			|(3 << _ADCON2_ADCRS_POSITION)	/* ADCRS 0x3(3) */
			|(0 << _ADCON2_ADPSIS_POSITION);	/* ADPSIS RES(0) */
    ADCON3 = (6 << _ADCON3_ADTMD_POSITION)	/* ADTMD ADERR > ADUTH(6) */
			|(0 << _ADCON3_ADSOI_POSITION)	/* ADSOI ADGO not cleared(0) */
			|(1 << _ADCON3_ADCALC_POSITION);	/* ADCALC Actual result vs setpoint(1) */
    ADSTAT = (0 << _ADSTAT_ADMATH_POSITION);	/* ADMATH registers not updated(0) */
    ADREF = (0 << _ADREF_ADNREF_POSITION)	/* ADNREF VSS(0) */
			|(0 << _ADREF_ADPREF_POSITION);	/* ADPREF VDD(0) */
    ADCSEL1 = (0 << _ADCSEL1_SSI_POSITION)	/* SSI scan sequence continues(0) */
			|(0 << _ADCSEL1_CHEN_POSITION);	/* CHEN channel context is not included(0) */

    adc_busy_status = false;
    ADC_ConversionDoneCallback = NULL;
    ADC_Context1ThresholdCallback = NULL;

    PIR1bits.ADIF = ADC_BIT_CLEAR;
    PIE1bits.ADIE = ADC_BIT_SET;

    PIR1bits.ADCH1IF = ADC_BIT_CLEAR;
    PIE1bits.ADCH1IE = ADC_BIT_CLEAR;

    PIR1bits.ADCH2IF = ADC_BIT_CLEAR;
    PIE1bits.ADCH2IE = ADC_BIT_CLEAR;

    PIR1bits.ADCH3IF = ADC_BIT_CLEAR;
    PIE1bits.ADCH3IE = ADC_BIT_CLEAR;

    PIR1bits.ADCH4IF = ADC_BIT_CLEAR;
    PIE1bits.ADCH4IE = ADC_BIT_CLEAR;

    ADCON0 = 0x90;
}

void ADC_Deinitialize(void)
{
    ADCON0 = 0x2;
    PIR1bits.ADIF = ADC_BIT_CLEAR;
    PIE1bits.ADIE = ADC_BIT_CLEAR;

    PIR1bits.ADCH1IF = ADC_BIT_CLEAR;
    PIE1bits.ADCH1IE = ADC_BIT_CLEAR;

    PIR1bits.ADCH2IF = ADC_BIT_CLEAR;
    PIE1bits.ADCH2IE = ADC_BIT_CLEAR;

    PIR1bits.ADCH3IF = ADC_BIT_CLEAR;
    PIE1bits.ADCH3IE = ADC_BIT_CLEAR;

    PIR1bits.ADCH4IF = ADC_BIT_CLEAR;
    PIE1bits.ADCH4IE = ADC_BIT_CLEAR;

    ADACT = 0x0;


    ADCLK = 0x0;

    ADCGA = 0x0;

    ADCGB = 0x0;

    ADCGC = 0x0;

    ADCGD = 0x0;

    ADCGE = 0x0;



    /****************************************
    *         Configure Context-1           *
    ****************************************/
    ADCTX = 0x0;

    ADLTHL = 0x0;

    ADLTHH = 0x0;

    ADUTHL = 0x0;

    ADUTHH = 0x0;

    ADSTPTL = 0x0;

    ADSTPTH = 0x0;

    ADACCL = 0x0;

    ADACCH = 0x0;

    ADACCU = 0x0;

    ADCNT = 0x0;

    ADRPT = 0x0;

    ADRESL = 0x0;

    ADRESH = 0x0;

    ADPCH = 0x0;

    ADNCH = 0x0;

    ADACQL = 0x0;

    ADACQH = 0x0;

    ADCAP = 0x0;

    ADPREL = 0x0;

    ADPREH = 0x0;
    
    ADCON0bits.ADCONT = ADC_BIT_CLEAR;

    ADCON1 = 0x0;

    ADCON2 = 0x0;

    ADCON3 = 0x0;

    ADSTAT = 0x0;

    ADREF = 0x0;
    
    ADCSEL1 = 0x0;
}

void ADC_Enable(void)
{
    ADCON0bits.ADON = ADC_BIT_SET;
}

void ADC_Disable(void)
{
    ADCON0bits.ADON = ADC_BIT_CLEAR;
}

void ADC_ContextSelect(adc_context_t context)
{
    ADCTX = context;
}

adc_context_t ADC_CurrentContextGet(void)
{
    return (adc_context_t)ADCTX;
}

void ADC_ChannelSelect(adc_channel_t channel)
{
    ADPCH = channel;
}

void ADC_ConversionStart(void)
{
    ADCON0bits.ADGO = ADC_BIT_SET;
}

bool ADC_IsConversionDone(void)
{
    return ((bool)(!ADCON0bits.ADGO));
}

void ADC_ConversionStop(void)
{
    ADCON0bits.ADGO = ADC_BIT_CLEAR;
}

adc_result_t ADC_ConversionResultGet(void)
{
    return ((adc_result_t) ((ADRESH << 8) | ADRESL));
}

void ADC_ComputationModeSet(adc_computation_mode_t computationMode)
{
    ADCON2bits.ADMD |= computationMode;
}

void ADC_ThresholdModeSet(adc_threshold_mode_t thresholdMode)
{
    ADCON3bits.ADTMD |= thresholdMode;
}

void ADC_SampleRepeatCountSet(adc_repeat_count_t repeatCount)
{
    ADRPT = repeatCount;
}

void ADC_UpperThresholdSet(adc_threshold_t upperThreshold)
{
    ADUTHH = (uint8_t) ((uint16_t)upperThreshold >> 8U);
    ADUTHL = (uint8_t) upperThreshold;
}

void ADC_LowerThresholdSet(adc_threshold_t lowerThreshold)
{
    ADLTHH = (uint8_t) ((uint16_t)lowerThreshold >> 8U);
    ADLTHL = (uint8_t) lowerThreshold;
}

adc_accumulate_t ADC_AccumulatedResultGet(void)
{
    return (adc_accumulate_t)(((uint32_t)ADACCU << 16) + ((uint32_t)ADACCH << 8) + ADACCL);
}

adc_result_t ADC_ChannelSelectAndConvert(adc_channel_t channel)
{
    ADPCH = channel;
    ADCON0bits.ADCONT = ADC_BIT_CLEAR;

    ADCON0bits.ADGO = ADC_BIT_SET;

    while (true == ADCON0bits.ADGO)
    {
    }
    
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}

void ADC_StopOnInterruptEnable(void)
{
    ADCON3bits.ADSOI = ADC_BIT_SET;
}

void ADC_StopOnInterruptDisable(void)
{
    ADCON3bits.ADSOI = ADC_BIT_CLEAR;
}

void ADC_SampleCapacitorDischarge(void)
{
    ADPCH = ADC_CHANNEL_VSS;
}

void ADC_AcquisitionTimeSet(uint16_t acquisitionValue)
{
    ADACQH = (uint8_t)(acquisitionValue >> 8);
    ADACQL = (uint8_t)acquisitionValue;
}

void ADC_PrechargeTimeSet(uint16_t prechargeTime)
{
    ADPREH = (uint8_t)(prechargeTime >> 8);
    ADPREL = (uint8_t)prechargeTime;
}

adc_repeat_count_t ADC_CurrentConversionCountGet(void)
{
    return (adc_repeat_count_t)ADCNT;
}

void ADC_AccumulatorClear(void)
{
    ADCON2bits.ADACLR = ADC_BIT_SET;
}

bool ADC_IsAccumulatorClearComplete(void)
{
    return ((bool)(!ADCON2bits.ADACLR));
}

bool ADC_HasAccumulatorOverflowed(void)
{
    return ADSTATbits.ADAOV;
}

adc_result_t ADC_FilterValueGet(void)
{
    return ((adc_result_t) ((ADFLTRH << 8) | ADFLTRL));
}

adc_result_t ADC_PreviousResultGet(void)
{
    return ((adc_result_t) ((ADPREVH << 8) | ADPREVL));
}

void ADC_SetPointDefine(adc_threshold_t setPoint)
{
    ADSTPTH = (uint8_t)((uint16_t)setPoint >> 8U);
    ADSTPTL = (uint8_t)setPoint;
}

adc_result_t ADC_ErrorCalculationGet(void)
{
    return ((adc_result_t) ((ADERRH << 8U) | ADERRL));
}

void ADC_DoubleSamplingEnable(void)
{
    ADCON1bits.ADDSEN = ADC_BIT_SET;
}

void ADC_DoubleSamplingDisable(void)
{
    ADCON1bits.ADDSEN = ADC_BIT_CLEAR;
}

void ADC_ContinuousConversionEnable(void)
{
    ADCON0bits.ADCONT = ADC_BIT_SET;
}

void ADC_ContinuousConversionDisable(void)
{
    ADCON0bits.ADCONT = ADC_BIT_CLEAR;
}

bool ADC_IsErrorGreaterThanUpperThreshold(void)
{
    return ADSTATbits.ADUTHR;
}

bool ADC_IsErrorLesserThanLowerThreshold(void)
{
    return ADSTATbits.ADLTHR;
}

adc_conversion_stage_t ADC_ConversionStageStatusGet(void)
{
    return ADSTATbits.ADSTAT;
}

void ADC_ErrorCalculationModeSet(adc_calculation_mode_t errorCalculationMode)
{
    ADCON3bits.ADCALC = errorCalculationMode;
}

void ADC_CalculationRightShiftSet(uint8_t rightShiftValue)
{
    ADCON2bits.ADCRS = rightShiftValue;
}

void ADC_ThresholdInterruptFlagClear(void)
{
    adc_context_t currentContext = ADCTX;
    switch(currentContext)
    {
    case context_1:
        PIR1bits.ADCH1IF = ADC_BIT_CLEAR;
        break;
    default:
        PIR1bits.ADCH1IF = ADC_BIT_CLEAR;
        break;
    }
}

bool ADC_IsThresholdInterruptFlagSet(void)
{
    adc_context_t currentContext = ADCTX;
    bool flagStatus = false;
    switch(currentContext)
    {
    case context_1:
        flagStatus = (bool)PIR1bits.ADCH1IF;
        break;
    default:
        flagStatus = (bool)PIR1bits.ADCH1IF;
        break;
    }
    return flagStatus;
}

void ADC_AutoTriggerSourceSet(adc_trigger_source_t triggerSource)
{
    ADACT = triggerSource;
}

uint8_t ADC_ResolutionGet(void)
{
    return ADC_RESOLUTION;
}


bool ADC_IsBusy(void)
{
    return adc_busy_status;
}

void ADC_BusyStatusSet(bool status)
{
    adc_busy_status = status;
}

void ADC_ConversionDoneInterruptFlagClear(void)
{
    PIR1bits.ADIF = ADC_BIT_CLEAR;
}

void ADC_Context1ThresholdInterruptFlagClear(void)
{
    PIR1bits.ADCH1IF = ADC_BIT_CLEAR;   
}




bool ADC_IsConversionDoneInterruptFlagSet(void)
{
    return PIR1bits.ADIF; 
}

bool ADC_IsContext1ThresholdInterruptFlagSet(void)
{
    return PIR1bits.ADCH1IF;
}




void ADC_ConversionDoneCallbackRegister(void (*callback)(void))
{
    ADC_ConversionDoneCallback = callback;
}

void ADC_ThresholdCallbackRegister(void (*callback)(void))
{
    adc_context_t currentContext = ADCTX;
    switch(currentContext)
    {
    case context_1:
        ADC_Context1ThresholdCallback = callback;
        break;
    default:
        ADC_Context1ThresholdCallback = callback;
        break;
    }
} 

void ADC_Context1ThresholdCallbackRegister(void (*callback)(void))
{
    ADC_Context1ThresholdCallback = callback;
} 




void ADC_ChannelScanEnable(adc_context_t context)
{
    switch (context)
    {
    case context_1:
        ADCSEL1bits.CHEN = ADC_BIT_SET;
        break;
    default:
        ADCSEL1bits.CHEN = ADC_BIT_SET;
        break;
    }
}

void ADC_ChannelScanDisable(adc_context_t context)
{
    switch (context)
    {
    case context_1:
        ADCSEL1bits.CHEN = ADC_BIT_CLEAR;
        break;
    default:
        ADCSEL1bits.CHEN = ADC_BIT_CLEAR;
        break;
    }
}

void ADC_ChannelSequencerEnable(void)
{
    ADCON0bits.CSEN = ADC_BIT_SET;
}

void ADC_ChannelSequencerDisable(void)
{
    ADCON0bits.CSEN  = ADC_BIT_CLEAR;
}


void ADC_ConversionDoneInterruptEnable(void)
{
    PIE1bits.ADIE = ADC_BIT_SET;
}

void ADC_ConversionDoneInterruptDisable(void)
{
    PIE1bits.ADIE = ADC_BIT_CLEAR;
}

void ADC_ThresholdInterruptEnable(void)
{
    adc_context_t currentContext = ADCTX;
    switch(currentContext)
    {
    case context_1:
        PIE1bits.ADCH1IE = ADC_BIT_SET;
        break;
    default:
        PIE1bits.ADCH1IE = ADC_BIT_SET;
        break;
    }
}

void ADC_ThresholdInterruptDisable(void)
{
    adc_context_t currentContext = ADCTX;
    switch(currentContext)
    {
    case context_1:
        PIE1bits.ADCH1IE = ADC_BIT_CLEAR;
        break;
    default:
        PIE1bits.ADCH1IE = ADC_BIT_CLEAR;
        break;
    }
}

void ADC_Context1ThresholdInterruptEnable(void)
{
    PIE1bits.ADCH1IE = ADC_BIT_SET;    
}

void ADC_Context1ThresholdInterruptDisable(void)
{
    PIE1bits.ADCH1IE = ADC_BIT_CLEAR;    
}




void __interrupt(irq(AD),base(8)) ADC_ISR(void)
{
    PIR1bits.ADIF = ADC_BIT_CLEAR;

    if (NULL != ADC_ConversionDoneCallback)
    {
        ADC_ConversionDoneCallback();
    }
    else
    {
        // Do nothing
    }
}

void __interrupt(irq(ADCH1),base(8)) ADC_Context1ThresholdISR(void)
{
    PIR1bits.ADCH1IF = ADC_BIT_CLEAR;

    if (NULL != ADC_Context1ThresholdCallback)
    {
        ADC_Context1ThresholdCallback();
    }
    else
    {
        // Do nothing
    }
}



