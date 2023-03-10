/*****************************************************************************

      AdEnv.hpp
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

AdEnv::AdEnv (size_t sample_rate)
{
   _impl.Init (float (sample_rate));
}



/*
==============================================================================
Name: trigger
==============================================================================
*/

void  AdEnv::trigger ()
{
   _impl.Trigger ();
}



/*
==============================================================================
Name: running
==============================================================================
*/

bool  AdEnv::running () const
{
   return _impl.IsRunning ();
}



/*
==============================================================================
Name: stage
==============================================================================
*/

AdEnv::Stage   AdEnv::stage () const
{
   return static_cast <AdEnv::Stage> (
      const_cast <daisysp::AdEnv &> (_impl).GetCurrentSegment ()
   );
}



/*
==============================================================================
Name: stage_attack
==============================================================================
*/

bool  AdEnv::stage_attack () const
{
   return stage () == Stage::Attack;
}



/*
==============================================================================
Name: stage_decay
==============================================================================
*/

bool  AdEnv::stage_decay () const
{
   return stage () == Stage::Decay;
}



/*
==============================================================================
Name: sample
==============================================================================
*/

float AdEnv::sample ()
{
   return _impl.Process ();
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

template <size_t size>
std::array <float, size>   AdEnv::operator () ()
{
   std::array <float, size> ret;
   for (size_t i = 0 ; i < size ; ++i)
   {
      ret [i] = _impl.Process ();
   }

   return ret;
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name: impl_set_attack_time
==============================================================================
*/

void  AdEnv::impl_set_attack_time (float time_s)
{
   _impl.SetTime (daisysp::ADENV_SEG_ATTACK, time_s);
}



/*
==============================================================================
Name: impl_set_attack_time
==============================================================================
*/

void  AdEnv::impl_set_attack_time (std::chrono::seconds time_s)
{
   _impl.SetTime (daisysp::ADENV_SEG_ATTACK, time_s.count ());
}



/*
==============================================================================
Name: impl_set_decay_time
==============================================================================
*/

void  AdEnv::impl_set_decay_time (float time_s)
{
   _impl.SetTime (daisysp::ADENV_SEG_DECAY, time_s);
}



/*
==============================================================================
Name: impl_set_decay_time
==============================================================================
*/

void  AdEnv::impl_set_decay_time (std::chrono::seconds time_s)
{
   _impl.SetTime (daisysp::ADENV_SEG_DECAY, time_s.count ());
}



/*
==============================================================================
Name: impl_set_curve
==============================================================================
*/

void  AdEnv::impl_set_curve (float scalar)
{
   _impl.SetCurve (scalar);
}



/*
==============================================================================
Name: impl_set_min
==============================================================================
*/

void  AdEnv::impl_set_min (float level)
{
   _impl.SetMin (level);
}



/*
==============================================================================
Name: impl_set_min
==============================================================================
*/

void  AdEnv::impl_set_min (Decibel level)
{
   _impl.SetMin (level.to_voltage_gain ());
}



/*
==============================================================================
Name: impl_set_max
==============================================================================
*/

void  AdEnv::impl_set_max (float level)
{
   _impl.SetMax (level);
}



/*
==============================================================================
Name: impl_set_max
==============================================================================
*/

void  AdEnv::impl_set_max (Decibel level)
{
   _impl.SetMax (level.to_voltage_gain ());
}



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
