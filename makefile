appname=clo
dynamiclibraryname=libcommandline.so
systempath=/opt/gcclib
installdirname=commandline
includepath=include
objects=obj/commandlineoption.o \
		obj/commandlineparser.o \
		obj/util.o \



obj/%.o: source/%.c
	@gcc -c $^ -o $@ -fPIC -Wall -I$(includepath)

all: source/main.c lib-static
	@gcc -c source/main.c -o obj/main.o -Iinclude
	@gcc -o clo obj/main.o library/libcommandline.a

lib-dynamic: $(objects)
	@echo "*** Creating Dynamic Library ..."
	@gcc -shared -o library/$(dynamiclibraryname) $(objects)
	@echo "*** Dynamic Library Created."

lib-static: $(objects)
	@echo "*** Objects Created."
	@ar rs library/libcommandline.a $(objects)
	@echo "*** Static Library Created.";

lib-install: library/$(dynamiclibraryname)
	@sudo mkdir -p $(systempath)/$(installdirname)
	@sudo cp library/$(dynamiclibraryname) $(systempath)/$(installdirname)/
	@echo "*** Dynamic Library Install Successfull - "$(systempath)

clean: 
	@rm -f obj/*.o clo
	@rm -f library/*
	@echo "*** Remove Library from System(/opt/gcclib/) (y/n)?"
	
	@echo "*** Cleaned Successfully."
