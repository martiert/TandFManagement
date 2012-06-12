project(tfm)

# include own directories
include_directories(include ${CMAKE_CURRENT_BINARY_DIR}/include)

set(src
    src/competitionmanager.cpp
  )

add_library(tfm SHARED ${src})

add_subdirectory(tests)
