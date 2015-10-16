#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node * next;
};


struct node* pushele(int push,struct node * head){
	struct node * new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->data=push;
	new_node->next=NULL;
	struct node* start=head;
	if (head==NULL)
	{
       head=new_node;
       return head;	
	}
	else{
		while(head->next!=NULL)
          {
          	head=head->next;
          	}  
          head->next=new_node;
        }
	return start;	
}


void printList(struct node* n1)
{
while(n1!=NULL)
{
	printf("function printlist %d \n",n1->data);
	n1=n1->next;
}

}
void reverse(struct node ** head1, struct node * n3)
{
	
	if(n3==NULL || n3->next==NULL )
	{
	*head1=n3;
	return;	
	}
	reverse(head1,n3->next);
	n3->next->next=n3;
	n3->next=NULL;
	return;	
}
struct node * sumTwoLinklist(struct node * n1,struct node * n2)
{
struct node * n3=NULL;
int carry=0,sum=0;
while(n1!=NULL || n2!=NULL)
{
	if(n1==NULL)
	{
		printf("i am here first \n");
		n3=pushele(n2->data+carry,n3);
		if((n2->data+carry)>10)
		carry=1;
		else 
		carry=0;
		n2=n2->next;
	}
	else if(n2==NULL)
	{
		printf("i am here second \n");
		n3=pushele(n1->data+carry,n3);
		if((n1->data+carry)>10)
		carry=1;
		else 
		carry=0;
		n1=n1->next;
	}
	else
	{
		printf("i am here third \n");
		sum=n1->data+n2->data;
		if (sum>9)
          {
          sum=sum-10;
          n3=pushele(sum+carry,n3);
		  carry=1;
			}
			else
			{
				n3=pushele(sum+carry,n3);
				carry=0;
			}
		n1=n1->next;
		n2=n2->next;
		
		
	}
}
return n3;
}

int main()
{

struct node * n1=NULL;
struct node * n2=NULL;
struct node * n3=NULL;
struct node ** head1=&n1;
//printf("hello main");

n1=pushele(9,n1);
n1=pushele(7,n1);
n1=pushele(1,n1);
n1=pushele(5,n1);
//head=pushele('a',head);
reverse(&n1,n1);
//n3=sumTwoLinklist(n1,n2);
printList(n1);
n2=pushele(2,n2);
n2=pushele(1,n2);
n2=pushele(5,n2);
reverse(&n2,n2);
printList(n2);
n3=sumTwoLinklist(n1,n2);

reverse(&n3,n3);
printList(n3);
return 0;

}
