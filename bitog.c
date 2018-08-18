#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/********* DEFINED CONSTANTS *********/
#define   MAX       15

/********* FUNCTION DECLARATION *********/
void bitog(int num, char *str);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        num = 0;
   char       *str;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <binary-string>\n", argv[0]);
      exit(1);
   }

   str = argv[1];

   bitog(num, str);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void bitog(int num, char *str)
{
   int        i = 0, j = 0, bin[MAX], gray[MAX];

   while (*str != '\0')
   {
      if ((*str == '0') || (*str == '1'))
      {
         bin[i] = (int)(*str - '0');
      }
      else
      {
         printf("Invalid Binary value.\n");
         exit(3);
      }

      str++;
      i++;
   }

   gray[j] = bin[j];
   j++;

   while (j < i)
   {
      gray[j] = (bin[j-1] ^ bin[j]);
      j++;
   }

   for (j = 0; j < i; j++)
   {
      printf("%d", gray[j]);
   }
   printf("is the gray code.\n");

   return ;
}
