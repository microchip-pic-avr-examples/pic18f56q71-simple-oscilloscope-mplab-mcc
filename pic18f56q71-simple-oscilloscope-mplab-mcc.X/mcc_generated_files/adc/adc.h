/**
 * ADC Generated Driver API Header File
 * 
 * @file adc.h
 * 
 * @defgroup  adc ADC
 * 
 * @brief This is the generated header file for the ADC driver.
 *
 * @version ADC Driver Version 1.0.0
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

#ifndef ADC_H
#define ADC_H

/**
  Section: Included Files
*/

#include <stdint.h>
#include <stdbool.h>

#ifndef uint24_t
typedef __uint24 uint24_t;
#endif

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_Initialize API
 */
#define ADC_Initialize ADC_Initialize

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_SelectContext API
 */
#define ADC_SelectContext ADC_SelectContext

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_EnableChannelScan API
 */
#define ADC_EnableChannelScan ADC_EnableChannelScan

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_DisableChannelScan API
 */
#define ADC_DisableChannelScan ADC_DisableChannelScan

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_EnableChannelSequencer API
 */
#define ADC_EnableChannelSequencer  ADC_EnableChannelSequencer

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_DisableChannelSequencer API
 */
#define ADC_DisableChannelSequencer ADC_DisableChannelSequencer

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_SetChannel API
 */
#define ADC_SetChannel ADC_SetChannel

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_DischargeSampleCapacitor API
 */
#define ADC_DischargeSampleCapacitor ADC_DischargeSampleCapacitor

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_StartConversionOnChannel API
 */
#define ADC_StartConversionOnChannel ADC_StartConversionOnChannel

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_StartConversion API
 */
#define ADC_StartConversion ADC_StartConversion

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_StopConversion API
 */
#define ADC_StopConversion ADC_StopConversion

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_IsConversionDone API
 */
#define ADC_IsConversionDone ADC_IsConversionDone

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_GetConversionResult API
 */
#define ADC_GetConversionResult ADC_GetConversionResult

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_GetSingleConversion API
 */
#define ADC_GetSingleConversion ADC_GetSingleConversion

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_GetConversionStageStatus API
 */
#define ADC_GetConversionStageStatus ADC_GetConversionStageStatus

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_EnableContinuousConversion API
 */
#define ADC_EnableContinuousConversion ADC_EnableContinuousConversion

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_DisableContinuousConversion API
 */
#define ADC_DisableContinuousConversion ADC_DisableContinuousConversion

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_SetStopOnInterrupt API
 */
#define ADC_SetStopOnInterrupt ADC_SetStopOnInterrupt

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_EnableDoubleSampling API
 */
#define ADC_EnableDoubleSampling ADC_EnableDoubleSampling

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_SetAcquisitionRegister API
 */
#define ADC_SetAcquisitionRegister ADC_SetAcquisitionRegister

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_SetPrechargeRegister API
 */
#define ADC_SetPrechargeRegister ADC_SetPrechargeRegister

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_DefineSetPoint API
 */
#define ADC_DefineSetPoint ADC_DefineSetPoint

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_SetUpperThreshold API
 */
#define ADC_SetUpperThreshold ADC_SetUpperThreshold

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_SetLowerThreshold API
 */
#define ADC_SetLowerThreshold ADC_SetLowerThreshold

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_HasErrorCrossedUpperThreshold API
 */
#define ADC_HasErrorCrossedUpperThreshold ADC_HasErrorCrossedUpperThreshold

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_HasErrorCrossedLowerThreshold API
 */
#define ADC_HasErrorCrossedLowerThreshold ADC_HasErrorCrossedLowerThreshold

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_SetRepeatCount API
 */
#define ADC_SetRepeatCount ADC_SetRepeatCount

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_GetCurrentCountofConversions API
 */
#define ADC_GetCurrentCountofConversions ADC_GetCurrentCountofConversions

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_GetAccumulatorValue API
 */
