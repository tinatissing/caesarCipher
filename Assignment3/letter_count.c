#include <stdio.h>
#include <stdlib.h>

int letter_count( char *string ) {

   int num_tot = 0;
   int i = 0;

   while ( string[i] != '\0' ) {
      if ( string[i] >= 'A' && string[i] <= 'Z' ) {
         num_tot++;
      }
      else if ( string[i] >= 'a' && string[i] <= 'z' ) {
         num_tot++;
      }
      i++;
   }

   return( num_tot );

}
