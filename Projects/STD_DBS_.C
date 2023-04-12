#include<stdio.h>
#include<conio.h>
struct student
{
	int roll,s1,s2,s3,total;
	char name[20];
	float per;
	struct student *next;
}*head,*newStd,*temp,*dummy;

int i,nor,search,flag,ch;
void save();
void AddStd()
{
	newStd=(struct student*)malloc(sizeof(struct student));
	printf("\n ROLL  : ");
	scanf("%d",&newStd->roll);
	printf("\n NAME  : ");
	fflush(stdin);
	gets(newStd->name);
	printf("\n SUB1  : ");
	scanf("%d",&newStd->s1);
	printf("\n SUB2  : ");
	scanf("%d",&newStd->s2);
	printf("\n SUB3  : ");
	scanf("%d",&newStd->s3);
	newStd->total=newStd->s1+newStd->s2+newStd->s3;
	newStd->per=newStd->total/3;
       //	newStd->per=newStd->s1+newStd->s2+newStd->s3/3;
	newStd->next=NULL;
}
void create()
{
	printf("\n HOW MANY RECORD DO YOU WANT ? : ");
	scanf("%d",&nor);
	for(i=1;i<=nor;i++)
	{
		printf("\n ENTER DETAIL OF STUDENT-%d",i);
		AddStd();
		if(head==NULL)
		{
			head=newStd;
			temp=head;
		}
		else
		{
			temp->next=newStd;
			temp=temp->next;
		}
	}
}
void display()
{
	if(head==NULL)
	{
		printf("\n NO RECORD FOUND !");
	}
	else
	{
		printf("\n\t\t STUDENT DATABASE MANAGEMENT SYSTEM");
		printf("\n\t\t ======= ======== ========== ======");
		printf("\n\n ROLL\tNAME\tSUB1\tSUB2\tSUB3\tTOTAL\tPERCENT");
		printf("\n ---------------------------------------------------------");
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("\n %d\t%s\t%d\t%d\t%d\t%d\t%.2f%",temp->roll,temp->name,temp->s1,temp->s2,temp->s3,temp->total,temp->per);
		}
	}
	save();
}
void insBegin()
{
	AddStd();
	if(head==NULL)
	{
		head=newStd;
	}
	else
	{
		newStd->next=head;
		head=newStd;
	}
}
void insEnd()
{
	AddStd();
	if(head==NULL)
	{
		head=newStd;
	}
	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=newStd;
	}
}
void insAfter()
{
	if(head==NULL)
	{
		printf("\n NO RECORD AVAILABLE");
	}
	else
	{
		flag=0;
		printf("\n AFTER WHICH ROLL NUMBER WANT TO ADD NEW ? ");
		scanf("%d",&search);
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			if(temp->roll==search)
			{
				flag=1;
				AddStd();
				newStd->next=temp->next;
				temp->next=newStd;
				break;
			}
		}
		if(flag==0)
		{
			printf("\n Roll Number Not Found ! ");
		}
	}
}
/*void insAtAny()
{
	if(head==NULL)
	{
		printf("\n NO RECORD AVAILABLE ! ");
	}
	else
	{
		printf("\n At Position You Want To Add ? :  ");
		scanf("%d",&search);
		for(i=1,temp=head;i<search,temp!=head;i++,temp=temp->next);
		temp->next=newStd;


	}
} */
void save()
{
	FILE* std;
	std=fopen("Student_DataBase.xls","w");
	fprintf(std,"\n\n ROLL\tNAME\tSUB1\tSUB2\tSUB3\tTOTAL\tPERCENT");
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		fprintf(std,"\n %d\t%s\t%d\t%d\t%d\t%d\t%.2f%",temp->roll,temp->name,temp->s1,temp->s2,temp->s3,temp->total,temp->per);
	}
	fclose(std);
}
void deleteFirst()
{
	if(head==NULL)
	{
		printf("\n NO RECORD FOUND! ");
	}
	else
	{
		temp=head;
		head=head->next;
		free(temp);
	}
}
void deleteLast()
{
	if(head==NULL)
	{
		printf("\n NO RECORD FOUND! ");
	}
	else
	{
		for(temp=head;temp->next->next!=NULL;temp=temp->next);
		free(temp->next);
		temp->next=NULL;
	}
}
void deleteAny()
{
	if(head==NULL)
	{
		printf("\n NO RECORD FOUND! ");
	}
	else
	{
		flag=0;
		printf("\n ENTER ROLL NUMBER : ");
		scanf("%d",&search);
		if(head->roll==search)
		{
			deleteFirst();
			flag=1;
		}
		else
		{
			for(temp=head;temp->next!=NULL;temp=temp->next)
			{
				if(temp->next->roll==search)
				{
					dummy=temp->next;
					temp->next=dummy->next;
					free(dummy);
					flag=1;
				}
			}
		}
		if(flag==0)
		{
			printf("\n ROLL NUMBER NOT FOUND! ");
		}

	}
}
void update()
{
	if(head==NULL)
	{
		printf("\n NO RECORD FOUND !");
	}
	else
	{
		flag=0;
		printf("\n ENTER ROLL NUMBER : ");
		scanf("%d",&search);
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			if(temp->roll==search)
			{
				flag=1;
				printf("\n 0 : WHOLE ");
				printf("\n 1 : Roll ");
				printf("\n 2 : Name ");
				printf("\n 3 : SUB1 ");
				printf("\n 4 : SUB2 ");
				printf("\n 5 : SUB3 ");
				printf("\n SELECT OPERATION");
				scanf("%d",&ch);
				if(ch==0)
				{
					printf("\n ROLL  : ");
					scanf("%d",&temp->roll);
					printf("\n NAME  : ");
					fflush(stdin);
					gets(temp->name);
					printf("\n SUB1  : ");
					scanf("%d",&temp->s1);
					printf("\n SUB2  : ");
					scanf("%d",&temp->s2);
					printf("\n SUB3  : ");
					scanf("%d",&temp->s3);
				}
				else
				{
					switch(ch)
					{
						case 1 : printf("\n ROLL :  ");
							 scanf("%d",&temp->roll);
							 break;
						case 2 : printf("\n NAME : ");
							 fflush(stdin);
							 gets(temp->name);
							 break;
						case 3 : printf("\n SUB1 :");
							 scanf("%d",&temp->s1);
							 break;
						case 4 : printf("\n SUB2 :");
							 scanf("%d",&temp->s2);
							 break;
						case 5 : printf("\n SUB3 :");
							 scanf("%d",&temp->s3);
							 break;
						default: printf("\n SELECT AVAILABLE FIELD!");
					}

				}
				temp->total=temp->s1+temp->s2+temp->s3;
				temp->per=temp->total/3;
			}
		}
	}
}
void main()
{
	clrscr();
	do
	{
		printf("\n MENU OF OPERATION ");
		printf("\n 1 : CREATE ");
		printf("\n 2 : Insert At Begins");
		printf("\n 3 : Insert At Ending");
		printf("\n 4 : Insert After Any");
		printf("\n 5 : Delete First ");
		printf("\n 6 : Delete Last ");
		printf("\n 7 : Delete Any ");
		printf("\n 8 : Update ");
		printf("\n 9 : SAVE ");
		printf("\n 0 : EXIT ");
		printf("\n ENTER CHOICE : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0 : exit(0);
			case 1 : create(); break;
			case 2 : insBegin(); break;
			case 3 : insEnd(); break;
			case 4 : insAfter(); break;
			case 5 : deleteFirst(); break;
			case 6 : deleteLast(); break;
			case 7 : deleteAny(); break;
			case 8 : update(); break;
			case 9 : save(); break;
			default : break;
		}
		display();
	}
	while(ch!=0);
	getch();
}