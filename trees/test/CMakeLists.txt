include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${ATHENE_SOURCE_DIR}/trees)

set(TESTS heap_test avl_test)

foreach (test ${TESTS})
  add_executable(tree-${test} ${test}.cpp)
  target_link_libraries(tree-${test} ${GTEST_BOTH_LIBRARIES})
  set_target_properties(tree-${test}
      PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${ATHENE_BINARY_DIR}/tests)
  add_test(tree-${test} ${ATHENE_BINARY_DIR}/tests/tree-${test})
endforeach (test)
