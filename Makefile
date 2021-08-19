SFMLPath := C:\Dev\CPP\Libs\SFML-2.5.1

all:
	g++ src/main.cpp -o bin/Application.exe -DSFML_STATIC -I$(SFMLPath)\include -L$(SFMLPath)\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32

setup:
	mkdir bin
