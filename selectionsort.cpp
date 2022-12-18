#include<stdio.h>
int maxind(int *a,int n)
{
	int i,max=0,ind=0,temp,j;
	max=a[0];
		for(j=1;j<=n;j++)//22 32 44 45 34
		{ 
			if(a[j]>max)
			{
				max=a[j];
				ind=i;
			}
		}
		return ind;	
}
int sort(int*a,int n)
{
	int i,res,temp,z;
	for(i=n-1;i>=0;i--)
	{
		res=maxind(a,i);
		temp=a[i];
		a[i]=a[res];
		a[res]=temp;
	}
}
int main()
{
	int n,a[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
/*
#include<stdio.h>
int main()
{
	int n,i,j,temp,c=0,tp,last;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
      last=n-1;
while(last!=0)
{
	if(arr[i]==0)
	{
		int temp=arr[i];
			arr[i]=arr[last];
			arr[last]=temp;
			c++;
	}
	last--;
}
for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}

for(i=0;i<n-c;i++)
	{
		for(j=i+1;j<n-c;j++)
		{
			if(arr[i]>arr[j])
			{
				tp=arr[i];
				arr[i]=arr[j];
				arr[j]=tp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
*/
