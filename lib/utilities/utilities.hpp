#pragma once

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_heap_caps.h>

namespace util
{

#pragma region CPU {

#pragma endregion }

#pragma region RAM {

void     ramUsage(Stream *debugPort);
uint16_t stackUsage(TaskHandle_t taskHandle, uint32_t totalStackSize);

#pragma endregion }

#pragma region Task {

void taskStatus(Stream *serialPort, TaskHandle_t taskHandle);

#pragma endregion }

} // namespace util
