/**============================================================================
 *  File: core1.cpp
 *  Project: ESP32 Multi-Core Template
 *  Version: 1.0.0
 *  Author: giminotron5
 *  GitHub: https://github.com/giminotron5/ESP32_Multi-Core_Template
 * 
 *  Description: Contains tasks that are specifically pinned to Core 1 of the ESP32.
 * 
 *  All tasks in this section will run exclusively on Core 1.
 *  If you need to create a task, use `xTaskCreatePinnedToCore()` with `CORE1` to ensure the task is pinned to Core 1.
 * 
 *  Example:
 *    xTaskCreatePinnedToCore(taskFunction, "Task Name", stackSize, param, priority, &taskHandle, CORE1);
 *                                                                                                `````
 * 
 * - Libraries:          Include Core 1-specific libraries/header_files in "core1/libraries.hpp".
 * - Macros/Definitions: Add Core 1-specific macros/definitions in "core1/definitions.hpp".
 * - Objects:            Declare Core 1-specific objects in "core1/objects.hpp".
 * - Variables:          Declare Core 1-specific variables in "core1/variables.hpp".
 *=============================================================================
 */
#include <common/common.hpp>
#include "core1.hpp"
#include "libraries.hpp"
#include "definitions.hpp"
#include "objects.hpp"
#include "variables.hpp"

namespace c1
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
 * @brief This task initializes the core 1 and then enters an infinite loop that runs on the core 1.
 */
void init(void *parameter)
{
  // Initialize the core1 debug feature
#ifdef __C1_DEBUG__
  if(!C1_DEBUG_PORT) { C1_DEBUG_PORT.begin(115200); }
  C1_P_DEBUG_LN("Setup started...");
#endif

  // Execute the core1 setup function
  setup();
#ifdef __C1_DEBUG__
  C1_P_DEBUG_LN("Setup done!");
#endif

  // Enable the watchdog timer to prevent the core1 from resetting in case of infinite loop
  esp_task_wdt_add(NULL);

  // Execute the core1 loop function
  for(;;)
  {
    vTaskDelay(5); //delay 1 RTOS tick
    esp_task_wdt_reset();
    loop();
  }
}

#pragma endregion }
} // namespace c1
/*-------------------- End of Program ! --------------------*/
