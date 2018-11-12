cmake_minimum_required(VERSION 3.11)
project(tao_json_example VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(taojson
  GIT_REPOSITORY https://github.com/taocpp/json
  GIT_SHALLOW TRUE
)

FetchContent_GetProperties(taojson)
if(NOT taojson_POPULATED)
  FetchContent_Populate(taojson)
  add_library(json INTERFACE)
  target_include_directories(json INTERFACE ${taojson_SOURCE_DIR}/include)
endif()

add_executable(ex1 ex1.cc)
target_link_libraries(ex1 json)

