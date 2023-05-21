all:    LR2_1   LR2_2

LR2_1: LR2_1.c
	gcc LR2_1.c -o LR2_1

LR2_2: thLib.so LR2_2.c
	gcc -o LR2_2 LR2_2.c thDynLib.so

thLib.so: thLib.c
	gcc -c -fPIC thLib.c -o thDynLib.o
	gcc -shared -o thDynLib.so thDynLib.o

clean:
	rm -f LR2_2
	rm -f LR2_1
	rm -f thDynLib.*
