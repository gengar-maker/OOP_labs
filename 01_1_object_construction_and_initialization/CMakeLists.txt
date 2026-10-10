cmake_minimum_required(VERSION 3.21)

project(Lab011ObjectInitialization VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

option(LAB011_ENABLE_WARNINGS "Enable strict compiler warnings" ON)
option(LAB011_ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

add_library(lab011_project_options INTERFACE)
target_compile_features(lab011_project_options INTERFACE cxx_std_20)

if(LAB011_ENABLE_WARNINGS)
    if(MSVC)
        target_compile_options(lab011_project_options INTERFACE /W4 /permissive-)
    else()
        target_compile_options(lab011_project_options INTERFACE
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
            -Wshadow
        )
    endif()
endif()

if(LAB011_ENABLE_SANITIZERS)
    if(MSVC)
        message(WARNING "The sanitizers preset is intended for Clang or GCC")
    else()
        target_compile_options(lab011_project_options INTERFACE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
        )
        target_link_options(lab011_project_options INTERFACE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
        )
    endif()
endif()

function(add_lab011_executable target_name source_file)
    add_executable(${target_name} ${source_file})
    target_link_libraries(${target_name} PRIVATE lab011_project_options)
    if(BUILD_TESTING)
        add_test(NAME ${target_name} COMMAND ${target_name})
    endif()
endfunction()

include(CTest)
add_subdirectory(steps)
add_subdirectory(tasks)
add_subdirectory(solutions)
