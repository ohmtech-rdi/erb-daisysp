/*****************************************************************************

      Overdrive.hpp
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

Overdrive::Overdrive ()
{
   _impl.Init ();
}


/*
==============================================================================
Name: operator ()
==============================================================================
*/

float Overdrive::operator () (float x)
{
   return _impl.Process (x);
}



/*
==============================================================================
Name: operator ()
==============================================================================
*/

template <size_t size>
std::array <float, size>   Overdrive::operator () (std::array <float, size> in)
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
Name: impl_set_drive
==============================================================================
*/

void  Overdrive::impl_set_drive (float drive)
{
   _impl.SetDrive (drive);
}



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
