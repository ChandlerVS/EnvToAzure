include(FetchContent)

cmake_minimum_required(VERSION 3.17)
project(EnvToAzure)

set(CMAKE_CXX_STANDARD 14)

add_executable(EnvToAzure main.cpp)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

target_link_libraries(EnvToAzure PRIVATE nlohmann_json::nlohmann_json)
