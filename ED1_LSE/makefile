
all: teste

teste: LSE.o main.o
	gcc -o teste LSE.o main.o

pilha.o: LSE.c LSE.h
	gcc -c LSE.c -Wall -Werror -Wextra

main.o: main.c LSE.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o teste