cmake_minimum_required(VERSION 3.21)

project(Lab01ClassesAndObjects VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

option(LAB01_ENABLE_WARNINGS "Enable strict compiler warnings" ON)
option(LAB01_ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

add_library(lab01_project_options INTERFACE)
target_compile_features(lab01_project_options INTERFACE cxx_std_17)

if(LAB01_ENABLE_WARNINGS)
    if(MSVC)
        target_compile_options(lab01_project_options INTERFACE
            /W4
            /permissive-
        )
    else()
        target_compile_options(lab01_project_options INTERFACE
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
            -Wshadow
        )
    endif()
endif()

if(LAB01_ENABLE_SANITIZERS)
    if(MSVC)
        message(WARNING "The sanitizers preset is intended for Clang or GCC")
    else()
        target_compile_options(lab01_project_options INTERFACE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
        )
        target_link_options(lab01_project_options INTERFACE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
        )
    endif()
endif()

function(add_lab01_executable target_name)
    add_executable(${target_name} ${ARGN})
    target_link_libraries(${target_name} PRIVATE lab01_project_options)
endfunction()

include(CTest)
add_subdirectory(steps)
