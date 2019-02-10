#Adapted from the tutorial "How to Create a Simple Makefile - Introduction to Makefiles"
#https://www.youtube.com/watch?v=_r7i5X0rXJk
#and "A Simple Makefile Tutorial"
#http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC = g++
CFLAGS = -g -std=c++11 -MD -MP
OBJ = main.o Menu.o Barbarian.o BlueMen.o Character.o Dice.o Game.o HarryPotter.o Medusa.o Vampire.o
PROJECT = Project3_Jones_Robert
BIN = Fantasy-Combat

$(BIN): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ)

main.o: main.cpp
	$(CC) -c $(CFLAGS) $^

Menu.o: Menu.cpp
	$(CC) -c $(CFLAGS) $^

Barbarian.o: Barbarian.cpp
	$(CC) -c $(CFLAGS) $^

BlueMen.o: BlueMen.cpp
	$(CC) -c $(CFLAGS) $^

Character.o: Character.cpp
	$(CC) -c $(CFLAGS) $^

Dice.o: Dice.cpp
	$(CC) -c $(CFLAGS) $^

Game.o: Game.cpp
	$(CC) -c $(CFLAGS) $^

HarryPotter.o: HarryPotter.cpp
	$(CC) -c $(CFLAGS) $^

Medusa.o: Medusa.cpp
	$(CC) -c $(CFLAGS) $^

Vampire.o: Vampire.cpp
		$(CC) -c $(CFLAGS) $^

valgrind:
	@valgrind --leak-check=full --track-origins=yes ./$(BIN)

zip:
	zip -D $(PROJECT).zip *.cpp *.hpp *.pdf makefile

clean:
	rm -f core $(OBJ) *.d *~ $(BIN)
