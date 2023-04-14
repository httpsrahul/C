/* 14/04/23*/
/* Code To Check Whether Entered Number Is Prime Or Not  */
/* BEST CASE */
#include<stdio.h>
#include<conio.h>
void main()
{
	int num,i,isPrime=1;
	clrscr();
	printf("\n ENTER NUMBER : ");
	scanf("%d",&num);
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{
			isPrime=0;
			break;
		}
	}
	if(isPrime==1)
	{
		printf("\n NUMBER IS PRIME");
	}
	else
	{
		printf("\n NUMBER IS COMPOSITE");
	}
	getch();
}