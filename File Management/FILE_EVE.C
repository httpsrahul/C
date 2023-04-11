/*
	CODER : GeeksRahul
	TITLE : Taking 10 Integer, seperating even and odd in different files
	DATE : 11 APRIL 2023
*/
#include<stdio.h>
#include<conio.h>
#define SZ 10
void main()
{
	int i,arr[SZ];
	FILE *fp,*fp1,*fp2;
	fp=fopen("AllNUMBER.txt","w");
	fp1=fopen("EVEN_NUM.txt","w");
	fprintf(fp1,"\n EVEN NUMBERS : ");
	fp2=fopen("ODD_NUM.txt","w");
	fprintf(fp2,"\n ODD NUMBERS : ");
	printf("\n ENTER 10 INTEGERS ");
	for(i=0;i<SZ;i++)
	{
	    scanf("%d",&arr[i]);
	    fprintf(fp,"\n %d",arr[i]);
	    if(arr[i]%2==0)
	    {
		fprintf(fp1,"%d,",arr[i]);
	    }
	    else
	    {
		fprintf(fp2,"%d,",arr[i]);
	    }
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	getch();
}

