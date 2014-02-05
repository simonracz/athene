cmake_minimum_required (VERSION 2.8)
project(athene)

option( ATHENE_BUILD_TESTS “Build the unit tests.” ON )

if(ATHENE_BUILD_TESTS)
  enable_testing()
  add_subdirectory(deps/gtest)
  set(GTEST_ROOT ${ATHENE_SOURCE_DIR}/deps/gtest)
  set(GTEST_INCLUDE_DIRS ${GTEST_ROOT}/include)
  set(GTEST_LIBRARY gtest)
  set(GTEST_MAIN_LIBRARY gtest_main)
  set(GTEST_BOTH_LIBRARIES ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
endif()

add_subdirectory(sorting)
add_subdirectory(trees)
add_subdirectory(graphs)
add_subdirectory(linux)

