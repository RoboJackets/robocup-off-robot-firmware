cmake_minimum_required(VERSION 3.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/mtrain/cmake/mtrain-toolchain.cmake)

project(
    mtrain-off-robot
    LANGUAGES ASM C CXX
)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/bin/mtrain" CACHE PATH "")
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib/mtrain" CACHE PATH "")
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib/mtrain" CACHE PATH "")

add_subdirectory(mtrain)

add_subdirectory(projects/template)
# add_subdirectory(projects/whatever)
