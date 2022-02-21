/*
 * =====================================================================================
 *
 *       Filename:  applicationListandGrouper.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/12/21 17:52:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <regex.h>

struct Applications {
	char Name[50];
	char Exec[100];
	char AllCategories[100];
	char Categories[7][100];
	int CatLen;
};

char categoryList[100];

struct Applications app[1000];
int main()
{
    FILE *fp;
	DIR *dp;
	struct dirent *pDirent;
	char line[256];
	dp = opendir("/usr/share/applications");
	int nc=0, i=0, ec=0, total=0, j=0, n=0, k=0;
	chdir("/usr/share/applications")	;
	while ((pDirent = readdir(dp)) !=NULL){
		fp = fopen(pDirent -> d_name , "r");
		if (fp == NULL)
		{
			printf("Unable to open %s\n", pDirent -> d_name);
			exit(0);
		}
		while (fgets(line,sizeof(line), fp))
		{

			if (strstr (line, "GenericName=") == NULL && strstr(line, "Name=") != NULL && nc == 0)
			{
				nc=1;
				
				strcpy(app[i].Name, line);
							}
			if (strstr (line, "Exec=") != NULL && ec ==0 && strstr (line, "TryExec") == NULL)
			{
				ec=1;
				strcpy(app[i].Exec, line);

				
			}


			if (strstr(line, "Categories=") != NULL)
			{
				strcpy(app[i].AllCategories, line);
			}

			if (strcmp (app[i].Name, "") && strcmp(app[i].Exec, "") && strcmp(app[i].AllCategories,"") ){
				i++;
				total++;
			}
		}
		nc=0;
		ec=0;
		fclose (fp);
	
	}
		for (i=0; i<=total;i++)
	{
		for (j=0; j<=4; j++)
		{
				memmove(app[i].Name, app[i].Name +1, strlen(app[i].Name));
				memmove(app[i].Exec, app[i].Exec + 1, strlen(app[i].Exec));
		}
		app[i].Name[strcspn(app[i].Name, "\n")] = 0; 
		app[i].Exec[strcspn(app[i].Exec, "\n")] = 0;
		if ( i == 66 )
		{
			printf("\n");
		}
		printf("{\"%s\", \"%s\"}\n", app[i].Name, app[i].Exec);
		printf("%s", app[i].AllCategories);
	}	
		/*Category listing*/
	
	 /* Get all groups separated with a semicolon, and then add them to an array of the groups that the object is present */
	/* 1. Copy categories from the struct app.AllCategories into an array with all of them  || Complete*/
		for (i=0; i<=total; i++)
		{
			app[i].CatLen=0;
			for (j=0; j <strlen(app[i].AllCategories); j++)
			{
				if (j >= 11)
				{
					if (app[i].AllCategories[j] != ';')
					{
						app[i].Categories[n][k]=app[i].AllCategories[j];
						k++;
					}
					else if (app[i].AllCategories[j] == ';' && app[i].CatLen <=10)
					{
						app[i].CatLen++;
						n++;
						k=0;
					}
				
				}
				}
			n=0;
			k=0;
		}
		for (i=0; i <=total; i++)
		{
			printf("%d", app[i].CatLen);
			for (j=0; j<app[i].CatLen; j++)
			{
				if (strcmp(app[i].Categories[j], "\0")!= 0)
				{
				printf("%s\n", app[i].Categories[j]);
				}
			}
		}
return 0;
}

