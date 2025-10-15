add_library(
    onxrt
    onx_lib.cc
)
add_library(OnyxRoot::OnyxRoot ALIAS onxrt)

target_include_directories(
    onxrt PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
