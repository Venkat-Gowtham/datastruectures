876// doubly linked lists
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int dat;
	struct node *next;
};typedef struct node NODE;
NODE *head=NULL;

void insert_end(int data){
	NODE *nn,*temp;
	nn=(NODE*)malloc(sizeof(NODE));
	nn->prev=NULL;
	nn->next=NULL;
	nn->dat=data;
	temp=head;
	if (head==NULL){
		head=nn;
	}
	else if (head->next==NULL){
		head->next=nn;
		nn->prev=head;
	}
	else{
		while (temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=nn;
		nn->prev=temp;
	}
}
void insert_head(int data){
	NODE *nn;
	nn=(NODE*)malloc(sizeof (nn));
	nn->prev=NULL;
	nn->next=NULL;
	nn->dat=data;
	if (head==NULL){
		head=nn;
	}
	else{
		nn->next=head;
		head=nn;
	}
}
void insert_pos(int data,int pos){
	NODE *nn,*temp;
	nn=(NODE*)malloc(sizeof(nn));
	nn->prev=NULL;
	nn->dat=data;
	nn->next=NULL;
	if (head==NULL){
		head=nn;
	}
	else if (pos==1){
		insert_head(data);
	}
	else{
		int i,f=0;
		temp=head;
		for (i=1; i<pos-1; i++){
			if (temp->next==NULL){
				insert_end(data);
				f=1;
				break;
			}
			else{
				temp=temp->next;
			}
		}
		if (f==0){
			nn->next=temp->next;
			temp->next=nn;
			nn->prev=temp;
		}
	}
}

void delete_end(){
	NODE *nn,*temp;
	if (head==NULL){
		printf("No Nodes\n");
	}
	else if (head->next==NULL){
		printf("Deleted->%d\n",head->dat);
		head=NULL;
	}
	else{
		temp=head;
		nn=head;
		while (1){
			nn=nn->next;
			if (nn->next==NULL){
				printf("Deleted->%d\n",nn->dat);
				temp->next=NULL;
				break;
			}
			else{
				temp=nn;
			}
		}

	}
}
void delete_head(){
	NODE *nn;
	nn=head;
	if (head==NULL){
		printf("No Nodes\n");
	}
	else if (head->next==NULL){
		printf("Deleted->%d\n",nn->dat);
		head=NULL;
	}
	else{
		printf("Deleted->%d\n",nn->dat);
		head=head->next;
	}
}
void delete_pos(int pos){
	NODE *temp,*nn;
	if (head==NULL){
		printf("No Nodes\n");
	}
	else if (head->next==NULL || pos==1){
		delete_head();
	}
	else{
		temp=head;
		nn=head;
		int i,f=0;
		for (i=1; i<pos-1; i++){
			temp=temp->next;
			if (temp->next==NULL){
				f=1;
				delete_end();
				break;
			}
			else{
				nn=temp;
			}
		}
		if (f==0){
			printf("Deleted->%d\n",temp->next->dat);
			temp=temp->next;
			nn->next=temp->next;
			temp->prev=nn;
		}
	}
}

void display(){
	NODE *temp;
	temp=head;
	if (head==NULL){
		printf("No Nodes");
	}
	else{
		while (1){
			if (temp->next==NULL){
				printf("%d ",temp->dat);
				break;
			}
			else{
				printf("%d ",temp->dat);
				temp=temp->next;
			}
		}
	}
}
int main(){
	while (1){
		printf("1,insert at end		2,delete at end		3,display		4,insert at head\n");
		printf("5,delete at head	6,insert at pos		7,delete at pos		8,exit :");
		int ch;
		scanf("%d",&ch);
		if (ch==1){
			int data;
			scanf("%d",&data);
			insert_end(data);
		}
		else if (ch==2){
			delete_end();
		}
		else if (ch==3){
			display();
			printf("\n");
		}
		else if (ch==4){
			int data;
			scanf("%d",&data);
			insert_head(data);
		}
		else if (ch==5){
			delete_head();
		}
		else if (ch==6){
			int data,pos;
			scanf("%d%d",&data,&pos);
			insert_pos(data,pos);
		}
		else if (ch==7){
			int pos;
			scanf("%d",&pos);
			delete_pos(pos);
		}
		else{
			break;
		}
		printf("\n");
	}
	return 0;
}
