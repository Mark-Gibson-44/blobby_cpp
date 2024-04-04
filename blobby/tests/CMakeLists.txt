Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

project(
  ${CMAKE_PROJECT_NAME}Tests
  LANGUAGES CXX
)

INCLUDE_DIRECTORIES("${BASEPATH}")



# Add all .cpp files in the src directory to the SOURCES variable
file(GLOB TEST_SOURCES "*.cpp")

file(GLOB SRC_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

#add_executable(YourTestExecutable ${TEST_SOURCES})

add_executable(YourTestExecutable test.cpp ${TEST_SOURCES} ${SRC_SOURCES})
target_link_libraries(YourTestExecutable Test_LIB Catch2::Catch2WithMain YourLibrary)

#target_link_libraries(YourTestExecutable PRIVATE Catch2::Catch2WithMain)