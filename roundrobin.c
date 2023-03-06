#include<stdio.h>
int front=-1,rear=-1;
int arr[20];
struct process
{
	int bt;
	int at;
	int btstat;
	int inque;
	int ct;
	int bef;
}p[20];
void add(int m)
{
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear++;
	}
	arr[rear]=m;
}
int deque()
{
    if(front==-1&&rear==-1)
    {
        return -1;
    }
    else
    {
	    int ret=arr[front];
	    if(front==rear)
	    {
		    front=-1;
	    	rear=-1;
	    }
	    else
	    {
		    front++;
        }
	    return ret;
    }
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
	int n,i,j,tot=0,q,prev=-1,tt,wt,z=-1,totcom=0;
	float twt,ttt;
	printf("\nenter the number of process");
	scanf("%d",&n);
	printf("\nenter the burst time and the arrival time");
	for(i=0;i<n;i++)
	{
		printf("\nprocess:%d\nburst time:\t",i+1);
		scanf("%d",&p[i].bt);
		printf("\narrival time:\t");
		scanf("%d",&p[i].at);
		p[i].btstat=p[i].bt;
		p[i].bef=i;
		p[i].inque=0;
		tot=tot+p[i].bt;
	}
	bubblesort(n);
	printf("\nenter the time quantum");
	scanf("%d",&q);
	printf("\nthe order of execution is");
	for(i=0;i<=tot;i++)
	{
	    for(j=0;j<n;j++)
	    {
	        if(p[j].at<=i&&p[j].inque==0)
	        {
	            add(j);
	            p[j].inque=1;
	        }
	    }
	    if(p[z].btstat!=0)
	    {
	        add(z);
	    }
	    int m=deque();
	    if(m!=-1)
	    {
	        if(p[m].btstat<=q)
	        {
	            i=i+p[m].btstat;
	            printf("\n%d",p[m].bef+1);
	            p[m].btstat=0;
	            p[m].ct=i;
	            i--;
	        }
	        else
	        {
	            p[m].btstat=p[m].btstat-q;
	            printf("\n%d",p[m].bef+1);
	            i=i+q;
	            i--;
	        }
	        z=m;
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