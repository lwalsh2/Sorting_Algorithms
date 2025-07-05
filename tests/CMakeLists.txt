# Call each algorithm test to compile
add_executable(bubble_test bubble_test.c)
add_executable(heap_test heap_test.c)
add_executable(merge_test merge_test.c)
add_executable(quick_test quick_test.c)
add_executable(tree_test tree_test.c)

# Link tests to their corresponding library
target_link_libraries(bubble_test bubble)
target_link_libraries(heap_test heap)
target_link_libraries(merge_test merge)
target_link_libraries(quick_test quick)
target_link_libraries(tree_test tree)
