mycat:mycat.o
	gcc -o mycat mycat.o
mycat.o:mycat.c
	gcc -c mycat.c -o mycat.o
clean:
	rm -f *.o
