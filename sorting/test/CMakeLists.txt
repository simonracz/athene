enable_testing()

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${ATHENE_SOURCE_DIR}/sorting)

set(TESTS bubble_test)
#set(TESTS bubble_test quicksort_test merge_sort_test)

foreach (test ${TESTS})
  add_executable(sorting-${test} ${test}.cpp)
  target_link_libraries(${GTEST_BOTH_LIBRARIES})
  #set_target_properties(sorting-${test} 
  #    PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${ATHENE_BINARY_DIR}/tests)
  add_test(sorting-${test}) ${ATHENE_BINARY_DIR}/tests/sorting-${test})
endforeach (test)

