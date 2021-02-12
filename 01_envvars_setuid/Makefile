# CFLAGS: Extra flags to give to the C compiler
CC        = gcc
CFLAGS   += -Wall -O2 -g #-Werror
SRC       = $(wildcard *.c)
OBJ       = $(SRC:.c=.o)
EXE       = $(subst .c,,$(SRC))

.PHONY: all clean

all: $(OBJ) $(EXE)

clean:
	@rm -f *.o *.i *.s *.so *.a *.la *~ $(EXE)
	@rm -rf *.dSYM/ # oops - compiled on mac! :)
