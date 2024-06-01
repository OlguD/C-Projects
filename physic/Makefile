CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = program
SDL_INCLUDE = -I/opt/homebrew/include
SDL_LIB = -L/opt/homebrew/lib
SDL_LIBS = -lSDL2 -lSDL2_ttf -lm

all: $(TARGET)

$(TARGET): main.o func.o
	$(CC) $(CFLAGS) $(SDL_LIB) -o $@ $^ $(SDL_LIBS)

main.o: main.c
	$(CC) $(CFLAGS) $(SDL_INCLUDE) -c $<

func.o: func.c
	$(CC) $(CFLAGS) $(SDL_INCLUDE) -c $<

clean:
    rm -f $(TARGET) *.o

