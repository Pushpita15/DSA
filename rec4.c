#include<stdio.h>
unsigned long int power2(unsigned int);
int main()
{
	int n;
	printf("enter the power");
	scanf("%d",&n);
	printf("%lu",power2(n));
	return 0;
}
unsigned long int power2(unsigned int n)
{
	if(n==0)
		return 1;
	else if(n==1)
		return 2;
	else
		return power2(n-1)*2;
}
