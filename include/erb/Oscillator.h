/*****************************************************************************

      Oscillator.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Synthesis/oscillator.h"

#include <cstddef>



namespace erb
{



class Oscillator
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Oscillator (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Oscillator () = default;

   enum class Waveform: uint8_t
   {
      Sinus = 0,
      Triangle,
      Saw,
      Ramp,
      Square,
      PolyBlepTriangle,
      PolyBlepSaw,
      PolyBlepSquare,
   };

   erb_MemberProxyW (frequency, Oscillator, impl_set_frequency);
   erb_MemberProxyW (amplitude, Oscillator, impl_set_amplitude);
   erb_MemberProxyW (waveform, Oscillator, impl_set_waveform);
   erb_MemberProxyW (pulse_width, Oscillator, impl_set_pulse_width);
   erb_MemberProxyA (phase, Oscillator, impl_add_phase);

   inline void    reset (float phase = 0.f);

   inline bool    end_of_rise () const;
   inline bool    end_of_cycle () const;
   inline bool    rising () const;
   inline bool    falling () const;

   inline float   sample ();
   template <size_t size = erb_BUFFER_SIZE>
   inline std::array <float, size>
                  operator () ();



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_frequency (float freq);
   inline void    impl_set_frequency (Frequency freq);
   inline void    impl_set_amplitude (float amp);
   inline void    impl_set_amplitude (Decibel amp);
   inline void    impl_set_waveform (Waveform waveform);
   inline void    impl_set_pulse_width (float pw);
   inline void    impl_add_phase (float phase_delta);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Oscillator
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Oscillator (const Oscillator & rhs) = delete;
                  Oscillator (Oscillator && rhs) = delete;
   Oscillator &   operator = (const Oscillator & rhs) = delete;
   Oscillator &   operator = (Oscillator && rhs) = delete;
   bool           operator == (const Oscillator & rhs) const = delete;
   bool           operator != (const Oscillator & rhs) const = delete;



}; // class Oscillator



}  // namespace erb



#include "erb/Oscillator.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
