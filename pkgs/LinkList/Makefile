CC = gcc
# 包目录，库所在的目录
INCLUDE_PATH = D:\DataBase_SHke_dev\Clang\data_structures_in_c\pkgs\LinkList
# 当前工作目录
WS_PATH = $(INCLUDE_PATH)

# 获取 INCLUDE_PATH 目录下的  *.cpp 文件
# 同时剔除 demo.cpp
SRC = $(filter-out $(INCLUDE_PATH)/demo.cpp, $(wildcard $(INCLUDE_PATH)/*.cpp))

ALL: main

# ToDo: 提升每次 构建效率，先把 LinkList 编译，再与main.cpp 链接

# 编译 main.cpp 源文件「同时加入 LinkList 单链表的依赖」
main: $(SRC)
# 在其他目录下编译需要复制 LinkList.h 文件
# LinkList.h 与 main.cpp 文件应在同一目录下
#	@copy $(INCLUDE_PATH)\LinkList.h $(WS_PATH)\LinkList.h

# 以 demo.cpp 编译为例
	$(CC) -o $(WS_PATH)\main.exe $(WS_PATH)\demo.cpp $(SRC)
	echo $(SRC)

.PHONY:clean
clean:
# 	@del -rf $(WS_PATH)\main.exe, $(WS_PATH)\LinkList.h

	@del -rf $(WS_PATH)\main.exe
	@echo cleaned workspace