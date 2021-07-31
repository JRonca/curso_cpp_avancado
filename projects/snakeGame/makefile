TARGET=snakeGame
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS= main.o snakeGame.o
NCURSES=-lncurses
TINFO=-ltinfo
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(NCURSES) $(TINFO)
 
main.o: main.cpp
	$(CC) -c $(CCFLAGS) $(NCURSES) $(TINFO) main.cpp -o main.o
 
snakeGame.o: snakeGame.cpp
	$(CC) -c $(CCFLAGS) $(NCURSES) $(TINFO) snakeGame.cpp  -o snakeGame.o

install:
	@install $(TARGET) /usr/local/bin/$(TARGET)

uninstall:
	@rm /usr/local/bin/$(TARGET)

clean:
	rm -f *.o
