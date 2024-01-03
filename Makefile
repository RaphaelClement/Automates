CC = gcc
CFLAGS = -Wall -Wextra -pedantic -Werror -g
LDFLAGS = -Llib
LDLIBS = -l_automate
INCLUDE = -Iinclude

SRCDIR = src
INCDIR = include
BINDIR = bin
LIBDIR = lib

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(SRCDIR)/%.o)
EXEC = test_automate

all: $(EXEC)
	ar rcs lib/lib_automate.a $(OBJ)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ bin/test_automate.c $(SRCDIR)/automate.c -I$(INCDIR)

$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR) -I$(SRCDIR)


.PHONY: test
test: $(EXEC)
	./$(BINDIR)/$(EXEC)

.PHONY: clean
clean: $(EXEC)
	rm bin/test_automate lib/lib_automate.a src/automate.o

