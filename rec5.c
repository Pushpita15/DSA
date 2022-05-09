#include<stdio.h>
unsigned long int power(unsigned int,unsigned int);
int main()
{
	unsigned int b,e;
	printf("enter the base and exponent");
	scanf("%hu %hu",&b,&e);
	printf("%lu",power(b,e));
	return 0;
}
unsigned long int power(unsigned int base,unsigned int expo)
{
	if(expo==0)
		return 1;
	else if(expo==1)
		return base;
	else
		return power(base,expo-1)*base;
}