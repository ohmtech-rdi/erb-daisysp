/*****************************************************************************

      Biquad.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/macros.h"

#include "Filters/biquad.h"

#include <cstddef>



namespace erb
{



class Biquad
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Biquad (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Biquad () = default;

   erb_MemberProxyW (cutoff, Biquad, impl_set_cutoff);
   erb_MemberProxyW (resonance, Biquad, impl_set_resonance);

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_cutoff (float freq);
   inline void    impl_set_resonance (float res);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Biquad
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Biquad (const Biquad & rhs) = delete;
                  Biquad (Biquad && rhs) = delete;
   Biquad &       operator = (const Biquad & rhs) = delete;
   Biquad &       operator = (Biquad && rhs) = delete;
   bool           operator == (const Biquad & rhs) const = delete;
   bool           operator != (const Biquad & rhs) const = delete;



}; // class Biquad



}  // namespace erb



#include "erb/Biquad.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
