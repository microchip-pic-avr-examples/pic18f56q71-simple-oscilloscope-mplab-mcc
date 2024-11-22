/**
 * ADC Type Definitions Header File
 *
 * @file adc_types.h
 *
 * @defgroup adc ADC
 *
 * @brief This file provides type definitions for the ADC module.
 *
 * @version ADC Driver Version 2.0.0
 * 
 * @version ADC Package Version 2.0.0
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

#ifndef ADC_TYPES_H
#define	ADC_TYPES_H


/**
 @ingroup adc
 @brief ADC resolution value.
*/
#define ADC_RESOLUTION 12

/**
 @ingroup adc
 @brief ADC bit set value.
*/
#define ADC_BIT_SET 1

/**
 @ingroup adc
 @brief ADC bit clear value.
*/
#define ADC_BIT_CLEAR 0


/**
 @ingroup adc
 @typedef adc_result_t
 @brief ADC conversion result type.
*/
typedef int16_t adc_result_t;

/**
 @ingroup adc
 @typedef adc_accumulate_t
 @brief ADC conversion accumulator type.
*/
typedef int32_t adc_accumulate_t;

/**
 @ingroup adc
 @typedef adc_threshold_t
 @brief ADC conversion threshold type.
*/
typedef int16_t adc_threshold_t;

/**
 @ingroup adc
 @typedef adc_repeat_count_t
 @brief ADC conversion repeat count type.
*/
typedef uint8_t adc_repeat_count_t;


/**
 * @ingroup adc
 * @enum adc_channel_t
 * @brief Enumeration in Single-Ended mode that describes the available ADC channels.
*/
typedef enum
{
    ADC_CHANNEL_ADCG1 =  0x36, /**< ADCG1*/
    ADC_CHANNEL_OPA1_POSITIVE_INPUT_SOURCE =  0x37, /**< OPA1 Positive Input Source*/
    ADC_CHANNEL_OPA2_POSITIVE_INPUT_SOURCE =  0x38, /**< OPA2 Positive Input Source*/
    ADC_CHANNEL_DAC2 =  0x39, /**< DAC2*/
    ADC_CHANNEL_DAC3 =  0x3a, /**< DAC3*/
    ADC_CHANNEL_VSS =  0x3b, /**< VSS*/
    ADC_CHANNEL_TEMP =  0x3c, /**< Temp*/
    ADC_CHANNEL_DAC1 =  0x3d, /**< DAC1*/
    ADC_CHANNEL_FVR_BUFFER1 =  0x3e, /**< FVR_Buffer1*/
    ADC_CHANNEL_FVR_BUFFER2 =  0x3f, /**< FVR_Buffer2*/
    ADC_CHANNEL_OPA1IN0_PLUS =  0x82, /**< OPA1IN0+*/
    ADC_CHANNEL_OPA1IN1_PLUS =  0x84, /**< OPA1IN1+*/
    ADC_CHANNEL_OPA1IN2_PLUS =  0x85, /**< OPA1IN2+*/
    ADC_CHANNEL_OPA1IN3_PLUS =  0x89, /**< OPA1IN3+*/
    ADC_CHANNEL_OPA2IN0_PLUS =  0x4c, /**< OPA2IN0+*/
    ADC_CHANNEL_OPA2IN1_PLUS =  0x41, /**< OPA2IN1+*/
    ADC_CHANNEL_OPA2IN2_PLUS =  0x4b, /**< OPA2IN2+*/
    ADC_CHANNEL_OPA2IN3_PLUS =  0x4a, /**< OPA2IN3+*/
    ADC_CHANNEL_ANA1 =  0x1, /**< IO_RA1: RA1*/
    ADC_CHANNEL_ANB1 =  0x9, /**< RB1_IN3: RB1*/
    ADC_CHANNEL_ANA0 =  0x0 /**< IO_RA0: ANA0*/
} adc_channel_t;


/**
 * @ingroup adc
 * @typedef adc_computation_mode_t
 * @brief Enumeration for the ADC computation modes.
 */
