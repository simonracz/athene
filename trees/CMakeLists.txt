set(TREES_HEADERS heaps.hpp)

get_filename_component(DIRNAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

add_custom_target(${DIRNAME} SOURCES ${TREES_HEADERS})

if (ATHENE_BUILD_TESTS)
  add_subdirectory(test)
endif()
