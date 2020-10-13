cmake_minimum_required(VERSION "3.10")
# set the project name
project("shell")
set(EXECUTABLE_OUTPUT_PATH ../bin/)
file(GLOB SOURCES
        ./src/main.cpp
        ./src/shell/*.cpp
        ./src/command/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
install(TARGETS ${PROJECT_NAME} DESTINATION ./build/bin)
