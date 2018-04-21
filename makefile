appname=clo
dlibname=libcommandline.so

all: source/main.c
	gcc -c source/main.c -o obj/main.o
	
clean: 
	rm obj/*.obj clo
	sudo rm -f library/*
