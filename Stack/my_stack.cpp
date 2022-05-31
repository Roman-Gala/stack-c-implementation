#include <stdio.h>
#include <stdlib.h>

#include "my_stack.h"
#include "my_node.h"
#include "my_messages.h"

#pragma warning (disable : 4996)

struct Stack * stack_init(FreeData pFreeData)
{
	struct Stack* newstack = (struct Stack*)malloc(sizeof(struct Stack));
	if (newstack)
	{
		newstack->Top = NULL;
		newstack->pFreeData = pFreeData;
		return newstack;
	}
	my_mess(MY_MESS_ALLOC_ERROR);
}

void stack_push(struct Stack* stack, void* pdata)
{
	struct Node* node = node_init(stack->Top, pdata);
	stack->Top = node;
}

void* stack_pop(struct Stack* stack)
{
	if (stack->Top != NULL)
	{
		void* pdata = stack->Top->data;
		struct Node* node = stack->Top;
		stack->Top = stack->Top->next;
		free(node);
		return pdata;
	}
	my_mess(MY_MESS_EMPTY);
	return NULL;
}

void stack_free(struct Stack* stack)
{
	if (stack)
	{
		struct Node* node;
		while (stack->Top != NULL)
		{
			node = stack->Top;
			stack->Top = node->next;
			node_free(node, stack->pFreeData);
		}
	}
}

void stack_print(struct Stack* stack, PrintData print)
{
	if (stack->Top)
	{
		printf("\n   === TOP ===  \n");
		node_print(stack->Top, print);
		printf("\n  === BOTTOM ===  \n");
	}
	else
		my_mess(MY_MESS_EMPTY);
}

void stack_save(struct Stack* stack, SaveData save)
{
	if (stack->Top)
	{
		FILE* fptr;
		fptr = fopen("saved_stack", "wb");
		if (fptr == NULL)
		{
			my_mess(MY_MESS_FILE_ERROR);
			return;
		}
		printf("\n");
		node_save(stack->Top, &fptr, save);
		fclose(fptr);
		my_mess(MY_MESS_SUCCESS);
	}
	else
		my_mess(MY_MESS_EMPTY);
}

void stack_read(struct Stack* stack, ReadData read)
{
	if (stack->Top == NULL)
	{
		FILE* fptr;
		fptr = fopen("saved_stack", "rb");
		if (fptr)
		{
			void* pdata = (*read)(&fptr);
			if (pdata)
			{
				while (pdata)
				{
					stack_push(stack, pdata);
					pdata = (*read)(&fptr);
				}
				my_mess(MY_MESS_SUCCESS);
			}
			else
				my_mess(MY_MESS_FILE_EMPTY);
		}
		else
			my_mess(MY_MESS_FILE_ERROR);
	}
	else
		my_mess(MY_MESS_NOT_EMPTY);
}

void stack_find_year(struct Stack* stack, int year, FindYear findyear)
{
	node_find_year(stack->Top, year, findyear);
}

void stack_find_faculty(struct Stack* stack, Faculty fac, FindFaculty findfac)
{
	node_find_faculty(stack->Top, fac, findfac);
}

void stack_find_lastname(struct Stack* stack, char* lastname, FindLastname findlast)
{
	node_find_lastname(stack->Top, lastname, findlast);
}
