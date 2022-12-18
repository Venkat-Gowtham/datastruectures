#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *HEAD=NULL;
void insert_end(int data)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->next=HEAD;
	if(HEAD==NULL)
	{
		HEAD=NN;
		HEAD->next=HEAD;
	}
	else if(HEAD->next==HEAD)
	{
		HEAD->next=NN;
		NN->next=HEAD;
	}
	else
	{
		temp=HEAD;
		while(temp->next!=HEAD)
		{
			temp=temp->next;
		}
		temp->next=NN;
		NN->next=HEAD;
	}
}
void display()
{
	NODE *temp;
	if(HEAD==NULL)
	{
		printf(" NO NODES\n");
	}
	else if(HEAD->next==HEAD)
	{
		printf("%d\n",HEAD->data);
	}
	else
	{
		temp=HEAD;
		while(temp->next!=HEAD)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
	}
}
void delete()
{
	NODE *temp;
	if(HEAD==NULL)
	{
		printf(" NO NODES\n");
	}
	else if(HEAD->next==HEAD)
	{
		printf(" Deleted %d\n",HEAD->data);
		HEAD=NULL;
	}
	else
	{
		temp=HEAD;
		while(temp->next->next!=HEAD)
		{
			temp=temp->next;
		}
		printf(" deleted %d\n",temp->next->data);
		temp->next=HEAD;
	}
}
void insert_head(int data)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->next=NULL;
	if(HEAD==NULL)
	{
		HEAD=NN;
	}
	else
	{
	   temp=HEAD;
	   while(temp->next!=HEAD)
	   {
	   	temp=temp->next;
	   }
	   NN->next=HEAD;
	   HEAD=NN;
	   temp->next=HEAD;
	}
}
delete_head()
{
	NODE *temp;
	if(HEAD==NULL)
	{
		printf("NO NODES");
	}
	else if(HEAD->next==HEAD)
	{
		HEAD=NULL;
	}
	else
	{
		temp=HEAD;
		while(temp->next!=HEAD)
		{
			temp=temp->next;
		}
		HEAD=HEAD->next;
		temp->next=HEAD;
	}
}

int main()
{
	int ch,data;
	while (1)
	{
		printf("1.insert_end 2.delete_end 3.display 4.delete_head 5.insert_head 6.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert
			scanf("%d",&data);
			insert_end(data);
		}
		else if(ch==2)
		{
			//delete
			delete();
		}
		else if (ch==3)
		{
			//display
			display();
		}
		else if(ch==4)
		{
			
			delete_head();
		}
		else if(ch==5)
		{
			//
			scanf("%d",&data);
			insert_head(data);
		}
		else
		{
			break;
		}
	}
}
