strtest: strs.o 
	gcc -o strtest strs.o
strs.o: strs.c headers.h
	gcc -c strs.c
clean:
	rm *.o
	rm *~
run: strtest
	./strtest
