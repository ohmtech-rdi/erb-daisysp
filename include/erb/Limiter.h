/*****************************************************************************

      Limiter.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Dynamics/limiter.h"

#include <cstddef>



namespace erb
{



class Limiter
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Limiter ();
   virtual        ~Limiter () = default;

   inline float   operator () (float in, float pre_gain);
   inline float   operator () (float in, Decibel pre_gain);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in, float pre_gain);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in, Decibel pre_gain);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Limiter
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Limiter (const Limiter & rhs) = delete;
                  Limiter (Limiter && rhs) = delete;
   Limiter &      operator = (const Limiter & rhs) = delete;
   Limiter &      operator = (Limiter && rhs) = delete;
   bool           operator == (const Limiter & rhs) const = delete;
   bool           operator != (const Limiter & rhs) const = delete;



}; // class Limiter



}  // namespace erb



#include "erb/Limiter.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
