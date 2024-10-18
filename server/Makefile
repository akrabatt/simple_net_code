C = gcc
CFLAGS = -Wall -g
TARGET = server
OBJS = main.o

$(TARGET): $(OBJS)
	$(C) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c 
	$(C) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJS) $(TARGET)
