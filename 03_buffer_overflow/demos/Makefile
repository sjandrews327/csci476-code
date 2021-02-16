# CFLAGS: Extra flags to give to the C compiler
CC        = gcc
CFLAGS   += -m32 -Wall -Wno-unused-result -g -Wno-unused-result#-Werror
SRC       = $(wildcard *.c)
OBJ       = $(SRC:.c=.o)
EXECS     = simpleshell stack_layout1 stack_layout2 vuln 

.PHONY: all clean

# targets
all: $(EXECS)
	@echo "\nDone! ~~> $(EXECS)"

simpleshell: simpleshell.c
	-$(CC) $(CFLAGS) -o $@ $^

stack_layout1: stack_layout1.c
	-$(CC) $(CFLAGS) -Wno-unused-but-set-variable -o $@ $^

stack_layout2: stack_layout2.c
	-$(CC) $(CFLAGS) -Wno-pointer-to-int-cast -o $@ $^

vuln: vuln.c
	-$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -f *.o *.i *.s *.so.* *.a *.la *~ $(EXECS)
	@rm -rf *.dSYM/ # oops - compiled on mac! :)
