/*****************************************************************************

      Adsr.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/dsp_units.h"
#include "erb/macros.h"

#include "Control/adsr.h"

#include <chrono>

#include <cstddef>



namespace erb
{



class Adsr
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         Adsr (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~Adsr () = default;

   erb_MemberProxyW (attack_time, Adsr, impl_set_attack_time);
   erb_MemberProxyW (decay_time, Adsr, impl_set_decay_time);
   erb_MemberProxyW (release_time, Adsr, impl_set_release_time);
   erb_MemberProxyW (sustain_level, Adsr, impl_set_sustain_level);

   inline void    retrigger (bool hard);

   enum class Stage: uint8_t
   {
      Idle = 0, Attack, Decay, Release = 4,
   };

   inline bool    running () const;
   inline Stage   stage () const;
   inline bool    stage_attack () const;
   inline bool    stage_decay () const;
   inline bool    stage_release () const;

   inline float   sample (bool gate);
   template <size_t size = erb_BUFFER_SIZE>
   inline std::array <float, size>
                  operator () (bool gate);



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

   inline void    impl_set_attack_time (float time_s);
   inline void    impl_set_attack_time (std::chrono::seconds time_s);
   inline void    impl_set_decay_time (float time_s);
   inline void    impl_set_decay_time (std::chrono::seconds time_s);
   inline void    impl_set_release_time (float time_s);
   inline void    impl_set_release_time (std::chrono::seconds time_s);
   inline void    impl_set_sustain_level (float level);
   inline void    impl_set_sustain_level (Decibel level);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::Adsr
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  Adsr (const Adsr & rhs) = delete;
                  Adsr (Adsr && rhs) = delete;
   Adsr &         operator = (const Adsr & rhs) = delete;
   Adsr &         operator = (Adsr && rhs) = delete;
   bool           operator == (const Adsr & rhs) const = delete;
   bool           operator != (const Adsr & rhs) const = delete;



}; // class Adsr



}  // namespace erb



#include "erb/Adsr.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
