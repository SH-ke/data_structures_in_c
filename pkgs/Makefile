CC = gcc
INCLUDE_PATH = E:/data_structures_in_c/_pkg_test_/LinkList
targ_file = main.exe

# 获取 INCLUDE_PATH 目录下的  *.cpp 文件
SRC = $(wildcard $(INCLUDE_PATH)/*.cpp)

ALL: main

# ToDo: 提升每次 构建效率，先把 LinkList 编译，再与main.cpp 链接

# 编译 main.cpp 源文件「同时加入 LinkList 单链表的依赖」
main: $(SRC)
	$(CC) -o $(targ_file) main.cpp $(SRC)

.PHONY:clean
clean:
	@del -f $(targ_file)
	@echo cleaned workspace