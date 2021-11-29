#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
char *fgets(char *s, int size, FILE *stream);

  fgets()  reads in at most one less than size characters from stream and
  stores them into the buffer pointed to by s.  Reading  stops  after  an
  EOF  or a newline.  If a newline is read, it is stored into the buffer.
  A terminating null byte ('\0') is stored after the  last  character  in
  the buffer.
*/

char * getFileName(char *fname);

int main(void) {
  FILE *fPointer;
  char dataToBeRead[50];
  char fname[20];

  getFileName(fname);
  fPointer = fopen(fname, "r");

  if (fPointer == NULL) {
    printf("\nError: fallo la apertura del archivo.");
  } else {
    printf("\nExito: el archivo fue accedido corretamente:\n");

    while (fgets(dataToBeRead, 50, fPointer) != NULL) {
      printf("%s", dataToBeRead);
    }
    printf("\n");
  }

  // Closing the file using fclose()
  fclose(fPointer);

  return EXIT_SUCCESS;
}

char * getFileName(char *fname) {
  printf("\nIngrese el nombre del archivo incluyendo la extension");
  printf("\nNombre: ");
  scanf(" %s", fname);

  return fname;
}