typedef enum
{
    ADC_BASIC = 0x0, /**< Basic mode*/  
    ADC_SERIES_ACCUMULATE = 0x1, /**< Series Accumulate mode*/  
    ADC_SERIES_AVERAGE = 0x2, /**< Series Average mode*/  
    ADC_BURST_AVERAGE = 0x3, /**< Burst Average mode*/  
    ADC_LOW_PASS_FILTER = 0x4 /**< Low-Pass Filter mode*/  
} adc_computation_mode_t;

/**
 * @ingroup adc
 * @typedef adc_calculation_mode_t
 * @brief Enumeration for the ADC error calculation modes.
 */
typedef enum
{
    ADC_FIRST_DERIVATIVE_OF_SINGLE_MEASUREMENT = 0x0, /**< First derivative of single measurement*/  
    ADC_ACTUAL_RESULT_VS_SETPOINT = 0x1, /**< Actual result vs setpoint*/  
    ADC_ACTUAL_RESULT_VS_FILTERED_VALUE = 0x2, /**< Actual result vs filtered value*/  
    ADC_FIRST_DERIVATIVE_OF_FILTERED_VALUE = 0x4, /**< First derivative of filtered value*/  
    ADC_FILTERED_VALUE_VS_SETPOINT = 0x5 /**< Filtered value vs setpoint*/  
} adc_calculation_mode_t;

/**
 * @ingroup adc
 * @typedef adc_threshold_mode_t 
 * @brief Enumeration for the ADC threshold modes.
 */
typedef enum
{
    ADC_NEVER_INTERRUPT = 0x0, /**< Disabled*/  
    ADC_BELOW_LOWER_THRESHOLD = 0x1, /**< ADERR < ADLTH*/  
    ADC_ABOVE_LOWER_THRESHOLD = 0x2, /**< ADERR >= ADLTH*/  
    ADC_INSIDE_LOWER_AND_UPPER_THRESHOLD = 0x3, /**< ADERR > ADLTH and ADERR < ADUTH*/  
    ADC_OUTSIDE_LOWER_AND_UPPER_THRESHOLD = 0x4, /**< ADERR < ADLTH or ADERR > ADUTH*/  
    ADC_BELOW_UPPER_THRESHOLD = 0x5, /**< ADERR <= ADUTH*/  
    ADC_ABOVE_UPPER_THRESHOLD = 0x6, /**< ADERR > ADUTH*/  
    ADC_ALWAYS_INTERRUPT = 0x7 /**< Enabled*/  
} adc_threshold_mode_t ;

/**
 * @ingroup adc
 * @typedef adc_trigger_source_t 
 * @brief Enumeration for the ADC auto-trigger sources.
 */
