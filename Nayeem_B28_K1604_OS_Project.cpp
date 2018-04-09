#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	int queue1[n],queue2[n],queue3[n];
	int prty[n],process[n],burst_t[n],ari_t[n],r_t[n];
	int p,q,r;
	int tq,t,remaining,flag=0;
	float waiting_time=0,turn_time=0;
	remaining=p;
	int i,j,z=0;
	
	cout<<"\n\t\t\t***   Welcome in my Project   ***\n";
	
	cout<<"\n\t\t\t How many Process you want to processe\n";
	cout<<"\t\t\t";
	cin>>n;

	for(i=0;i<n;i++)
	{
		cout<<"\t\t\tenter process name for process %d = ",i+1,"\n\t\t\t";
		
		cin>>process[i];
		cout<<("\t\t\t enter priority for this process \n\t\t\t");
		cin>>prty[i];
		cout<<("\t\t\tenter burst time for this process \n\t\t\t");
		cin>>burst_t[i];
	}
	int temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(prty[j]>prty[j+1])	
			{
				temp=prty[j];
				prty[j]=prty[j+1];
				prty[j+1]=temp;
				temp=process[j];
				process[j]=process[j+1];
				process[j+1]=temp;
				temp=burst_t[j];
				burst_t[j]=burst_t[j+1];		
				burst_t[j+1]=temp;	
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\t\t\tProcess P%d",process[i]);
		printf(" its priority %d",prty[i]);
		printf(" and burst time %d",burst_t[i]);
		cout<<"\n";
	}
	
	cout<<"\n \t\t\tenter the number of processes you want to process in queue 1 \n\t\t\t";
	cin>>p;
	cout<<"\t\t\tenter the number of processes you want to process in queue 2 \n\t\t\t";
	cin>>q;
	cout<<"\t\t\tenter the number of processes you want to process in queue 3 \n\t\t\t";
	cin>>r;
	for(i=0;i<p;i++)
	{
		queue1[z]=prty[i];
		z=z+1;
	}
	
	cout<<"\n";
	cout<<"	\t\t\tQUEUE 1		       Priority	 \n";
	cout<<"\n";
	
	for(i=0;i<p;i++)
	{
		printf("\t\t\t	  P%d		   ",process[i]);
		printf("\t\t\t%d\n",prty[i]);
	}
	cout<<"\n\n";
	for(i=p;i<q+p;i++)
	{
		queue2[z]=prty[i];
		z=z+1;
	}
		cout<<"\n";
	cout<<"\n";
	cout<<"	\t\t\tQUEUE 2	         Priority	 \n";
	cout<<"\n";
	
	
	for(i=p;i<q+p;i++)
	{
	printf("\t\t\t	  P%d		   ",process[i]);
	printf("\t\t\t%d\n",prty[i]);
	}
	cout<<"\n\n";
	for(i=q+p;i<r+q+p;i++)
	{
		queue3[z]=prty[i];
		z=z+1;
	}
		cout<<"\n";

	cout<<"\n";
	cout<<"\t\t\t	QUEUE 3	           	Priority	\n";
	cout<<"\n";
	
	for(i=q+p;i<r+p+q;i++)
	{
		printf("\t\t\t	  P%d		   ",process[i]);
		printf("\t\t\t%d\n",prty[i]);
	}

	cout<<"\n";
	 	cout<<"\n";
	
	cout<<"\t\t\tQUEUE 1 Round robin scheduling\n";
	for(i=0;i<p;i++)
	{
		printf("\t\t\tEnter arrival time for P%d =",process[i],"\t\t\t");
		cin>>ari_t[i];
		r_t[i]=burst_t[i];
	}
	cout<<"\t\t\tenter time quantum =";
	cin>>tq;
	cout<<"\n\n\t\t\tProcess\t  Turnaround time  Waiting time\n\n";
	for(t=0,i=0;remaining!=0;)
	{
		if(r_t[i]<=tq && r_t[i]>0)
		{
			t=t+r_t[i];
			r_t[i]=0;
			flag=1;
		}
		else if(r_t[i]>0)
		{
			r_t[i]=r_t[i]-tq;
			t=t+tq;
		}
		if(r_t[i]==0 && flag==1)
		{
			remaining--;
			printf("\t\t\tP%d\t  \t%d\t  \t%d\n",i+1,t-ari_t[i],t-ari_t[i]-burst_t[i]);
			waiting_time=waiting_time+t-ari_t[i]-burst_t[i];
			turn_time=turn_time+t-ari_t[i];
			flag=0;
		}
		if(i==p-1)
			i=0;
		else if(ari_t[i+1]<=t)
		i++;
		else
		i=0;
	}
		printf("\n\t\t\tAverage waiting time= %f\n",waiting_time/p);
		printf("\n\t\t\tAverage turnaround time= %f\n",turn_time/p);

		cout<<"\n\n\t\t\tQUEUE 2 Priority  scheduling\n";
		float w_time[n],t_time[n];
		float avg_wt,avg_tat,total=0;
		w_time[p]=0;
	for(i=p+1;i<q+p;i++)
	{
		w_time[i]=0;
		for(j=p;j<i;j++)
			w_time[i]=w_time[i]+burst_t[j];
			total=total+w_time[i];
	}
	avg_wt=total/q;
	total=0;
	cout<<"\n\t\t\tProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
	for(i=p;i<q+p;i++)
	{
		t_time[i]=burst_t[i]+w_time[i];
		total=total+t_time[i];
		printf("\n\t\t\tP%d\t\t%d\t\t%d\t\t%d",i+1,burst_t[i],w_time[i],t_time[i]);
	}
	avg_tat=total/q;
	printf("\n\t\t\tAverage waiting time= %f\n",avg_wt);
	printf("\n\t\t\tAverage turnaround time= %f\n",avg_tat);

	cout<<"\n\n\t\t\tQUEUE 3  FCFS scheduling\n";
	float w_t[n],t_at[n];
	float av_wt=0,av_tat=0;
	w_t[q+p]=0;
	for(i=q+p+1;i<r+p+q;i++)
	{
		w_t[i]=0;
	for(j=q+p;j<i;j++)
	w_t[i]=w_t[i]+burst_t[j];
	}
	cout<<"\n\t\t\tProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
	for(i=q+p;i<q+p+r;i++)
	{
		t_at[i]=burst_t[i]+w_t[i];
		av_wt=av_wt+w_t[i];
		av_tat=av_tat+t_at[i];
		printf("\n\t\t\tP%d\t\t%d\t\t%d\t\t%d",i+1,burst_t[i],w_t[i],t_at[i]);
	}

	printf("\n\t\t\tAverage waiting time= %f\n",av_wt/r);
	printf("\n\t\t\tAverage turnaround time= %f\n",av_tat/r);
	
	cout<<"\n\n\n\t\t\t\t!!!!!***   THANK YOU ***!!!!!";
	return 0;
}

