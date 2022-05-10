#include<stdio.h>
#include<stdlib.h>
int * counting_sort(int*ip,int size)
{
    int *arr;
	arr=(int*)malloc(sizeof(int)*size);
    
    int i,j,k,c,l;
    for(i=0;i<size;i++)
    {
        arr[i]=0;
    }
    for(i=0;i<size;i++)
    {
		for(j=0;j<size;j++)
		{
			if(i==ip[j])
		   	 arr[i]++;

		}
		
    }
    

	return arr;
    
}
int main()
{
    int ip[10]={1,3,2,3,3,4,4,4,5,0};
	int * pt,l,k,c;
	pt=counting_sort(ip,10);
    
    for(k=0;k<10;k++)
    {
        c=pt[k];
        for(l=1;l<=c;l++)
        {
            printf("%d ",k);
        }

    }
    return 0;

}