a: client.o server.o
	gcc client.o server.o -o a
client.o: client.c 
	gcc -c client.c 
server.o: server.c server.h
	gcc -c server.c
clean:
	rm *.o a



