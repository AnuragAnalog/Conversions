#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
void itob(int num, char str[], int b);
void reverse(char str[]);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        num, b;
   char       str[MAX];

   if (argc != 3)
   {
     fprintf(stderr, "Usage: %s <integer> <base>\n", argv[0]);
     exit(1);
   }
   num = atoi(argv[1]);
   b = atoi(argv[2]);

   if (b < 2 || b > 16)
   {
      printf("Enter a base which is in between 2 and 16.\n");
      exit(2);
   }

   itob(num, str, b);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void itob(int num, char str[], int b)
{
   int        i = 0, rem, num1;

   num1 = num;
   if (num < 0)
   {
      printf("Enter a +ve value or value less than %d\n", MAXINT);
      exit(1);
   }

   do
   {
      rem = num % b;
      if ((rem >= 0) && (rem < 10))
      {
         str[i++] = rem + '0';
      }
      else
      {
         str[i++] = rem + '7';
      }
   } while ((num /= b) > 0);

   str[i] = '\0';
   reverse(str);
   printf("The value of %d in %d base representation is %s\n", num1, b, str);
   return ;
}

void reverse(char str[])
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
