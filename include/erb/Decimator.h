/*****************************************************************************

      Decimator.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Effects/decimator.h"

#include <cstddef>



namespace erb
{



class Decimator
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Decimator ();
   virtual        ~Decimator () = default;

   erb_MemberProxyW (downsample_amount, Decimator, impl_set_downsample_amount);
   erb_MemberProxyW (bitcrush_amount, Decimator, impl_set_bitcrush_amount);
   erb_MemberProxyW (bitcrush_depth, Decimator, impl_set_bitcrush_depth);
   erb_MemberProxyW (smooth_crushing, Decimator, impl_set_smooth_crushing);

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_downsample_amount (float amount);
   inline void    impl_set_bitcrush_amount (float amount);
   inline void    impl_set_bitcrush_depth (int depth);
   inline void    impl_set_smooth_crushing (bool enable);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Decimator
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Decimator (const Decimator & rhs) = delete;
                  Decimator (Decimator && rhs) = delete;
   Decimator &    operator = (const Decimator & rhs) = delete;
   Decimator &    operator = (Decimator && rhs) = delete;
   bool           operator == (const Decimator & rhs) const = delete;
   bool           operator != (const Decimator & rhs) const = delete;



}; // class Decimator



}  // namespace erb



#include "erb/Decimator.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
