#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>

/********* FUNCTION DECLARATION *********/
void reverse(char *str);
void otoi(char *str, int num);
int pow8(int ind);

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

   if (strlen(str) > 11)
   {
      printf("You can enter upto 8 characters only.\n");
      exit(2);
   }
   else
   {
      if ((strlen(str) == 11) && (*str > '1'))
      {
         printf("The maximum value in Octal that can be entered is 17777777777.\n");
         exit(3);
      }
   }

   otoi(str, num);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void otoi(char *str, int num)
{
   int        i = 0, x = 0;

   reverse(str);

   while (*str != '\0')
   {
      if ((*str >= '0') && (*str <= '7'))
      {
         x = pow8(i);
         num = num + (int) (*str - '0') * x;
      }
      else
      {
         printf("Given string is not an Octal string\n");
         exit(2);
      }
      i++;
      str++;
   }

   printf("The decimal value is %d\n", num);
   return ;
}

int pow8(int ind)
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
         base = base * 8;
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

