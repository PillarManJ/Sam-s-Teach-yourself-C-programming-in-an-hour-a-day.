#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int file_copy(char *oldname, char *newname);
void buffer_change(char* obuff, char* nbuff );
void char_change(char* obuff, char* nbuff);

int main(void)
{
  char source[MAX];
  char dest[MAX];

  printf("\nEnter source file");
  gets(source);
  printf("\nEnter Destination file.");
  gets(dest);
  file_copy(source, dest);

}

int file_copy(char *oldname, char *newname)
{
  FILE *fold, *fnew;
  int c;
  char abuffer[MAX];
  char bbuffer[MAX];

  // Open the source file for reading in binary mode.

  if((fold = fopen(oldname, "rb"))== NULL)
  {
    fprintf(stderr, "Error opening file.");
    return -1;
  }


 // Open the source file for writing in binary mode.
  if((fnew = fopen(newname, "wb")) == NULL)
  {
    fprintf(stderr, "Error writing to file.");
    return -1;
  }

  if(!feof(fold))
  {
    fgets(abuffer, MAX, fold);
    buffer_change(abuffer, bbuffer);
    fputs(bbuffer, fnew);
  }

  fclose(fold);
  fclose(fnew);
/*
  //Read one byte a time from the source; if end of file.
  // Has not been reached, write the byte to the
  // Destination.

  while(1)
  {
    c = fgetc(oldname){
      if(!feof(oldname))
          fput(c, newname);
      else
          break;
      }
    }  */
  }

void buffer_change(char *obuff, char *nbuff)
{
  // Note : create a buffer array.
  char abuff[MAX];
  char c;
  //Do not open the file here, remember this is for changing the file which implies it has already been opened

  for(int i = 0; i < MAX; i++)
  {
    // Get characters from the original file, and place them into a buffer stream.
    c = obuff[i];
    abuff[i] = c;
    nbuff[i] = abuff[i];
  }
    //Take the original buffer stream, initiate the char_change method and create the new buffer stream.
    printf("The old file has the string %s", abuff);
    printf("\n\nand just to make sure nbuff was transferred properly %s", nbuff);

    char_change(obuff, nbuff);
    printf("\n\nThe new file has the string %s", nbuff);
}

void char_change(char *obuff, char *nbuff)
//A void method that takes a buffer stream and writes to new buffer stream.
//@The writing changes are as follows, changes the previous buffer streams
//@Uppercase to lowercase and lowercase to Uppercase.
{
  char c;

 for(int i = 0; i < MAX && c != '\0'; i++){
  c  = obuff[i];
  if(c >= 'A' && c <= 'Z')
    nbuff[i] =  c +  32;
  else if(c >= 'a' && c <= 'z')
    nbuff[i] = c - 32;
  }
  printf("\n\nc is %c", c);
}
