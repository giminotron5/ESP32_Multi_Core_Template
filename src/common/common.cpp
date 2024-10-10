/**============================================================================
 *  File: common.cpp
 *  Project: ESP32 Multi-Core Template
 *  Version: 1.0.0
 *  Author: giminotron5
 *  GitHub: https://github.com/giminotron5/ESP32_Multi-Core_Template
 * 
 *  Description: Contains tasks that are not tied to a specific core and can 
 *               run on either core, managed by FreeRTOS.
 *
 *  Tasks in this file are dynamically assigned to the available cores.
 *  Use `xTaskCreatePinnedToCore()` to assign tasks with the `COMMON_CORE` affinity when needed.
 *
 *  Example:
 *    xTaskCreatePinnedToCore(taskFunction, "Task Name", stackSize, param, priority, &taskHandle, COMMON_CORE);
 *                                                                                                ```````````
 *
 *  - Libraries:          Include shared libraries/header_files in "common/libraries.hpp".
 *  - Macros/Definitions: Add shared macros/definitions in "common/definitions.hpp".
 *  - Objects:            Declare global objects in "common/objects.hpp" that are shared across cores.
 *  - Variables:          Initialize shared variables in "common/variables.cpp" and declare them as "extern" in "common/variables.hpp".
 *=============================================================================
 */
#include "common.hpp"

namespace common
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
 * @brief This task initializes the common core and then enters an infinite loop that runs on the common core.
 */
void init(void *parameter)
{
  // Initialize the common core debug feature
#ifdef __COM_DEBUG__
  if(!COM_DEBUG_PORT) { COM_DEBUG_PORT.begin(115200); }
  COM_P_DEBUG_LN("Setup started...");
#endif

  // Execute the common core setup function
  setup();
#ifdef __COM_DEBUG__
  COM_P_DEBUG_LN("Setup done!");
#endif

  // Enable the watchdog timer to prevent the common core from resetting in case of infinite loop
  esp_task_wdt_add(NULL);

  // Execute the common core loop function
  for(;;)
  {
    vTaskDelay(5); //delay 1 RTOS tick
    esp_task_wdt_reset();
    loop();
  }
}

#pragma endregion }
} // namespace common
/*-------------------- End of Program ! --------------------*/
