cmake_minimum_required(VERSION 3.28)
message(STATUS "[START] OnyxRoot project setup")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT DEFINED onxrt)
    set(onxrt ON)
endif()
if(NOT DEFINED onxed)
    set(onxed ON)
endif()
if(NOT DEFINED onxtt)
    set(onxtt OFF)
endif()

project(
    OnyxRoot
    LANGUAGES CXX
)

# OnyxRoot (lib)
if(onxrt)
    message(STATUS "  [START] OnyxRoot library setup")
    add_subdirectory(src/onxrt onxrt)
endif()
# OnyxEdit (app)
if(onxed)
    message(STATUS "  [START] OnyxEdit application setup")
    add_subdirectory(src/onxed onxed)
endif()
# OnyxTest (apps)
if(onxtt)
    message(STATUS "  [START] OnyxEdit application setup")
    add_subdirectory(test onxtt)
endif()

message(STATUS "[END] OnyxRoot project setup")