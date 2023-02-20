/*****************************************************************************

      dsp_util.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "dsp_units.h"

#include <type_traits>



namespace erb
{



inline float      scale (float x_norm, float min, float max);

template <typename T>
inline typename std::enable_if <
is_unit_type <T>::value, T
>::type           scale (float x_norm, T min, T max);

inline float      scale (float x_norm, float min, float max, float skew);

template <typename T>
inline typename std::enable_if <
is_unit_type <T>::value, T
>::type           scale (float x_norm, T min, T max, float skew);



}  // namespace erb



#include "erb/dsp_util.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
