#! /bin/bash

# 显示指令
set -x
# 删除上次编译的文件
rm -rf ./build
#新建一个目录，进入该目录
mkdir build
cd build
# -D 选项编译DEBUG版本
cmake -DCMAKE_BUILD_TYPE=Debug ..
# 执行makefile
make
#安装lib和bin到系统目录
sudo make install


