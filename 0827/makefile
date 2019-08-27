server: main.o threadpool.o queue.o net.o process.o
	gcc main.o threadpool.o queue.o net.o  process.o -lpthread -o server
main.o:main.c
	gcc -c main.c -o main.o
threadpool.o:threadpool.c
	gcc -c threadpool.c -o threadpool.o
queue.o:queue.c
	gcc -c queue.c -o queue.o
net.o:net.c
	gcc -c net.c -o net.o
process.o:process.c
	gcc -c process.c -o process.o
clear:
	rm net.o queue.o main.o threadpool.o process.o
