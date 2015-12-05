#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void insert( int data)
{
	struct node *n,*temp;
	n = (struct node *)malloc(sizeof(struct node));
	n->data = data;
	if (head == NULL)
	{
		head = n;
		n->next = NULL;
	}
	else
	{
		temp = head;
		while (temp->next!= NULL)
			temp = temp->next;
		temp->next= n;
		n->next = NULL;
	}
}
void display()
{
	struct node *temp = head;
	while (temp != NULL)
	{
		printf("%d \n", temp->data);
		temp = temp->next;
	}
}
void median()
{
	int count=0,i=1;
	struct node *temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	temp = head;
	if (count % 2 == 0)
	{
		while (i != ((count / 2)))
		{
			temp = temp->next;
			i++;
		}
		i=temp->data;
		temp = temp->next;
		i=((temp->data)+i)/2;
		printf("%d", i);
	}
	else
	{
		while (i != count / 2)
		{
			temp = temp->next;
			i++;
		}
		temp = temp->next;
		printf("%d", temp->data);
	}
};
void main()
{
	head = NULL;
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	display();
	median();
	_getch();
}