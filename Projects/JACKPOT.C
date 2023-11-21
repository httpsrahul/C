/*
    [#]-------------------------------------------[#]
	|                                             |
	|     Jackpot Betting Game [For Just Fun]     |
	|                                             |
    [#]------------------[ made by geeksrahul ]---[#]
*/
#include<stdio.h>
#include<conio.h>
#include<time.h>

#define true 1
#define false 0
typedef short int bool;

void help()
{
	printf("\n\t\t\t----------------------------------");
	printf("\n\t\t\t JACKPOT DHAMAKA : EK KA DOUBLE !");
	printf("\n\t\t\t----------------------------------");
	printf("\n\t\t\t * You Have To Enter Amount");
	printf("\n\t\t\t * Then You Have To Enter A Digit");
	printf("\n\t\t\t   On Which You Want To Bet !");
	printf("\n\t\t\t * If Middle Slot Get Same Digits");
	printf("\n\t\t\t   Then You Won 2x Amount !");
	printf("\n\t\t\t * Else You Lose Your Amount !");
	printf("\n\t\t\t----------------------------------");
}
int get_player_digit()
{
	int digit;
	while(1)
	{
		printf("\t\t\t On Which Digit You Want To Bet : ");
		scanf("%d",&digit);
		if(digit>=0 && digit<=9){
			return digit;
		}
		printf("\t\t\t Enter Digit From 0 to 9 ! \n");
	}
}
int get_player_amount()
{
	int amount;
	printf("\n\t\t\t Enter Amount : ");
	scanf("%d",&amount);
	return amount;
}
int get_random_digit(int n)
{
	srand(rand());
	return rand()%n;
}
void display_board(int* n)
{
	clrscr();
	printf("\n\t\t\t\t|--------------|");
	printf("\n\t\t\t\t| Jackpot Slot |");
	printf("\n\t\t\t\t|--------------|");
	printf("\n\t\t\t\t| %d  | %d  | %d  |",n[0],n[3],n[6]);
	printf("\n\t\t\t\t|----|----|----|");
	printf("\n\t\t\t\t| %d  | %d  | %d  |",n[1],n[4],n[7]);
	printf("\n\t\t\t\t|----|----|----|");
	printf("\n\t\t\t\t| %d  | %d  | %d  |",n[2],n[5],n[8]);
	printf("\n\t\t\t\t|--------------|");
}

bool start_game(int digit)
{
	short int digits[9];
	short int i=0;
	int spins;
	spins=get_random_digit(1000);
	while(spins!=0)
	{
		for(i=0;i<9;i++)
		{
			digits[i]=get_random_digit(9);
		}
		display_board(digits);
		delay(10);
		if(digits[1]==digit && digits[1]==digits[4] && digits[1]==digits[7]){
			return true;
		}
		spins--;
	}
	return false;
}
void main()
{
	int digit,amount;
	char decision;
	bool won;

	clrscr();
	help();

	amount=get_player_amount();
	digit=get_player_digit();
	won=start_game(digit);
	printf("\n\t\t\t----------------------------------");
	printf("\n\t\t\t Amount You Have Entered : %d",amount);
	printf("\n\t\t\t Digit In Which You Betted : %d",digit);
	if(won)
	{
		printf("\n\t\t\t Congrats, You Won %d",2*amount);
	}
	else
	{
		printf("\n\t\t\t OOPS,you lose your amount :(");
	}
	printf("\n\t\t\t----------------------------------");
	printf("\n\t\t\t PlayAgain ? (y/n) : ");
	fflush(stdin);
	decision=getche();
	if(decision=='y' || decision=='Y')
	{
		main();
	}
}