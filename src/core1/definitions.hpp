#pragma once

#pragma region DEBUG {

// #define __C1_DEBUG__ // Uncomment to enable core1 debug output

//---------------- Serial port definition ----------------
#ifdef __C1_DEBUG__
  #define C1_DEBUG_PORT Serial // Debug port
#endif
//---------------- Definition debug macros ----------------
#ifdef C1_DEBUG_PORT
  #define C1_PREFIX "[CORE1] "
  // Core1 debug using printf with "[CORE1] " prefix.
  #define C1_P_DEBUG_F(...)              \
    {                                    \
      C1_DEBUG_PORT.print(C1_PREFIX);    \
      C1_DEBUG_PORT.printf(__VA_ARGS__); \
    }
  // Core1 debug using print with "[CORE1] " prefix.
  #define C1_P_DEBUG(...)               \
    {                                   \
      C1_DEBUG_PORT.print(C1_PREFIX);   \
      C1_DEBUG_PORT.print(__VA_ARGS__); \
    }
  // Core1 debug using println with "[CORE1] " prefix.
  #define C1_P_DEBUG_LN(...)              \
    {                                     \
      C1_DEBUG_PORT.print(C1_PREFIX);     \
      C1_DEBUG_PORT.println(__VA_ARGS__); \
    }
  #define C1_DEBUG_F(...)  C1_DEBUG_PORT.printf(__VA_ARGS__)  // Core1 debug using printf.
  #define C1_DEBUG(...)    C1_DEBUG_PORT.print(__VA_ARGS__)   // Core1 debug using print.
  #define C1_DEBUG_LN(...) C1_DEBUG_PORT.println(__VA_ARGS__) // Core1 debug using println.
#else
  #define C1_P_DEBUG(...)    // Core1 debug using print with "[CORE1] " prefix.
  #define C1_P_DEBUG_LN(...) // Core1 debug using println with "[CORE1] " prefix.
  #define C1_P_DEBUG_F(...)  // Core1 debug using printf with "[CORE1] " prefix.
  #define C1_DEBUG_F(...)    // Core1 debug using printf.
  #define C1_DEBUG(...)      // Core1 debug using print.
  #define C1_DEBUG_LN(...)   // Core1 debug using println.
#endif

#pragma endregion } // DEBUG

/*---------------- Declare your core 1-specific macros/definitions here ----------------*/
