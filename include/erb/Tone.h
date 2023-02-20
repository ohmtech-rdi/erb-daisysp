/*****************************************************************************

      Tone.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/macros.h"

#include "Filters/tone.h"

#include <cstddef>



namespace erb
{



class Tone
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Tone (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Tone () = default;

   erb_MemberProxyW (cutoff, Tone, impl_set_cutoff);

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_cutoff (float freq);
   inline void    impl_set_cutoff (Frequency freq);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Tone
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Tone (const Tone & rhs) = delete;
                  Tone (Tone && rhs) = delete;
   Tone &         operator = (const Tone & rhs) = delete;
   Tone &         operator = (Tone && rhs) = delete;
   bool           operator == (const Tone & rhs) const = delete;
   bool           operator != (const Tone & rhs) const = delete;



}; // class Tone



}  // namespace erb



#include "erb/Tone.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
