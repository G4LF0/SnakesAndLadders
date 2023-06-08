# Modified by Ken Bauer for his students
# Based on file from this page by Tia Newhall:
# https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html

# "make"        build executable file
# "make clean"  removes all .o and executable files
# "make run"    run your program

# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g -std=c++11

# define any directories containing header files other than /usr/include
#
INCLUDES =

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I"d specify
#   their path using -Lpath, something like:
LFLAGS =

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname
#   option, something like (this will link in libmylib.so and libm.so:
LIBS =

# define the C++ source files
SRCS = snakes.cpp Dice.cpp MyGame.cpp

# define the C++ object files
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in "name" replace "string1" with "string2"
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.cpp=.o)

# define the executable file
MAIN = snakes

# optional arguments to the main program
ARGS =

all:    $(MAIN)
	@echo  Your program has been built with  make

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o"s from .c"s
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

run:
	./$(MAIN) $(ARGS)
# DO NOT DELETE

Dice.o: Dice.h
MyGame.o: MyGame.h Dice.h
snakes.o: MyGame.h Dice.h
