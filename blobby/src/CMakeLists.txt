# This CMakeLists.txt is for configuring source files

# Glob all the source files in the src directory
file(GLOB SOURCE_FILES "*.cpp")

# Add the source files to the project's executable
target_sources(YourExecutable PRIVATE ${SOURCE_FILES})