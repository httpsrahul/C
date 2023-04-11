/*
	CODER : GeeksRahul
	TITLE : Taking 10 Integers & Seperating Prime and composite numbers in different files
	DATE : 11 APRIL 2023
*/
#include<stdio.h>
#include<conio.h>
#define SZ 10
int isPrime(int num)
{
	int i;
	for(i=2;i<num;i++)
	{
		if(num%i==0)
			break;
	}
	return (num==i) ? 1: 0;
}
void main()
{
	FILE *all,*prime1,*prime0;
	int num,i,j,p=0,q=0,n;
	clrscr();
	all=fopen("allNUM.txt","w");
	printf("\n ENTER NUMBER: ");
	fprintf(all,"ENTERED NUMBER : ");
	prime1=fopen("primeNUM.txt","w");
	prime0=fopen("notprimeNUM.txt","w");
	fprintf(prime1,"PRIME NUMBERS : ");
	fprintf(prime0,"NOT PRIME NUMBER : ");
	for(i=0;i<SZ;i++)
	{
		scanf("%d",&num);
		fprintf(all,"%d,",num);
		if(isPrime(num))
		{
			fprintf(prime1,"%d,",num);
		}
		else
		{
			fprintf(prime0,"%d,",num);
		}
	}
	fclose(all);
	fclose(prime1);
	fclose(prime0);
	getch();
}
