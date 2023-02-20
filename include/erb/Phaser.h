/*****************************************************************************

      Phaser.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Effects/phaser.h"

#include <chrono>

#include <cstddef>



namespace erb
{



class Phaser
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Phaser (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Phaser () = default;

   erb_MemberProxyW (feedback, Phaser, impl_set_feedback);
   erb_MemberProxyW (lfo_depth, Phaser, impl_set_lfo_depth);
   erb_MemberProxyW (lfo_frequency, Phaser, impl_set_lfo_frequency);
   erb_MemberProxyW (frequency, Phaser, impl_set_frequency);

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_feedback (float feedback);
   inline void    impl_set_lfo_depth (float depth);
   inline void    impl_set_lfo_frequency (float freq);
   inline void    impl_set_lfo_frequency (Frequency freq);
   inline void    impl_set_frequency (float freq);
   inline void    impl_set_frequency (Frequency freq);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Phaser
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Phaser (const Phaser & rhs) = delete;
                  Phaser (Phaser && rhs) = delete;
   Phaser &       operator = (const Phaser & rhs) = delete;
   Phaser &       operator = (Phaser && rhs) = delete;
   bool           operator == (const Phaser & rhs) const = delete;
   bool           operator != (const Phaser & rhs) const = delete;



}; // class Phaser



}  // namespace erb



#include "erb/Phaser.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
