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
void insert(int data)
{
	struct node *n, *temp;
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
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = n;
		n->next = NULL;
	}
}
int find(int k)
{
	struct node *temp;
	temp = head;
	while (temp != NULL)
	{
		if (temp->data == k)
			return 1;
		temp = temp->next;
	}
	return 0;
}
void sort(int pos)
{
	struct node *temp1,*temp2;
	int temp;
	for (temp1 = head; temp1->next != NULL; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
		{
			if (temp2->data <= temp1->data)
			{
				temp = temp1->data;
				temp1->data = temp2->data;
				temp2->data = temp;
			}
		}
	}
	temp = 1;
	temp1 = head;
	while (temp < pos)
	{
		temp1 = temp1->next;
		temp++;
	}
	printf("%d", temp1->data);
}
void merge_table(int n1, int n2, int pos)
{
	int i = 1;
	while (i <= 10)
	{
		insert(i*n1);
		i++;
	}
	i = 1;
	while (i <= 10)
	{
		if (find(i*n2) != 1)
			insert(i*n2);
		i++;
	}
	sort(pos);
};
void main()
{
	int n1, n2, pos;
	scanf("%d%d%d", &n1, &n2, &pos);
	head = NULL;
	merge_table(n1, n2, pos);
	_getch();
}