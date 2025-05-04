cmake_minimum_required(VERSION 3.10)
project(MyInventoryApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add FLTK to your project
# If FLTK is inside a submodule or locally cloned, link to the path
add_subdirectory(external/fltk)

# Add your executable
add_executable(MyInventoryApp main.cpp)

# Link your executable to FLTK
target_link_libraries(MyInventoryApp fltk)

# Optional: Set the required include directories for FLTK
target_include_directories(MyInventoryApp PRIVATE external/fltk/include)
