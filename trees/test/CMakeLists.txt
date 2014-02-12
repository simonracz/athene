include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${ATHENE_SOURCE_DIR}/trees)

set(TESTS heaps_test)

foreach (test ${TESTS})
  add_executable(heaps-${test} ${test}.cpp)
  target_link_libraries(heaps-${test} ${GTEST_BOTH_LIBRARIES})
  set_target_properties(heaps-${test}
      PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${ATHENE_BINARY_DIR}/tests)
  add_test(heaps-${test} ${ATHENE_BINARY_DIR}/tests/heaps-${test})
endforeach (test)
