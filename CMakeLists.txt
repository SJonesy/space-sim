cmake_minimum_required(VERSION 3.25)
project(space-sim)

file(GLOB_RECURSE binary_SOURCES src/*.cpp)

############################################################
# Add clang-tidy make target
############################################################
find_program(CLANG_TIDY_EXE NAMES "clang-tidy" "clang-tidy-7" "clang-tidy-8" "clang-tidy-9")

if(CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    add_custom_target(
        clang-tidy
        COMMAND ${CLANG_TIDY_EXE} --checks='-*,clang-diagnostic-*,-clang-diagnostic-unused-value,clang-analyzer-*,-*,bugprone-*,performance-*,readability-*,-readability-magic-numbers,-readability-braces-around-statements,-readability-inconsistent-declaration-parameter-name,-readability-named-parameter' ${binary_SOURCES}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running clang-tidy on your code..."
        VERBATIM
    )
else()
    message(FATAL_ERROR "clang-tidy executable not found. Please install clang-tidy and make sure it is in your PATH.")
endif()

############################################################
# Create flecs target
############################################################
file(GLOB_RECURSE flecs_SOURCES third-party/flecs/*)
add_library(flecs ${flecs_SOURCES})
target_include_directories(flecs SYSTEM PRIVATE "third-party/flecs/")

############################################################
# Create space-sim executable target
############################################################
add_executable(space-sim ${binary_SOURCES})
set_target_properties(space-sim PROPERTIES COMPILE_FLAGS "-save-temps")
target_include_directories(space-sim SYSTEM PRIVATE "third-party/flecs/")
target_link_libraries(space-sim flecs)
add_dependencies(space-sim flecs)
