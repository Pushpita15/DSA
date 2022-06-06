
#include<string.h>
#include "polyad.h"

int main()
{
    FILE * fp;
    int i=0,j=0,num,arr1[40],arr2[40];
    int c=0,p=0;
    char exp1[100],exp2[100];
    node * h1=NULL;
    node * h2=NULL;
    node * resad;
    node * resmult;
    node * ressub;
    fp=fopen("number.txt","r");
    printf("the first expression is %s",fgets(exp1,50,fp) );
    printf("the second expression is %s",fgets(exp2,50,fp) );
    for(i=0;exp1[i]!='\0';i++)
    {
        if(exp1[i]>='0' && exp1[i]<='9')
        {    
            c++;
            arr1[j++]=exp1[i]-'0';
        }
    }
    printf("\n");
    for(p=0;p<c;p=p+2)
    {
        append(&h1,arr1[p],arr1[p+1]);
    }
    printf("converted expression 1: ");
    traverse(h1);
    printf("\n");
    c=0;
    j=0;

    for(i=0;exp2[i]!='\0';i++)
    {
        if(exp2[i]>='0' && exp2[i]<='9')
        {    
            c++;
            arr2[j++]=exp2[i]-'0';
            
        }
    }
    for(p=0;p<c;p=p+2)
    {
        append(&h2,arr2[p],arr2[p+1]);
    }
    printf("converted expression 2: ");
    traverse(h2);
    printf("\n");
    
    printf("the resultant converted expression after addition\n");
    resad=padd(h1,h2);
    traverse(resad);

    printf("the resultant converted expression after multiplication\n");
    resmult=pmult(h1,h2);
    traverse(resmult);

    printf("the resultant converted expression after subtraction\n");
    ressub=psub(h1,h2);
    traverse(ressub);


    
    fclose(fp);
    return 0;

}