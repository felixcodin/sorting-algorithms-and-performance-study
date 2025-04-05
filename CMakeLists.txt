cmake_minimum_required(VERSION 3.16)

# Project name
project(BTL_Sort)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB_RECURSE SRC_FILES
    "src/sorting/*.cpp"
    "src/utils/*.cpp"
    "main.cpp"
)

add_executable(BTL_Sort main.cpp ${SRC_FILES})

if(TEST_FILES AND TEST_FILES)
    add_executable(SortTests ${TEST_FILES} ${SRC_FILES})
endif()