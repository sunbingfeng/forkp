cmake_minimum_required(VERSION 3.0)
project(forkp_test)

set(CMAKE_CXX_STANDARD 11)

##################
### Target  ######
##################

add_library(forkp STATIC
  source/signal.cpp
  source/utils.cpp
)

target_include_directories(forkp PUBLIC
  include/
)

add_executable(forkp_test
  main.cpp
)

target_include_directories(forkp_test PUBLIC
  include/
)

target_link_libraries(forkp_test
  forkp
)

