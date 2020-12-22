project(
    template
    LANGUAGES ASM C CXX
)


add_executable(main.elf
    src/main.cpp
    )

# Makes it so each of the off robot firmware projects build into /bin/PROJECT_NAME as given above (so this one would be /build/bin/template)
set_target_properties( main.elf
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${PROJECT_NAME}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${PROJECT_NAME}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}"
)

target_include_directories(main.elf PUBLIC
    include
)

target_link_libraries(main.elf
    mtrain
)

add_custom_target(main ALL
    arm-none-eabi-objcopy -Obinary "main.elf" "main.bin"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}"
    DEPENDS main.elf
    COMMENT "objcopying to make binary executable for control"
)
