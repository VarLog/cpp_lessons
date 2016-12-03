all: game

CXX = c++

#LDLIBS += 
CPPFLAGS += -Iinclude -std=c++14

DEBUG = -g -Wall

OBJ = main.o game.o

game: $(OBJ)
	$(CXX) $(LDLIBS) $(OBJ) -o game

main.o: src/main.cpp
	$(CXX) $(DEBUG) $(CPPFLAGS) -c src/main.cpp

game.o: src/game.cpp
	$(CXX) $(DEBUG) $(CPPFLAGS) -c src/game.cpp

clean: 
	rm -fv $(OBJ) game

