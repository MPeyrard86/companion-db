cmake_minimum_required(VERSION 3.17)
project(companion_db)

set(CMAKE_CXX_STANDARD 20)

include_directories("include")

add_library(companion_ingest SHARED
        "src/ingest/ingest_controller.cpp")
target_include_directories(companion_ingest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(companion_db src/main.cpp)
target_link_libraries(companion_db LINK_PUBLIC companion_ingest)
