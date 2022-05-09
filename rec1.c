#include<stdio.h>
unsigned long int sum(unsigned int);

int main()
{
	int n;
	printf("enter the no. of terms");
	scanf("%d",&n);
	printf("%lu",sum(n));
	return 0;
}
unsigned long int sum(unsigned int n);
{
	if(n==0 || n==1)
		return 1;
	else
		return n+sum(n-1);
}
	