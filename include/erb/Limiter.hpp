/*****************************************************************************

      Limiter.hpp
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



namespace erb
{



/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name: ctor
==============================================================================
*/

Limiter::Limiter ()
{
   _impl.Init ();
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

float Limiter::operator () (float in, float pre_gain)
{
   _impl.ProcessBlock (&in, 1, pre_gain);
   return in;
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

float Limiter::operator () (float in, Decibel pre_gain)
{
   _impl.ProcessBlock (&in, 1, pre_gain.to_voltage_gain ());
   return in;
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

template <size_t size>
std::array <float, size>   Limiter::operator () (std::array <float, size> in, float pre_gain)
{
   std::array <float, size> ret = in;
   for (size_t i = 0 ; i < size ; ++i)
   {
      _impl.ProcessBlock (&ret [0], ret.size (), pre_gain);
   }

   return ret;
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

template <size_t size>
std::array <float, size>   Limiter::operator () (std::array <float, size> in, Decibel pre_gain)
{
   const auto pre_gain_linear = pre_gain.to_voltage_gain ();
   std::array <float, size> ret = in;
   for (size_t i = 0 ; i < size ; ++i)
   {
      _impl.ProcessBlock (&ret [0], ret.size (), pre_gain_linear);
   }

   return ret;
}



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
