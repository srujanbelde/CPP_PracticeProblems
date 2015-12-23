#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL;
void insert(int num)
{
	struct node *node, *temp;
	node = (struct node *)malloc(sizeof(struct node));
	node->data = num;
	if (head == NULL)
	{
		head = node;
		node->next = NULL;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
		node->next = NULL;
	}
}
void ad_sort(struct node *head)//function used to sort
{
	struct node *temp1, *temp2,*temp3;//3 pointers each pointing to head intially
	int temp;
	temp1 = temp2 = temp3=head;
	while (temp1->next != NULL)//temp1 is moved to the end
		temp1 = temp1->next;
	while (temp2->next->data > temp2->data)//temp2 is moved to the point where decending order starts
		temp2 = temp2->next;
	while (temp2 < temp1)//now all the decending values are reversed untill temp1 is lessthan or equal to temp2
	{
		temp = temp2->data;
		temp2->data = temp1->data;
		temp1->data = temp;
		temp2 = temp2->next;
		temp3 = temp2;
		while (temp3 < temp1)//we use temp3 to move temp1 backward
			temp3 = temp3->next;//temp3 is moved stil one step behind of temp1 
		temp1 = temp3;//now temp1 to pointed to temp3
	}
}
void main()
{
	insert(1);
	insert(2);
	insert(7);
	insert(20);
	insert(15);
	insert(10);
	ad_sort(head);
	for (struct node *temp = head; temp != NULL; temp = temp->next)
		printf("%d\n", temp->data);
	_getch();
}