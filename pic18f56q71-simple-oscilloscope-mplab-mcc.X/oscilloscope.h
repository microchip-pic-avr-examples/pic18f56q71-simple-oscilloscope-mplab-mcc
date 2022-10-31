#ifndef OSCILLOSCOPE_H
#define	OSCILLOSCOPE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>
    
    typedef enum {
        UNITY_GAIN = 0, GAIN_2, GAIN_4, GAIN_8, GAIN_16
    } OSCILLOSCOPE_GAIN;
    
    typedef enum {
        SINE = 0, TRIANGLE_RISE, TRIANGLE_FALL, SAWTOOTH, SQUARE
    } OSCILLOSCOPE_WAVEFORM;

    
    //Increments the gain of the OPAMP (1 -> 2 -> 4 -> 8 -> 16 -> 1...)
    void Oscilloscope_incrementGain(void);
    
    //Changes the waveform of the oscilloscope
    void Oscilloscope_changeWaveform(void);
    
    //Sets the configuration of OPAMP
    void Oscilloscope_setGain(OSCILLOSCOPE_GAIN gain);

    //Sets the test waveform of the oscilloscopes
    void Oscilloscope_setWaveform(OSCILLOSCOPE_WAVEFORM wave);
    
    //Updates the waveforms created in software
    void Oscilloscope_updateWaveform(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* OSCILLOSCOPE_H */

