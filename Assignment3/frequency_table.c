#include <stdio.h>
#include <stdlib.h>

int *frequency_table( char *string, int text_freq[26] ) {

   int i = 0;
   int holder;

   while ( string[i] != '\0' ) {
      
      if ( string[i] >= 'A' && string[i] <= 'Z' ) {
         holder = string[i] - 'A';
         text_freq[holder]++;
      }
      else if ( string[i] >= 'a' && string[i] <= 'z' ) {
         holder = string[i] - 'a';
         text_freq[holder]++;
      }

      i++;

   }

   return( text_freq );

}
