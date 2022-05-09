#include<stdio.h>
void show(char [],int);
int main()
{
	int n;
	char s[40];
	printf("enter your name ");
	scanf("%s",s);
	printf("enter the times ");
	scanf("%d",&n);
	show(s,n);
	return 0;
}
void show(char a[],int n)
{
	int i;
	if(n==0)
		return;
	else if(n==1)
		printf("%s\n",a);
	else
	{	show(a,n-1);
		printf("%s\n",a);
	}
}