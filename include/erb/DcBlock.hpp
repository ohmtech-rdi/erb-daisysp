/*****************************************************************************

      DcBlock.hpp
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

DcBlock::DcBlock (size_t sample_rate)
{
   _impl.Init (float (sample_rate));
}


/*
==============================================================================
Name: operator ()
==============================================================================
*/

float DcBlock::operator () (float x)
{
   return _impl.Process (x);
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

template <size_t size>
std::array <float, size>   DcBlock::operator () (std::array <float, size> in)
{
   std::array <float, size> ret;
   for (size_t i = 0 ; i < size ; ++i)
   {
      ret [i] = _impl.Process (in [i]);
   }

   return ret;
}



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/