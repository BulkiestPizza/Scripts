/*
 * =====================================================================================
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
	int num, i, d1, d2, d3, pwin=0, money=0, pwin3fk=0, pwin3row=0, pwin18=0, pwin20=0, pwin24=0;
	double per=0.0, cas=100.0, hedge;
	time_t t1;
	

	printf("How many times will you be simulating this specific dice rolling simulation?\n");
	scanf(" %d", &num);

	srand((unsigned) time (&t1));
	printf("\n");	
	for (i=0;i<num;i++)
	{
		money-=1000;
		/* randomise dice*/
		d1=rand() % 8;
		
		d2=rand() % 8;
		
		d3=rand() % 8;
		
		d1++;d2++;d3++;
		int dt=d1+d2+d3;
		/* compare dice */
		if (dt == 24)
		{
			pwin++;
			pwin24++;
			money += 15450;
		}
			
	
		if (d1 == d2 && d1 == d3)
		{
			pwin++;
			pwin3fk++;
			money += 6200; 
		}
		
		if (dt >=22 && dt < 24)
		{
			pwin++;
			pwin20++;
			money += 5850;
		}
	 
		if (dt >= 20 && dt < 22)
		{
			pwin++;
			pwin18++;
			money += 4500;
		}
			
		if ((d1+1 == d2 && d1+2 == d3) || (d1+1 == d3 && d1+2 == d2) || (d2+1 == d3 && d2+2 == d1) || (d2+1 == d1 && d2+2 == d3) || (d3+1 == d2 && d3+2 == d1) || (d3+1 == d1 && d3+2 ==d2))
		{
			pwin++;
			pwin3row++;
			money += 3500;
		}
		
	}
		
	printf("Player Wins-%d\n", pwin);
	printf("Money Made-%d\n\n", money);
	printf("%d-3 of a kind", pwin3fk);

	per=((double)pwin3fk/(double)num)*100;
	printf("\n%f\%\n\n", per);
	cas=cas-per;
	
	printf("%d -3 in a row", pwin3row);
	per=((double)pwin3row/(double)num)*100;
	printf("\n%f\%\n\n", per);
	cas=cas-per;
	
	printf("%d -20", pwin18);
	per=((double)pwin18/(double)num)*100;
	printf("\n%f\%\n\n", per);
	cas=cas-per;
	
	printf("%d -22", pwin20);
	per=((double)pwin20/(double)num)*100;
	printf("\n%f\%\n\n", per);
	cas=cas-per;
	
	printf("%d -24", pwin24);
	per=((double)pwin24/(double)num)*100;
	printf("\n%f\%\n\n", per);
	cas=cas-per;
	
	printf("%f\n", hedge);
	printf("%f", cas);
	return 0;
}
