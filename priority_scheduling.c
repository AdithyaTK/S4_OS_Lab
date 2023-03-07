#include<stdio.h>
int n,i,tot=0,m,j,k,d,greatprio,changemade=0,top=-1,past=0,ch;
int stack[20];
struct process
{
    int at;
    int bt;
    int pri;
    int stat;
}p[20];
void push(int m)
{
    top++;
    stack[top]=m;
}
int pop()
{
    int y=stack[top];
    top--;
    return y;
}
void nonpre()
{
    printf("\tP%d",greatprio);
    p[greatprio].stat=0;
    j=j+p[greatprio].bt;
}
void pre()
{
    if(past!=greatprio)
    {
        printf("\tP%d",greatprio);
    }
    past=greatprio;
    p[greatprio].bt--;
    if(p[greatprio].bt==0)
    {
        p[greatprio].stat=0;
    }    
}
void main()
{
    printf("\nenter the total number of process");
    scanf("%d",&n);
    printf("\nenter the arrival time,burst time and priority");
    for(i=1;i<=n;i++)
    {
        printf("\nPROCESS P%d",i);
        printf("\narrival time:\t");
        scanf("%d",&p[i].at);
        printf("\nburst time:\t");
        scanf("%d",&p[i].bt);
        printf("\npriority time:\t");
        scanf("%d",&p[i].pri);
        p[i].stat=1;
        tot=tot+p[i].bt;
    }
    printf("\nenter the choice:\n1.premptive\n2.non preemptive");
    scanf("%d",&ch);
    printf("\nthe output is");
    for(j=0;j<=tot;j++)
    {
        for(k=1;k<=n;k++)
        {
            if(p[k].at<=j&&p[k].stat==1)
            {
                push(k);
                changemade=1;
            }
        }
        if(changemade==1)
        {
            greatprio=pop();
            int y=pop();
            while(top!=-2)
            {
                if(p[y].pri<p[greatprio].pri)
                {
                    greatprio=y;
                }
                else if(p[y].pri==p[greatprio].pri)
                {
                    if(p[y].at<p[greatprio].at)
                    {
                        greatprio=y;
                    }
                }
                y=pop();
            }
            if(top==-2)
            {
                top=-1;
            }
            if(ch==2)
            {
                nonpre();
            }
            else
            {
                pre();
            }
            changemade=0;
        }
    }
}





