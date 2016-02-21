INCLUDE = main.cpp src/entity.cpp src/io.cpp src/item.cpp src/map.cpp src/player.cpp src/tile.cpp src/vector2.cpp src/vector3.cpp include/entity.h include/io.h include/item.h include/map.h include/player.h include/tile.h include/vector2.h include/vector3.h
EXECUTABLE = main

all : $(INCLUDE)
	g++ -o $(EXECUTABLE) $(INCLUDE)
