/*****************************************************************************

      Balance.hpp
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

Balance::Balance (size_t sample_rate)
{
   _impl.Init (float (sample_rate));
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

float Balance::operator () (float sig, float comp)
{
   return _impl.Process (sig, comp);
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

template <size_t size>
std::array <float, size>   Balance::operator () (std::array <float, size> sig, std::array <float, size> comp)
{
   std::array <float, size> ret;
   for (size_t i = 0 ; i < size ; ++i)
   {
      ret [i] = _impl.Process (sig [i], comp [i]);
   }

   return ret;
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name: impl_set_cutoff
==============================================================================
*/

void  Balance::impl_set_cutoff (float freq)
{
   _impl.SetCutoff (freq);
}



/*
==============================================================================
Name: impl_set_cutoff
==============================================================================
*/

void  Balance::impl_set_cutoff (Frequency freq)
{
   _impl.SetCutoff (freq.value);
}



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