#define ADC_GetAccumulatorValue ADC_GetAccumulatorValue

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_ClearAccumulator API
 */
#define ADC_ClearAccumulator ADC_ClearAccumulator

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_HasAccumulatorOverflowed API
 */
#define ADC_HasAccumulatorOverflowed ADC_HasAccumulatorOverflowed

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_GetErrorCalculation API
 */
#define ADC_GetErrorCalculation ADC_GetErrorCalculation

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_GetPreviousResult API
 */
#define ADC_GetPreviousResult ADC_GetPreviousResult

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_GetFilterValue API
 */
#define ADC_GetFilterValue ADC_GetFilterValue

/**
 * @ingroup  adc
 * @brief    This macro defines the Custom Name for \ref ADC_SetADIInterruptHandler API
 */
#define ADC_SetADIInterruptHandler ADC_SetADIInterruptHandler

/**
 @ingroup adc
 @typedef adc_result_t
 @brief This typedef should be used for result of A/D conversion.
 */
typedef uint16_t adc_result_t;

/**
 * @ingroup adc
 * @enum adc_channel_t
 * @brief This enumeration contains available ADC channels.
*/
typedef enum
{
    channel_ADCG1 =  0x36,
    channel_OPA1IN_pos =  0x37,
    channel_OPA2IN_pos =  0x38,
    channel_DAC2 =  0x39,
    channel_DAC3 =  0x3a,
    channel_VSS =  0x3b,
    channel_Temp =  0x3c,
    channel_DAC1 =  0x3d,
    channel_FVR_Buffer1 =  0x3e,
    channel_FVR_Buffer2 =  0x3f,
    channel_OPA1IN0_pos =  0x42,
    channel_OPA1IN1_pos =  0x44,
    channel_OPA1IN2_pos =  0x45,
    channel_OPA1IN3_pos =  0x49,
    channel_OPA2IN0_pos =  0x81,
    channel_OPA2IN1_pos =  0x8a,
    channel_OPA2IN2_pos =  0x8b,
    channel_OPA2IN3_pos =  0x8c,
    channel_ANA1 =  0x1
} adc_channel_t;

/**
 @ingroup adc
 @enum ADC_context_t
 @brief This enumeration contains available ADC contexts.
 */
typedef enum
{
    context_1 = 0,
} adc_context_t;

/**
 * @ingroup adc
 * @brief This API initializes the ADC module. This routine must be called before any other ADC routine.
 * @param none
 * @return none
*/
void ADC_Initialize(void);

/**
 * @ingroup adc
 * @brief This API is used to select an ADC context to perform read/write operations on 
 *        context specific registers.
 * @param Context to be selected. Refer @ref adc_context_t for available contexts
 * @return void
*/
inline void ADC_SelectContext(adc_context_t context);

/**
 * @ingroup adc
 * @brief This API is used to include a channel context in the scan sequence.
 *        Correct context should be selected using @ref ADC_SelectContext before calling this API.
 * @param Context which needs to be included in scan. Refer @ref adc_context_t for available contexts
 * @return void
*/
void ADC_EnableChannelScan(adc_context_t context);
 
/**
 * @ingroup adc
 * @brief This API is used to exclude a channel context from the scan sequence.
 *        Correct context should be selected using @ref ADC_SelectContext before calling this API.
 * @param Context which needs to be excluded from scan. Refer @ref adc_context_t for available contexts
 * @return void
*/
void ADC_DisableChannelScan(adc_context_t context);

/**
 * @ingroup adc
 * @brief This API enables ADC channel sequencer.
 *        ADC module should be initialized using @ref ADC_Initialize before calling this API.
 * @param void
 * @return void
*/
inline void ADC_EnableChannelSequencer(void);

/**
 * @ingroup adc
 * @brief This API disables ADC channel sequencer.
 *        ADC module should be initialized using @ref ADC_Initialize before calling this API.
 * @param void
 * @return void
*/
inline void ADC_DisableChannelSequencer(void);    

