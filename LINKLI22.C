#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
}*start='\0',*temp='\0',*end='\0';
void insertAtEnd()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n Enter Data : ");
	scanf("%d",&temp->data);
	temp->next='\0';
	if(start=='\0')
	{
		start=temp;
	}
	else
	{
		end->next=temp;
	}
	end=temp;
}
void insertAtBegin()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n Enter data : ");
	scanf("%d",&temp->data);
	temp->next=start;
	if(end=='\0')
	{
		end=temp;
	}
	start=temp;
}
void deleteFirst()
{
	temp=start;
	start=start->next;
	free(temp);
}
void display()
{
	temp=start;
	while(temp!='\0')
	{
		printf("\n [%u] %d [->%u]",temp,temp->data,temp->next);
		temp=temp->next;
	}
}
void main()
{
	int ch;
	clrscr();
	do
	{
		printf("\n-----------------");
		printf("\n 0 : EXIT");
		printf("\n 1 : InsertAtBegin");
		printf("\n 2 : InsertAtEnd");
		printf("\n 3 : DeleteFirst");
		printf("\n 4 : DeleteLast");
		printf("\n---------------\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0 : exit(0);
			case 1 : insertAtBegin(); break;
			case 2 : insertAtEnd(); break;
			case 3 : deleteFirst(); break;
	//		case 4 : deleteLast(); break;
			default : break;
		}
		display();
		getch();
	}
	while(ch!=0);
}
