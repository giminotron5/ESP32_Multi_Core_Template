# ESP32 Multi-Core Template

A solid starting point for ESP32 multi-core projects using PlatformIO.  
This template splits tasks between cores, with a clear structure for core-specific and shared tasks, making debugging, task management, and resource monitoring easier.
Powered by FreeRTOS, it handles task scheduling across both cores efficiently.
Ideal for developers looking to maximize performance and streamline project structure.
It's designed with flexibility in mind, offering the tools you need to get up and running with multi-core development fast.

## Features
- **Modular Structure**: Organized into separate folders for each section, making it easy to manage core-specific code.
- **Multi-core Task Management**: Organize your tasks across Core 0, Core 1, and a common section (either core) with FreeRTOS.
- **Debugging Tools**: Use custom debug macros for simplified debugging with different cores.
- **Utility Module**: The utility module offers essential functions to help monitor system performance and manage tasks in ESP32 projects.


## Project Structure
📦 src
- 📂 common
  - 📜 common.cpp
  - 📜 definitions.hpp
  - 📜 libraries.hpp
  - 📜 objects.hpp
  - 📜 variables.cpp
  - 📜 variables.hpp
- 📂 core0
  - 📜 core0.cpp
  - 📜 definitions.hpp
  - 📜 libraries.hpp
  - 📜 objects.hpp
  - 📜 variables.hpp
- 📂 core1
  - 📜 core1.cpp
  - 📜 definitions.hpp
  - 📜 libraries.hpp
  - 📜 objects.hpp
  - 📜 variables.hpp
- 📜 main.cpp


### Main Components
- **Common Folder**: Contains tasks that are not bound to a specific core and can run on either core.
- **Core 0 Folder**: Contains tasks that are pinned to Core 0 of the ESP32.
- **Core 1 Folder**: Contains tasks that are pinned to Core 1 of the ESP32.

Each section has a `setup` and `loop` function where you can implement your tasks.
The watchdog timer is handled automatically this `loop` functions to prevent the system from freezing.


## Getting Started
### Requirements
- **PlatformIO**: This project is designed to work with PlatformIO. Make sure you have it installed in your environment.  
  You can install PlatformIO via [PlatformIO IDE](https://platformio.org/install) or [VSCode](https://code.visualstudio.com/).

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/giminotron5/ESP32_Multi-Core_Template.git
   ```
   
2. Navigate to the project directory:
   ```bash
   cd ESP32_Multi-Core_Template
   ```

3. Remove the `.git` folder to clean up the project for your own use:
   ```bash
   rm -rf .git
   ```
   
4. Open the project in PlatformIO:
   - Open the cloned folder in Visual Studio Code with PlatformIO extension:
     ```bash
     code .
     ```
   - Alternatively, you can go to **Open Project** in PlatformIO and select the project folder.

5. Build and upload to your ESP32 board:
     ```bash
     pio run --target upload
     ```

6. Feel free to customize this template to fit your project’s needs. ***Enjoy structured coding!***


## Debugging
### Debug Macros
The template provides debugging macros to output information during runtime. These macros come in two variants:
- **P-type macros**: These macros include the core or section name as a prefix in the output (e.g., `CO_P_DEBUG`, `C1_P_DEBUG_LN`, `COM_P_DEBUG_F`), making it easier to identify the source.
- **Non-P-type macros**: These macros do not include any prefix (e.g., `CO_DEBUG`, `C1_DEBUG_LN`, `COM_DEBUG_F`), offering a cleaner output for more general use.

To enable debugging for a specific section, define the corresponding macro in the `definitions.hpp` file of that section:
- `#define __COM_DEBUG__` for the common section.
- `#define __C0_DEBUG__` for core0.
- `#define __C1_DEBUG__` for core1.

### Debug Port Configuration
The debug serial port for each core can be set separately. To change the default serial port (which is UART0), go to `definitions.hpp` for each section and modify the following:
- For the common core: `COM_DEBUG_PORT`
- For core0: `C0_DEBUG_PORT`
- For core1: `C1_DEBUG_PORT`

The default baud rate for debug serial communication is `115200`.


## Utilities Module
The Utilities module provides essential helper functions to monitor various system parameters.
This module helps developers keep track of RAM usage, task status, and more, ensuring efficient resource management during development.

### Key Features
- **RAM Monitoring**: Functions to retrieve and display current RAM usage statistics.
- **Stack Usage**: Functions to calculate and report stack usage for tasks.
- **Task Status**: Functionality to check and report the status of tasks running on the ESP32.

For the source code, please refer to the [Utilities Source](https://github.com/giminotron5/ESP32_Multi-Core_Template/tree/main/lib/utilities).


## FreeRTOS Integration
This template leverages FreeRTOS for task management across the ESP32’s dual-core architecture. FreeRTOS allows efficient task scheduling and switching, making it easier to handle tasks on both cores simultaneously.

For more information about FreeRTOS on ESP32, you can refer to [FreeRTOS Documentation](https://freertos.org/).


## Contributing
Contributions are welcome! If you would like to enhance this project, please follow these guidelines:

1. **Fork the Repository**: Create a personal copy of the repository by forking it.
2. **Create a Feature Branch**: Keep your changes organized by working in a new branch.
3. **Follow the Code Style**: When writing your code, please stick to the formatting guidelines provided in the `.clang-format` file. It helps keep everything clean and consistent!
4. **Test Your Changes**: Make sure everything works as expected before you submit.
5. **Submit a Pull Request**: Once you’re happy with your changes, go ahead and create a pull request!

Thanks for considering contributing! Every little bit helps.

