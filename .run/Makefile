CC = gcc
RM = rm -f


all : prog

prog : runsanitize
	$(CC) run.c -o run

runsanitize :
	$(CC) runsanitize.c -o runsanitize

clean : 
	$(RM) run runsanitize

.PHONY: all clean