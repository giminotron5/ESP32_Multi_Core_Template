#pragma once

#pragma region DEBUG {

// #define __C0_DEBUG__ // Uncomment to enable core0 debug output

//---------------- Serial port definition ----------------
#ifdef __C0_DEBUG__
  #define C0_DEBUG_PORT Serial // Debug port
#endif
//---------------- Definition debug macros ----------------
#ifdef C0_DEBUG_PORT
  #define C0_PREFIX "[CORE0] "
  // Core0 debug using printf with "[CORE0] " prefix.
  #define C0_P_DEBUG_F(...)              \
    {                                    \
      C0_DEBUG_PORT.print(C0_PREFIX);    \
      C0_DEBUG_PORT.printf(__VA_ARGS__); \
    }
  // Core0 debug using print with "[CORE0] " prefix.
  #define C0_P_DEBUG(...)               \
    {                                   \
      C0_DEBUG_PORT.print(C0_PREFIX);   \
      C0_DEBUG_PORT.print(__VA_ARGS__); \
    }
  // Core0 debug using println with "[CORE0] " prefix.
  #define C0_P_DEBUG_LN(...)              \
    {                                     \
      C0_DEBUG_PORT.print(C0_PREFIX);     \
      C0_DEBUG_PORT.println(__VA_ARGS__); \
    }
  #define C0_DEBUG_F(...)  C0_DEBUG_PORT.printf(__VA_ARGS__)  // Core0 debug using printf.
  #define C0_DEBUG(...)    C0_DEBUG_PORT.print(__VA_ARGS__)   // Core0 debug using print.
  #define C0_DEBUG_LN(...) C0_DEBUG_PORT.println(__VA_ARGS__) // Core0 debug using println.
#else
  #define C0_P_DEBUG(...)    // Core0 debug using print with "[CORE0] " prefix.
  #define C0_P_DEBUG_LN(...) // Core0 debug using println with "[CORE0] " prefix.
  #define C0_P_DEBUG_F(...)  // Core0 debug using printf with "[CORE0] " prefix.
  #define C0_DEBUG_F(...)    // Core0 debug using printf.
  #define C0_DEBUG(...)      // Core0 debug using print.
  #define C0_DEBUG_LN(...)   // Core0 debug using println.
#endif

#pragma endregion } // DEBUG

/*---------------- Declare your core 0-specific macros/definitions here ----------------*/
