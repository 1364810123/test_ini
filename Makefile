all:process_ini

process_ini:main.o ini_parser.o libiniparser.so.1

	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)

	echo $LD_LIBRARY_PATH

	gcc -o process_ini main.o ini_parser.o -liniparser -L. 


main.o:main.c

	gcc -c main.c

ini_parser.o:ini_parser.c

	gcc -c ini_parser.c

clean:

	rm -rf *.o process_ini 
