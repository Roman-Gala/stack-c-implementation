#ifndef MY_INTERFACE___H
#define MY_INTERFACE___H


enum MY_INTERFACE
{
	INTER_PUSH,
	INTER_POP,
	INTER_FREE,
	INTER_PRINT,
	INTER_SAVE,
	INTER_READ,
	INTER_FIND,
	INTER_QUIT,
	INTER_TOT
};

void inter_push(struct Stack* stack);
void inter_pop(struct Stack* stack);
void inter_free(struct Stack* stack);
void inter_menu(struct Stack* stack);
void inter_quit(struct Stack* stack);
void inter_print(struct Stack* stack);
void inter_save(struct Stack* stack);
void inter_read(struct Stack* stack);
void inter_find(struct Stack* stack);

#endif