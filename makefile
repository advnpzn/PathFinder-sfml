all: path
	./build/path

path: main.o pixelmap.o
	g++ -o ./build/path ./build/main.o ./build/pixelmap.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

pixelmap.o:
	g++ -c ./src/pixelmap.cpp -o ./build/pixelmap.o

main.o:
	g++ -c ./src/main.cpp -o ./build/main.o

clean:
	rm -rf ./build/*.o ./build/path