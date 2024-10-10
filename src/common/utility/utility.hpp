#pragma once

namespace common::util
{

#pragma region CPU {

#pragma endregion }

#pragma region RAM {

extern void     ramUsage(Stream *debugPort);
extern uint16_t stackUsage(TaskHandle_t taskHandle, uint32_t totalStackSize);

#pragma endregion }

#pragma region Task {

extern void taskStatus(Stream *serialPort, TaskHandle_t taskHandle);

#pragma endregion }

} // namespace common::util
