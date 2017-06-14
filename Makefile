output: main.o Cops.o EmptyRoom.o FrontRoom.o Managers.o Game.o Robber.o Room.o StartRoom.o menuMaker.o inputCheck.o Vault.o Windowed.o
	g++ main.o Cops.o EmptyRoom.o FrontRoom.o Managers.o Game.o Robber.o Room.o StartRoom.o menuMaker.o inputCheck.o Vault.o Windowed.o -std=c++11 -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Cops.o: Cops.cpp Cops.hpp
	g++ -std=c++11 -c Cops.cpp

EmptyRoom.o: EmptyRoom.cpp EmptyRoom.hpp
	g++ -std=c++11 -c EmptyRoom.cpp

FrontRoom.o: FrontRoom.cpp FrontRoom.hpp
	g++ -std=c++11 -c FrontRoom.cpp

Managers.o: Managers.cpp Managers.hpp
	g++ -std=c++11 -c Managers.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

Robber.o: Robber.cpp Robber.hpp
	g++ -std=c++11 -c Robber.cpp

Room.o: Room.cpp Room.hpp
	g++ -std=c++11 -c Room.cpp

StartRoom.o: StartRoom.cpp StartRoom.hpp
	g++ -std=c++11 -c StartRoom.cpp

menuMaker.o: menuMaker.cpp menuMaker.hpp
	g++ -std=c++11 -c menuMaker.cpp

inputCheck.o: inputCheck.cpp inputCheck.hpp
	g++ -std=c++11 -c inputCheck.cpp

Vault.o: Vault.cpp Vault.hpp
	g++ -std=c++11 -c Vault.cpp

Windowed.o: Windowed.cpp Windowed.hpp
	g++ -std=c++11 -c Windowed.cpp

clean:
	rm *.o output