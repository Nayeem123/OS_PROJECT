#include<stdio.h>
int main()
{
	int queue1[50];
	int queue2[50];
	int queue3[50];
	int i,n,ar_time[30],b_time[30];
	char p_name[20];
	printf("\n\n \t\t\t\t WELCOME IN MY O.S. PROJECT :\n");
	printf("\t\t\t\tEnter number of process :\n");
	scanf("%d",&n);
	printf("\t\t\t\tname of process \t burst time \t arrival time\n");
	for(i=0;i<n;i++)
	{
		scanf("%c %d %d",&p_name[i],&b_time[i],&ar_time[i]);
	}
	
	for(i=0;i<n;i++)
	{
		printf("\n\t\t\t\t%c \t%d\t %d\n",p_name[i],b_time[i],ar_time[i]);
	}
	return 0;
	
}
