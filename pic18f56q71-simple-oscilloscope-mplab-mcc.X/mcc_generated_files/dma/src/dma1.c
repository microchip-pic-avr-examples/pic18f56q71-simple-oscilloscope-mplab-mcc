/**
 * DMA1 Generated Driver File
 * 
 * @file dma1.c
 * 
 * @ingroup  dma1
 * 
 * @brief This is the generated driver implementation file for the DMA1 driver.
 *
 * @version DMA1 Driver Version 2.11.0
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
#include "../dma1.h"

/**
  Section: DMA1 APIs
*/

void DMA1_Initialize(void)
{   
    
    //DMA Instance Selection : 0x0
    DMASELECT = 0x0;
    //Source Address : ADRESH_CX1
    DMAnSSA = ADRESH_CX1;
    //Destination Address : &U2TXB
    DMAnDSA = &U2TXB;
    //SSTP not cleared; SMODE unchanged; SMR SFR; DSTP not cleared; DMODE unchanged; 
    DMAnCON1 = 0x0;
    //Source Message Size : 1
    DMAnSSZ = 1;
    //Destination Message Size : 1
    DMAnDSZ = 1;
    //Start Trigger : SIRQ U2TX; 
    DMAnSIRQ = 0x41;
    //Abort Trigger : AIRQ Software Interrupt; 
    DMAnAIRQ = 0x0;
	
    // Clear Destination Count Interrupt Flag bit
    PIR2bits.DMA1DCNTIF = 0; 
    // Clear Source Count Interrupt Flag bit
    PIR2bits.DMA1SCNTIF = 0; 
    // Clear Abort Interrupt Flag bit
    PIR2bits.DMA1AIF = 0; 
    // Clear Overrun Interrupt Flag bit
    PIR2bits.DMA1ORIF =0; 
    
    PIE2bits.DMA1DCNTIE = 0;
    PIE2bits.DMA1SCNTIE = 0;
    PIE2bits.DMA1AIE = 0;
    PIE2bits.DMA1ORIE = 0;
	
    //AIRQEN enabled; DGO not in progress; SIRQEN enabled; EN enabled; 
    DMAnCON0 = 0xC4;
	 
}

void DMA1_SelectSourceRegion(uint8_t region)
{
    DMASELECT = 0x0;
	DMAnCON1bits.SMR  = region;
}

void DMA1_SetSourceAddress(uint24_t address)
{
    DMASELECT = 0x0;
	DMAnSSA = address;
}

void DMA1_SetDestinationAddress(uint16_t address)
{
    DMASELECT = 0x0;
	DMAnDSA = address;
}

void DMA1_SetSourceSize(uint16_t size)
{
    DMASELECT = 0x0;
	DMAnSSZ= size;
}

void DMA1_SetDestinationSize(uint16_t size)
{                     
    DMASELECT = 0x0;
	DMAnDSZ= size;
}

uint24_t DMA1_GetSourcePointer(void)
{
    DMASELECT = 0x0;
	return DMAnSPTR;
}

uint16_t DMA1_GetDestinationPointer(void)
{
    DMASELECT = 0x0;
	return DMAnDPTR;
}

void DMA1_SetStartTrigger(uint8_t sirq)
{
    DMASELECT = 0x0;
	DMAnSIRQ = sirq;
}

void DMA1_SetAbortTrigger(uint8_t airq)
{
    DMASELECT = 0x0;
	DMAnAIRQ = airq;
}

void DMA1_StartTransfer(void)
{
    DMASELECT = 0x0;
	DMAnCON0bits.DGO = 1;
}

void DMA1_StartTransferWithTrigger(void)
{
    DMASELECT = 0x0;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA1_StopTransfer(void)
{
    DMASELECT = 0x0;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA1_SetDMAPriority(uint8_t priority)
{
    // This function is dependant on the PR1WAY CONFIG bit
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA1PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
}

/**
 End of File
*/
