cmake_minimum_required(VERSION 2.8)
add_library(myffi SHARED
  ffi.cpp
  )
set_target_properties(myffi PROPERTIES PREFIX "")
