#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

bool perfectNum(int in){
  int i, acum=0;
	for (i=1;i<in;i++){
		if (in%i == 0)
		acum += i;
	}	
	if ( acum == in)
	return true;
	else
	return false;
}

int main(int argc, char * argv[]){
if (argc != 2){
printf("the arguments should be 2\n");
exit(EXIT_FAILURE);
}
const char *uInC = argv[1];
int u_in = atoi(uInC);
if (perfectNum(u_in))
printf("i am a perfect number\n");
else
printf("%d is not a perfect number\n",u_in);

for (int i=1; i<1000000; i++){
if (perfectNum(i))
printf("%d is a perfect number\n",i);
}
return 0;
}
