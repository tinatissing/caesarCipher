#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int chi_sq( int n, int *text_freq, int shift, float ef[26] ) {

   char i;
   int shift_num = 0;

   for ( i = 0; i < 26; i++ ) {
      shift_num += ( ( ( n * ef[offset('a'+i)] - text_freq[offset(encode('a'+i, shift))] ) * ( n * ef[offset('a'+i)] - text_freq[offset(encode('a'+i, shift))] ) ) / ( ( n * n ) * ef[offset('a'+i)] ) );
   }

   return ( shift_num );

}
