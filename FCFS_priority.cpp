
//sorting in arrivaltime ||||||||||||||||||||||||||

void swap(int id[],int at[],int bt[],int n){
	int ind,min,k,f,i,j,m;
	
	for(i=0;i<n;i++){
		m=at[i];
	ind=i;
		for(int j=i+1;j<n;j++){
			if(at[j]<m){
				ind=j;
				m=at[j];
			}
			
		}
		//printf("%d\t",m);
		min=at[i];
		at[i]=at[ind];
		at[ind]=min;
		min=id[i];
		id[i]=id[ind];
		id[ind]=min;
		min=bt[i];
		bt[i]=bt[ind];
		bt[ind]=min;
	}
}

	//priority scheduling  |||||||||||||||||||||||||||||||||
	
	
	int f1[e1],r1=0;
	for(int i=0;i<b;i++)
	{
		while(bt2[i]!=0)
		{
			f1[r1++]=id2[i];
			bt2[i]=bt2[i]-1;
		}
	}
	printf("\n\n\n");
	
	for(int i=0;i<e1;i++)
	{
 		printf("%d\t",f1[i]);	
		
	}	

// FCFS scheduling.......||||||||||||||||||||||||

		int f2[o];
		int r3=0;
	
	for(int i=0;i<c;i++)
	{
		while(bt3[i]!=0)
		{
			f2[r3++]=id3[i];
				bt3[i]=bt3[i]-1;
		}
	}


	for(int i=0;i<o;i++)
	{
 		printf("%d\t",f2[i]);	
	}



