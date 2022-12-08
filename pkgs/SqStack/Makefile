CC = gcc
# 包目录，库所在的目录
INCLUDE_PATH = D:\DataBase_SHke_dev\Clang\data_structures_in_c\pkgs\SqStack
# 编译器选项 控制台 gbk 编码
CFLAGS = -fexec-charset=GBK

# 获取 INCLUDE_PATH 目录下的  *.cpp 文件
# 同时剔除 demo.cpp
SRC = $(filter-out $(INCLUDE_PATH)/demo.cpp, $(wildcard $(INCLUDE_PATH)/*.cpp))

ALL: main

# 编译 main.cpp 源文件「同时加入 SqStack 依赖」
main: $(SRC)
# 在其他目录下编译需要复制 SqStack.h 文件
# SqStack.h 与 main.cpp 文件应在同一目录下
#	@copy $(INCLUDE_PATH)\SqStack.h SqStack.h

# 以 demo.cpp 编译为例
	$(CC) -o main.exe demo.cpp $(SRC) $(CFLAGS)
	echo $(SRC)

.PHONY:clean
clean:
# 	@del -rf main.exe, SqStack.h

	@del -rf main.exe
	@echo cleaned workspace