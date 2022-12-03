CC = gcc
# 包目录，库所在的目录
INCLUDE_PATH = D:/DataBase_SHke_dev/Clang/data_structures_in_c/pkgs/LinkList
# 当前工作目录
WS_PATH = D:/DataBase_SHke_dev/Clang/data_structures_in_c/src

# 获取 INCLUDE_PATH 目录下的  *.cpp 文件
SRC = $(wildcard $(INCLUDE_PATH)/*.cpp)

ALL: main

# ToDo: 提升每次 构建效率，先把 LinkList 编译，再与main.cpp 链接

# 编译 main.cpp 源文件「同时加入 LinkList 单链表的依赖」
main: $(SRC)
	$(CC) -o $(WS_PATH)/main.exe $(WS_PATH)/main.cpp $(SRC)

.PHONY:clean
clean:
	@del -f $(WS_PATH)/main.exe
	@echo cleaned workspace