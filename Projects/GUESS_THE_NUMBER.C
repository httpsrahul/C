#include<stdio.h>
#include<conio.h>
int points=105,b_num,p_num,i=0;
void instruction();
void thinkNumber();
void guessNumber();
void result();
void main()
{
	clrscr();
	instruction();
	thinkNumber();
	guessNumber();
	result();
	getch();
}
void instruction()
{
	printf("\n===========================================");
	printf("\n\t    GUESS THE NUMBER");
	printf("\n===========================================");
	printf("\n * STEPS");
	printf("\n-------------------------------------------");
	printf("\n [1]. PLAYER WILL PLAYING WITH BOT");
	printf("\n [2]. BOT WILL THINK RANDOM NUMBER");
	printf("\n [3]. PLAYER HAVE TO GUESS IT TRUE");
	printf("\n-------------------------------------------");
	printf("\n * RULES");
	printf("\n-------------------------------------------");
	printf("\n [1]. PLAYER SCORE WILL 100 IF THE\n      PLAYER SUCCEED ON FIRST TRY!");
	printf("\n [2]. PLAYER HAVE ONLY 7 EXTRA TRY");
	printf("\n [3]. 5 POINT REDUCE PER EXTRA TRY");
}
void thinkNumber()
{
	srand(time(NULL));
	b_num=rand()%100;
}
void guessNumber()
{
	do
	{
		printf("\n-------------------------------------------");
		printf("\n| ATTEMPT-%d                               |",i);
		points-=5;
		printf("\n| WHICH NUMBER IN MY MIND ? : ");
		scanf("%d",&p_num);
		if(b_num==p_num)
		{
			printf("| OHV, YOU GUESSED IT AWESOME !           |");
			break;
		}
		else if(b_num>p_num)
		{
			printf("| MINE NUMBER IS GREATER, TRY AGAIN       |");
		}
		else
		{
			printf("| MINE NUMBER IS SMALLER, TRY AGAIN       |");
		}
		i++;
	}
	while(i<8);

}
void result()
{
	printf("\n-------------------------------------------");
	printf("\n * RESULT");
	printf("\n-------------------------------------------");
	if(i==8)
	{
		printf("\n| SORRY YOU LOST THIS GAME VERY BADLY !   |");
		printf("\n| MINE THINKED NUMBER IS %d               |",b_num);
	}
	else
	{
		printf("\n| YOU TAKE %d EXTRA ATTEMPTS               |",i-1);
		printf("\n| SO YOUR SCORE IS 100 - %d = %d          |",(i-1)*5,points);
	}
	printf("\n-------------------------------------------");
	printf("\n| GAME HAS BEEN CREATED BY RAHUL BARAIYA! |");
	printf("\n-------------------------------------------");
}