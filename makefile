
CFLAGS = -Wall -g -Wextra -Wpedantic
LIBS = -lm

SRC_C = main.c
OBJ_C = $(patsubst %.c,%.o,$(SRC_C))

all:patcher.elf

patcher.elf: $(OBJ_C)
	gcc $(CFLAGS) -o patcher.elf $(OBJ_C) $(LIBS)

%.o: %.c
	gcc $(CFLAGS) -c $<


clean:
	rm *.o
	rm *.elf
