@goto %1

:all
	@echo "Creating object ..."
	gcc -Iinclude -c source\main.c -o object\main.o
	gcc -Iinclude -c source\util.c -o object\util.o
	gcc -Iinclude -c source\commandlineoption.c -o object\commandlineoption.o
	@goto end
	
:obj
	@echo "Creating object ..."
	gcc -Iinclude -c source\main.c -o object\main.o
	gcc -Iinclude -c source\commandlineoption.c -o object\commandlineoption.o
	gcc -Iinclude -c source\commandlineparser.c -o object\commandlineparser.o
	gcc -Iinclude -c source\util.c -o object\util.o
	@goto end

:exe
	gcc -o cla object\commandlineoption.o object\util.o object\main.o object\commandlineparser.o
	goto end
	
:clear
	@echo "Claning all ..."
	@del /f object\*.o
	@del /f library\*.*
	@del /f cla.exe
	@goto end
	
:end
	