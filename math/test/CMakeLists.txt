include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${ATHENE_SOURCE_DIR}/math)

set(TESTS basic_math_test prime_numbers_test)

foreach (test ${TESTS})
  add_executable(math-${test} ${test}.cpp)
  target_link_libraries(math-${test} ${GTEST_BOTH_LIBRARIES})
  set_target_properties(math-${test}
      PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${ATHENE_BINARY_DIR}/tests)
  add_test(math-${test} ${ATHENE_BINARY_DIR}/tests/math-${test})
endforeach (test)
