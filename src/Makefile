CC = gcc
# 包目录，库所在的目录
INCLUDE_PATH = D:\DataBase_SHke_dev\Clang\data_structures_in_c\pkgs\LinkList

# 获取 INCLUDE_PATH 目录下的  *.cpp 文件
# 同时剔除 demo.cpp
SRC = $(filter-out $(INCLUDE_PATH)/demo.cpp, $(wildcard $(INCLUDE_PATH)/*.cpp))

ALL: main

# ToDo: 提升每次 构建效率，先把 LinkList 编译，再与main.cpp 链接

# 编译 main.cpp 源文件「同时加入 LinkList 单链表的依赖」
main: $(SRC)
# 在其他目录下编译需要复制 LinkList.h 文件
# LinkList.h 与 main.cpp 文件应在同一目录下
	@copy $(INCLUDE_PATH)\LinkList.h LinkList.h

# 编译 main.cpp
	$(CC) -o main.exe main.cpp $(SRC)
	echo $(SRC)

.PHONY:clean
clean:
# 	@del -rf main.exe

	@del -rf main.exe, LinkList.h
	@echo cleaned workspace