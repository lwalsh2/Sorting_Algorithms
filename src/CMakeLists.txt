cmake_minimum_required(VERSION 3.22)

# Set thread requirements for Ubuntu 20.04
# (Automatically included in 22.04)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Compiles passed struct with corresponding source code
function(compile_struct struct_type struct_src)
    # Define / Create Executable binary
    add_executable(${struct_type} ${struct_src})

    # Add struct compilation flags / links
    target_compile_options(${struct_type} PRIVATE -Wall)
    set(TARGET ${struct_type} PROPERTY C_STANDARD 11)
    set(TARGET ${struct_type} PROPERTY C_STANDARD_REQUIRED ON)

    target_link_libraries(${struct_type} PRIVATE Threads::Threads)
endfunction()

# Call each algorithm to compile
compile_struct(bubble bubble.c)
compile_struct(heap heap.c)
compile_struct(merge merge.c)
compile_struct(quick-Hoare quick-Hoare.c)
compile_struct(tree tree.c)
