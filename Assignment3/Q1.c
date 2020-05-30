#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main( int argc, char *argv[] ) {

   char *file_store = NULL;
   int num_tot = 0;
   int char_tot = 0;
   int *text_freq = malloc( sizeof( int ) * 26 );
   int i = 0;
   FILE *fp = NULL;

   for ( i = 0; argv[i] != NULL; i++ ) {
      if ( ( strcmp ( argv[i], "-F" ) == 0 ) && (argv[i+1] != NULL) ) {
         fp = fopen( argv[i+1], "r" );
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
         printf("Character total: %d Letter total: %d\n", char_tot, num_tot);
         printf("Letters  Frequency\n");
         for (i = 0; i < 26; i++) {
            printf("%c \t %d\n", (i+65), text_freq[i]);
         }
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
      printf("Character total: %d Letter total: %d\n", char_tot, num_tot);
      printf("Letters   Frequency\n");
      for (i = 0; i < 26; i++) {
         printf("%c \t %d\n", (i+65), text_freq[i]);
      }
   }

   free( text_freq );
   free( file_store );

   return( 0 );
}

