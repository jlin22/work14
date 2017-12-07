all : sem.c
	gcc -o control sem.c
run : control
	./control -c 5
	./control -v
	./control -c 3
	./control -v
	./control -r
