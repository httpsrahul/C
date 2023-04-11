/*
	NAME : GEEKSRAHUL
	TITLE : encrypting text into file & descrypting text from file.
	INPUT : ABCD
	Encrypt.txt : KLMN
	DATE : 11 APRIL 2023
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *fp;
	char str1[20],str2[20];
	int i;
	clrscr();
	fp=fopen("encrypt.txt","w");
	printf("\n ENTER NAME : ");
	fflush(stdin);
	gets(str1);
	for(i=0;str1[i]!=NULL;i++)
	{
		fprintf(fp,"%c",str1[i]+10);
	}
	fclose(fp);
	fp=fopen("encrypt.txt","r");
	fgets(str2,i+1,fp);
	printf("\n ENCRYPTED  : %s",str2);
	printf("\n DESCRYPTED : ");
	for(i=0;str2[i]!=NULL;i++)
	{
		printf("%c",str2[i]-10);
	}
	fclose(fp);
	getch();
}