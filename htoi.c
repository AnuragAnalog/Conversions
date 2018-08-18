#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
void htoi(int num, char *str);
void reverse(char *str);
int pow16(int ind);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        num = 0;
   char       *str;

   if (argc != 2)
   {
     fprintf(stderr, "Usage: %s <hexa-decimal value>\n", argv[0]);
     exit(1);
   }

   str = argv[1];

   if (strlen(str) > 8)
   {
      printf("You can enter upto 8 characters only.\n");
      exit(2);
   }
   else
   {
      if ((strlen(str) == 8) && (*str > '7'))
      {
         printf("The maximum value in hexa-decimal that can be entered is 7fffffff or 7FFFFFFF.\n");
         exit(3);
      }
   }

   htoi(num, str);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void htoi(int num, char *str)
{
   int        i = 0, x = 0;

   reverse(str);

   while (*str != '\0')
   {
      if ((*str >= '0') && (*str <= '9'))
      {
         x = pow16(i);
         num = num + (int)(*str - '0') * x;
      }
      else
      {
         switch (*str)
         {
            case 'A':
                     x = pow16(i);
                     num = num + 10 * x;
                     break;
            case 'B':
                     x = pow16(i);
                     num = num + 11 * x;
                     break;
            case 'C':
                     x = pow16(i);
                     num = num + 12 * x;
                     break;
            case 'D':
                     x = pow16(i);
                     num = num + 13 * x;
                     break;
            case 'E':
                     x = pow16(i);
                     num = num + 14 * x;
                     break;
            case 'F':
                     x = pow16(i);
                     num = num + 15 * x;
                     break;
            case 'a':
                     x = pow16(i);
                     num = num + 10 * x;
                     break;
            case 'b':
                     x = pow16(i);
                     num = num + 11 * x;
                     break;
            case 'c':
                     x = pow16(i);
                     num = num + 12 * x;
                     break;
            case 'd':
                     x = pow16(i);
                     num = num + 13 * x;
                     break;
            case 'e':
                     x = pow16(i);
                     num = num + 14 * x;
                     break;
            case 'f':
                     x = pow16(i);
                     num = num + 15 * x;
                     break;
            default :
                     printf("Invalid Hexadecimal value.\n");
                     exit(4);
                     break;
         }
      }
      i = i + 1;
      str++;
   }
   printf("The decimal value is %d\n", num);
   return ;
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

int pow16(int ind)
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
         base = base * 16;
      }
      return base;
   }
}

