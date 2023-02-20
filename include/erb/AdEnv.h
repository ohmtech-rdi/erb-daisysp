/*****************************************************************************

      AdEnv.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Control/adenv.h"

#include <chrono>

#include <cstddef>



namespace erb
{



class AdEnv
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         AdEnv (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~AdEnv () = default;

   erb_MemberProxyW (attack_time, AdEnv, impl_set_attack_time);
   erb_MemberProxyW (decay_time, AdEnv, impl_set_decay_time);
   erb_MemberProxyW (curve, AdEnv, impl_set_curve);
   erb_MemberProxyW (min, AdEnv, impl_set_min);
   erb_MemberProxyW (max, AdEnv, impl_set_max);

   inline void    trigger ();

   enum class Stage: uint8_t
   {
      Idle = 0, Attack, Decay,
   };

   inline bool    running () const;
   inline Stage   stage () const;
   inline bool    stage_attack () const;
   inline bool    stage_decay () const;

   inline float   sample ();
   template <size_t size = erb_BUFFER_SIZE>
   inline std::array <float, size>
                  operator () ();



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_attack_time (float time_s);
   inline void    impl_set_attack_time (std::chrono::seconds time_s);
   inline void    impl_set_decay_time (float time_s);
   inline void    impl_set_decay_time (std::chrono::seconds time_s);
   inline void    impl_set_curve (float scalar);
   inline void    impl_set_min (float level);
   inline void    impl_set_min (Decibel level);
   inline void    impl_set_max (float level);
   inline void    impl_set_max (Decibel level);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::AdEnv
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  AdEnv (const AdEnv & rhs) = delete;
                  AdEnv (AdEnv && rhs) = delete;
   AdEnv &        operator = (const AdEnv & rhs) = delete;
   AdEnv &        operator = (AdEnv && rhs) = delete;
   bool           operator == (const AdEnv & rhs) const = delete;
   bool           operator != (const AdEnv & rhs) const = delete;



}; // class AdEnv



}  // namespace erb



#include "erb/AdEnv.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
