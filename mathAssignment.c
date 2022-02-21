/*
 * =====================================================================================
 *
 *       Filename:  mathAssignment.c
 *
 *    Description: math work 
 *
 *        Version:  1.0
 *        Created:  18/02/22 13:04:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	int num, i, d1, d2, d3, pwin=0, bet, money=0;
	time_t t1;
	

	printf("How many times will you be simulating this specific dice rolling equation?\n");
	scanf(" %d", &num);

	printf("How much are you betting?\n");
	scanf(" %d", &bet);

	srand((unsigned) time (&t1));
	printf("\n");	
	for (i=0;i<num;i++)
	{
		money-=bet;
		/* randomise dice*/
		d1=rand() % 8;

		d2=rand() % 8;

		d3=rand() % 8;

		/* compare dice */
		/*  
		if (d1==d2 && d1==d3)
		{
			printf("Player Wins\n");
			pwin++;
			money += bet*75;
		}
		
		if ((d1 == d2-1 && d1 == d3-2) || (d1 == d3-1 && d1 == d2 - 2) || (d2 == d1 - 1 && d2 == d3 -2 ) || (d2 == d3 - 1 && d2 == d1 -2 ) || (d3 == d2 -1 && d3 == d1 -2) || (d3 == d1 -1 && d3 == d2 -2))
		{
			printf("Player Wins\n");
			pwin++;
			money += bet*14;
		}
			
		 if ((d1 + d2 + d3) > 20)
		{
			printf("Player Wins\n");
			pwin++;
			money += bet*500;
		}
		*/	
		if ((d1 + d2 + d3) > 18 && (d1+d2+d3) < 20)
		{
			printf("Player Wins\n");
			pwin++;
			money += bet*80;
		}
		/*
		if ((d1 + d2 + d3) > 16 && (d1+d2+d3) < 18)
		{
			printf("Player Wins\n");
			pwin++;
			money += bet*10;
		}
		*/
	} 
	printf("%d\n", pwin);
	printf ("%d\n", money);
	return 0;
}
