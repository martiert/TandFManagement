include_directories(include)

include_directories("${gtest_SOURCE_DIR}/include")
include_directories("${TandFManager_SOURCE_DIR}/include")
include_directories("include")

set(src
    src/competition_tests.cpp
    )

add_executable(tfmtests ${src})
target_link_libraries(tfmtests gtest gtest_main tfm)

add_test(tfmtests ${CMAKE_BINARY_DIR}/bin/tfmtests)
