#ifndef OSCILLOSCOPE_H
#define	OSCILLOSCOPE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>
    
    typedef enum {
        UNITY_GAIN = 0, GAIN_2, GAIN_4, GAIN_8, GAIN_16
    } OSCILLOSCOPE_GAIN;
    
    //Increments the gain of the OPAMP (1 -> 2 -> 4 -> 8 -> 16 -> 1...)
    void Oscilloscope_incrementGain(void);
    
    //Sets the configuration of OPAMP
    void Oscilloscope_setGain(OSCILLOSCOPE_GAIN gain);

#ifdef	__cplusplus
}
#endif

#endif	/* OSCILLOSCOPE_H */

