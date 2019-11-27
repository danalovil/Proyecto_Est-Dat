a.out: main.o adivinador.o
	gcc main.o adivinador.o
main.o: main.c
	gcc -c main.c
adivinador.o: adivinador.c
	gcc -c adivinador.c
clear:
	rm main.o adivinador.o a.out
run: a.out
	./a.out
