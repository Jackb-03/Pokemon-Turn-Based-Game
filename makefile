output: main.o Pokemon.o Player.o Commentator.o
	g++ main.o Pokemon.o Player.o Commentator.o -o output -Wall

#test: testing.o Pokemon.o Player.o Commentator.o
#g++ testing.o Pokemon.o Player.o Commentator.o -o test -Wall

main.o: main.cpp
	g++ -c main.cpp
	
testing.o: testing.cpp 
	g++ -c testing.cpp

Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -c Pokemon.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

Commentator.o: Commentator.cpp Commentator.h
	g++ -c Commentator.cpp
	

clean:
	rm *.o output