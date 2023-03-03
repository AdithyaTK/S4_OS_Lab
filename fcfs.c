#include<stdio.h>
#include<stdlib.h>
struct fcfs
{
	int at;
	int bt;
	int pno;
	int stat;
	int ct;
}p[20];
void bubblesort(int n)
{
	int temp1,temp2,temp3,i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				temp1=p[j].at;
				p[j].at=p[j+1].at;
				p[j+1].at=temp1;
			
				temp2=p[j].bt;
				p[j].bt=p[j+1].bt;
				p[j+1].bt=temp2;

				temp3=p[j].pno;
				p[j].pno=p[j+1].pno;
				p[j+1].pno=temp3;
			}
		}
	}
}
void main()
{
	int i,n,wt,tt,k,j,tot=0,flag=0,twt=0,ttt=0;
	printf("\nenter the number of process");
	scanf("%d",&n);
	printf("\nenter the arraival time and the burst time");
	for(i=0;i<n;i++)
	{
		printf("\nprocess:%d\nburst time:\t",i+1);
		scanf("%d",&p[i].bt);
		printf("\narrival time:\t");
		scanf("%d",&p[i].at);
		p[i].pno=i+1;
		p[i].stat=0;
		tot=tot+p[i].bt;
	}
	bubblesort(n);
	for(i=0;i<=tot;i++)
	{
	    flag=0;
	    for(j=0;j<n;j++)
	    {
	        if(p[j].at<=i&&p[j].stat==0)
	        {
	            p[j].stat=1;
	            i=i+p[j].bt;
	            p[j].ct=i;
	            flag=1;
	        }
	    }
	    if(flag==1)
	    {
	        i--;
	    }
	}
	printf("\nPROCESS BURST ARRIVAL COMPLETION WAITING TURNAROUND");
	for(i=0;i<n;i++)
	{
		tt=p[i].ct-p[i].at;
		wt=tt-p[i].bt;
		twt=twt+wt;
		ttt=ttt+tt;
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i].pno,p[i].bt,p[i].at,p[i].ct,wt,tt);
	}
	printf("\naverage turn around time %d",ttt/n);
	printf("\naverage waiting time %d",twt/n);
}