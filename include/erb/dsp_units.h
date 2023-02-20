/*****************************************************************************

      dsp_units.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include <type_traits>

#include <cmath>



namespace erb
{



struct Decibel
{
   float          value;

   constexpr Decibel
                  operator + () const { return {value}; }
   constexpr Decibel
                  operator - () const { return {-value}; }

   float          to_voltage_gain () const { return std::pow (10.f, value * 0.05f); }
};

struct Frequency
{
   float          value;
};


template <typename T>
struct is_unit_type
{
   enum { value
      = std::is_same <T, Decibel>::value
      || std::is_same <T, Frequency>::value
   };
};


inline namespace literals
{
   Decibel        operator ""_dB (unsigned long long int x) { return {float (x)}; }
   Decibel        operator ""_dB (long double x) { return {float (x)}; }

   constexpr Frequency operator ""_Hz (unsigned long long int x) { return {float (x)}; }
   constexpr Frequency operator ""_Hz (long double x) { return {float (x)}; }

   constexpr Frequency operator ""_kHz (unsigned long long int x) { return {float (x) * 1000.f}; }
   constexpr Frequency operator ""_kHz (long double x) { return {float (x) * 1000.f}; }
}



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
