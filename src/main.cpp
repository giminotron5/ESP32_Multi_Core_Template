/**============================================================================
 *  File: main.cpp
 *  Project: ESP32 Multi-Core Template
 *  Version: 1.0.0
 *  License: MIT License
 *  Author: giminotron5
 *  GitHub: https://github.com/giminotron5/ESP32_Multi-Core_Template
 * 
 *  Description: This is the main entry point for the ESP32 multi-core application. 
 *               It initializes and manages tasks that are assigned to specific cores 
 *               (Core 0, Core 1, or dynamically by FreeRTOS).
 * 
 *  The `setup()` function creates and pins tasks to specific cores using `xTaskCreatePinnedToCore()`. 
 *  Tasks from the `common` section can be executed on any available core, while tasks from `core0` 
 *  are pinned to Core 0 and tasks from `core1` are pinned to Core 1.
 * 
 *  Once tasks are created, the default Arduino loop task is deleted as it is not needed.
 *
 *  Core Assignment:
 *    - Common Tasks: Run dynamically on any core based on FreeRTOS scheduling.
 *    - Core 0 Tasks: Pinned to Core 0.
 *    - Core 1 Tasks: Pinned to Core 1.
 *=============================================================================
 */
#include <Arduino.h>
#include <common/common.hpp>
#include <core0/core0.hpp>
#include <core1/core1.hpp>

TaskHandle_t commonHandle = NULL;
TaskHandle_t core0Handle  = NULL;
TaskHandle_t core1Handle  = NULL;

/*-------------------- Main Functions --------------------*/
void setup()
{
  // Initialize the cpu cores task
  xTaskCreatePinnedToCore(common::init, "common loop", CONFIG_ARDUINO_LOOP_STACK_SIZE, NULL, 1, &commonHandle, COMMON_CORE);
  xTaskCreatePinnedToCore(c0::init, "core0 loop", CONFIG_ARDUINO_LOOP_STACK_SIZE, NULL, 1, &core0Handle, CORE0);
  xTaskCreatePinnedToCore(c1::init, "core1 loop", CONFIG_ARDUINO_LOOP_STACK_SIZE, NULL, 1, &core1Handle, CORE1);
  // Delete default Arduino loop task
  vTaskDelete(NULL);
}
void loop() {}
/*-------------------- End of Program ! --------------------*/
