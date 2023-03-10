/*****************************************************************************

      dsp_util.hpp
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



namespace erb
{



/*
==============================================================================
Name: scale
==============================================================================
*/

float scale (float x_norm, float min, float max)
{
   return min + x_norm * (max - min);
}



/*
==============================================================================
Name: scale
==============================================================================
*/

template <typename T>
typename std::enable_if <
is_unit_type <T>::value, T
>::type  scale (float x_norm, T min, T max)
{
   return {min.value + x_norm * (max.value - min.value)};
}



/*
==============================================================================
Name: scale
==============================================================================
*/

float scale (float x_norm, float min, float max, float skew)
{
   if (x_norm == 0.f) return min;

   float x = std::exp (std::log (x_norm) / skew);
   return min + x * (max - min);
}



/*
==============================================================================
Name: scale
==============================================================================
*/

template <typename T>
typename std::enable_if <
is_unit_type <T>::value, T
>::type  scale (float x_norm, T min, T max, float skew)
{
   if (x_norm == 0.f) return min;

   float x = std::exp (std::log (x_norm) / skew);
   return {min.value + x * (max.value - min.value)};
}



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
