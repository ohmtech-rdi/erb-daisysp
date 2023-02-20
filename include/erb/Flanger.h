/*****************************************************************************

      Flanger.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Effects/flanger.h"

#include <chrono>

#include <cstddef>



namespace erb
{



class Flanger
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Flanger (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Flanger () = default;

   erb_MemberProxyW (feedback, Flanger, impl_set_feedback);
   erb_MemberProxyW (lfo_depth, Flanger, impl_set_lfo_depth);
   erb_MemberProxyW (lfo_frequency, Flanger, impl_set_lfo_frequency);
   erb_MemberProxyW (delay, Flanger, impl_set_delay);

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_feedback (float feedback);
   inline void    impl_set_lfo_depth (float depth);
   inline void    impl_set_lfo_frequency (float freq);
   inline void    impl_set_lfo_frequency (Frequency freq);
   inline void    impl_set_delay (float delay_norm);
   inline void    impl_set_delay (std::chrono::milliseconds delay_ms);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Flanger
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Flanger (const Flanger & rhs) = delete;
                  Flanger (Flanger && rhs) = delete;
   Flanger &      operator = (const Flanger & rhs) = delete;
   Flanger &      operator = (Flanger && rhs) = delete;
   bool           operator == (const Flanger & rhs) const = delete;
   bool           operator != (const Flanger & rhs) const = delete;



}; // class Flanger



}  // namespace erb



#include "erb/Flanger.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
