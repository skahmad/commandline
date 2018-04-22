appname=clo
dlibname=libcommandline.so

objects=obj/main.o

all: source/main.c
	gcc -c source/main.c -o obj/main.o -Iinclude
	gcc -o clo $(objects)

clean: 
	rm -f obj/*.obj clo
	sudo rm -f library/*
