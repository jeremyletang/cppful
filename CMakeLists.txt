cmake_minimum_required (VERSION 2.8.1)

if(POLICY CMP0042)
cmake_policy(SET CMP0042 NEW)
endif()

include_directories (include)

project (cppful CXX)

file (GLOB headers "*.h")
file (GLOB sources "*.cpp")

set (DIRS "src")

foreach (dir ${DIRS})
   file (GLOB h_${dir} "${dir}/*.h")
   file (GLOB s_${dir} "${dir}/*.cpp")
   source_group (${dir} FILES ${s_${dir}} ${h_${dir}})
   set (sources ${sources} ${s_${dir}})
   set (header ${headers} ${h_${dir}})
endforeach ()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -g")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++1y")
endif()

add_library (cppful SHARED ${sources})
add_executable (simple_server examples/main.cpp)

target_link_libraries (simple_server cppful)

set_target_properties(simple_server
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/target"
)