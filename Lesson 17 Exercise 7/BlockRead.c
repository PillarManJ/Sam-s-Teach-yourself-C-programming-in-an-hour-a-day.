#include <stdlib.h>
#include <stdio.h>

#define BLOCK 128
#define MAX 1000000
int main(void){

 int i = 0;
 int j = 0;
 FILE *fp;

 // A buffer for the filename.
 char file1[BLOCK];
 char buffer[MAX];

 printf("Please enter file to be read:\n");
 printf("\nWarning: Your file will only be read in increments of 128 byte blocks\n");
 gets(file1);

 if((fp = fopen(file1, "r+")) == NULL){
   fprintf(stderr, "Error opening file");
   exit(1);
 }else

while(!feof(fp))
{
 if(fread(buffer, sizeof(char), BLOCK, fp)!= BLOCK)
 {
    printf("\n abbherant Block %d",i);
    printf("\n HEX: %x", buffer);
    printf("\n\n\t%s", buffer);
    i++;
  }else{
    printf("\n Block : %d", j);
    printf("\n HEX: %x", buffer);
    printf("\n\n\t%s", buffer);
    j++;
  }
}
  fclose(fp);

  //printf("\n%s", buffer);
  //printf("\n%x", buffer);
}
