
OBJECTS = main.o game.o sprite.o player.o
CC = g++
LIBS = -Wall -lSDL2 -lSDL2_image 

test: $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -v -o test 

clean:
	-rm *.o

