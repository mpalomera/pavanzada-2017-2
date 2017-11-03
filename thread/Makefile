LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c hellow.c
	 gcc -c main.c
	 gcc -o hellow.exe hellow.o main.o $(LIB)

test_hellow: clean
	 gcc -c hellow.c
	 gcc -c test_hellow.c
	 gcc -o test_hellow.exe hellow.o test_hellow.o
	 ./test_hellow.exe

test:	 test_hellow

clean:
	 rm *.out *.o *.exe || exit 0

hellow: clean
	 gcc -c hellow.c
	 gcc -c main.c
	 gcc -o hellow.exe hellow.o main.o $(LIB)

run: hellow
	 ./hellow.exe

runtest: hellow
	 ./integrationtest.tcl ./hellow.exe

