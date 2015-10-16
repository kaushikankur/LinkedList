#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
	char data;
	struct node * info;
};

struct node * left;

//struct node * left=head;
//struct node * right=head;

struct node* pushele(char push,struct node * head){
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
	printf("function printlist %c \n",n1->data);
	n1=n1->info;
}

}


bool palindrome(struct node ** left,struct node * right)
{
if(right==NULL)
return true;

bool isp=palindrome(left,right->info);
if (isp==false)
{
return false;
}

bool isp1=((*left)->data==right->data);
(*left)=(*left)->info;
return isp1;
}


struct node *  findloop(struct node * n1)
{
	struct node * slw=n1;
	struct node * fast=n1;
	while(slw!=NULL && fast!=NULL && fast->info!=NULL)
	{
		//printf("hello findloop");
		slw=slw->info;
		fast=fast->info->info;
		
		if(slw==fast)
		{
			printf("loop is at value%c \n",fast->data);
			return slw;
		}
	}

}
void removeloop(struct node * head,struct node * loop_pnt)
{
	struct node * temp=loop_pnt;
	while(loop_pnt->info!=temp)
	{
		printf("ankky");
		printf("%c",temp->data);
		loop_pnt=loop_pnt->info;
		printf("after%c",loop_pnt->data);
	}
//	printf("%c",loop_pnt->data);
}

int main()
{

struct node * head=NULL;
struct node * loop_pnt=NULL;
printf("hello main");

head=pushele('r',head);
head=pushele('u',head);
head=pushele('k',head);
head=pushele('n',head);
head=pushele('a',head);
//head=pushele('k',head);
//head=pushele('m',head);
head->info->info->info->info = head->info->info;
//printf("value is %c",head->info->info->info->info->info->data);
//head=appendHead(10,head);
//middleNode(head);

//head=deleteNode(2,head);

//middleNode(head);
//head=reverseLink(head);
//deleteLink(head);

loop_pnt=findloop(head);
removeloop(head,loop_pnt);
//struct node * left=head;
//printList(head);
//bool ek=palindrome(&head,head);
//printf("the value is %b",ek);
//if(ek)
//printf("is palindrome");
//else
//printf("not a palindrome");
return 0;

}
