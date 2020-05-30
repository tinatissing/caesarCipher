#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define EF {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07707, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074}

int main( int argc, char *argv[] ) {

   char *file_store = NULL;
   int num_tot = 0;
   int char_tot = 0;
   int *text_freq = malloc( sizeof( int ) * 26 );
   int i = 0;
   FILE *fp = NULL;
   FILE *fout = NULL;
   float ef[26] = EF;
   int shift_guess[26];
   int shift = 0;
   int holder = 61;
   int S_flag = 0;
   int j = 0;
   int n_flag = 0;
   int s_flag = 0;
   int t_flag = 0;
   int x_flag = 0;

   for ( i = 0; argv[i] != NULL; i++ ) {
      if ( ( strcmp ( argv[i], "-F" ) == 0 ) && (argv[i+1] != NULL) ) {
         fp = fopen( argv[i+1], "r" );
      }
      if ( ( strcmp ( argv[i], "-O" ) == 0 ) && (argv[i+1] != NULL) ) {
         fout = fopen( argv[i+1], "w" );
      }
      if ( strcmp ( argv[i], "-S" ) == 0 ) {
         S_flag = 1;
      }
   }

   if ( fp == NULL ) {
      file_store = malloc( sizeof ( char ) * 1000 );
      if (fgets ( file_store, 1000, stdin ) != NULL) {
         num_tot += letter_count( file_store );
         text_freq = frequency_table( file_store, text_freq );
         for ( i = 0; file_store[i] != '\0'; i++ ) {
            char_tot++;
         }
         char_tot--;
      }
   }
   else {
      fseek( fp, 0, SEEK_END );
      long f_size = ftell( fp );
      fseek( fp, 0, SEEK_SET);
      file_store = malloc( f_size + 1 );
      fread( file_store, 1, f_size, fp );
      fclose( fp );

      num_tot = letter_count( file_store );
      text_freq = frequency_table( file_store, text_freq );
      char_tot = strlen( file_store );

      char_tot--;
   }

   for (i = 0; i < 26; i++) {
      shift_guess[i] = chi_sq( char_tot, text_freq, i, ef );
      if ( shift_guess[i] < holder ) {
         holder = shift_guess[i];
         shift = i;
      }
   }

   for ( i = 0; file_store[i] != '\0'; i++ ) {
      file_store[i] = decode( file_store[i], shift );
   }

   for ( i = 1; argv[i] != NULL; i++ ) {
      if ( argv[i][0] == '-' ) {
         for ( j = 1; argv[i][j] != '\0'; j++ ) {
            if ( argv[i][j] == 'n' ) {
               n_flag = 1;
            }
            if ( argv[i][j] == 's' ) {
               s_flag = 1;
            }
            if ( argv[i][j] == 't' ) {
               t_flag = 1;
            }
            if ( argv[i][j] == 'x' ) {
               x_flag = 1;
            }
         }
      }
   }

   if ( (s_flag == 1 ) && ( n_flag == 0 ) ) {
      printf( "Decode shift = %d\n\n", shift );
   }

   if ( ( S_flag == 1 ) && ( n_flag == 0 ) ) {
         printf( "Encode shift = %d\n\n", 26-shift );
   }
   if ( ( x_flag == 1 ) && ( n_flag == 0 ) ) {
      for (i = 0; i < 26; i++) {
         printf("Shift of %d: %d\n", i, shift_guess[i]);
      }
      printf("\n");
   }
   if ( ( t_flag == 1 ) && ( n_flag == 0 ) ) {
      printf("Character total: %d Letter total: %d\n", char_tot, num_tot);
      for (i = 0; i < 26; i++) {
         printf("%c \t %d\n", (i+65), text_freq[i]);
      }
      printf("\n");
   }
   if ( fout != NULL ) {
      fprintf( fout, "%s\n", file_store );
   }
   else if ( n_flag == 0 ) {
      printf( "%s", file_store );
   }

   free( text_freq );
   free( file_store );

   return( 0 );
}

