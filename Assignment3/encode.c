#include <stdio.h>
#include <stdlib.h>

char encode( char letter, int shift_num ) {

   char temp;

   if ( shift_num > 0 ) {
      if ( letter > 64 && letter < 91 ) {
         if ( letter > (90 - shift_num) ) {
            temp = 90 - letter;
	    temp = shift_num - temp + 64;
	    letter = temp;
         }
         else {
   	    letter = letter + shift_num;
         }
      }
      else if ( letter > 96 && letter < 123 ) {
         if ( letter > (122 - shift_num) ) {
            temp = 122 - letter;
	    temp = shift_num - temp + 96;
	    letter = temp;
         }
         else {
	    letter = letter + shift_num;
         }
      }
   }
   else {
      if ( letter > 64 && letter < 91 ) {
         if ( letter < (65 - shift_num) ) {
            temp = letter - 65;
	    temp = 91 + temp + shift_num;
	    letter = temp;
         }
         else {
   	    letter = letter + shift_num;
         }
      }
      else if ( letter > 96 && letter < 123 ) {
         if ( letter < (97 - shift_num) ) {
            temp = letter - 97;
	    temp = 123 + temp + shift_num;
	    letter = temp;
         }
         else {
	    letter = letter + shift_num;
         }
      }
   }

   return ( letter );
}
