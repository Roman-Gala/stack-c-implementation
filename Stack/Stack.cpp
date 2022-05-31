#include <stdlib.h>
#include <stdio.h>

#include "my_interface.h"
#include "my_stack.h"
#include "my_student.h"
#include "my_node.h"
#include "my_messages.h"

#pragma warning (disable : 4996)

int main()
{
	struct Stack* stack = stack_init(student_free);
	int op = 0;
	while (op >= INTER_PUSH && op <= INTER_QUIT)
	{
		inter_menu(stack);
		scanf("%d", &op);
		switch (op)
		{
		case INTER_PUSH:
			inter_push(stack);
			break;
		case INTER_POP:
			inter_pop(stack);
			break;
		case INTER_FREE:
			inter_free(stack);
			break;
		case INTER_PRINT:
			inter_print(stack);
			break;
		case INTER_QUIT:
			inter_quit(stack);
			break;
		case INTER_SAVE:
			inter_save(stack);
			break;
		case INTER_READ:
			inter_read(stack);
			break;
		case INTER_FIND:
			inter_find(stack);
			break;
		default:
			my_mess(MY_MESS_INVALID);
			op = 0;
			break;
		};
	}
	return 0;
}