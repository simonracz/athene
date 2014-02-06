cmake_minimum_required(VERSION 2.8)
project(ATHENE)

option(ATHENE_BUILD_TESTS "Build the unit tests." ON)

if (${CMAKE_CXX_COMPILER_ID} MATCHES GNU)
  include(CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG(-std=c++11 HAVE_STD11)
  if (HAVE_STD11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  else ()
    message(FATAL_ERROR "No advanced standard C++ support (-std=c++11 not defined).")
  endif ()
elseif (${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
  include(CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG(-std=c++11 HAVE_STD11)
  if (HAVE_STD11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
    set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -stdlib=libc++")
  else ()
    message(FATAL_ERROR "No C++11 support for Clang version. Please upgrade Clang to a version supporting C++11.")
  endif ()
  add_definitions(
  -DASIO_HAS_MOVE -DASIO_HAS_VARIADIC_TEMPLATES -DASIO_HAS_STD_SYSTEM_ERROR
  -DASIO_ERROR_CATEGORY_NOEXCEPT=noexcept -DASIO_HAS_STD_ARRAY
  -DASIO_HAS_STD_SHARED_PTR -DASIO_HAS_STD_ATOMIC -DASIO_HAS_STD_CHRONO
  -DASIO_HASSTD_ADDRESSOFF -DASIO_HAS_STD_FUNCTION -DASIO_HAS_STD_TYPE_TRAITS)
endif ()

message(STATUS "C++ Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Flags: ${CMAKE_CXX_FLAGS} linker flags: ${CMAKE_CXX_LINK_FLAGS}")

if (ATHENE_BUILD_TESTS)
  enable_testing()
  add_subdirectory(deps/gtest)
  set(GTEST_ROOT ${ATHENE_SOURCE_DIR}/deps/gtest)
  set(GTEST_FOUND ON)
  set(GTEST_INCLUDE_DIRS ${GTEST_ROOT}/include)
  set(GTEST_LIBRARY gtest)
  set(GTEST_MAIN_LIBRARY gtest_main)
  set(GTEST_BOTH_LIBRARIES ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
endif()

add_subdirectory(sorting)
add_subdirectory(trees)
add_subdirectory(graphs)
add_subdirectory(linux)
