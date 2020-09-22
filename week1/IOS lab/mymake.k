output: main.o randomInt.o getmyno.o square.o
	gcc main.o randomInt.o getmyno.o square.o -o output

main.o: main.c dependency.h
	gcc -c main.c

randomInt.o: randomInt.c random.h
	gcc -c randomInt.c	

getmyno.o: getmyno.c random.h dependency.h
	gcc -c getmyno.c

square.o: square.c dependency.h
	gcc -c square.c

clean: 
	@echo "Cleaning up..."
	rm -f *.o 
