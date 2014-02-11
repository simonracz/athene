set(MATH_HEADERS basic_math.hpp prime_numbers.hpp)

get_filename_component(DIRNAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

add_custom_target(${DIRNAME} SOURCES ${MATH_HEADERS})

if (ATHENE_BUILD_TESTS)
  add_subdirectory(test)
endif()