/**
 * @ingroup adc
 * @brief Sets the positive channel as per user selection
 * @pre adc should be initialized with ADC_Initialize() before calling this API.
 * @param Desired analog channel. For available analog channels refer adc_channel_t enum from adc.h file
 * @return None
*/
inline void ADC_SetChannel(adc_channel_t channel);

/**
 * @ingroup adc
 * @brief This API is used to discharge input sample capacitor for selected context by
 *        setting the channel to AVss.
 *        Correct ADC context should be selected using @ref ADC_SelectContext
 *        before calling this API.
 * @param void
 * @return void
*/
inline void ADC_DischargeSampleCapacitor(void); 

/**
 * @ingroup adc
 * @brief This API starts A/D conversion on selected channel.
 * @param channel - Analog channel number on which A/D conversion has to be applied.
 *                  Refer adc_channel_t for available list of channels
 * @return none
*/
void ADC_StartConversionOnChannel(adc_channel_t channel);

/**
 * @ingroup adc
 * @brief This API starts A/D conversion on selected channel.
 * @param none
 * @return none
*/
inline void ADC_StartConversion(void);

/**
 * @ingroup adc
 * @brief This API is used to stop ongoing A/D conversion.
 * @pre ADC_StartConversion() function should have been called before calling this function.
 * @param none
 * @return none
*/
inline void ADC_StopConversion(void);

/**
 * @ingroup adc
 * @brief This API checks if ongoing A/D conversion is complete.
 * @pre ADC_StartConversion() should be called before calling this function.
 * @param none
 * @retval true - if conversion is complete
 * @retval false - if conversion is ongoing
*/
inline bool ADC_IsConversionDone(void);

/**
 * @ingroup adc
 * @brief This API is used to retrieve the result of latest A/D conversion.
 * @pre ADC_StartConversion() should be called before calling this function and completion status should be checked using ADC_IsConversionDone() routine.
 * @param none
 * @return The result of A/D conversion. Refer adc_result_t
*/
inline adc_result_t ADC_GetConversionResult(void);

/**
 * @ingroup adc
 * @brief This API is used to retrieve the result of single A/D conversion on given channel in single-ended mode.
 * @pre ADC_DisableContinuousConversion function should have been called before calling this function
 * @param channel - Analog channel number on which A/D conversion has to be applied.
 *                  Refer adc_channel_t  for available channels
 * @return The result of A/D conversion. Refer adc_result_t
*/
adc_result_t ADC_GetSingleConversion(adc_channel_t channel);

/**
 * @ingroup adc
 * @brief This API is used retrieve the multi-stage status.
 * @pre ADC_StartConversion() should be called before calling this function.
 * @param none
 * @return Contents of ADC STATUS register.
*/
inline uint8_t ADC_GetConversionStageStatus(void);

/**
 * @ingroup adc
 * @brief This API enables continuous conversion.
 * @param none
 * @return none
*/
inline void ADC_EnableContinuousConversion(void);

/**
 * @ingroup adc
 * @brief This API disables continuous conversion.
 * @param none
 * @return none
*/
inline void ADC_DisableContinuousConversion(void);

/**
 * @ingroup adc
 * @brief This API is used enable Stop On Interrupt bit.
 * @pre ADC_EnableContinuousConversion() function should have been called before calling this function.
 * @param none
 * @return none
*/
inline void ADC_SetStopOnInterrupt(void);

/**
 * @ingroup adc
 * @brief This API enables double-sampling bit.
 * @param none
 * @return none
*/
inline void ADC_EnableDoubleSampling(void);

/**
 * @ingroup adc
 * @brief This API is used to load ADC Acquisition Time Control register with specified value.
 * @param acquisitionValue - Value to be loaded in the acquisition time control register.
 * @return none
*/
void ADC_SetAcquisitionRegister(uint16_t acquisitionValue);

/**
 * @ingroup adc
 * @brief This API is used to load ADC Precharge Time Control register with specified value.
 * @param prechargeTime - Value to be loaded in the precharge time control register.
 * @return none
*/
void ADC_SetPrechargeRegister(uint16_t prechargeTime);

