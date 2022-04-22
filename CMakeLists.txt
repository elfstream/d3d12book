cmake_minimum_required(VERSION 3.14)

project(my_tests)
set(CMAKE_CXX_STANDARD 11)

# 路径定论
set (COMMON_PATH ${CMAKE_SOURCE_DIR}/Common)
set (CLIENT_TESTS_PATH ${CMAKE_SOURCE_DIR}/ClientTests)

# 头文件引入 使全局可见
include_directories(
    ${COMMON_PATH}/
	)
	
# 添加依赖
add_subdirectory(ClientTests)