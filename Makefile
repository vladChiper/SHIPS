compile: build run

build:
	gcc $(wildcard sursa/*.c)  -o ./out/main.exe -lSDL3 -lSDL3_image

run:
	cmd /c out\main.exe