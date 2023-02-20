// SimpleOscillator.h

#pragma once

#include "artifacts/SimpleOscillatorUi.h"
#include "erb/erb.h"
#include "erb/daisysp.h"

using namespace erb::literals;

struct SimpleOscillator
{
   SimpleOscillatorUi ui;

   erb::Oscillator oscillator;
   erb::Tone tone;

   void  init () {
      oscillator.amplitude = -3_dB;
      oscillator.waveform = erb::Oscillator::Waveform::PolyBlepSquare;
   }

   void  process () {
      oscillator.frequency = erb::scale (ui.frequency, 80_Hz, 10_kHz, 0.25f /* skew */);
      tone.cutoff = erb::scale (ui.cutoff, 30_Hz, 20_kHz, 0.25f /* skew */);

      ui.audio_out = tone (oscillator ());
   }
};
