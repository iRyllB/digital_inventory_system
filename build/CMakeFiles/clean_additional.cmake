# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\digital_inventory_system_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\digital_inventory_system_autogen.dir\\ParseCache.txt"
  "digital_inventory_system_autogen"
  )
endif()
