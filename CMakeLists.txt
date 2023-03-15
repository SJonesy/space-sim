cmake_minimum_required(VERSION 3.25)
project(space-sim)

############################################################
# Create a library
############################################################
# Source files to be used in the library
set(library_SOURCES
    src/flecs.c
)

#Generate the static library from the library sources
add_library(flecs STATIC ${library_SOURCES})

target_include_directories(flecs
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create an executable
############################################################
# Source fles for the binary
set(binary_SOURCES
    src/main.cpp
)

# Add an executable with the above sources
add_executable(space-sim ${binary_SOURCES})

# link the new hello_library target with the hello_binary target
target_link_libraries( space-sim
    PRIVATE flecs
)

