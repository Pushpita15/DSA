#include<stdio.h>
unsigned long int bacteria(unsigned int);
int main()
{
	int day;
	printf("enter the no of days");
	scanf("%d",&day);
	printf("%lu",bacteria(day));
	return 0;
}
unsigned long int bacteria(unsigned int n)
{
	if(n==0)
		return 1;
	else if(n==1)
		return 2;
	else
		return bacteria(n-1)*2;
}

	