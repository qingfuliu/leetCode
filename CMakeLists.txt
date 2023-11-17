cmake_minimum_required(VERSION 3.2)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


aux_source_directory(./src LEETCODE_SOURCE_CODE)

foreach(file IN LISTS LEETCODE_SOURCE_CODE)
    get_filename_component(fileName ${file} NAME)
    get_filename_component(fileFullName ${file} EXT)
    add_executable(${fileName} ${file})
endforeach()


