/**
 * Interrupt Manager Generated Driver API Header File
 * 
 * @file interrupt.h
 * 
 * @defgroup interrupt INTERRUPT
 * 
 * @brief This file contains API prototypes and other datatypes for Interrupt Manager.
 *
 * @version Interrupt Manager Driver Version 2.1.3
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

#ifndef INTERRUPT_H
#define INTERRUPT_H

/**
 * @ingroup interrupt
 * @brief This macro will enable high priority global interrupts.
 * @param void
 * @return void
 */
#define INTERRUPT_GlobalInterruptHighEnable() (INTCON0bits.GIE = 1)

/**
 * @ingroup interrupt
 * @brief This macro will disable high priority global interrupts.
 * @param void
 * @return void
 */
#define INTERRUPT_GlobalInterruptHighDisable() (INTCON0bits.GIE = 0)

/**
 * @ingroup interrupt
 * @brief This macro will return the global interrupt enable high bit status.
 * @param void
 * @retval 0 - Global Interrupt Disabled
 * @retval 1 - Global Interrupt Enabled
 */
#define INTERRUPT_GlobalInterruptHighStatus() (INTCON0bits.GIE)

/**
 * @ingroup interrupt
 * @brief This macro will enable low priority global interrupts.
 * @param void
 * @return void
 */
#define INTERRUPT_GlobalInterruptLowEnable() (INTCON0bits.GIEL = 1)

/**
 * @ingroup interrupt
 * @brief This macro will disable low priority global interrupts.
 * @param void
 * @return void
 */
#define INTERRUPT_GlobalInterruptLowDisable() (INTCON0bits.GIEL = 0)

/**
 * @ingroup interrupt
 * @brief This macro will return the global interrupt enable low bit status.
 * @param void
 * @retval 0 - Global Interrupt Disabled
 * @retval 1 - Global Interrupt Enabled
 */
#define INTERRUPT_GlobalInterruptLowStatus() (INTCON0bits.GIEL)

/**
 * @ingroup interrupt
 * @brief Initializes Peripheral Interrupt priorities; Enables/disables priority vectors; and, Initializes External Interrupt.
 * @param void
 * @return void
 */
void INTERRUPT_Initialize (void);


/**
 * @ingroup interrupt
 * @brief This routine clears the interrupt flag for the external interrupt, INT0.
 * @param void
 * @return void
 */
#define EXT_INT0_InterruptFlagClear()       (PIR1bits.INT0IF = 0)

/**
 * @ingroup interrupt
 * @brief This routine clears the interrupt enable for the external interrupt, INT0, and thereafter external interrupts on this pin will not be serviced by the interrupt handler.
 * @param void
 * @return void
 */
#define EXT_INT0_InterruptDisable()     (PIE1bits.INT0IE = 0)

/**
 * @ingroup interrupt
 * @brief This routine sets the interrupt enable for the external interrupt, INT0, and thereafter external interrupts on this pin will be serviced by the interrupt handler.
 * @param void
 * @return void
 */
#define EXT_INT0_InterruptEnable()       (PIE1bits.INT0IE = 1)


/**
 * @ingroup interrupt
 * @brief This routine set the edge detect of the extern interrupt to positive edge, and thereafter interrupt flag will be set when the external interrupt pins level transitions from a low to high level.
 * @param void
 * @return void
 */
#define EXT_INT0_risingEdgeSet()          (INTCON0bits.INT0EDG = 1)

/**
 * @ingroup interrupt
 * @brief This routine set the edge detect of the extern interrupt to negative edge, and thereafter interrupt flag will be set when the external interrupt pins level transitions from a high to low level.
 * @param void
 * @return void
 */
#define EXT_INT0_fallingEdgeSet()          (INTCON0bits.INT0EDG = 0)

/**
 * @ingroup interrupt
 * @brief This routine clears the interrupt flag for the external interrupt, INT1.
 * @param void
 * @return void
 */
#define EXT_INT1_InterruptFlagClear()       (PIR6bits.INT1IF = 0)

/**
 * @ingroup interrupt
 * @brief This routine clears the interrupt enable for the external interrupt, INT1, and thereafter external interrupts on this pin will not be serviced by the interrupt handler.
 * @param void
 * @return void
 */
#define EXT_INT1_InterruptDisable()     (PIE6bits.INT1IE = 0)

/**
 * @ingroup interrupt
 * @brief This routine sets the interrupt enable for the external interrupt, INT1, and thereafter external interrupts on this pin will be serviced by the interrupt handler.
 * @param void
 * @return void
 */
#define EXT_INT1_InterruptEnable()       (PIE6bits.INT1IE = 1)


/**
 * @ingroup interrupt
 * @brief This routine set the edge detect of the extern interrupt to positive edge, and thereafter interrupt flag will be set when the external interrupt pins level transitions from a low to high level.
 * @param void
 * @return void
 */
#define EXT_INT1_risingEdgeSet()          (INTCON0bits.INT1EDG = 1)

/**
 * @ingroup interrupt
 * @brief This routine set the edge detect of the extern interrupt to negative edge, and thereafter interrupt flag will be set when the external interrupt pins level transitions from a high to low level.
 * @param void
 * @return void
 */
