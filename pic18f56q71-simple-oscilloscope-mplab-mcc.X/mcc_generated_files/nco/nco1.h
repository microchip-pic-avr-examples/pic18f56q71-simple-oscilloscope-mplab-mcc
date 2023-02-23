/**
 * NCO1 Generated Driver API Header File.
 * 
 * @file nco1.h
 * 
 * @defgroup  nco1 NCO1
 * 
 * @brief This file contains the API prototypes for the NCO1 driver.
 *
 * @version NCO1 Driver Version 2.0.1
*/
/*
© [2023] Microchip Technology Inc. and its subsidiaries.

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


#ifndef NCO1_H
#define NCO1_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
 * @ingroup nco1
 * @brief Initializes the NCO1 module. This routine must be called once before any other NCO1 APIs.
 * @param None.
 * @return None.
 */
void NCO1_Initialize(void);

;

/**
 * @ingroup nco1
 * @brief Returns the NCO1 output level.
 * @pre NCO1_Initialize() is already called.
 * @param None.
 * @retval 1 - Output is high.
 * @retval 0 - Output is low.
 * 
 */
bool NCO1_GetOutputStatus(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  //NCO1_H
/**
 End of File
*/
