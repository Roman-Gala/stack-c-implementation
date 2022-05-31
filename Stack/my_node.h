#ifndef MY_NODE___H
#define MY_NODE___H

#include "faculties.h"

typedef void (*FreeData)(void* pdata);
typedef void (*PrintData)(void* pdata);
typedef void (*SaveData)(void* pdata, FILE** fptr);
typedef void* (*ReadData)(FILE** fptr);
typedef int (FindLastname)(void* pdata, char* lastname);
typedef int (FindYear)(void* pdata, int year);
typedef int (FindFaculty)(void* pdata, Faculty fac);


struct Node
{
	void* data;
	struct Node* next;
};



struct Node* node_init(struct Node* next, void* pdata);
void node_free(struct Node* node, FreeData pFreeData);
void node_print(struct Node* node, PrintData print);
void node_save(struct Node* node, FILE** fptr, SaveData save);
void node_find_year(struct Node* node, int year, FindYear findyear);
void node_find_faculty(struct Node* node, Faculty faculty, FindFaculty findfac);
void node_find_lastname(struct Node* node, char* lastname, FindLastname findlast);

#endif