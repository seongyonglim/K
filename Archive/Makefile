CC = gcc
INCLUDES=
CFLAGS = -g -Wall $(INCLUDE)
LDFLAGS = -g
LDLIBS=$(C) $(LDFLAGS) isort.o  $(LDLIBS)

isort : isort.c
	$(CC) -c $(CFLAGS) isort.c
isort.o : isort.c main.h

.PHONY: clean
clean:
	rm *.o a.out core isort
.PHONY: all clean isort 
