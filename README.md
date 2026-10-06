# Modern C++ Project Template

A reusable C++20 project template for modern C++ development with CMake, vcpkg, Clang, GoogleTest and GitHub Actions.

## Features

- C++20
- CMake
- CMake Presets
- Ninja
- vcpkg
- fmt
- spdlog
- GoogleTest
- clangd
- clang-format
- clang-tidy
- LLDB debugging
- VS Code configuration
- GitHub Actions CI
- macOS and Linux CI builds

## Requirements

- CMake 3.25+
- Ninja
- Git
- vcpkg
- C++20 compatible compiler

Set the `VCPKG_ROOT` environment variable:

```bash
export VCPKG_ROOT="$HOME/Developer/vcpkg"
```

## Build

### Debug

```bash
cmake --preset debug
cmake --build --preset debug
```

### Release

```bash
cmake --preset release
cmake --build --preset release
```

## Run

### Debug

```bash
./build/debug/cpp_project
```

### Release

```bash
./build/release/cpp_project
```

## Tests

Run the test suite with:

```bash
ctest --preset debug
```

## Project Structure

```text
.
├── .github/
│   └── workflows/
│       └── ci.yml
├── .vscode/
│   ├── extensions.json
│   ├── launch.json
│   └── tasks.json
├── include/
│   └── project/
│       └── example.hpp
├── src/
│   ├── example.cpp
│   └── main.cpp
├── tests/
│   └── example_test.cpp
├── .clang-format
├── .clang-tidy
├── .editorconfig
├── .gitignore
├── CMakeLists.txt
├── CMakePresets.json
├── LICENSE
├── README.md
└── vcpkg.json
```

## VS Code

The repository includes a ready-to-use VS Code configuration.

Recommended extensions:

- clangd
- CMake Tools
- CMake
- CodeLLDB
- Error Lens
- GitLens
- GitHub Pull Requests
- Todo Tree

### Build

The default Debug build task can be started with:

```text
⇧⌘B
```

or from the Command Palette:

```text
Tasks: Run Build Task
```

### Debug

Select:

```text
Debug Application
```

in the VS Code Run and Debug panel.

The debugger automatically builds the Debug configuration before launching the application.

## Code Quality

### clang-format

Source files are automatically formatted on save when using the included VS Code configuration.

The formatting rules are defined in:

```text
.clang-format
```

### clang-tidy

Static analysis is provided by clangd using:

```text
.clang-tidy
```

The configuration enables checks from:

- clang-analyzer
- bugprone
- performance
- modernize
- readability

## Dependencies

Dependencies are managed using vcpkg in manifest mode.

Current dependencies:

- fmt
- spdlog
- GoogleTest

They are declared in:

```text
vcpkg.json
```

When CMake configures the project, vcpkg automatically installs the required dependencies.

## CMake Presets

The project provides two CMake presets.

### Debug

```bash
cmake --preset debug
cmake --build --preset debug
```

Build directory:

```text
build/debug
```

Tests are enabled in this configuration.

### Release

```bash
cmake --preset release
cmake --build --preset release
```

Build directory:

```text
build/release
```

Tests are disabled in this configuration.

## Continuous Integration

GitHub Actions automatically builds and tests the project after pushes and pull requests.

CI currently runs on:

- Ubuntu
- macOS

The workflow performs:

1. Repository checkout
2. Ninja setup
3. vcpkg setup
4. CMake configuration
5. Debug build
6. Automated tests

The workflow is located at:

```text
.github/workflows/ci.yml
```

## Creating a New Project

This repository is intended to be used as a base for new modern C++ projects.

After creating a new repository from this template, update the project-specific names in:

- `CMakeLists.txt`
- `vcpkg.json`
- `.vscode/launch.json`
- `include/project/`
- source files
- tests

Then configure the project:

```bash
cmake --preset debug
```

Build it:

```bash
cmake --build --preset debug
```

Run the tests:

```bash
ctest --preset debug
```

## License

This project is licensed under the MIT License.

See the `LICENSE` file for details.
