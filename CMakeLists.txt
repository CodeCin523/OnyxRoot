cmake_minimum_required(VERSION 3.28)
message(STATUS "  [START] OnyxRoot project setup")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
    OnyxRoot
    LANGUAGES CXX
)


# OnyxRoot (lib)
message(STATUS "    [START] OnyxRoot library setup")
add_subdirectory(src/onxrt onxrt)
# OnyxEdit (app)
message(STATUS "    [START] OnyxEdit application setup")
add_subdirectory(src/onxed onxed)

message(STATUS "  [end] OnyxRoot project setup")