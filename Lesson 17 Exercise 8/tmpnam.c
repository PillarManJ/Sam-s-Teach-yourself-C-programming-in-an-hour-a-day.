#include <stdio.h>
#include <stdlib.h>

int main()
{

FILE *fp;

char buffer[10], *c;
char buffer_zero[10];
char *buffer_one;
tmpnam(buffer);

printf("What write privileges do you desire? Write 1 for read 2 for write and 3 for append only");
gets(buffer_zero);

c = tmpnam(NULL);

//Display the name.

printf("Temporary name1 : %s", buffer);
printf("\n Temporary name 2: %s", buffer);

if(buffer_zero == '1')
{
if(fp = fopen(buffer, "r") == NULL)
{
  fprintf(stderr, "Error opening file.");
  exit(1);
}
}else if(buffer_zero == '2')
{
if(fp = fopen(buffer,"w") == NULL)
{
  fprintf(stderr, "Error opening file.");
  exit(1);
}
}else if(buffer_zero == '3')
{
if(fp = fopen(buffer,"a") == NULL)
  {
   fprintf(stderr, "Error opening file.");
   exit(1);
  }
}


fclose(fp);
remove(buffer); 
if(remove(buffer) == 0)
  printf("The file %s has been deleted", buffer);
else
  printf(stderr, "Error deleting the file %s.\n", buffer);

}
