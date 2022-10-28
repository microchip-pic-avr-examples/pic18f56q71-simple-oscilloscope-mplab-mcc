/**
 * DMA2 Generated Driver API Header File
 * 
 * @file dma2.h
 * 
 * @defgroup  dma2 DMA2
 * 
 * @brief This is the generated header file for the DMA2 driver.
 *
 * @version DMA2 Driver Version 2.11.0
 */

/*
� [2022] Microchip Technology Inc. and its subsidiaries.

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

#ifndef DMA2_H
#define DMA2_H

/**
  Section: Included Files
*/
#include <stdint.h>


/**
 * @ingroup dma2
 * @brief Initializes the DMA2 module
 *        This routine must be called before any other DMA2 routine
 * @param None.
 * @return None. 
 */
void DMA2_Initialize(void);

/**
 * @ingroup dma2
 * @brief Sets the source region as per user selection
 * @param [in] Desired source region 
 * @return None.
 */
void DMA2_SelectSourceRegion(uint8_t region);

/**
 * @ingroup dma2
 * @brief Sets the Source Address for the DMA packet
 * @param [in] Desired Source Address
 * @return None.
 */
void DMA2_SetSourceAddress(uint24_t address);

/**
 * @ingroup dma2
 * @brief Sets the destination address for the DMA packet
 * @param [in] Desired Destination Address 
 * @return None.
 */
void DMA2_SetDestinationAddress(uint16_t address);

/**
 * @ingroup dma2
 * @brief Sets the size of the Source array 
 * @param [in] Size of Source Array
 * @return None.
 */
void DMA2_SetSourceSize(uint16_t size);

/**
 * @ingroup dma2
 * @brief Sets the size of the destination array
 * @param [in] Size of Destination array
 * @return None.
 */
void DMA2_SetDestinationSize(uint16_t size);

/**
 * @ingroup dma2
 * @brief Returns the current location from which the DMA has read
 * @return Current Source pointer
 * @param None
 */
uint24_t DMA2_GetSourcePointer(void);

/**
 * @ingroup dma2
 * @brief Returns the current location where the DMA last wrote
 * @param None 
 * @return Current Destination pointer
 */
uint16_t DMA2_GetDestinationPointer(void);

/**
 * @ingroup dma2
 * @brief Sets the Start Trigger for DMA, doesn't start the transfer
 * @param [in] Start Trigger Source
 * @return None.
 */
void DMA2_SetStartTrigger(uint8_t sirq);

/**
 * @ingroup dma2
 * @brief Sets the Abort Trigger for DMA, doesn't abort the transfer
 * @param [in] Abort Trigger Source
 * @return None.
 */
void DMA2_SetAbortTrigger(uint8_t airq);

/**
 * @ingroup dma2
 * @brief Starts the DMA Transfer by setting GO bit
 * @param None.
 * @return None.
 */
void DMA2_StartTransfer(void);

/**
 * @ingroup dma2
 * @brief Starts the DMA transfer by enabling the trigger
 * @param None.
 * @return None.
 */
void DMA2_StartTransferWithTrigger(void);	

/**
 * @ingroup dma2
 * @brief Stops all the possible triggers and also clears the GO bit
 * @param None.
 * @return None.
 */
void DMA2_StopTransfer(void);

/**
 * @ingroup dma2
 * @brief Unlocks Arbiter - changes priority - locks Arbiter
 * @param [in] Priority of DMA
 * @return None.
 */
void DMA2_SetDMAPriority(uint8_t priority);




#endif //DMA2_H
