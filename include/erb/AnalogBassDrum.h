/*****************************************************************************

      AnalogBassDrum.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Drums/analogbassdrum.h"

#include <chrono>

#include <cstddef>



namespace erb
{



class AnalogBassDrum
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         AnalogBassDrum (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~AnalogBassDrum () = default;

   erb_MemberProxyW (sustain, AnalogBassDrum, impl_set_sustain);
   erb_MemberProxyW (accent, AnalogBassDrum, impl_set_accent);
   erb_MemberProxyW (root_frequency, AnalogBassDrum, impl_set_root_frequency);
   erb_MemberProxyW (click, AnalogBassDrum, impl_set_click);
   erb_MemberProxyW (decay, AnalogBassDrum, impl_set_decay);
   erb_MemberProxyW (attack_fm_amount, AnalogBassDrum, impl_set_attack_fm_amount);
   erb_MemberProxyW (self_fm_amount, AnalogBassDrum, impl_set_self_fm_amount);

   inline void    trigger ();

   inline float   sample (bool trigger = false);
   template <size_t size = erb_BUFFER_SIZE>
   inline std::array <float, size>
                  operator () (bool trigger = false);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_sustain (bool infinite);
   inline void    impl_set_accent (float accent);
   inline void    impl_set_root_frequency (float freq);
   inline void    impl_set_root_frequency (Frequency freq);
   inline void    impl_set_click (float click);
   inline void    impl_set_decay (float decay);
   inline void    impl_set_attack_fm_amount (float amount);
   inline void    impl_set_self_fm_amount (float amount);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::AnalogBassDrum
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  AnalogBassDrum (const AnalogBassDrum & rhs) = delete;
                  AnalogBassDrum (AnalogBassDrum && rhs) = delete;
   AnalogBassDrum &
                  operator = (const AnalogBassDrum & rhs) = delete;
   AnalogBassDrum &
                  operator = (AnalogBassDrum && rhs) = delete;
   bool           operator == (const AnalogBassDrum & rhs) const = delete;
   bool           operator != (const AnalogBassDrum & rhs) const = delete;



}; // class AnalogBassDrum



}  // namespace erb



#include "erb/AnalogBassDrum.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