#define EXT_INT1_fallingEdgeSet()          (INTCON0bits.INT1EDG = 0)

/**
 * @ingroup interrupt
 * @brief This routine clears the interrupt flag for the external interrupt, INT2.
 * @param void
 * @return void
 */
#define EXT_INT2_InterruptFlagClear()       (PIR10bits.INT2IF = 0)

/**
 * @ingroup interrupt
 * @brief This routine clears the interrupt enable for the external interrupt, INT2, and thereafter external interrupts on this pin will not be serviced by the interrupt handler.
 * @param void
 * @return void
 */
#define EXT_INT2_InterruptDisable()     (PIE10bits.INT2IE = 0)

/**
 * @ingroup interrupt
 * @brief This routine sets the interrupt enable for the external interrupt, INT2, and thereafter external interrupts on this pin will be serviced by the interrupt handler.
 * @param void
 * @return void
 */
#define EXT_INT2_InterruptEnable()       (PIE10bits.INT2IE = 1)


/**
 * @ingroup interrupt
 * @brief This routine set the edge detect of the extern interrupt to positive edge, and thereafter interrupt flag will be set when the external interrupt pins level transitions from a low to high level.
 * @param void
 * @return void
 */
#define EXT_INT2_risingEdgeSet()          (INTCON0bits.INT2EDG = 1)

/**
 * @ingroup interrupt
 * @brief This routine set the edge detect of the extern interrupt to negative edge, and thereafter interrupt flag will be set when the external interrupt pins level transitions from a high to low level.
 * @param void
 * @return void
 */
#define EXT_INT2_fallingEdgeSet()          (INTCON0bits.INT2EDG = 0)

/**
   Section: External Interrupt Handlers
 */

/**
 * @ingroup interrupt
 * @brief Allows for a specific callback function to be called in the INT0 ISR and allows for a non-specific interrupt handler to be called at runtime.
 * @pre Interrupt Manager is initialized.
 * @param void
 * @return void
 */
void INT0_CallBack(void);

/**
 * @ingroup interrupt
 * @brief Allows selecting an interrupt handler for EXT_INT0 - INT0 at application runtime.
 * @pre Interrupt Manager is initialized.
 * @param (*InterruptHandler)(void) - InterruptHandler function pointer
 * @return void
 */
void INT0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup interrupt
 * @brief This is the dynamic interrupt handler which is called every time the INT0 ISR is executed and allows any function to be registered at runtime.
 * @pre Interrupt Manager is initialized.
 * @param void
 * @return void
 */
extern void (*INT0_InterruptHandler)(void);

/**
 * @ingroup interrupt
 * @brief This is the default interrupt handler which is called every time the INT0 ISR is executed and allows any function to be registered at runtime.
 * @pre Interrupt Manager is initialized.
 * @param void
 * @return void
 */
void INT0_DefaultInterruptHandler(void);

/**
 * @ingroup interrupt
 * @brief Allows for a specific callback function to be called in the INT1 ISR and allows for a non-specific interrupt handler to be called at runtime.
 * @pre Interrupt Manager is initialized.
 * @param void
 * @return void
 */
void INT1_CallBack(void);

/**
 * @ingroup interrupt
 * @brief Allows selecting an interrupt handler for EXT_INT1 - INT1 at application runtime.
 * @pre Interrupt Manager is initialized.
 * @param (*InterruptHandler)(void) - InterruptHandler function pointer
 * @return void
 */
void INT1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup interrupt
 * @brief This is the dynamic interrupt handler which is called every time the INT1 ISR is executed and allows any function to be registered at runtime.
 * @pre Interrupt Manager is initialized.
 * @param void
 * @return void
 */
extern void (*INT1_InterruptHandler)(void);

/**
 * @ingroup interrupt
 * @brief This is the default interrupt handler which is called every time the INT1 ISR is executed and allows any function to be registered at runtime.
 * @pre Interrupt Manager is initialized.
 * @param void
 * @return void
 */
void INT1_DefaultInterruptHandler(void);

/**
 * @ingroup interrupt
 * @brief Allows for a specific callback function to be called in the INT2 ISR and allows for a non-specific interrupt handler to be called at runtime.
 * @pre Interrupt Manager is initialized.
 * @param void
 * @return void
 */
void INT2_CallBack(void);

/**
 * @ingroup interrupt
 * @brief Allows selecting an interrupt handler for EXT_INT2 - INT2 at application runtime.
 * @pre Interrupt Manager is initialized.
 * @param (*InterruptHandler)(void) - InterruptHandler function pointer
 * @return void
 */
void INT2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup interrupt
 * @brief This is the dynamic interrupt handler which is called every time the INT2 ISR is executed and allows any function to be registered at runtime.
 * @pre Interrupt Manager is initialized.
 * @param void
 * @return void
 */
extern void (*INT2_InterruptHandler)(void);

/**
 * @ingroup interrupt
 * @brief This is the default interrupt handler which is called every time the INT2 ISR is executed and allows any function to be registered at runtime.
 * @pre Interrupt Manager is initialized.
 * @param void
 * @return void
 */
void INT2_DefaultInterruptHandler(void);

#endif  // INTERRUPT_H
/**
 End of File
*/
