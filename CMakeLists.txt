cmake_minimum_required(VERSION 3.0)
project(forkp_test)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED COMPONENTS system date_time thread)
add_library(boost INTERFACE)
target_include_directories(boost INTERFACE ${Boost_INCLUDE_DIRS})
target_link_libraries(boost INTERFACE ${Boost_LIBRARIES} pthread)
target_compile_options(boost INTERFACE "-Wno-deprecated-declarations;")

##################
### Target  ######
##################

add_library(forkp SHARED
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
  boost
  forkp
)

