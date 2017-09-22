all:
	 gcc -c dict.c
	 gcc -c main.c
	 gcc -o main dict.o main.o

test_dict: clean
	 gcc -c dict.c
	 gcc -c test_dict.c
	 gcc -o test_dict.exe dict.o test_dict.o
	 ./test_dict.exe

test:	 test_dict

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c dict.c
	 gcc -c main.c
	 gcc -o main.exe dict.o main.o
	 ./main
