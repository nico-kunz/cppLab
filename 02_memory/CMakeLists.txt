cmake_minimum_required(VERSION 3.20)
project(memory LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(memory
        src/main.cpp
        src/Colony.cpp
        src/Colony.hpp
        src/GameOfLife.cpp
        src/GameOfLife.hpp
        src/Visualizer.cpp
        src/Visualizer.hpp
)

target_link_libraries(memory PRIVATE sfml-graphics)
target_compile_features(memory PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET memory
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:memory>
            VERBATIM)
endif()

install(TARGETS memory)

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
        src/Colony.cpp
        src/Colony.hpp
        src/Colony.test.cpp
        src/GameOfLife.cpp
        src/GameOfLife.hpp
        src/GameOfLife.test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src/)

# Register Tests
add_test(tests ./tests)
set_property(TEST tests PROPERTY ENVIRONMENT "CTEST_OUTPUT_ON_FAILURE=1")
