/* 14/04/23 */
/* Code To Check Whether Entered Number Is Prime Or Not  */
#include<stdio.h>
#include<conio.h>
void main()
{
	int num,i,count=0;
	clrscr();
	printf("\n ENTER NUMBER : ");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		if(num%i==0)
		{
			count++;
		}
	}
	if(count==2)
	{
		printf("\n NUMBER IS PRIME");
	}
	else
	{
		printf("\n NUMBER IS NOT PRIME");
	}
	getch();
}