#include "utility.hpp"

namespace util
{

#pragma region CPU {

#pragma endregion }

#pragma region RAM {

/**
 * @brief Prints the current RAM usage statistics.
 *
 * This function provides detailed information about the system memory usage, such as:
 * 
 * - Total heap size
 * 
 * - Used heap size
 * 
 * - Free heap size
 * 
 * - Largest allocatable block size
 * 
 * - Heap fragmentation
 * 
 * This is useful for monitoring memory consumption and optimizing task allocation in ESP32 projects.
 *
 * Example:
 * 
 * ```
 * ramUsage(&COM_DEBUG_PORT);  // Prints the current memory usage on common debug port.
 * ```
 * 
 * @param debugPort Pointer to a `Stream` object (e.g., `Serial`, `Serial1`, `Serial2`,
 * or predefined debug ports like `C0_DEBUG_PORT` for printing memory statistics.
 */
void ramUsage(Stream *serialPort)
{
  // Calculate free space of RAM memory (heap) in bytes
  uint32_t totalHeap    = heap_caps_get_total_size(MALLOC_CAP_INTERNAL);
  uint32_t freeHeap     = heap_caps_get_free_size(MALLOC_CAP_INTERNAL);
  uint32_t largestBlock = heap_caps_get_largest_free_block(MALLOC_CAP_INTERNAL);
  uint32_t usedHeap     = totalHeap - freeHeap;

  // Calculate fragmentation in percent
  float fragmentation = (freeHeap - largestBlock) / (float)freeHeap * 100.0;

  serialPort->print("Total Heap: ");
  serialPort->print(totalHeap);
  serialPort->println(" bytes");

  serialPort->print("Used Heap: ");
  serialPort->print(usedHeap);
  serialPort->println(" bytes");

  serialPort->print("Free Heap: ");
  serialPort->print(freeHeap);
  serialPort->println(" bytes");

  serialPort->print("Largest Free Block: ");
  serialPort->print(largestBlock);
  serialPort->println(" bytes");

  serialPort->print("Heap Fragmentation: ");
  serialPort->print(fragmentation);
  serialPort->println("%");
}

/**
 * @brief Returns the used stack space of a given task.
 *
 * This function calculates and returns the amount of stack space used by a task, as well as the remaining stack space.
 * It is useful for ensuring that a task is not running out of stack, helping to optimize memory usage and avoid stack overflows.
 *
 * Example:
 * 
 * ```
 * uint16_t usedStack = stackUsage(taskHandle, taskStackSize);  // Get used stack space for the specified task.
 * ```
 * 
 * @param taskHandle    The handle of the task whose stack usage is to be checked.
 * @param taskStackSize The total stack size assigned to the task.
 * 
 * @return The amount of stack space used by the task (in bytes).
 */
uint16_t stackUsage(TaskHandle_t taskHandle, uint32_t taskStackSize)
{
  // uxTaskGetStackHighWaterMark returns the minimum amount of stack space that has been left for the task
  UBaseType_t stackHighWaterMark = uxTaskGetStackHighWaterMark(taskHandle);
  // Return the used amount of stack space for the task
  return taskStackSize - stackHighWaterMark;
}

#pragma endregion }

#pragma region Task {

/**
 * @brief Prints the current status of a given task.
 *
 * This function retrieves and displays the status of a task, such as whether it's:
 * 
 * - Running
 * 
 * - Ready
 * 
 * - Blocked
 * 
 * - Suspended
 * 
 * - Deleted 
 * 
 * It helps in monitoring the execution state of tasks during debugging and system performance analysis.
 *
 * Example:
 * 
 * ```
 * taskStatus(&COM_DEBUG_PORT, taskHandle); // Prints the status of the specified task on the common debug port.
 * ```
 * 
 * @param serialPort The `Stream` object (e.g., `Serial`, `Serial1`, etc.) used for printing the task status.
 * @param taskHandle The handle of the task whose status is to be checked.
 */
void taskStatus(Stream *serialPort, TaskHandle_t taskHandle)
{
  // Get the current state of the task
  eTaskState taskState = eTaskGetState(taskHandle);
  // Get the name of the task
  const char *taskName = pcTaskGetName(taskHandle);

  // Print task status
  serialPort->print("Task name: \"");
  serialPort->print(taskName);
  serialPort->print("\" - Status: ");
  switch(taskState)
  {
    case eRunning:
      serialPort->println("Running");
      break;
    case eReady:
      serialPort->println("Ready");
      break;
    case eBlocked:
      serialPort->println("Blocked");
      break;
    case eSuspended:
      serialPort->println("Suspended");
      break;
    case eDeleted:
      serialPort->println("Deleted");
      break;
    default:
      serialPort->println("Unknown");
      break;
  }
}

#pragma endregion }

} // namespace util
