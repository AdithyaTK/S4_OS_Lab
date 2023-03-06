//sjf premeptive
#include<stdio.h>
struct process
{
	int at;
	int bt;
	int btstat;
	int stat;
	int ct;
	int bef;
}p[20];
int smallest(int arr[],int k)
{
    int i;
    int small=p[arr[0]].btstat;
    int retvalue=arr[0];
    for(i=0;i<k;i++)
    {
        if(p[arr[i]].btstat<small)
        {
            small=p[arr[i]].btstat;
            retvalue=arr[i];
        }
    }
    return retvalue;
}
void bubblesort(int n)
{
    int i,j,temp1,temp2,temp3,temp4;
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
                
                temp3=p[j].bef;
                p[j].bef=p[j+1].bef;
                p[j+1].bef=temp3;
                
                temp4=p[j].btstat;
                p[j].btstat=p[j+1].btstat;
                p[j+1].btstat=temp4;
            }
        }
    }
}
void main()
{
	int n,j,tot=0,i,k,flag,tt,wt,m,prev=-1;
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
		p[i].btstat=p[i].bt;
		p[i].bef=i;
		tot=tot+p[i].bt;
	}
	bubblesort(n);
	printf("\nthe order of execution is ");
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
			p[s].btstat--;
			if(prev!=s)
			{
			    printf("\nP%d",p[s].bef+1);
			    prev=s;
			}
			if(p[s].btstat==0)
			{	
				p[s].ct=i+1;
				p[s].stat=1;
			}
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
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i].bef+1,p[i].bt,p[i].at,p[i].ct,wt,tt);
	}
	printf("\naverage turn around time %f",ttt/n);
	printf("\naverage waiting time %f",twt/n);
}