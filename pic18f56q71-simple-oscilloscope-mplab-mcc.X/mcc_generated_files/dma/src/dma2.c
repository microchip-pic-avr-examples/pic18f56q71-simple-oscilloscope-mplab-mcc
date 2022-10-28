/**
 * DMA2 Generated Driver File
 * 
 * @file dma2.c
 * 
 * @ingroup  dma2
 * 
 * @brief This is the generated driver implementation file for the DMA2 driver.
 *
 * @version DMA2 Driver Version 2.11.0
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

 /**
   Section: Included Files
 */

#include <xc.h>
#include "../dma2.h"

/**
  Section: DMA2 APIs
*/

void DMA2_Initialize(void)
{   
    
    //DMA Instance Selection : 0x1
    DMASELECT = 0x1;
    //Source Address : 0x1200
    DMAnSSA = 0x1200;
    //Destination Address : &DAC1DATL
    DMAnDSA = &DAC1DATL;
    //SSTP not cleared; SMODE decremented; SMR Program Flash; DSTP not cleared; DMODE incremented; 
    DMAnCON1 = 0x4C;
    //Source Message Size : 512
    DMAnSSZ = 512;
    //Destination Message Size : 2
    DMAnDSZ = 2;
    //Start Trigger : SIRQ TMR4; 
    DMAnSIRQ = 0x53;
    //Abort Trigger : AIRQ Software Interrupt; 
    DMAnAIRQ = 0x0;
	
    // Clear Destination Count Interrupt Flag bit
    PIR6bits.DMA2DCNTIF = 0; 
    // Clear Source Count Interrupt Flag bit
    PIR6bits.DMA2SCNTIF = 0; 
    // Clear Abort Interrupt Flag bit
    PIR6bits.DMA2AIF = 0; 
    // Clear Overrun Interrupt Flag bit
    PIR6bits.DMA2ORIF =0; 
    
    PIE6bits.DMA2DCNTIE = 0;
    PIE6bits.DMA2SCNTIE = 0;
    PIE6bits.DMA2AIE = 0;
    PIE6bits.DMA2ORIE = 0;
	
    //AIRQEN enabled; DGO not in progress; SIRQEN enabled; EN enabled; 
    DMAnCON0 = 0xC4;
	 
}

void DMA2_SelectSourceRegion(uint8_t region)
{
    DMASELECT = 0x1;
	DMAnCON1bits.SMR  = region;
}

void DMA2_SetSourceAddress(uint24_t address)
{
    DMASELECT = 0x1;
	DMAnSSA = address;
}

void DMA2_SetDestinationAddress(uint16_t address)
{
    DMASELECT = 0x1;
	DMAnDSA = address;
}

void DMA2_SetSourceSize(uint16_t size)
{
    DMASELECT = 0x1;
	DMAnSSZ= size;
}

void DMA2_SetDestinationSize(uint16_t size)
{                     
    DMASELECT = 0x1;
	DMAnDSZ= size;
}

uint24_t DMA2_GetSourcePointer(void)
{
    DMASELECT = 0x1;
	return DMAnSPTR;
}

uint16_t DMA2_GetDestinationPointer(void)
{
    DMASELECT = 0x1;
	return DMAnDPTR;
}

void DMA2_SetStartTrigger(uint8_t sirq)
{
    DMASELECT = 0x1;
	DMAnSIRQ = sirq;
}

void DMA2_SetAbortTrigger(uint8_t airq)
{
    DMASELECT = 0x1;
	DMAnAIRQ = airq;
}

void DMA2_StartTransfer(void)
{
    DMASELECT = 0x1;
	DMAnCON0bits.DGO = 1;
}

void DMA2_StartTransferWithTrigger(void)
{
    DMASELECT = 0x1;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA2_StopTransfer(void)
{
    DMASELECT = 0x1;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA2_SetDMAPriority(uint8_t priority)
{
    // This function is dependant on the PR1WAY CONFIG bit
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA2PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
}

/**
 End of File
*/
