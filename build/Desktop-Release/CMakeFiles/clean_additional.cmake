# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/LearnFlow_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/LearnFlow_autogen.dir/ParseCache.txt"
  "LearnFlow_autogen"
  )
endif()
