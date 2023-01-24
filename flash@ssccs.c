/*
    TITLE : TAKE NUMBER FROM USER & SPECIFY NUMBER IS SUM OF WHICH TWO PRIME NUMBER ? 
    CODER : RAHUL BARAIYA

*/
#include<stdio.h>
#include<conio.h>
#define SZ 10000
int main()
{
    int i,j,num,prime[SZ],p=0,q=0;
    clrscr();
    printf("enter an number : ");
    scanf("%d",&num);
    for(i=2;i<=num;i++)
    {
        for(j=2;j<=i;j++)
        {
            if(i%j==0)
            {
                break;
            }
        }
        if(j==i)
        {
            prime[p++]=i;
            prime[q++]=i;
        }
    }
    for(i=2;i<=p;i++)
    {
        for(j=2;j<=q;j++)
        {
            if(prime[i]+prime[j]==num)
            {
                printf("%d is sum of %d & %d\n",num,prime[i],prime[j]);            
            }
        }
    }
    return 0;
}