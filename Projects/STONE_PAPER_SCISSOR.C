#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,nor,p_choice,b_choice,p_win=0,b_win=0;
char p_name[10];
void round();
void inputChoice();
void displayChoice();
void game();
void main()
{
	clrscr();
	printf("\n===================================");
	printf("\n\tSTONE PAPER SCISSOR ");
	printf("\n===================================");
	printf("\nENTER NAME : ");
	fflush(stdin);
	gets(p_name);
	printf("\-----------------------------------");
	printf("\nHELLO %s,I AM AN BOT AND HERE WE\nGONNA TO PLAY STONE PAPER SCISSOR",p_name);
	printf("\nHow Many Round You Wanna Play : ");
	scanf("%d",&nor);
	printf("\-----------------------------------");
	for(i=1;i<=nor;i++)
	{
		printf("\n>>> ROUND-%d <<<",i);
		round();
	}
	printf("\nYOUR WINNING : %d",p_win);
	printf("\nBOTS WINNING : %d",b_win);
	printf("\n===================================");
	if(p_win==b_win)
	{
		printf("\nOOPS, THIS GAME HAS BEEN DRAWN");
	}
	else if(p_win > b_win)
	{
		printf("\nCONGRATULATIONS, YOU WON THIS GAME");
	}
	else
	{
		printf("\nSORRY, BETTER LUCK FOR NEXT TIME");
	}

	printf("\n===================================");
	getch();
}
void inputChoice()
{
	srand(time(NULL));
	b_choice=rand()%3;
	printf("\n---------------");
	printf("\n| CHOICE MENU |");
	printf("\n---------------");
	printf("\n| 0 : STONE   |");
	printf("\n| 1 : PAPER   |");
	printf("\n| 2 : SCISSOR |");
	printf("\n---------------");
	do
	{
		printf("\nYour Choice: ");
		scanf("%d",&p_choice);
	}
	while(p_choice<0 || p_choice>2);
	printf("---------------");
}
void displayChoice()
{
	printf("\nYOU : ");
	switch(p_choice)
	{
		case 0 : printf("STONE"); break;
		case 1 : printf("PAPER"); break;
		case 2 : printf("SCISSOR"); break;
		default : break;
	}
	printf("\nBOT : ");
	switch(b_choice)
	{
		case 0 : printf("STONE"); break;
		case 1 : printf("PAPER"); break;
		case 2 : printf("SCISSOR"); break;
		default : break;
	}
}
void game()
{
	printf("\n-----------------------------------");
	if(p_choice==b_choice)
	{
		printf("\nTIED , WE NEED TO PLAY THIS AGAIN");
		printf("\n-----------------------------------");
		printf("\n>>> ROUND-%d <<<",i);
		round();
	}
	else if((p_choice==0 && b_choice==2) || (p_choice==1 && b_choice==0) || (p_choice==2 && b_choice==1))
	{
		printf("\nCONGRATULATIONS,YOU WON THIS ROUND");
		p_win++;
	}
	else
	{
		printf("\nSORRY, BETTER LUCK FOR NEXT TIME !");
		b_win++;
	}
	printf("\n-----------------------------------");

}
void round()
{
	inputChoice();
	displayChoice();
	game();
}
