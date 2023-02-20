/*****************************************************************************

      DcBlock.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/macros.h"

#include "Utility/dcblock.h"

#include <cstddef>



namespace erb
{



class DcBlock
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
   inline         DcBlock (size_t sample_rate = erb_SAMPLE_RATE);
   virtual        ~DcBlock () = default;

   inline float   operator () (float x);
   template <size_t size>
   inline std::array <float, size>
                  operator () (std::array <float, size> in);



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   daisysp::DcBlock
                  _impl;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  DcBlock (const DcBlock & rhs) = delete;
                  DcBlock (DcBlock && rhs) = delete;
   DcBlock &      operator = (const DcBlock & rhs) = delete;
   DcBlock &      operator = (DcBlock && rhs) = delete;
   bool           operator == (const DcBlock & rhs) const = delete;
   bool           operator != (const DcBlock & rhs) const = delete;



}; // class DcBlock



}  // namespace erb



#include "erb/DcBlock.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
