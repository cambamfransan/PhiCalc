cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR} CACHE PATH
  "Locaction for installation"
  FORCE)
project (CalcPhi)
set(exe_name CalcPhi)
set (CMAKE_CXX_STANDARD 11)

set(${exe_name}_srcs
  ComputePhi.hpp
  ComputePhi.cpp
  main.cpp
  )
  
source_group("" FILES ${${exe_name}_srcs})

add_executable(${exe_name}.exe ${${exe_name}_srcs})
install(TARGETS ${exe_name}.exe DESTINATION bin)
