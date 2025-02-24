CC = clang
CFLAGS = -g -Wall
TARGET = main
OBJS = main.o cache.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c cache.h
	$(CC) $(CFLAGS) -c main.c

cache.o: cache.c cache.h
	$(CC) $(CFLAGS) -c cache.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
