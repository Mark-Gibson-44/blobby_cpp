include_directories(include)

set(HEADERS 
    include/Field.h 
    include/Entity.h 
    include/Player.h 
    )

file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(YourExecutable ${SOURCES})

# Add subdirectories
add_subdirectory(include)
add_subdirectory(src)


add_subdirectory(tests)

