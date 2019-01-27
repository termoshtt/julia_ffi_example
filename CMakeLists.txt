add_library(myffi SHARED
  ffi.cpp
  )
set_target_properties(myffi PROPERTIES PREFIX "")
