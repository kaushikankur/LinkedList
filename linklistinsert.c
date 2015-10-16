#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * info;
};

void printList(struct node * n);
struct node* pushele(int push,struct node * abc );
struct node* appendHead(int push,struct node * abc );
struct node* deleteNode(int val,struct node * abc );
int main()
{
struct node * head=NULL;

printf("hello main");



head=pushele(5,head);
head=pushele(15,head);
head=appendHead(10,head);
head=deleteNode(2,head);
printList(head);
return 0;

}

struct node* deleteNode(int val,struct node * n4)
{
	struct node* strt_pntr;
	strt_pntr=n4;
	struct node* prev;
	int count=0;
	while(n4!=NULL)
	{
	if(count==val)
	{
		prev->info=n4->info;
		break;
	}
	
	prev=n4;
	n4=n4->info;
	count++;
	
}
	return strt_pntr;
}

struct node* appendHead(int push,struct node * head)
{
	struct node * new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->data=push;
	new_node->info=head;
	return new_node;

}
struct node* pushele(int push,struct node * head){
	struct node * new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->data=push;
	new_node->info=NULL;
	struct node* start=head;
	if (head==NULL)
	{
       head=new_node;
       return head;	
	}
	else{
		while(head->info!=NULL)
          {
          	head=head->info;
          	}  
          head->info=new_node;
        }
	return start;	
}


void printList(struct node* n1)
{
while(n1!=NULL)
{
	printf("function printlist %d \n",n1->data);
	n1=n1->info;
}

}
