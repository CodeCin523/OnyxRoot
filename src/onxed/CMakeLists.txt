add_executable(
    onxed
    main.cc
)
add_executable(OnyxRoot::OnyxEdit ALIAS onxed)

target_link_libraries(
    onxed PUBLIC
    OnyxRoot::OnyxRoot
)