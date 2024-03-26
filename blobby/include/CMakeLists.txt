# This CMakeLists.txt is for configuring header files

# Glob all the header files in the include directory
file(GLOB HEADER_FILES "*.h")

# Add the header files to the project's include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
