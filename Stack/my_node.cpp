#include <stdio.h>
#include <stdlib.h>

#include "my_node.h"
#include "my_stack.h"
#include "my_messages.h"

struct Node* node_init(struct Node* next, void* pdata)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	if (node)
	{
		node->next = next;
		node->data = pdata;
		return node;
	}
	else
		my_mess(MY_MESS_STACK_OVERFLOW);
	return NULL;
}

void node_free(struct Node* node, FreeData pFreeData)
{
	(*pFreeData)(node->data);
	free(node);
}

void node_print(struct Node* node, PrintData print)
{
	if (node)
	{
		(*print)(node->data);
		node_print(node->next, print);
	}
}

void node_save(struct Node* node, FILE** fptr, SaveData save)
{
	if (node)
	{
		node_save(node->next, fptr, save);
		(*save)(node->data, fptr);
	}
}

void node_find_year(struct Node* node, int year, FindYear findyear)
{
	int i;
	if(node != NULL)
		i = (*findyear)(node->data, year);
	else
	{
		my_mess(MY_MESS_EMPTY);
		system("pause");
		return;
	}
	if (node->next != NULL && i == 0)
		node_find_year(node->next, year, findyear);
	else if (i == 0)
		my_mess(MY_MESS_NOT_FOUND);
}

void node_find_faculty(struct Node* node, Faculty faculty, FindFaculty findfac)
{
	int i;
	if (node != NULL)
		i = (*findfac)(node->data, faculty);
	else
	{
		my_mess(MY_MESS_EMPTY);
		return;
	}
	if (node->next != NULL && i == 0)
		node_find_faculty(node->next, faculty, findfac);
	else if (i == 0)
		my_mess(MY_MESS_NOT_FOUND);
}

void node_find_lastname(struct Node* node, char* lastname, FindLastname findlast)
{
	int i;
	if (node != NULL)
		i = (*findlast)(node->data, lastname);
	else
	{
		my_mess(MY_MESS_EMPTY);
		return;
	}
	if (node->next != NULL && i == 0)
		node_find_lastname(node->next, lastname, findlast);
	else if (i == 0)
		my_mess(MY_MESS_NOT_FOUND);
}