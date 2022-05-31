#include <stdio.h>
#include <stdlib.h>

#include "my_messages.h"
#include "my_stack.h"

void my_mess(MY_MESSAGES message, struct Stack* stack)
{
	switch (message)
	{
	case MY_MESS_ALLOC_ERROR:
		printf("\nMemory allocation ERROR.\n");
		if (stack)
		{
			stack_free(stack);
			exit(0);
		}
		break;
	case MY_MESS_FILE_ERROR:
		printf("\nERROR: Cannot open file\n");
		break;
	case MY_MESS_FILE_EMPTY:
		printf("\nFile empty!\n");
		break;
	case MY_MESS_STACK_OVERFLOW:
		printf("\nStack overflow!\n");
		break;
	case MY_MESS_NOT_FOUND:
		printf("\nCannot find data maching specified criteria.\n");
		break;
	case MY_MESS_SUCCESS:
		printf("\nSuccess!\n");
		break;
	case MY_MESS_INVALID:
		printf("\nInvalid operation code.\n");
		break;
	case MY_MESS_EMPTY:
		printf("\nStack empty.\n");
		break;
	case MY_MESS_NOT_EMPTY:
		printf("\nStack not empty. Free it first.\n");
		break;
	case MY_MESS_TOTAL:
		break;
	default:
		break;
	}
}