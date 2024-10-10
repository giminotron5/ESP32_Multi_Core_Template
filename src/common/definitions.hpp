#pragma once

#pragma region DEBUG {

// #define __COM_DEBUG__ // Uncomment to enable common debug output

//---------------- Serial port definition ----------------
#ifdef __COM_DEBUG__
  #define COM_DEBUG_PORT Serial // Debug port
#endif
//---------------- Definition debug macros ----------------
#ifdef COM_DEBUG_PORT
  #define COM_PREFIX "[COM] "
  // Common debug using printf with "[COM] " prefix.
  #define COM_P_DEBUG_F(...)              \
    {                                     \
      COM_DEBUG_PORT.print(COM_PREFIX);   \
      COM_DEBUG_PORT.printf(__VA_ARGS__); \
    }
  // Common debug using print with "[COM] " prefix.
  #define COM_P_DEBUG(...)               \
    {                                    \
      COM_DEBUG_PORT.print(COM_PREFIX);  \
      COM_DEBUG_PORT.print(__VA_ARGS__); \
    }
  // Common debug using println with "[COM] " prefix.
  #define COM_P_DEBUG_LN(...)              \
    {                                      \
      COM_DEBUG_PORT.print(COM_PREFIX);    \
      COM_DEBUG_PORT.println(__VA_ARGS__); \
    }
  #define COM_DEBUG_F(...)  COM_DEBUG_PORT.printf(__VA_ARGS__)  // Common debug using printf.
  #define COM_DEBUG(...)    COM_DEBUG_PORT.print(__VA_ARGS__)   // Common debug using print.
  #define COM_DEBUG_LN(...) COM_DEBUG_PORT.println(__VA_ARGS__) // Common debug using println.
#else
  #define COM_P_DEBUG(...)    // Common debug using print with "[COM] " prefix.
  #define COM_P_DEBUG_LN(...) // Common debug using println with "[COM] " prefix.
  #define COM_P_DEBUG_F(...)  // Common debug using printf with "[COM] " prefix.
  #define COM_DEBUG_F(...)    // Common debug using printf.
  #define COM_DEBUG(...)      // Common debug using print.
  #define COM_DEBUG_LN(...)   // Common debug using println.
#endif

#pragma endregion } // DEBUG

/*---------------- Declare your shared macros/definitions here ----------------*/
