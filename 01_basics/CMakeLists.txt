cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Complex)

include_directories(
        ${CMAKE_SOURCE_DIR}/src
)

add_library(common OBJECT
       src/Complex.cpp
       src/Complex.hpp
        src/Complex.cpp
        src/Complex.hpp
)

# Executable
add_executable(tasks
        $<TARGET_OBJECTS:common>
        src/main.cpp
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
        src/Complex_public.test.cpp
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src/)

# Register Tests
add_test(tests ./tests)
set_property(TEST tests PROPERTY ENVIRONMENT "CTEST_OUTPUT_ON_FAILURE=1")
