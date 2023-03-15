cmake_minimum_required(VERSION 3.25)
project(space-sim)

############################################################
# Add clang-tidy make target
############################################################
find_program(CLANG_TIDY_EXE NAMES "clang-tidy" "clang-tidy-7" "clang-tidy-8" "clang-tidy-9")

if(CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    add_custom_target(
        clang-tidy
        COMMAND ${CLANG_TIDY_EXE} --checks='-*,clang-diagnostic-*,-clang-diagnostic-unused-value,clang-analyzer-*,-*,bugprone-*,performance-*,readability-*,-readability-magic-numbers,-readability-braces-around-statements,-readability-inconsistent-declaration-parameter-name,-readability-named-parameter' ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        #    DEPENDS space-sim
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running clang-tidy on your code..."
        VERBATIM
    )
else()
    message(FATAL_ERROR "clang-tidy executable not found. Please install clang-tidy and make sure it is in your PATH.")
endif()


############################################################
# Create space-sim executable target
############################################################
set(binary_SOURCES 
    src/main.cpp
)

add_executable(space-sim ${binary_SOURCES})

