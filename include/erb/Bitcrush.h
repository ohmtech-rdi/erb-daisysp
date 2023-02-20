/*****************************************************************************

      Bitcrush.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Effects/bitcrush.h"

#include <cstddef>



namespace erb
{



class Bitcrush
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Bitcrush (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Bitcrush () = default;

   erb_MemberProxyW (bit_depth, Bitcrush, impl_set_bit_depth);
   erb_MemberProxyW (crush_rate, Bitcrush, impl_set_crush_rate);

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_bit_depth (int depth);
   inline void    impl_set_crush_rate (float freq);
   inline void    impl_set_crush_rate (Frequency freq);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Bitcrush
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Bitcrush (const Bitcrush & rhs) = delete;
                  Bitcrush (Bitcrush && rhs) = delete;
   Bitcrush &     operator = (const Bitcrush & rhs) = delete;
   Bitcrush &     operator = (Bitcrush && rhs) = delete;
   bool           operator == (const Bitcrush & rhs) const = delete;
   bool           operator != (const Bitcrush & rhs) const = delete;



}; // class Bitcrush



}  // namespace erb



#include "erb/Bitcrush.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
