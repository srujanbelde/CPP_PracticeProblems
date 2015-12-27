#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL;
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
void pos_sort(struct node *head)
{
	int count = 1,temp,xchange[2],i=0;
	struct node *temp1,*temp2,*temp3;
	temp1 = temp2 = temp3 = head;
	while (temp1 != NULL)//we are travensing up to next of the list
	{
		if (temp1 == head)//if we are at first elemet then we are checking if next elemet is greater than it or not
		{
			if (temp1->data > temp1->next->data)
				xchange[i++] = count;
		}
		else if (temp1->next == NULL)//if we are at last element then we are checking if before element if less than it or not
		{
			while (temp2<temp1)
				temp2 = temp2->next;
			if (temp2->data > temp1->data)
				xchange[i++] = count;
		}
		else//here if the elemet to be checked is not first or last element
		{
			temp2 = temp3 = head;//we move temp2 to element before temp1 and temp3 to element after temp1
			while (temp2 < temp1)
				temp2 = temp2->next;
			while (temp3 <= temp1)
				temp3 = temp3->next;
			temp3 = temp3->next;
			if ((temp2->data > temp1->data) ||( temp1->data > temp3->data))//now we are checking if it is in order or not
				xchange[i++] = count;
		}
		count++;
		temp1 = temp1->next;
	}//in this loop which ever elements are not in proper order thore element  positions are recorded into an array called xcahnge[]
	temp1 = temp2 = head;
	count = 1;
	while (count < xchange[1])//we move temp1 to one element and temp2 to other element who have to be excahnged
		temp1 = temp1->next;
	count = 1;
	while (count < xchange[2])
		temp2 = temp2->next;
	temp = temp1->data;//here those two elements are interchanged
	temp1->data = temp2->data;
	temp2->data = temp;
}
void main()
{
	insert(20);
	insert(2);
	insert(3);
	insert(5);
	insert(10);
	insert(15);
	insert(1);
	pos_sort(head);
	for (struct node *temp = head; temp != NULL; temp = temp->next)
		printf("%d\n", temp->data);
	_getch();
}