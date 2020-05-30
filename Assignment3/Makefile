Q1: Q1.o letter_count.o frequency_table.o
	gcc -ansi -Wall -o Q1 Q1.o letter_count.o frequency_table.o

Q1.o: Q1.c
	gcc -ansi -Wall -c Q1.c

Q2: Q2.o letter_count.o frequency_table.o encode.o chi_sq.o offset.o decode.o
	gcc -ansi -Wall -o Q2 Q2.o letter_count.o frequency_table.o encode.o chi_sq.o offset.o decode.o

Q2.o: Q2.c
	gcc -ansi -Wall -c Q2.c

letter_count.o: letter_count.c
	gcc -ansi -Wall -c letter_count.c

frequency_table.o: frequency_table.c
	gcc -ansi -Wall -c frequency_table.c

encode.o: encode.c
	gcc -ansi -Wall -c encode.c

chi_sq.o: chi_sq.c
	gcc -ansi -Wall -c chi_sq.c

offset.o: offset.c
	gcc -ansi -Wall -c offset.c

decode.o: decode.c
	gcc -ansi -Wall -c decode.c

clean:
	rm Q1 Q2.o letter_count.o frequency_table.o encode.o chi_sq.o offset.o decode.o
