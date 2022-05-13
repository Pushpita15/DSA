#include<stdio.h>
#include<stdlib.h>
int * counting_sort(int*ip,int size)
{
    int *arr;
	arr=(int*)malloc(sizeof(int)*size);
    int i,j,k,c,l;
    //finding minimum element from input arrray
    int min=ip[0];
    for(int i=0;i<size;i++)
    {
         if(ip[i]<min)
             min=ip[i];

    }
    

    for(i=0;i<size;i++)
    {
        if(min<0)
            ip[i]=ip[i]-min;
        else
            ip[i]=ip[i]+min;
        
    }
    //finding maximum element from new array

    int max=ip[0];
    for(i=0;i<size;i++)
    {
        if(ip[i]>max)
            max=ip[i];
    }
    //following algorithm

    for(i=0;i<max+1;i++)
    {
        arr[i]=0;
    }
    for(j=0;j<max+1;j++)
    {
        for(i=0;i<max;i++)
        {
            if(j==ip[i])
                arr[j]++;

        }
        
    }

    return arr;
    
}
int main()
{
    int ip[7]={-1,1,2,3,-3,4};
	int * pt,l,k,c;
    int min=ip[0];
    for(int i=0;i<7;i++)
    {
         if(ip[i]<min)
             min=ip[i];

    }
    
    pt=counting_sort(ip,7);
    
    
    for(k=0;k<8;k++)
    {
        c=pt[k];
        for(l=1;l<=c;l++)
        {
            printf("%d ",k+min);
        }

    }
    return 0;

}