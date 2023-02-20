/*****************************************************************************

      CrossFade.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Dynamics/crossfade.h"

#include <cstddef>



namespace erb
{



class CrossFade
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         CrossFade (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~CrossFade () = default;

   enum class Curve: uint8_t
   {
      Linear = 0,
      ConstantPower,
      Logarithmic,
      Exponential,
   };

   erb_MemberProxyW (position, CrossFade, impl_set_position);
   erb_MemberProxyW (curve, CrossFade, impl_set_curve);

   inline float   operator () (float in1, float in2);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in1, std::array <float, size> in2);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_position (float position);
   inline void    impl_set_curve (Curve curve);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::CrossFade
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  CrossFade (const CrossFade & rhs) = delete;
                  CrossFade (CrossFade && rhs) = delete;
   CrossFade &    operator = (const CrossFade & rhs) = delete;
   CrossFade &    operator = (CrossFade && rhs) = delete;
   bool           operator == (const CrossFade & rhs) const = delete;
   bool           operator != (const CrossFade & rhs) const = delete;



}; // class CrossFade



}  // namespace erb



#include "erb/CrossFade.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
