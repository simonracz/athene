include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${ATHENE_SOURCE_DIR}/sorting)
include_directories(${ATHENE_SOURCE_DIR}/trees)

set(TESTS bubble_test insertion_test
          merge_test heap_test quick_test)

foreach (test ${TESTS})
  add_executable(sorting-${test} ${test}.cpp)
  target_link_libraries(sorting-${test} ${GTEST_BOTH_LIBRARIES})
  set_target_properties(sorting-${test}
      PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${ATHENE_BINARY_DIR}/tests)
  add_test(sorting-${test} ${ATHENE_BINARY_DIR}/tests/sorting-${test})
endforeach (test)
