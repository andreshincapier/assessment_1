# Data Structures CLI Manager

A simple **C++** command-line application that provides interactive menus to manage two fundamental data structures:

- **Stack** (LIFO) operations via `stack_menu.cpp`
- **Queue** (FIFO) operations via `queue_menu.cpp`

Both programs let you insert, remove, list elements, and exit cleanly.

---

## Table of Contents

1. [Features](#features)
2. [Prerequisites](#prerequisites)
3. [Environment Setup (macOS & VS Code)](#environment-setup-macos--vs-code)
   - [Install Xcode Command Line Tools](#install-xcode-command-line-tools)
   - [Install LLVM/Clang via Homebrew](#install-llvmclang-via-homebrew)
   - [Configure Environment Variables](#configure-environment-variables)
   - [VS Code Extensions](#vs-code-extensions)
   - [User & Project Configuration](#user--project-configuration)
   - [Build & Debug Tasks](#build--debug-tasks)
4. [Compilation & Usage](#compilation--usage)
5. [Project Structure](#project-structure)
6. [Contributing](#contributing)
7. [License](#license)
8. [Author](#author)

---

## Features

- **Interactive Stack Manager** (`stack_menu.cpp`)
  - Push integers onto the stack
  - Pop the top element
  - Display contents from top to bottom

- **Interactive Queue Manager** (`queue_menu.cpp`)
  - Enqueue integers
  - Dequeue from the front
  - Display contents from front to back

Both programs use the C++ Standard Library (`std::vector` for stack, `std::queue` for queue) and simple `std::cin/std::cout` for I/O.

---

## Prerequisites

- **macOS** (Intel or Apple Silicon)
- **Homebrew** package manager
- **VS Code** editor (optional but recommended)
- **Git** (for version control)
- **C/C++ Compiler**: `clang`/`clang++` or `g++`

---

## Environment Setup (macOS & VS Code)

This guide is adapted from Ryan Schachte’s notes on setting up C++ on macOS with VS Code (May 4 2024).

### Install Xcode Command Line Tools

```bash
# Install Apple’s compiler toolchain
xcode-select --install
```  
*(If you already have Xcode.app, this may already be installed.)*


### Install LLVM/Clang via Homebrew

```bash
brew update
brew install llvm
```  
Verify installation paths:
```bash
which clang       # should show /opt/homebrew/opt/llvm/bin/clang
which clang++     # should show /opt/homebrew/opt/llvm/bin/clang++
```

### Configure Environment Variables

Add the following to your `~/.zshrc` (or shell profile) to help the compiler and linker find headers and libraries:

```bash
# C++ standard library headers
export CPLUS_INCLUDE_PATH=/opt/homebrew/opt/llvm/include/c++/v1:$(xcrun --show-sdk-path)/usr/include

# Linker library path
export LIBRARY_PATH=$LIBRARY_PATH:$(xcrun --show-sdk-path)/usr/lib
```

Reload with:
```bash
source ~/.zshrc
```

### VS Code Extensions

Install from the VS Code Marketplace:

- **C/C++** (`ms-vscode.cpptools`): IntelliSense, debugging, code browsing.
- **CodeLLDB** (`vadimcn.vscode-lldb`): Native debugger support.

### User & Project Configuration

#### Default (User) Settings

Open **User Settings (JSON)** via `⇧⌘P` → **Preferences: Open User Settings (JSON)**, then verify/add:

```json
"C_Cpp.default.compilerPath": "/opt/homebrew/opt/llvm/bin/clang",
"C_Cpp.default.cStandard": "c23",
"C_Cpp.default.cppStandard": "c++23",
"C_Cpp.default.intelliSenseMode": "macos-clang-arm64",
"C_Cpp.default.includePath": [
    "${workspaceFolder}/**",
    "/opt/homebrew/opt/llvm/include/c++/v1",
    "$(xcrun --show-sdk-path)/usr/include"
]
```

#### Per-Project (`.vscode/c_cpp_properties.json`)

Trigger with `⇧⌘P` → **C/C++: Edit Configurations (JSON)**:

```json
{
  "configurations": [
    {
      "name": "macOS",
      "includePath": [
        "${workspaceFolder}/**",
        "/opt/homebrew/opt/llvm/include/c++/v1",
        "$(xcrun --show-sdk-path)/usr/include"
      ],
      "compilerPath": "/opt/homebrew/opt/llvm/bin/clang",
      "cStandard": "c23",
      "cppStandard": "c++23",
      "intelliSenseMode": "macos-clang-arm64"
    }
  ],
  "version": 4
}
```

### Build & Debug Tasks

Create `.vscode/tasks.json` with a build task:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Build Active File",
      "type": "cppbuild",
      "command": "/opt/homebrew/opt/llvm/bin/clang++",
      "args": [
        "-fcolor-diagnostics",
        "-fansi-escape-codes",
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "options": { "cwd": "${fileDirname}" },
      "problemMatcher": ["$gcc"],
      "group": { "kind": "build", "isDefault": true }
    }
  ]
}
```

Then configure debugging in `.vscode/launch.json` by selecting **CodeLLDB** in the Debug panel.

---

## Compilation & Usage

Compile manually in terminal:

```bash
# Stack manager
clang++ -std=c++23 stack_menu.cpp -o stack_menu
./stack_menu

# Queue manager
clang++ -std=c++23 queue_menu.cpp -o queue_menu
./queue_menu
```

Or use the **Build Active File** task in VS Code (`⇧⌘B`).

---

## Project Structure

```
├── stack_menu.cpp      # Stack operations menu
├── queue_menu.cpp      # Queue operations menu
├── README.md           # This file
└── .vscode/            # VS Code settings & tasks
```

---

## Contributing

1. Fork the repo
2. Create a feature branch (`git checkout -b feature/XYZ`)
3. Commit your changes (`git commit -m "Add ..."`)
4. Push (`git push origin feature/XYZ`)
5. Open a Pull Request

---

## License

This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.

---

