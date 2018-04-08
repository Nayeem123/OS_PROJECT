#include<stdio.h>
int main()
{
	int queue1[50];
	int queue2[50];
	int queue3[50];
	int i,n,ar_time[30],b_time[30];
	char p_name[20];
	int tq1=4;
	int j,k;
	printf("\n\n \t\t\t\t WELCOME IN MY O.S. PROJECT :\n");
/*	printf("\t\t\t\tEnter number of process :\n");
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
	while(tq!=0)
	{
		for(i=0;i<n;i++)
		{
			if(ar_time[i]==0)
			{
				printf("\n\t\t\t\t%c \t%d\t %d\n",p_name[i],b_time[i],ar_time[i]);
			}
		}
	}
	*/
	 int count,j,n,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
	  
	return 0;
	
}
