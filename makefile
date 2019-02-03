#Adapted from the tutorial "How to Create a Simple Makefile - Introduction to Makefiles"
#https://www.youtube.com/watch?v=_r7i5X0rXJk
#and "A Simple Makefile Tutorial"
#http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC = g++
CFLAGS = -g -std=c++11
OBJ = main.o Menu.o Game.o Character.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o

output: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ)

main.o: main.cpp
	$(CC) -c $(CFLAGS) $^

Menu.o: Menu.cpp
	$(CC) -c $(CFLAGS) $^

Game.o: Game.cpp
	$(CC) -c $(CFLAGS) $^

Character.o: Character.cpp
	$(CC) -c $(CFLAGS) $^

Barbarian.o: Barbarian.cpp
	$(CC) -c $(CFLAGS) $^

BlueMen.o: BlueMen.cpp
	$(CC) -c $(CFLAGS) $^

HarryPotter.o: HarryPotter.cpp
		$(CC) -c $(CFLAGS) $^

Medusa.o: Medusa.cpp
		$(CC) -c $(CFLAGS) $^

Vampire.o: Vampire.cpp
		$(CC) -c $(CFLAGS) $^

clean:
	rm -f core $(OBJ) *~ output
