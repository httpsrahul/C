/* 14/04/23 */
/* Code To Check Whether Entered Number Is Prime Or Not  */
#include<stdio.h>
#include<conio.h>
void main()
{
	int num,i;
	clrscr();
	printf("\n ENTER NUMBER : ");
	scanf("%d",&num);
	for(i=2;i<=num;i++)
	{
		if(num%i==0)
		{
			break;
		}
	}
	if(num==i)
	{
		printf("\n NUMBER IS PRIME");
	}
	else
	{
		printf("\n NUMBER IS NOT PRIME");
	}
	getch();
}