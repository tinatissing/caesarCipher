Program Name: Q1.c and Q2.c
	
Author: Tina Tissington
	
Last Update: March 9, 2020

Note: I really didn't understand what code was supposed to go into what functions going off of the instructions, so I did all the required work interpreting the instructions the best I could but also with using some of my own function names. I hope this is okay.

Function Q1.c: Count and print the number of characters and number of letters in the input (whether it be from a file or stdin), and print a frequency table for the letters.

Compilation: make

Execution: ./Q1 or ./Q1 -F fileName.txt

Other functions used: letter_count() and frequency_table()

Function Q2.c: Find the shift value and decode the message inputted (whether it be through stdin or a file) and either print to stdout or a file depending on the flags used when executing the code.

Compilation: make Q2

Execution: ./Q2 or ./Q2 -F -O -nstx -S

The flags (including the order their inputted as) are all optional.

Other functions used: letter_count(), frequency_table(), chi_sq(), decode(), encode(), and offset()
