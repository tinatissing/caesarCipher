#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

char decode( char letter, int shift_num ) {

   char temp;

   if ( shift_num > 0 ) {
      if ( letter > 64 && letter < 91 ) {
         if ( letter < (64 + shift_num) ) {
            temp = shift_num - (letter - 65);
	    letter = 91 - temp;
         }
         else {
   	    letter = letter - shift_num;
         }
      }
      else if ( letter > 96 && letter < 123 ) {
         if ( letter < (96 + shift_num) ) {
            temp = shift_num - (letter - 97 );
	    letter = 123 - temp;
         }
         else {
	    letter = letter - shift_num;
         }
      }
   }

   return ( letter );

}

