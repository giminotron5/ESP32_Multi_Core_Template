/**============================================================================
 *  File: core0.cpp
 *  Project: ESP32 Multi-Core Template
 *  Version: 1.0.0
 *  License: MIT License
 *  Author: giminotron5
 *  GitHub: https://github.com/giminotron5/ESP32_Multi-Core_Template
 * 
 *  Description: Contains tasks that are specifically pinned to Core 0 of the ESP32.
 * 
 *  All tasks in this section will run exclusively on Core 0.
 *  If you need to create a task, use `xTaskCreatePinnedToCore()` with `CORE0` to ensure the task is pinned to Core 0.
 * 
 *  Example:
 *    xTaskCreatePinnedToCore(taskFunction, "Task Name", stackSize, param, priority, &taskHandle, CORE0);
 *                                                                                                `````
 * 
 * - Libraries:          Include Core 0-specific libraries/header_files in "core0/libraries.hpp".
 * - Macros/Definitions: Add Core 0-specific macros/definitions in "core0/definitions.hpp".
 * - Objects:            Declare Core 0-specific objects in "core0/objects.hpp".
 * - Variables:          Declare Core 0-specific variables in "core0/variables.hpp".
 *=============================================================================
 */
#include <common/common.hpp>
#include "core0.hpp"
#include "libraries.hpp"
#include "definitions.hpp"
#include "objects.hpp"
#include "variables.hpp"

namespace c0
{
/*-------------------- User Functions --------------------*/
// put your functions here

/*-------------------- Main Functions --------------------*/
void setup()
{
  // put your setup code here, to run once:
}
void loop()
{
  // put your main code here, to run repeatedly:
}

#pragma region PRIVATE {

/**
 * @brief This task initializes the core 0 and then enters an infinite loop that runs on the core 0.
 */
void init(void *parameter)
{
  // Initialize the core0 debug feature
#ifdef __C0_DEBUG__
  if(!C0_DEBUG_PORT) { C0_DEBUG_PORT.begin(115200); }
  C0_P_DEBUG_LN("Setup started...");
#endif

  // Execute the core0 setup function
  setup();
#ifdef __C0_DEBUG__
  C0_P_DEBUG_LN("Setup done!");
#endif

  // Enable the watchdog timer to prevent the core0 from resetting in case of infinite loop
  esp_task_wdt_add(NULL);

  // Execute the core0 loop function
  for(;;)
  {
    vTaskDelay(5); //delay 1 RTOS tick
    esp_task_wdt_reset();
    loop();
  }
}

#pragma endregion }
} // namespace c0
/*-------------------- End of Program ! --------------------*/
