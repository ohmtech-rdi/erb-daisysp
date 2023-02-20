/*****************************************************************************

      MoogLadder.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/macros.h"

#include "Filters/moogladder.h"

#include <cstddef>



namespace erb
{



class MoogLadder
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         MoogLadder (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~MoogLadder () = default;

   erb_MemberProxyW (cutoff, MoogLadder, impl_set_cutoff);
   erb_MemberProxyW (resonance, MoogLadder, impl_set_resonance);

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_cutoff (float freq);
   inline void    impl_set_cutoff (Frequency freq);
   inline void    impl_set_resonance (float res);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::MoogLadder
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  MoogLadder (const MoogLadder & rhs) = delete;
                  MoogLadder (MoogLadder && rhs) = delete;
   MoogLadder &   operator = (const MoogLadder & rhs) = delete;
   MoogLadder &   operator = (MoogLadder && rhs) = delete;
   bool           operator == (const MoogLadder & rhs) const = delete;
   bool           operator != (const MoogLadder & rhs) const = delete;



}; // class MoogLadder



}  // namespace erb



#include "erb/MoogLadder.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