/**
 * @ingroup adc
 * @brief This API used to set value of ADC Threshold Set-point.
 * @param setPoint - 16-bit value for set point.
 * @return none
*/
void ADC_DefineSetPoint(uint16_t setPoint);
/**
 * @ingroup adc
 * @brief This API used to set value of ADC Upper Threshold register.
 * @param upperThreshold - 16-bit value for upper threshold.
 * @return none
*/
void ADC_SetUpperThreshold(uint16_t upperThreshold);

/**
 * @ingroup adc
 * @brief This API used to set value of ADC Lower Threshold register.
 * @param lowerThreshold - 16-bit value for lower threshold.
 * @return none
*/
void ADC_SetLowerThreshold(uint16_t lowerThreshold);
/**
 * @ingroup adc
 * @brief This API is used to determine if ADC error has crossed the upper threshold.
 * @pre ADC_StartConversion() should be called before calling this function.
 * @param none
 * @retval true - if ERR > UTH
 * @retval false - if ERR <= UTH
*/
inline bool ADC_HasErrorCrossedUpperThreshold(void);

/**
 * @ingroup adc
 * @brief This API is used to determine if ADC error is less than the lower threshold.
 * @pre ADC_StartConversion() should be called before calling this function.
 * @param none
 * @retval true - if ERR < LTH
 * @retval false - if ERR >= LTH
*/
inline bool ADC_HasErrorCrossedLowerThreshold(void);

/**
 * @ingroup adc
 * @brief This API is used to load repeat counter with specified value.
 * @param repeatCount - Value to be loaded to repeat counter.
 * @return none
*/
inline void ADC_SetRepeatCount(uint8_t repeatCount);

/**
 * @ingroup adc
 * @brief This API retrieves the current value of ADC Repeat Count register.
 * @pre ADC_StartConversion() should be called before calling this function.
 * @param none
 * @return Current value of ADC Repeat Count register
*/
inline uint8_t ADC_GetCurrentCountofConversions(void);

/**
 * @ingroup adc
 * @brief This API retrieves 24-bit value of ADC accumulator.
 * @param none
 * @return Value of ADC accumulator.
*/
inline uint24_t ADC_GetAccumulatorValue(void);
/**
 * @ingroup adc
 * @brief This API clears the accumulator.
 * @param none
 * @return none
*/
inline void ADC_ClearAccumulator(void);

/**
 * @ingroup adc
 * @brief This API is used to determine whether ADC accumulator has overflowed.
 * @pre ADC_StartConversion() should be called before calling this function.
 * @param none
 * @retval true - ADC accumulator has overflowed
 * @retval false - ADC accumulator has not overflowed
*/
inline bool ADC_HasAccumulatorOverflowed(void);

/**
 * @ingroup adc
 * @brief This API retrieves the value of ADC Set-point Error register.
 * @pre ADC_StartConversion() should be called before calling this function.
 * @param none
 * @return 16-bit value obtained from ADERRH and ADERRL registers.
*/
inline int16_t ADC_GetErrorCalculation(void);

/**
 * @ingroup adc
 * @brief This API retrieves the value of ADC Previous register.
 * @pre ADC_StartConversion() should be called before calling this function.
 * @param none
 * @return 16-bit value obtained from ADPREVH and ADPREVL registers.
*/
inline uint16_t ADC_GetPreviousResult(void);

/**
 * @ingroup adc
 * @brief This API retrieves the value of ADC Filter register.
 * @param none
 * @return 16-bit value obtained from ADFLTRH and ADFLTRL registers.
*/
inline uint16_t ADC_GetFilterValue(void);
/**
 * @ingroup adc
 * @brief This routine is used to set the callback for the ADI Interrupt.
 * @param Callback Function to be called
 * @return none
*/
void ADC_SetADIInterruptHandler(void (* InterruptHandler)(void));






#endif //ADC_H