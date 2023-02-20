// SimpleOscillator.h

#pragma once

#include "artifacts/SimpleOscillatorUi.h"
#include "erb/erb.h"
#include "erb/daisysp.h"


struct SimpleOscillator
{
   SimpleOscillatorUi ui;

   daisysp::Oscillator oscillator;
   daisysp::Tone tone;

   void  init () {
      oscillator.Init (erb_SAMPLE_RATE);
      oscillator.SetAmp (0.71f /* -3 dB */);
      oscillator.SetWaveform (daisysp::Oscillator::WAVE_POLYBLEP_SQUARE);

      tone.Init (erb_SAMPLE_RATE);
   }

   void  process () {
      oscillator.SetFreq (
         erb::scale (ui.frequency, 80.f /* Hz */, 10000.f /* Hz */, 0.25f /* skew */)
      );
      tone.SetFreq (
         erb::scale (ui.cutoff, 30.f /* Hz */, 20000.f /* Hz */, 0.25f /* skew */)
      );

      for (size_t i = 0 ; i < erb_BUFFER_SIZE ; ++i)
      {
         auto x = oscillator.Process ();
         ui.audio_out [i] = tone.Process (x);
      }
   }
};
