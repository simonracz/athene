set(SORTING_HEADERS bubble_sort.hpp insertion_sort.hpp)

get_filename_component(DIRNAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

add_custom_target(${DIRNAME} SOURCES ${SORTING_HEADERS})

if (ATHENE_BUILD_TESTS)
  add_subdirectory(test)
endif()