typedef enum
{
    ADC_TRIGGER_SOURCE_DISABLED = 0x0, /**< Disabled*/  
    ADC_TRIGGER_SOURCE_ADACTPPS = 0x1, /**< ADACTPPS*/  
    ADC_TRIGGER_SOURCE_TMR0 = 0x2, /**< TMR0*/  
    ADC_TRIGGER_SOURCE_TMR1 = 0x3, /**< TMR1*/  
    ADC_TRIGGER_SOURCE_TMR2 = 0x4, /**< TMR2*/  
    ADC_TRIGGER_SOURCE_TMR3 = 0x5, /**< TMR3*/  
    ADC_TRIGGER_SOURCE_TMR4 = 0x6, /**< TMR4*/  
    ADC_TRIGGER_SOURCE_CCP1 = 0x7, /**< CCP1*/  
    ADC_TRIGGER_SOURCE_CCP2 = 0x8, /**< CCP2*/  
    ADC_TRIGGER_SOURCE_PWM1_OUT1 = 0x9, /**< PWM1_OUT1*/  
    ADC_TRIGGER_SOURCE_PWM1_OUT2 = 0xa, /**< PWM1_OUT2*/  
    ADC_TRIGGER_SOURCE_PWM2_OUT1 = 0xb, /**< PWM2_OUT1*/  
    ADC_TRIGGER_SOURCE_PWM2_OUT2 = 0xc, /**< PWM2_OUT2*/  
    ADC_TRIGGER_SOURCE_PWM3_OUT1 = 0xd, /**< PWM3_OUT1*/  
    ADC_TRIGGER_SOURCE_PWM3_OUT2 = 0xe, /**< PWM3_OUT2*/  
    ADC_TRIGGER_SOURCE_NCO1 = 0xf, /**< NCO1*/  
    ADC_TRIGGER_SOURCE_CMP1 = 0x10, /**< CMP1*/  
    ADC_TRIGGER_SOURCE_CMP2 = 0x11, /**< CMP2*/  
    ADC_TRIGGER_SOURCE_LOGICAL_OR_OF_ALL_IOC_FLAGS = 0x12, /**< Logical OR of all IOC flags*/  
    ADC_TRIGGER_SOURCE_CLC1 = 0x13, /**< CLC1*/  
    ADC_TRIGGER_SOURCE_CLC2 = 0x14, /**< CLC2*/  
    ADC_TRIGGER_SOURCE_CLC3 = 0x15, /**< CLC3*/  
    ADC_TRIGGER_SOURCE_CLC4 = 0x16, /**< CLC4*/  
    ADC_TRIGGER_SOURCE_CLC5 = 0x17, /**< CLC5*/  
    ADC_TRIGGER_SOURCE_CLC6 = 0x18, /**< CLC6*/  
    ADC_TRIGGER_SOURCE_CLC7 = 0x19, /**< CLC7*/  
    ADC_TRIGGER_SOURCE_CLC8 = 0x1a, /**< CLC8*/  
    ADC_TRIGGER_SOURCE_ADERRH = 0x1b, /**< ADERRH*/  
    ADC_TRIGGER_SOURCE_ADRESH = 0x1c, /**< ADRESH*/  
    ADC_TRIGGER_SOURCE_ADPCH = 0x1d, /**< ADPCH*/  
    ADC_TRIGGER_SOURCE_TU16A = 0x1e, /**< TU16A*/  
    ADC_TRIGGER_SOURCE_TU16B = 0x1f, /**< TU16B*/  
    ADC_TRIGGER_SOURCE_RW0 = 0x20, /**< RW0*/  
    ADC_TRIGGER_SOURCE_RW1 = 0x21, /**< RW1*/  
    ADC_TRIGGER_SOURCE_RW2 = 0x22, /**< RW2*/  
    ADC_TRIGGER_SOURCE_RW3 = 0x23, /**< RW3*/  
    ADC_TRIGGER_SOURCE_RW4 = 0x24, /**< RW4*/  
    ADC_TRIGGER_SOURCE_RW5 = 0x25, /**< RW5*/  
    ADC_TRIGGER_SOURCE_RW6 = 0x26, /**< RW6*/  
    ADC_TRIGGER_SOURCE_RW7 = 0x27, /**< RW7*/  
    ADC_TRIGGER_SOURCE_ANALOG_PERIPHERAL_MODULE = 0x28 /**< Analog Peripheral Module*/  
} adc_trigger_source_t ;

/**
 * @ingroup adc
 * @typedef adc_conversion_stage_t
 * @brief Enumeration for the ADC conversion stage statuses.
 */
typedef enum
{
    ADC_NOT_CONVERTING = 0x0, /**< Not converting*/  
    ADC_1ST_PRECHARGE = 0x1, /**< 1st precharge*/  
    ADC_1ST_ACQUISITION = 0x2, /**< 1st acquisition*/  
    ADC_1ST_CONVERSION = 0x3, /**< 1st conversion*/  
    ADC_SUSPENDED_BETWEEN_1ST_AND_2ND_SAMPLE = 0x4, /**< Suspended between 1st and 2nd sample*/  
    ADC_2ND_PRECHARGE = 0x5, /**< 2nd precharge*/  
    ADC_2ND_ACQUISITION = 0x6, /**< 2nd acquisition*/  
    ADC_2ND_CONVERSION = 0x7 /**< 2nd conversion*/  
} adc_conversion_stage_t;

/**
 @ingroup adc
 @enum adc_context_t
 @brief Contains the available ADC contexts.
 */
typedef enum
{
    context_1 = 0,
} adc_context_t;

#endif // ADC_TYPES_H