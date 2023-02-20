/*****************************************************************************

      Overdrive.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Effects/overdrive.h"

#include <chrono>

#include <cstddef>



namespace erb
{



class Overdrive
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Overdrive ();
   virtual        ~Overdrive () = default;

   erb_MemberProxyW (drive, Overdrive, impl_set_drive);

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_drive (float drive);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Overdrive
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Overdrive (const Overdrive & rhs) = delete;
                  Overdrive (Overdrive && rhs) = delete;
   Overdrive &    operator = (const Overdrive & rhs) = delete;
   Overdrive &    operator = (Overdrive && rhs) = delete;
   bool           operator == (const Overdrive & rhs) const = delete;
   bool           operator != (const Overdrive & rhs) const = delete;



}; // class Overdrive



}  // namespace erb



#include "erb/Overdrive.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
