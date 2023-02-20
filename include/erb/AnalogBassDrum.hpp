/*****************************************************************************

      AnalogBassDrum.hpp
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

AnalogBassDrum::AnalogBassDrum (size_t sample_rate)
{
   _impl.Init (float (sample_rate));
}



/*
==============================================================================
Name: trigger
==============================================================================
*/

void  AnalogBassDrum::trigger ()
{
   _impl.Trig ();
}



/*
==============================================================================
Name: sample
==============================================================================
*/

float AnalogBassDrum::sample (bool trigger)
{
   return _impl.Process (trigger);
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

template <size_t size>
std::array <float, size>   AnalogBassDrum::operator () (bool trigger)
{
   static_assert (size > 0);

   std::array <float, size> ret;
   ret [0] = _impl.Process (trigger);
   for (size_t i = 1 ; i < size ; ++i)
   {
      ret [i] = _impl.Process (false);
   }

   return ret;
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name: impl_set_sustain
==============================================================================
*/

void  AnalogBassDrum::impl_set_sustain (bool infinite)
{
   _impl.SetSustain (infinite);
}



/*
==============================================================================
Name: impl_set_accent
==============================================================================
*/

void  AnalogBassDrum::impl_set_accent (float accent)
{
   _impl.SetAccent (accent);
}



/*
==============================================================================
Name: impl_set_root_frequency
==============================================================================
*/

void  AnalogBassDrum::impl_set_root_frequency (float freq)
{
   _impl.SetFreq (freq);
}



/*
==============================================================================
Name: impl_set_root_frequency
==============================================================================
*/

void  AnalogBassDrum::impl_set_root_frequency (Frequency freq)
{
   _impl.SetFreq (freq.value);
}



/*
==============================================================================
Name: impl_set_click
==============================================================================
*/

void  AnalogBassDrum::impl_set_click (float click)
{
   _impl.SetTone (click);
}



/*
==============================================================================
Name: impl_set_decay
==============================================================================
*/

void  AnalogBassDrum::impl_set_decay (float decay)
{
   _impl.SetDecay (decay);
}



/*
==============================================================================
Name: impl_set_attack_fm_amount
==============================================================================
*/

void  AnalogBassDrum::impl_set_attack_fm_amount (float amount)
{
   _impl.SetAttackFmAmount (amount);
}



/*
==============================================================================
Name: impl_set_self_fm_amount
==============================================================================
*/

void  AnalogBassDrum::impl_set_self_fm_amount (float amount)
{
   _impl.SetSelfFmAmount (amount);
}



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
