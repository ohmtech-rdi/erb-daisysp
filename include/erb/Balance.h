/*****************************************************************************

      Balance.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Dynamics/balance.h"

#include <chrono>

#include <cstddef>



namespace erb
{



class Balance
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Balance (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Balance () = default;

   erb_MemberProxyW (cutoff, Balance, impl_set_cutoff);

   inline float   operator () (float sig, float comp);
   template <size_t size = erb_BUFFER_SIZE>
   inline std::array <float, size>
                  operator () (std::array <float, size> sig, std::array <float, size> comp);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_cutoff (float freq);
   inline void    impl_set_cutoff (Frequency freq);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Balance
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Balance (const Balance & rhs) = delete;
                  Balance (Balance && rhs) = delete;
   Balance &      operator = (const Balance & rhs) = delete;
   Balance &      operator = (Balance && rhs) = delete;
   bool           operator == (const Balance & rhs) const = delete;
   bool           operator != (const Balance & rhs) const = delete;



}; // class Balance



}  // namespace erb



#include "erb/Balance.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
