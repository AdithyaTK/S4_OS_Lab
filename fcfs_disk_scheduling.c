#include<stdio.h>
void main()
{
	int n,a,i,tot=0;
	int arr[20];
	printf("\nenter the size of the disk queue");
	scanf("%d",&n);
	printf("\nenter the elements of the disk queue");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nenter the initial disk head");
	scanf("%d",&a);
	for(i=0;i<n;i++)
	{
		if(a>arr[i])
		{
			tot=tot+(a-arr[i]);
			a=arr[i];
		}
		else
		{
			tot=tot+(arr[i]-a);
			a=arr[i];
		}
	}
	printf("\nthe order of execution is ");
	for(i=0;i<n;i++)
	{
		printf("\n%d",arr[i]);
	}
	printf("\ntotal time:%d",tot);
	printf("\naverage time%d",tot/n);
}