all:
	g++ src/main.cpp -o bin/Application.exe -DSFML_STATIC -IC:\Dev\CPP\Libs\SFML-2.5.1\include -LC:\Dev\CPP\Libs\SFML-2.5.1\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32

setup:
	mkdir bin
