cmake_minimum_required(VERSION 3.17)
project(companion_db)

set(CMAKE_CXX_STANDARD 20)

include_directories("include")
# TODO: Figure out how to do this properly
include_directories(/home/matt/Workspace/vcpkg/installed/x64-linux/include)
link_directories(/home/matt/Workspace/vcpkg/installed/x64-linux/lib)

add_library(companion_ingest SHARED
        "src/ingest/ingest_controller.cpp")
target_include_directories(companion_ingest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(companion_db src/main.cpp)
target_link_libraries(companion_db LINK_PUBLIC fmt)
target_link_libraries(companion_db LINK_PUBLIC companion_ingest)
