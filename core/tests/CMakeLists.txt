include_directories(include)

include_directories("${gtest_SOURCE_DIR}/include")
include_directories("${TandFManager_SOURCE_DIR}/include")
include_directories("include")

set(src
    src/competition_tests.cpp
    )

add_executable(managertests ${src})
target_link_libraries(managertests gtest gtest_main TandFManager)

add_test(managertests ${CMAKE_BINARY_DIR}/bin/managertests)
