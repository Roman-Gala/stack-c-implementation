#ifndef MY_STACK___H
#define MY_STACK___H

#include "my_node.h"
#include "faculties.h"

struct Stack
{
	struct Node* Top;
	FreeData pFreeData;
};

typedef void (*FreeData)(void* pdata);
typedef void (*PrintData)(void* pdata);
typedef void (*SaveData)(void* pdata, FILE** fptr);
typedef void* (*ReadData)(FILE** fptr);
typedef int (FindLastname)(void* pdata, char* lastname);
typedef int (FindYear)(void* pdata, int year);
typedef int (FindFaculty)(void* pdata, Faculty fac);

struct Stack * stack_init(FreeData pFreeData);
void stack_free(struct Stack* stack);
void stack_push(struct Stack* stack, void* pdata);
void* stack_pop(struct Stack* stack);
void stack_print(struct Stack* stack, PrintData print);
void stack_save(struct Stack* stack, SaveData save);
void stack_read(struct Stack* stack, ReadData read);
void stack_find_lastname(struct Stack* stack, char* lastname, FindLastname findlast);
void stack_find_year(struct Stack* stack, int year, FindYear findyear);
void stack_find_faculty(struct Stack* stack, Faculty fac, FindFaculty findfac);

#endif