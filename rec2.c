#include<stdio.h>
unsigned long int fact(unsigned int);
int main()
{
	int n;
	printf("enter no of terms");
	scanf("%d",&n);
	printf("%lu",fact(n));
	return 0;
}

unsigned long int fact(unsigned int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return n*fact(n-1);
}