//sjf non premeptive
#include<stdio.h>
struct process
{
	int at;
	int bt;
	int stat;
	int ct;
}p[20];
int smallest(int arr[],int k)
{
    int i;
    int small=p[arr[0]].bt;
    int retvalue=arr[0];
    for(i=0;i<k;i++)
    {
        if(p[arr[i]].bt<small)
        {
            small=p[arr[i]].bt;
            retvalue=arr[i];
        }
    }
    return retvalue;
}
void main()
{
	int n,j,tot=0,i,k,flag,tt,wt,m;
	float ttt,twt;
	int arr[20];
	printf("\nenter the number of process");
	scanf("%d",&n);
	printf("\nenter the burst time and the arrival time");
	for(i=0;i<n;i++)
	{
		printf("\nprocess:%d\nburst time:\t",i+1);
		scanf("%d",&p[i].bt);
		printf("\narrival time:\t");
		scanf("%d",&p[i].at);
		p[i].stat=0;
		tot=tot+p[i].bt;
	}
	for(i=0;i<tot;i++)
	{
		k=0;
		flag=0;
		for(j=0;j<n;j++)
		{
			if(p[j].at<=i&&p[j].stat==0)
			{
				arr[k]=j;
				flag=1;
				k++;
			}
		}
		if(flag==1)
		{
			int s=smallest(arr,k);
			i=i+p[s].bt;
			p[s].ct=i;
			p[s].stat=1;
			i--;
			for(j=0;j<=k;j++)
			{
				arr[j]=0;
			}
		}
	}
	printf("\nPROCESS BURST ARRIVAL COMPLETION WAITING TURNAROUND");
	for(i=0;i<n;i++)
	{
		tt=p[i].ct-p[i].at;
		wt=tt-p[i].bt;
		twt=twt+wt;
		ttt=ttt+tt;
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",i+1,p[i].bt,p[i].at,p[i].ct,wt,tt);
	}
	printf("\naverage turn around time %f",ttt/n);
	printf("\naverage waiting time %f",twt/n);
}