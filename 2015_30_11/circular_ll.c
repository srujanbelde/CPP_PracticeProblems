#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *next;
};
void addnode_cll(struct node *head, int size)
{
	int element, i;
	struct node *temp, *move;
	for (i = 1; i <= size; i++)
	{
		scanf("%d", &element);
		temp = (struct node*)malloc(sizeof(struct node));
		if (head->next == head)//it it is pointing to itself then we add a new node
		{
			temp->data = element;
			head->next = temp;
			temp->next = head;
		}
		else//if it is not pointing to itself then we traverse up to it and add a new node over there
		{
			move = head;
			while (move->next != head)
				move = move->next;
			move->next = temp;
			temp->data = element;
			temp->next = head;
		}
	}
}
void main()
{
	int size;
	struct node *new, *head;
	new = (struct node*)malloc(sizeof(struct node));//intial node
	head = new;
	new->next = head;//next pointer pointing to itself
	scanf("%d", &size);
	addnode_cll(head, size);
	for (new = head->next; new != head; new = new->next)
		printf("%d", new->data);
	_getch();
}

