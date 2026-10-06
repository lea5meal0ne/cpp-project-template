cmake_minimum_required(VERSION 3.25)

project(
    cpp_project
    VERSION 0.1.0
    DESCRIPTION "Modern C++ project"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTING "Build tests" ON)

# Dependencies
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# Core library
add_library(project_core
    src/example.cpp
)

target_include_directories(project_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(project_core
    PUBLIC
        cxx_std_20
)

if(MSVC)
    target_compile_options(project_core PRIVATE /W4 /permissive-)
else()
    target_compile_options(project_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Application
add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        project_core
        fmt::fmt
        spdlog::spdlog
)

# Tests
if(BUILD_TESTING)
    enable_testing()

    find_package(GTest CONFIG REQUIRED)

    add_executable(project_tests
        tests/example_test.cpp
    )

    target_link_libraries(project_tests
        PRIVATE
            project_core
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(project_tests)
endif()
