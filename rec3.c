#include<stdio.h>
unsigned long int fibo(unsigned int);
int main()
{
	int n;
	printf("enter the term ");
	scanf("%d",&n);
	printf("%d",fibo(n));
	return 0;
}
unsigned long int fibo(unsigned int n){
	
	if(n==1 || n==0)
		return 1;
	else 
		return fibo(n-2)+fibo(n-1);
}