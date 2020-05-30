#include <stdio.h>
#include <stdlib.h>

int offset( char letter ) {

   int num = 0;

   if ( letter > 64 && letter < 91 ) {
      num = letter - 65;
   }
   else if ( letter > 96 && letter < 123 ) {
      num = letter - 97;
   }

   return ( num );

}
