#include<stdio.h>
int search_(int n,int* a,int se)
{
   int i,l,m,h;
   l=0;
   h=n-1;
   m=(l+h)/2;
   while(l<h)
   {
   	  if(se==a[m])
   	  {
   	  	return 1;
	  }
	  else if(se>a[m])
	  {
	  	l=m+1;
	  	m=(l+h)/2;
	  }
	  else if(se<a[m])
	  {
	  	h=m-1;
	  	m=(l+h)/2;
	  }
   }
   return 0;
}
int main()
{
	int n,a[100],i,se,v;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&se);
	v=search_(n,a,se);
	if(v==1)
	{
		printf("element found");
	}
	else
	{
		printf("element not found");
	}
}
