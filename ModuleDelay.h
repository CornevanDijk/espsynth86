/*
 *  +----------------------+
 *  | ModuleDelay          |
 *  |----------------------|
 *  > audio_input          |
 *  > mix_input            |
 *  > feedback_input       |
 *  > length_input         |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleDelay is an extremely short audio delay effect with control over
// mix, feedback, and buffer length.  All inputs should range from 0 to 4095.
//
// Example usage:
//
//   ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
//   ModuleDelay *delay = new ModuleDelay();
//
//   wavetable_osc->wavetable_input  = inputs->mod;
//   wavetable_osc->frequency_input  = inputs->sr;
//  
//   delay->audio_input = wavetable_osc;
//   delay->mix_input = inputs->param1;
//   delay->feedback_input = inputs->param2;
//   delay->length_input = inputs->param3;
//
//   this->last_module = delay;
//

#ifndef ModuleDelay_h
#define ModuleDelay_h

#include "Arduino.h"
#include "Module.h"
#define DELAY_BUFFER_SIZE 1024

class ModuleDelay : public Module
{
  
  public:
    ModuleDelay();
    uint16_t compute();
    
    // Inputs
    Module *audio_input;
    Module *mix_input;   
    Module *feedback_input;
    Module *length_input; 

  private:
    
    uint16_t buffer[DELAY_BUFFER_SIZE];
    int buffer_index;
    
    uint16_t feedback;
    int mix;  // ranged from 0 to 4095, where 0 == dry, 4095 == wet
    uint32_t delay_output;
};

#endif
