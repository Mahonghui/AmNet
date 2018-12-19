cmake_minimum_required(VERSION 3.10)
project(AmNet)
set(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# 设置编译器

set(CMAKE_CXX_COMPILER "g++")
# 开启所有警告
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
# 不优化，打开调试信息和gdb
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")

# 编译Release版本时，打开高级优化
set(CMAKE_CXX_FLAGS_RELEASE "-03")

# 打印编译类型
message(STATUS "BUILD_TYPE: " ${CMAKE_BUILD_TYPE})
string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
# 打印编译选项
message(STATUS "CXXFLAGS: " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})


# 指定库的输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# 指定库的可执行文件位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# 设置库和头文件的路径
set(INSTALL_PATH_LIB lib)
set(INSTALL_PATH_INCLUDE include)

# src下的源码列表
set(SRC_DIR "base" "http" "log" "net")


foreach(SUB_DIR ${SRC_DIR})
        # 设置搜索目录路径
        include_directories(${PROJECT_SOURCE_DIR}/src/${SUB_DIR})
        # 读取源文件
        aux_source_directory(src/${SUB_DIR} SUB_LIST)
        #将所有头文件安装(复制)到CMAKE_INSTALL_PREFIX/INSTALL_PATH_INCLUDE
        # make install时起作用
        install(DIRECTORY src/${SUB_DIR}/ DESTINATION ${INSTALL_PATH_INCLUDE} FILES_MATCHING PATTERN "*.h")
endforeach()

# 打包源文件至动态库
add_library(${CMAKE_PROJECT_NAME}_shared SHARED ${SUB_LIST} src/net/epollor.h src/net/epollor.cpp src/base/timestamp.h src/base/util.h src/base/util.cpp src/log/logbuf.h src/log/logbuf.cpp src/log/logger.h src/log/logger.cpp src/log/asynclogger.h src/log/util.h src/log/util.cpp src/log/logfile.h src/log/logfile.cpp src/log/asynclogger.cpp src/net/iobuffer.h src/net/iobuffer.cpp src/net/timer.h src/net/loop.h src/net/timerqueue.h src/net/timerqueue.cpp src/net/loop.cpp src/net/loopthread.h src/net/loopthread.cpp src/base/anyone.h src/net/connection.h src/net/connection.cpp src/net/threadpool.h src/net/threadpool.cpp src/net/server.h src/net/server.cpp src/http/httprequest.h src/http/httpresponse.h src/http/httpresponse.cpp src/http/httpparser.h src/http/httpparser.cpp src/http/filehandler.h src/http/filestat.h src/http/filestat.cpp src/http/filehandler.cpp src/http/matcher.h src/http/matcher.cpp src/http/route.h src/http/router.cpp src/http/router.h src/http/route.cpp src/http/httpserver.h src/http/httpserver.cpp)
# 链接用到的库
target_link_libraries(${CMAKE_PROJECT_NAME}_shared pthread)
# 修改动态库的名称
set_target_properties(${CMAKE_PROJECT_NAME}_shared PROPERTIES OUTPUT_NAME "${CMAKE_PROJECT_NAME}")
# make install
install(TARGETS ${CMAKE_PROJECT_NAME}_shared ARCHIVE DESTINATION ${INSTALL_PATH_LIB} LIBRARY DESTINATION ${INSTALL_PATH_LIB})

# 打包源文件至静态库
add_library(${CMAKE_PROJECT_NAME}_static STATIC ${SUB_LIST})
# 链接用到的库
target_link_libraries(${CMAKE_PROJECT_NAME}_shared pthread)
# 修改静态库名称
set_target_properties(${CMAKE_PROJECT_NAME}_static PROPERTIES OUTPUT_NAME "${CMAKE_PROJECT_NAME}")
# make install
install(TARGETS ${CMAKE_PROJECT_NAME}_static ARCHIVE DESTINATION ${INSTALL_PATH_LIB})

# 添加子目录
add_subdirectory(example)

