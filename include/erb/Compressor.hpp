/*****************************************************************************

      Compressor.hpp
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

Compressor::Compressor (size_t sample_rate)
{
   _impl.Init (float (sample_rate));
}



/*
==============================================================================
Name: gain
==============================================================================
*/

float Compressor::gain () const
{
   return const_cast <daisysp::Compressor &> (_impl).GetGain ();
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

float Compressor::operator () (float in)
{
   return _impl.Process (in);
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

float Compressor::operator () (float in, float key)
{
   return _impl.Process (in, key);
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

template <size_t size>
std::array <float, size>   Compressor::operator () (std::array <float, size> in)
{
   std::array <float, size> ret;
   _impl.ProcessBlock (&in [0], &ret [0], size);

   return ret;
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

template <size_t size>
std::array <float, size>   Compressor::operator () (std::array <float, size> in, std::array <float, size> key)
{
   std::array <float, size> ret;
   _impl.ProcessBlock (&in [0], &ret [0], &key [0], size);

   return ret;
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name: impl_set_ratio
==============================================================================
*/

void  Compressor::impl_set_ratio (float ratio)
{
   _impl.SetRatio (ratio);
}



/*
==============================================================================
Name: impl_set_threshold
==============================================================================
*/

void  Compressor::impl_set_threshold (float threshold)
{
   _impl.SetThreshold (threshold);
}



/*
==============================================================================
Name: impl_set_threshold
==============================================================================
*/

void  Compressor::impl_set_threshold (Decibel threshold)
{
   _impl.SetThreshold (threshold.value);
}



/*
==============================================================================
Name: impl_set_attack
==============================================================================
*/

void  Compressor::impl_set_attack (float time_s)
{
   _impl.SetAttack (time_s);
}



/*
==============================================================================
Name: impl_set_attack
==============================================================================
*/

void  Compressor::impl_set_attack (std::chrono::seconds time_s)
{
   _impl.SetAttack (time_s.count ());
}



/*
==============================================================================
Name: impl_set_release
==============================================================================
*/

void  Compressor::impl_set_release (float time_s)
{
   _impl.SetRelease (time_s);
}



/*
==============================================================================
Name: impl_set_release
==============================================================================
*/

void  Compressor::impl_set_release (std::chrono::seconds time_s)
{
   _impl.SetRelease (time_s.count ());
}



/*
==============================================================================
Name: impl_set_makeup
==============================================================================
*/

void  Compressor::impl_set_makeup (float makeup)
{
   _impl.SetMakeup (makeup);
}



/*
==============================================================================
Name: impl_set_makeup
==============================================================================
*/

void  Compressor::impl_set_makeup (Decibel makeup)
{
   _impl.SetMakeup (makeup.value);
}



/*
==============================================================================
Name: impl_set_auto_makeup
==============================================================================
*/

void  Compressor::impl_set_auto_makeup (bool enable)
{
   _impl.AutoMakeup (enable);
}



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
