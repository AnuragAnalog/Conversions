#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>

/********* FUNCTION DECLARATION *********/
void reverse(char *str);
void bitoi(char *str, int num);
int pow2(int ind);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   char *str;
   int  num = 0;

   if (argc != 2)
   {
     fprintf(stderr, "Usage: %s <Octal value>\n", argv[0]);
     exit(1);
   }

   str = argv[1];

   if (strlen(str) > 31)
   {
      printf("You can enter upto 31 characters only.\n");
      exit(2);
   }

   bitoi(str, num);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void bitoi(char *str, int num)
{
   int        i = 0, x = 0;

   reverse(str);

   while (*str != '\0')
   {
      if ((*str == '0') || (*str == '1'))
      {
         x = pow2(i);
         num = num + (int) (*str - '0') * x;
      }
      else
      {
         printf("Given string is not a Binary string\n");
         exit(2);
      }
      i++;
      str++;
   }

   printf("The decimal value is %d\n", num);
   return ;
}

int pow2(int ind)
{
   int        i, base = 1;

   if (ind == 0)
   {
      return base;
   }
   else
   {
      for (i = 0; i < ind; i++)
      {
         base = base * 2;
      }
      return base;
   }
}

void reverse(char *str)
{
   int       c, i, j;

   for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
   {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
   }

   return ;
}

