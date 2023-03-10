/*****************************************************************************

      MoogLadder.hpp
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

MoogLadder::MoogLadder (size_t sample_rate)
{
   _impl.Init (float (sample_rate));
}


/*
==============================================================================
Name: operator ()
==============================================================================
*/

float MoogLadder::operator () (float x)
{
   return _impl.Process (x);
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

template <size_t size>
std::array <float, size>   MoogLadder::operator () (std::array <float, size> in)
{
   std::array <float, size> ret;
   for (size_t i = 0 ; i < size ; ++i)
   {
      ret [i] = _impl.Process (in [i]);
   }

   return ret;
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name: impl_set_cutoff
==============================================================================
*/

void  MoogLadder::impl_set_cutoff (float freq)
{
   _impl.SetFreq (freq);
}



/*
==============================================================================
Name: impl_set_cutoff
==============================================================================
*/

void  MoogLadder::impl_set_cutoff (Frequency freq)
{
   _impl.SetFreq (freq.value);
}



/*
==============================================================================
Name: impl_set_resonance
==============================================================================
*/

void  MoogLadder::impl_set_resonance (float res)
{
   _impl.SetRes (res);
}



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
