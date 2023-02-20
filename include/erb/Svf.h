/*****************************************************************************

      Svf.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Effects/autowah.h"

#include <cstddef>



namespace erb
{



class Svf
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Svf (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Svf () = default;

   erb_MemberProxyW (frequency, Svf, impl_set_frequency);
   erb_MemberProxyW (resonance, Svf, impl_set_resonance);
   erb_MemberProxyW (drive, Svf, impl_set_drive);

   struct OutputSample
   {
      float       low, high, band, notch, peak;
   };

   inline OutputSample
                  operator () (float x);

   template <size_t size>
   struct OutputBuffer
   {
      std::array <float, size>
                  low, high, band, notch, peak;
   };

   template <size_t size>
   inline OutputBuffer <size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_frequency (float freq);
   inline void    impl_set_frequency (Frequency freq);
   inline void    impl_set_resonance (float res);
   inline void    impl_set_drive (float drive);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Svf   _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Svf (const Svf & rhs) = delete;
                  Svf (Svf && rhs) = delete;
   Svf &          operator = (const Svf & rhs) = delete;
   Svf &          operator = (Svf && rhs) = delete;
   bool           operator == (const Svf & rhs) const = delete;
   bool           operator != (const Svf & rhs) const = delete;



}; // class Svf



}  // namespace erb



#include "erb/Svf.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
