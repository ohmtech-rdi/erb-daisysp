/*****************************************************************************

      Fold.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Effects/fold.h"

#include <chrono>

#include <cstddef>



namespace erb
{



class Fold
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Fold ();
   virtual        ~Fold () = default;

   erb_MemberProxyW (increment, Fold, impl_set_increment);

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_increment (float increment);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Fold  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Fold (const Fold & rhs) = delete;
                  Fold (Fold && rhs) = delete;
   Fold &         operator = (const Fold & rhs) = delete;
   Fold &         operator = (Fold && rhs) = delete;
   bool           operator == (const Fold & rhs) const = delete;
   bool           operator != (const Fold & rhs) const = delete;



}; // class Fold



}  // namespace erb



#include "erb/Fold.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
