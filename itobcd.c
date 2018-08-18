#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        10

/********* FUNCTION DECLARATION *********/
void bcdgen(char *bcdh[]);
void itobcd(char *num);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   char       *num;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <Integer>\n", argv[0]);
      exit(1);
   }

   num = argv[1];
   itobcd(num);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void bcdgen(char *bcdh[])
{
   bcdh[0] = "0000";
   bcdh[1] = "0001";
   bcdh[2] = "0010";
   bcdh[3] = "0011";
   bcdh[4] = "0100";
   bcdh[5] = "0101";
   bcdh[6] = "0110";
   bcdh[7] = "0111";
   bcdh[8] = "1000";
   bcdh[9] = "1001";

   return ;
}

void itobcd(char *num)
{
   int         i, x, len;
   char        *bcdh[MAX];

   bcdgen(bcdh);
   len = strlen(num);

   for (i = 0; i < len; i++)
   {
      x = (int)(*num - '0');
      printf("%s ", bcdh[x]);
      num++;
   }
   printf("is the BCD value of the number.\n");

   return ;
}
