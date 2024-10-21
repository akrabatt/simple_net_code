C = gcc
CFLAGS = -Wall -g
TARGET = server
OBJS = main.o global.o

$(TARGET): $(OBJS)
	$(C) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c 
	$(C) $(CFLAGS) -c main.c

global.0: global.c
	$(C) $(CFLAGS) -c global.c

clean:
	rm -f $(OBJS) $(TARGET)
