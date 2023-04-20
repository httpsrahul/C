#include<stdio.h>
#include<conio.h>
void main()
{
	int number,reminder,reverse=0,temp;
	clrscr();
	printf("\n ENTER NUMBER : ");
	scanf("%d",&number);
	temp=number;
	while(temp>0)
	{
		reminder=temp%10;
		reverse=reverse*10+reminder;
		temp=temp/10;
	}
	printf(" REVERSE : %d",reverse);
	if(reverse==number)
	{
		printf("\n NUMBER IS PALINDROM");
	}
	else
	{
		printf("\n NUMBER IS NOT PALINDROM");
	}
	getch();
}