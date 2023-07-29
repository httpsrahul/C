/******************************************************************

	TITLE : LINKED LIST BY STORING ADDRESS OF NEXT NODE
	CODER : RAHUL BARAIYA
	 DATE : 19/07/2023

	----------------------------------------
	THIS PROGRAM SUPPORT FOLLOWING OPERATION
	----------------------------------------

		[1] : INSERTION AT BEGINING
		[2] : INSERTION AT ENDING
		[3] : INSERTION AFTER PARTICULAR NODE
		[4] : DELETION OF FIRST NODE
		[5] : DELETION OF LAST NODE
		[6] : DELETION OF ANY NODE
		[7] : SEARCH DATA
		[8] : UPDATION DATA
		[9] : DISPLAY DATA


*******************************************************************/
#include<stdio.h>
#include<string.h>
#include<conio.h>

//node structure
struct node
{
	int data;
	struct node *next;
}*start,*end,*temp,*dummy='\0';
int isFound=0,srch;
// insertion before first node
void insertAtBegin()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n\t\t\tEnter Data : ");
	scanf("%d",&temp->data);
	temp->next=start;
	if(end=='\0')
		 end=temp;
	start=temp;
	printf("\t\t\tInseterd Successfully !");
}
// insertion after last node
void insertAtEnd()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n\t\t\tEnter Data : ");
	scanf("%d",&temp->data);
	temp->next='\0';
	if(start=='\0')
		start=temp;
	else
		end->next=temp;
	end=temp;
	printf("\t\t\tInseterd Successfully !");
}
// boolean function for searching
// objective of this function is to make search(), update() & insertAfter() easier !
int isDataFound()
{
	printf("\n\t\t\tEnter Value Of Node :  ");
	scanf("%d",&srch);
	for(temp=start;temp!='\0';temp=temp->next)
	{
		if(srch==temp->data)
		{
			return 1;
		}
	}
	return 0;
}
// insertion after particular node
void insertAfter()
{
	if(start=='\0')
		printf("\n\t\t\t List Dosen't Exist !");
	else
	{
		if(isDataFound()==1)
		{
			if(srch==end->data)
				insertAtEnd();
			else
			{
				dummy=(struct node*)malloc(sizeof(struct node));
				printf("\t\t\t Enter Data : ");
				scanf("%d",&dummy->data);
				dummy->next=temp->next;
				temp->next=dummy;
				printf("\t\t\t Inserted Successfully !");
			}
		}
		else
			printf("\t\t\t Data Not Found !");
	}
}
// delition of first node
void deleteFirst()
{
	if(start=='\0')
		printf("\n\t\t\t List Dosen't Exist !");
	else
	{
		temp=start;
		start=start->next;
		free(temp);
		printf("\n\t\t\t Deleted Successfully !");
	}
}
// delition of last node
void deleteLast()
{
	if(start=='\0')
		printf("\n\t\t\t List Dosen't Exist !");
	else
	{
		for(temp=start;temp->next!=end;temp=temp->next);
		end=temp;
		free(end->next);
		end->next='\0';
		printf("\n\t\t\t Deleted Successfully !");
	}
}
// delition of any particular node
void deleteAny()
{
	if(start=='\0')
		printf("\n\t\t\t Link Dosen't Exist !");
	else
	{
		printf("\n\t\t\t Enter Value Of Node : ");
		scanf("%d",&srch);
		if(start->data==srch)
		{
			deleteFirst();
			isFound=1;
		}
		else if(end->data==srch)
		{
			deleteLast();
			isFound=1;
		}
		else
		{
			for(isFound=0,temp=start;temp!='\0';temp=temp->next)
			{
				if(srch==temp->next->data)
				{
					isFound=1;
					dummy=temp->next;
					temp->next=dummy->next;
					free(dummy);
					printf("\t\t\t Deleted Successfully !");
					break;
				}
			}
			if(isFound==0)
				printf("\t\t\t Data Not Found !");
		}
	}
}
// updation of any particular node
void update()
{
	if(start=='\0')
		printf("\n\t\t\t List Dosen't Exist !");
	else
	{
		if(isDataFound()==1)
		{
			printf("\n\t\t\t Enter New Data : ");
			scanf("%d",&temp->data);
			printf("\t\t\t Updated Successfully");
		}
		else
			printf("\n\t\t\t Element Not Found !");
	}
}
// main search function
void searchNode()
{
	if(isDataFound()==1)
	{
		printf("\n\t\t\t Element Found !");
		printf("\n\t\t\t [%u] [%d] -> [%u]",temp,temp->data,temp->next);
	}
	else
	{
		printf("\n\t\t\t Element Not Found !");
	}
}
// function for displaying data
void display()
{
	if(start=='\0')
		printf("\n\t\t\t Link Dosen't Exist !");
	else
	{
		printf("\n\t\t\t[BASE] [DATA] -> [NEXT]");
		printf("\n\t\t\t-----------------------");
		for(temp=start;temp!=NULL;temp=temp->next)
		{
			printf("\n\t\t\t [%u] [%d] -> [%u]",temp,temp->data,temp->next);
		}
	}
}
 