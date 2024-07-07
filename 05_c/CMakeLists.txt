cmake_minimum_required(VERSION 3.20)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(c)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

## Comment in the following line to compile with flag -D FAST_ADC
# add_compile_definitions("FAST_ADC")

add_library(common OBJECT
    src/pic32_registers.c
    src/pic32_registers.h
    src/registers.c
    src/registers.h
    src/strings.c
    src/strings.h
)

# Executable
add_executable(tasks
    $<TARGET_OBJECTS:common>
    src/main.c
)

# Fetch Catch2
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.2
)
FetchContent_MakeAvailable(Catch2)

# Build Tests
enable_testing()
add_executable(tests
    $<TARGET_OBJECTS:common>
    src/registers.test.cpp
    src/strings.test.cpp
    src/util.strings.test.cpp
    src/util.strings.test.cpp
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src/)

# Register Tests
add_test(tests ./tests)
set_property(TEST tests PROPERTY ENVIRONMENT "CTEST_OUTPUT_ON_FAILURE=1")
