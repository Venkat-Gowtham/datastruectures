#include<stdio.h>
int c=0;
int swap(int *x,int *y)
{
	int temp;
	temp=*y;
	*y=*x;
	*x=temp;
	c++;
}
void bubble(int *a,int n)
{
	int i,temp,j,k,sc,z;
	for(i=0;i<n-1;i++)
	{ //sc=0;
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
			   swap(&a[j],&a[j+1]);
				for(z=0;z<n;z++)
				{
					printf("%d ",a[z]);
				}
				printf("\n");
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
//	printf("%d",c);
//	i>j swap(i,j)i++,j++
//	i++,j++
//	55 66 22 11 77 23 43 56
	//55 22  11 66 23 43 56 77 sc=5
      	      //       i   j  
}
