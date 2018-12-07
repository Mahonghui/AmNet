aux_source_directory(. EXAMPLE_SRC_LIST)

foreach(EXAMPLE_SRC ${EXAMPLE_SRC_LIST})
    # xx.cpp --> xx
    string(REGEX REPLACE "\\./|\\.c[a-zA-Z0-9_]*$" "" EXAMPLE_EXE_NAME ${EXAMPLE_SRC})
    # 生成可执行文件
    add_executable(${EXAMPLE_EXE_NAME} ${EXAMPLE_SRC})
    # 链接到动态库
    target_link_libraries(${EXAMPLE_EXE_NAME} ${CMAKE_PROJECT_NAME}_shared)
endforeach()