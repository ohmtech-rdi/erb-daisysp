/*****************************************************************************

      Compressor.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Dynamics/compressor.h"

#include <cstddef>



namespace erb
{



class Compressor
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Compressor (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Compressor () = default;

   erb_MemberProxyW (ratio, Compressor, impl_set_ratio);
   erb_MemberProxyW (threshold, Compressor, impl_set_threshold);
   erb_MemberProxyW (attack, Compressor, impl_set_attack);
   erb_MemberProxyW (release, Compressor, impl_set_release);
   erb_MemberProxyW (makeup, Compressor, impl_set_makeup);
   erb_MemberProxyW (auto_makeup, Compressor, impl_set_auto_makeup);

   float          gain () const;

   inline float   operator () (float in);
   inline float   operator () (float in, float key);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in, std::array <float, size> key);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_ratio (float ratio);
   inline void    impl_set_threshold (float threshold);
   inline void    impl_set_threshold (Decibel threshold);
   inline void    impl_set_attack (float time_s);
   inline void    impl_set_attack (std::chrono::seconds time_s);
   inline void    impl_set_release (float time_s);
   inline void    impl_set_release (std::chrono::seconds time_s);
   inline void    impl_set_makeup (float makeup);
   inline void    impl_set_makeup (Decibel makeup);
   inline void    impl_set_auto_makeup (bool enable);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Compressor
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Compressor (const Compressor & rhs) = delete;
                  Compressor (Compressor && rhs) = delete;
   Compressor &   operator = (const Compressor & rhs) = delete;
   Compressor &   operator = (Compressor && rhs) = delete;
   bool           operator == (const Compressor & rhs) const = delete;
   bool           operator != (const Compressor & rhs) const = delete;



}; // class Compressor



}  // namespace erb



#include "erb/Compressor.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
