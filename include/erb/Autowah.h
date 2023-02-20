/*****************************************************************************

      Autowah.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/macros.h"

#include "Effects/autowah.h"

#include <cstddef>



namespace erb
{



class Autowah
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Autowah (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Autowah () = default;

   erb_MemberProxyW (wah, Autowah, impl_set_wah);
   erb_MemberProxyW (dry_wet, Autowah, impl_set_dry_wet);
   erb_MemberProxyW (level, Autowah, impl_set_level);

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_wah (float wah);
   inline void    impl_set_dry_wet (float dry_wet);
   inline void    impl_set_level (float level);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Autowah
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Autowah (const Autowah & rhs) = delete;
                  Autowah (Autowah && rhs) = delete;
   Autowah &      operator = (const Autowah & rhs) = delete;
   Autowah &      operator = (Autowah && rhs) = delete;
   bool           operator == (const Autowah & rhs) const = delete;
   bool           operator != (const Autowah & rhs) const = delete;



}; // class Autowah



}  // namespace erb



#include "erb/Autowah.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
