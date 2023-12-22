TARGET=test
OBJ=test.o test1.o test2.o
CC=gcc
CFLAGS=-c
LFLAGES=

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

test2.o: test2.c
	$(CC) $(CFLAGS) -I/user/lib/include -lm -L/usr/lib -DDEBUG $<
.c.o:
	$(CC) $(CFLAGS) $<


clean:
	rm -rf $(TARGET) $(OBJ)
