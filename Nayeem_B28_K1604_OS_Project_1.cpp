#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	int queue1[n],queue2[n],queue3[n];
	int prty[n],process[n],burst_t[n],ari_t[n],r_t[n];
	int tq,t,remain,flag=0;
	float waiting_time=0,turn_time=0;
	
	int i,j;
	int z=0;
	cout<<"\n\t\t\t How many Process you want to processe\n";
	cout<<"\t\t\t";
	cin>>n;
	
	int a,b,c;
	remain=a;
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
	cin>>a;
	cout<<"\t\t\tenter the number of processes you want to process in queue 2 \n\t\t\t";
	cin>>b;
	cout<<"\t\t\tenter the number of processes you want to process in queue 3 \n\t\t\t";
	cin>>c;
	for(i=0;i<a;i++)
	{
		queue1[z]=prty[i];
		z=z+1;
	}
	
	cout<<"\n";
	cout<<"	\t\t\tQUEUE 1		Priority	 \n";
	cout<<"\n";
	
	for(i=0;i<a;i++)
	{
		printf("\t\t\t	  P%d",process[i]);
		printf("\t\t\t%d\n",prty[i]);
	}
	cout<<"\n\n";
	for(i=a;i<b+a;i++)
	{
		queue2[z]=prty[i];
		z=z+1;
	}
		cout<<"\n";
	cout<<"\n";
	cout<<"	\t\t\tQUEUE 2	      Priority\n";
	cout<<"\n";
	
	
	for(i=a;i<b+a;i++)
	{
	printf("\t\t\t	  P%d",process[i]);
	printf("\t\t\t%d\n",prty[i]);
	}
	cout<<"\n\n";
	for(i=b+a;i<c+b+a;i++)
	{
		queue3[z]=prty[i];
		z=z+1;
	}
		cout<<"\n";

	cout<<"\n";
	cout<<"\t\t\t	QUEUE 3		Priority	\n";
	cout<<"\n";
	
	for(i=b+a;i<c+a+b;i++)
	{
		printf("\t\t\t	  P%d",process[i]);
		printf("\t\t\t%d\n",prty[i]);
	}

	cout<<"\n";
	 	cout<<"\n";
	
	cout<<"\t\t\tQUEUE 1 Round robin scheduling\n";
	for(i=0;i<a;i++)
	{
		printf("\t\t\tEnter arrival time for P%d =",process[i],"\t\t\t");
		cin>>ari_t[i];
		r_t[i]=burst_t[i];
	}
	cout<<"\t\t\tenter time quantum =";
	cin>>tq;
	cout<<"\n\n\t\t\tProcess\t  Turnaround time \t Waiting time\n\n";
	
	for(t=0,i=0;remain!=0;)
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
			
			remain--;
			printf("\t\t\t P%d\t \t%d\t \t%d\n",i+1,(t-ari_t[i]),(t-ari_t[i]-burst_t[i]));
			waiting_time=waiting_time + t-ari_t[i] - burst_t[i];
			turn_time=turn_time+t-ari_t[i];
			flag=0;
		}
		if(i==a-1)
			i=0;
		else if(ari_t[i+1]<=t)
		i++;
		else
		i=0;
	}
		printf("\n\t\t\tAverage waiting time= %f\n",waiting_time*1.0/a);
		printf("\n\t\t\tAverage turnaround time= %f\n",turn_time*1.0/a);

		cout<<"\n\n\t\t\tQUEUE 2 Priority  scheduling\n";
		float w_time[n],t_time[n];
		int avg_wt,avg_tat,total=0;
		w_time[a]=0;
	for(i=a+1;i<b+a;i++)
	{
		w_time[i]=0;
		for(j=a;j<i;j++)
			w_time[i]=w_time[i]+burst_t[j];
			total=total+w_time[i];
	}
	avg_wt=total/b;
	total=0;
	cout<<"\n\t\t\tProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
	for(i=a;i<b+a;i++)
	{
		t_time[i]=burst_t[i]+w_time[i];
		total=total+t_time[i];
		printf("\n\t\t\tP%d\t\t%d\t\t%d\t\t%d",i+1,burst_t[i],w_time[i],t_time[i]);
	}
	avg_tat=total/b;
	printf("\n\t\t\tAverage waiting time= %f\n",avg_wt*1.0);
	printf("\n\t\t\tAverage turnaround time= %f\n",avg_tat*1.0);

	cout<<"\n\n\t\t\tQUEUE 3  FCFS scheduling\n";
	float w_t[n],t_at[n];
	 float av_wt=0,av_tat=0;
	w_t[b+a]=0;
	for(i=b+a+1;i<c+a+b;i++)
	{
		w_t[i]=0;
	for(j=b+a;j<i;j++)
	w_t[i]=w_t[i]+burst_t[j];
	}
	cout<<"\n\t\t\tProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
	for(i=b+a;i<b+a+c;i++)
	{
		t_at[i]=burst_t[i]+w_t[i];
		av_wt=av_wt+w_t[i];
		av_tat=av_tat+t_at[i];
		printf("\n\t\t\tP%d\t\t%d\t\t%d\t\t%d",i+1,burst_t[i],w_t[i],t_at[i]);
	}

	printf("\n\t\t\tAverage waiting time= %f\n",av_wt/c);
	printf("\n\t\t\tAverage turnaround time= %f\n",av_tat/c);
	
	cout<<"\n\n\n\t\t\t\t!!!!!***   THANK YOU ***!!!!!";
	return 0;
}

