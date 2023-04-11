#include<stdio.h>
#include<conio.h>
#define SZ 15
void main()
{
	char name[SZ];
	int i;
	FILE *fp1,*fp2,*fp3;
	clrscr();
	fp1=fopen("NAME.txt","w");
	fp2=fopen("VOWEL.txt","w");
	fp3=fopen("CONSOLE.txt","w");
	fprintf(fp2,"VOWELS : ");
	fprintf(fp3,"CONSOLES : ");
	printf("\n ENTER NAME : ");
	fflush(stdin);
	gets(name);
	fprintf(fp1,"NAME : %s",name);
	for(i=0;name[i]!=NULL;i++)
	{
		if(name[i]=='a' || name[i]=='A' || name[i]=='e' || name[i]=='E' || name[i]=='i' || name[i]=='I' || name[i]=='o' || name[i]=='O' || name[i]=='u' || name[i]=='U' )
		{
			fprintf(fp2,"%c,",name[i]);
		}
		else
		{
			fprintf(fp3,"%c,",name[i]);
		}
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	getch();
}
