all: Main

Main: ./bin/Main.o ./bin/reproduction.o ./bin/selection.o ./bin/math.o
	g++ -o Main ./bin/Main.o ./bin/reproduction.o ./bin/selection.o ./bin/math.o

./bin/Main.o: ./src/Main.cpp
	g++ -o ./bin/Main.o -c ./src/Main.cpp

./bin/reproduction.o: ./src/reproduction.cpp ./src/reproduction.h
	g++ -o ./bin/reproduction.o -c ./src/reproduction.cpp

./bin/selection.o: ./src/selection.cpp ./src/selection.h
	g++ -o ./bin/selection.o -c ./src/selection.cpp

./bin/math.o: ./src/math.cpp ./src/math.h
	g++ -o ./bin/math.o -c ./src/math.cpp