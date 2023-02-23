/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define SW0_TRIS                 TRISAbits.TRISA0
#define SW0_LAT                  LATAbits.LATA0
#define SW0_PORT                 PORTAbits.RA0
#define SW0_WPU                  WPUAbits.WPUA0
#define SW0_OD                   ODCONAbits.ODCA0
#define SW0_ANS                  ANSELAbits.ANSELA0
#define SW0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SW0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SW0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SW0_GetValue()           PORTAbits.RA0
#define SW0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SW0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SW0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SW0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SW0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define SW0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define SW0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define SW0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)
   
// get/set RA1 aliases
#define IO_RA1_TRIS                 TRISAbits.TRISA1
#define IO_RA1_LAT                  LATAbits.LATA1
#define IO_RA1_PORT                 PORTAbits.RA1
#define IO_RA1_WPU                  WPUAbits.WPUA1
#define IO_RA1_OD                   ODCONAbits.ODCA1
#define IO_RA1_ANS                  ANSELAbits.ANSELA1
#define IO_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_GetValue()           PORTAbits.RA1
#define IO_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_RA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_RA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_RA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_RA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)
   
// get/set RB1 aliases
#define RB1_IN3_TRIS                 TRISBbits.TRISB1
#define RB1_IN3_LAT                  LATBbits.LATB1
#define RB1_IN3_PORT                 PORTBbits.RB1
#define RB1_IN3_WPU                  WPUBbits.WPUB1
#define RB1_IN3_OD                   ODCONBbits.ODCB1
#define RB1_IN3_ANS                  ANSELBbits.ANSELB1
#define RB1_IN3_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_IN3_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_IN3_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_IN3_GetValue()           PORTBbits.RB1
#define RB1_IN3_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_IN3_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_IN3_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_IN3_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_IN3_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define RB1_IN3_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define RB1_IN3_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_IN3_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)
   
// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)
   
// get/set RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)
   
// get/set RC7 aliases
#define LED0_TRIS                 TRISCbits.TRISC7
#define LED0_LAT                  LATCbits.LATC7
#define LED0_PORT                 PORTCbits.RC7
#define LED0_WPU                  WPUCbits.WPUC7
#define LED0_OD                   ODCONCbits.ODCC7
#define LED0_ANS                  ANSELCbits.ANSELC7
#define LED0_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED0_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED0_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED0_GetValue()           PORTCbits.RC7
#define LED0_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED0_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED0_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LED0_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LED0_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define LED0_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)
   
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/