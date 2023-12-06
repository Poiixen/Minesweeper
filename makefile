Default:
	@echo 'Running makefile'
	g++ -Isrc/include -c main.cpp -o main.exe -lsfml-graphics -lsfml-window -lsfml-system
