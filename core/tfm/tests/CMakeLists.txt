include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/cpputest/include)

set(src
    src/competition_tests.cpp
    src/main.cpp
    )

add_executable(tfmtests ${src})
target_link_libraries(tfmtests CppUTest tfm)
add_test(tfmtests ${CMAKE_CURRENT_BINARY_DIR}/tfmtests)
