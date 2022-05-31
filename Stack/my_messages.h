#pragma once
#include <stdio.h>

#include "my_stack.h"

enum MY_MESSAGES
{
	MY_MESS_ALLOC_ERROR,
	MY_MESS_FILE_ERROR,
	MY_MESS_FILE_EMPTY,
	MY_MESS_STACK_OVERFLOW,
	MY_MESS_NOT_FOUND,
	MY_MESS_SUCCESS,
	MY_MESS_INVALID,   	       
	MY_MESS_EMPTY,             
	MY_MESS_NOT_EMPTY,
	MY_MESS_TOTAL              
};

void my_mess(MY_MESSAGES mess, struct Stack* stack = NULL);