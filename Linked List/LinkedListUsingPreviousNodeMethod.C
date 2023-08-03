/******************************************************************

	TITLE : LINKED LIST BY STORING ADDRESS OF PREVIOUS NODE
	CODER : RAHUL BARAIYA
	 ROLL : 9
	 DATE : 19/07/2023

	------------------------------------------
	 THIS PROGRAM SUPPORT FOLLOWING OPERATION
	------------------------------------------

		[1] : INSERTION AT BEGINING
		[2] : INSERTION AT ENDING
		[3] : INSERTION AFTER PARTICULAR NODE
		[4] : DELETION OF FIRST NODE
		[5] : DELETION OF LAST NODE
		[6] : DELETION OF ANY PARTICULAR NODE
		[7] : SEARCH
		[8] : UPDATION
		[9] : DISPLAY


*******************************************************************/
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *prev;
}*start,*end,*temp,*dummy;
void display() // displaying all the nodes data available in list
{
	if(end=='\0')
	{
		printf("\n List is empty!");
	}
	else
	{
		for(temp=end;temp!='\0';temp=temp->prev)//data display from last to first
		{
			printf("\n\t\t\t[%u] %d [->%u]",temp,temp->data,temp->prev);
		}
		printf("NULL");
	}
}
// insering node after end node
void insertAtEnding()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n\t\t\t Enter Data : ");
	scanf("%d",&temp->data);
	temp->prev=end;
	if(start=='\0')
	{
		start=temp;
	}
	end=temp;
	printf("\t\t\t Inserted Successfully !");
}
// inserting node before start node
void insertAtBegining()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n\t\t\t Enter Data : ");
	scanf("%d",&temp->data);
	temp->prev='\0';
	if(end=='\0')
	{
		end=temp;
	}
	else
	{
		start->prev=temp;
	}
	start=temp;
	printf("\t\t\t Inserted Successfully !");
}
// insert node before particular node
void insertBefore()
{
	if(end=='\0')
	{
		printf("\t\t\t List Is Empty");
	}
	else
	{
		if(isDataFound()==1)
		{
			 dummy=(struct node*)malloc(sizeof(struct node));
			 printf("\t\t\t Enter Data : ");
			 scanf("%d",&dummy->data);
			 dummy->prev=temp->prev;
			 temp->prev=dummy;
		}
		else
		{
			printf("\t\t\t Data Unavailable");
		}
	}
}
// deletion of end node
void deleteLast()
{
	if(end=='\0')
	{
		printf("\n\t\t\t list is empty !");
	}
	else
	{
		temp=end;
		end=end->prev;
		free(temp);
		printf("\n\t\t\t Deleted Successfully !");
	}
}
// deletion of start node
void deleteFirst()
{
	if(end=='\0')
	{
		printf("\n\t\t\t list is empty !");
	}
	else
	{
		if(end->prev=='\0')
			deleteLast();
		else
		{
			for(temp=end;temp->prev!=start;temp=temp->prev);
			free(start);
			start=temp;
			start->prev='\0';
			printf("\n\t\t\t Deleted Successfully !");
		}
	}
}
// deletion of any particular node
void deleteAny()
{
	int srch;
	if(end=='\0')
	{
		printf("\n\t\t\tList is empty !");
	}
	else
	{
		printf("\n\t\t\t Enter Data : ");
		scanf("%d",&srch);
		if(end->data==srch)
			deleteLast();
		else if(start->data==srch)
			deleteFirst();
		else
		{
			for(temp=end;temp!='\0';temp=temp->prev)
			{
				if(temp->prev->data==srch)
				{
					dummy=temp->prev;
					temp->prev=dummy->prev;
					free(dummy);
					printf("\n\t\t\t Deleted Successfully !");
					return;
				}
			}
			printf("\n\t\t\t Data Unavailable");
		}
	}
}
// boolean type function for searching
int isDataFound()
{
	int srch;
	printf("\n\t\t\t Enter Data : ");
	scanf("%d",&srch);
	for(temp=end;temp!='\0';temp=temp->prev)
	{
		if(temp->data==srch)
			return 1;
	}
	return 0;
}
// searching function
void searchNode()
{
	if(end=='\0')
	{
		printf("\n\t\t\t list Is Empty !");
	}
	else
	{
		if(isDataFound()==1)
		{
			printf("\t\t\t Data Available !");
		}
		else
		{
			printf("\t\t\t Data Unavailable !");
		}
	}
}
// to update particular nodes data
void update()
{
	if(end=='\0')
	{
		printf("\n\t\t\t list Is Empty !");
	}
	else
	{
		if(isDataFound()==1)
		{
			printf("\t\t\t Enter New Data : ");
			scanf("%d",&temp->data);
		}
		else
		{
			printf("\t\t\t Data Unavailable !");
		}
	}

}
// to getting user choice
char getCommand()
{
	char c;
	printf("\t\t\t----------------------------\n");
	printf("\t\t\t| COMMANDS MENU : LINKLIST |\n");
	printf("\t\t\t----------------------------\n");
	printf("\t\t\t| [1] : Insert_At_Begining |\n");
	printf("\t\t\t| [2] : Insert_At_Ending   |\n");
	printf("\t\t\t| [3] : Insert_Before      |\n");
	printf("\t\t\t| [4] : Delete_First       |\n");
	printf("\t\t\t| [5] : Delete_Last        |\n");
	printf("\t\t\t| [6] : Delete_Any         |\n");
	printf("\t\t\t| [7] : Search             |\n");
	printf("\t\t\t| [8] : Update             |\n");
	printf("\t\t\t| [9] : DISPLAY            |\n");
	printf("\t\t\t----------------------------\n");
	printf("\t\t\t| Enter Command : ");
	c=getche();
	clrscr();
	return c;
}
void main()
{
	char cmd;
	clrscr();
	do
	{
		cmd=getCommand();
		printf("\n\t\t\t----------------------------");
		switch(cmd)
		{
			case '0' : exit(); break;
			case '1' : insertAtBegining(); break;
			case '2' : insertAtEnding(); break;
			case '3' : insertBefore(); break;
			case '4' : deleteFirst(); break;
			case '5' : deleteLast(); break;
			case '6' : deleteAny(); break;
			case '7' : searchNode(); break;
			case '8' : update(); break;
			case '9' : display(); break;
			default: break;
		}
		printf("\n\t\t\t----------------------------");
		getch();
		clrscr();
	}
	while(1);
	getch();
}