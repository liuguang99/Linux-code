sortime:main.o func.o
	gcc main.o func.o sortime
main.o:main.c uhead.h
	gcc main.c -c
func.o:func.c
	gcc func.c -c
clean:
	rm -f *.o
