//============================================================================
// Name        : nanfang.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : convert the number based on any base into 10-base
//============================================================================

#include <stdio.h>

int convert(char c) {
 c = tolower(c);
       if (c >= '0' && c <= '9')
               return c - '0';
       if (c >= 'a' && c <= 'z')
               return c - 'a' + 10;

       return -1;
}

int multi(int factor, int base) {
       int maxFactor = 0b000001;
       int loop = 5, sig = 0;
       int results = 0;
       for (; loop > 0; loop--) {
               if (factor & 1) {
                       results += (base << sig);
                       //factor = factor >> 1;
						
               }
	       factor = factor >> 1;
               sig++;
	       //printf("factor %d, base %d, loop %d, sig %d\n", factor, base, loop, sig);
       }
       return results;
}

int pow(int base, int pw) {
       if (pw == 0)
       return 1;
       int i = pw;
       //for (; i > 0; i--) {
               if (i == 1)
                       return base;
               else
                       return multi(base, pow(base, i-1));
       //}
}

int atoi(char* str, int base) {
       int len = 0, result = 0, i = 0;
       int mark = 0;//mark for the negative

       if (str == NULL)
               return -1;
       if (base < -36 || base > 36)
               return -1;

       if (str[0] == '-' && str[1] == '\0')// - case
               return -1;

       while (str[len] != '\0') {
               len++;
       }
       if (str[0] == '-') {
               len--;
               mark = 1;
       }

       while (str[i] != '\0') {
               int temp = convert(str[i]);

               if (temp >= base)
                       return -1;
               result += temp * pow(base, len - i - 1);

               i++;
       }
       

       if (!mark)
               return result;
       else
               return -result;
}


int main(int argc, char * argv[]){
       char *input, *base;
       int results = 0, ba = 0;
       if (argc != 3)
       printf("enter a string and a base: bigswitch string num\n");
       input = argv[1];
       base = argv[2];
       ba = atoi(base, 10);

       results = atoi(input, ba);
       printf("the results is %d\n", results);

	  //printf("for test 5*2 %d\n", multi(15, 6));
}
