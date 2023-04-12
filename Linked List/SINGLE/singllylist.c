#include<stdio.h>
#include<conio.h>
struct node
{
	 int data;
	 struct node *next;
}*head,*temp1,*temp2,*dummy,*newnode,*temp;
int i,nor,flag,search;
void create()
{
	printf("\n NUMBER OF DATA RECORDS : ");
	scanf("%d",&nor);
	for(i=1;i<=nor;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n ENTER DATA : ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
			temp=head;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
		}
	}
}
void display()
{
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY ");
	}
	else
	{
		printf("\n SINGLY LIST : ");
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("%d->",temp->data);
		}
		printf("NULL");
	}
}
void insertBEGIN()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER DATA : ");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head=newnode;
	printf("\n INSERTED SUCCESSFULLY");
}
void insertEND()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER DATA : ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=newnode;
	}
	printf("\n INSERTED SUCCESSFULLY");
}
void insertAFTER()
{
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{
		flag=0;
		display();
		printf("\n ENTER ELEMENT : ");
		scanf("%d",&search);
		for(temp=head;temp->next!=NULL;temp=temp->next)
		{
			if(temp->data==search)
			{
				flag=1;
				newnode=(struct node*)malloc(sizeof(struct node));
				printf("\n ENTER DATA : ");
				scanf("%d",&newnode->data);
				newnode->next=temp->next;
				temp->next=newnode;
				printf("\n INSERTED SUCCESSFULLY");
				break;
			}
		}
		if(flag==0)
		{
			printf("\n DATA NOT FOUND !");
		}
	}
}
void deleteFIRST()
{
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
		printf("\n DELETED SUCCESSFULLY");
	}
}
void deleteLAST()
{
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{
		for(temp=head;temp->next->next!=NULL;temp=temp->next);
		free(temp->next);
		temp->next=NULL;
		printf("\n DELETED SUCCESSFULLY");
	}
}
void deleteANY()
{
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{
		flag=0;
		display();
		printf("\n ENTER DATA : ");
		scanf("%d",&search);
		if(head->data==search)
		{
			flag=1;
			deleteFIRST();
		}
		else
		{
			for(temp=head;temp->next!=NULL;temp=temp->next)
			{
				if(temp->next->data==search)
				{
					flag=1;
					dummy=temp->next;
					temp->next=dummy->next;
					free(dummy);
					break;
				}
			}
		}
		if(flag==0)
		{
			printf("\n DATA NOT FOUND");
		}
		else
		{
			printf("\n DELETED SUCCESSFULLY");
		}
	}
}
void update()
{
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{
		flag=0;
		display();
		printf("\n ENTER ELEMENT  : ");
		scanf("%d",&search);
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			if(temp->data==search)
			{
				flag=1;
				printf("\n ENTER DATA : ");
				scanf("%d",&temp->data);
				printf("\n UPDATED SUCCESSFULLY");
				break;
			}
		}
		if(flag==0)
		{
			printf("\n DATA NOT FOUND !");
		}
	}
}
void sortlist()
{
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{
		for(temp1=head;temp1->next!=NULL;temp1=temp1->next)
		{
			for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
			{
				if(temp1->data > temp2->data)
				{
					flag=temp1->data;
					temp1->data=temp2->data;
					temp2->data=flag;
				}
			}
		}
	}
}
void main()
{
	int ch;
	do
	{
		clrscr();
		printf("\n 0 : EXIT");
		printf("\n 1 : CREATE");
		printf("\n 2 : INSERT BEGINING");
		printf("\n 3 : INSERT ENDING");
		printf("\n 4 : INSERT AFTER");
		printf("\n 5 : DELETE FIRST");
		printf("\n 6 : DELETE LAST");
		printf("\n 7 : DELETE ANY");
		printf("\n 8 : UPDATE");
		printf("\n 9 : SORT");
		printf("\n 10 : DISPLAY");
		printf("\n ENTER CHOICE : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : create(); break;
			case 2 : insertBEGIN(); break;
			case 3 : insertEND(); break;
			case 4 : insertAFTER(); break;
			case 5 : deleteFIRST(); break;
			case 6 : deleteLAST(); break;
			case 7 : deleteANY(); break;
			case 8 : update(); break;
			case 9 : sortlist(); break;
			case 10 : display(); break;
			default : break;
		}
		getch();
	}
	while(ch!=0);
}