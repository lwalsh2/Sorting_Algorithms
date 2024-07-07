cmake_minimum_required(VERSION 3.22)
project(
    Sorting_Algorithms
    LANGUAGES "C"
    DESCRIPTION "C-based sorting algorithm project"
)

if (DEBUG EQUAL "1")
    message("DEBUGGING VERSION")
    add_compile_definitions(DEBUG)
else()
    message("RELEASE VERSION")
endif()

include_directories(include)
add_subdirectory(src)
