/*****************************************************************************

      def.h
      Copyright (c) 2023 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include <cstddef>



/*\\\ MACROS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#if defined (__clang__)
   #define erb_daisysp_DISABLE_WARNINGS_OFFSET_OF \
      _Pragma ("clang diagnostic push") \
      _Pragma ("clang diagnostic ignored \"-Winvalid-offsetof\"")

   #define erb_daisysp_RESTORE_WARNINGS \
      _Pragma ("clang diagnostic pop")

#elif defined (__GNUC__)
   #define erb_daisysp_DISABLE_WARNINGS_OFFSET_OF \
      _Pragma ("GCC diagnostic push") \
      _Pragma ("GCC diagnostic ignored \"-Winvalid-offsetof\"")

   #define erb_daisysp_RESTORE_WARNINGS \
      _Pragma ("GCC diagnostic pop")

#endif

/*
==============================================================================
Name: erb_MemberProxyW
Description: Write proxy to a parent member function.
==============================================================================
*/

#define erb_MemberProxyW(name, base, function) \
   struct erb_MemberProxyW_##name { \
      template <typename value_type> \
      erb_MemberProxyW_##name & operator = (value_type x) { \
         erb_daisysp_DISABLE_WARNINGS_OFFSET_OF \
         auto parent_ptr = reinterpret_cast <base *> ( \
            this - std::ptrdiff_t (offsetof (base, name)) \
         ); \
         erb_daisysp_RESTORE_WARNINGS \
         parent_ptr->function (x); \
         return *this; \
      } \
   }; \
   erb_MemberProxyW_##name name



/*
==============================================================================
Name: erb_MemberProxyA
Description: Add proxy to a parent member function.
==============================================================================
*/

#define erb_MemberProxyA(name, base, function) \
   struct erb_MemberProxyA_##name { \
      template <typename value_type> \
      erb_MemberProxyA_##name & operator += (value_type x) { \
         erb_daisysp_DISABLE_WARNINGS_OFFSET_OF \
         auto parent_ptr = reinterpret_cast <base *> ( \
            this - std::ptrdiff_t (offsetof (base, name)) \
         ); \
         erb_daisysp_RESTORE_WARNINGS \
         parent_ptr->function (x); \
         return *this; \
      } \
   }; \
   erb_MemberProxyA_##name name



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
