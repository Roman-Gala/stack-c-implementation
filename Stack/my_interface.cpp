#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_interface.h"
#include "my_student.h"
#include "my_stack.h"
#include "faculties.h"
#include "my_messages.h"

#pragma warning (disable : 4996)

const char* strtab[]
{
	"0 - push",			 //INTER_PUSH
	"1 - pop",			 //INTER_POP
	"2 - free",		     //INTER_FREE
	"3 - print",         //INTER_PRINT
	"4 - save",          //INTER_SAVE
    "5 - read",          //INTER_READ
    "6 - find",          //INTER_FIND
    "7 - quit"           //INTER_QUIT
};

void inter_menu(struct Stack* stack)
{
	size_t it;
    printf("\nMenu:\n\n");
	for (it = 0; it < INTER_TOT; it++)
	{
		printf("%s\n", strtab[it]);
	}
    printf("\nOption: ");
}

void inter_push(struct Stack* stack)
{
    int year, fac;
    printf("\nLastname: ");
    char* temp = (char*)malloc(150 * sizeof(char));
    char* lastname;
    size_t len;
    if (temp)
    {
        scanf("%s", temp);
        len = strlen(temp)+1;
        lastname = (char*)malloc(len * sizeof(char));
        if (lastname)
        {
            strcpy(lastname, temp);
        }
        else
        {
            free(temp);
            my_mess(MY_MESS_ALLOC_ERROR, stack);
            return;
        }
    }
    else
    {
        free(temp);
        my_mess(MY_MESS_ALLOC_ERROR, stack);
        return;
    }
    free(temp);
    printf("Year: ");
    scanf("%d", &year);
    faculty_print();
    printf("Option: ");
    scanf("%d", &fac);
    Faculty faculty = (Faculty)fac;
    void* pdata = student_init(lastname, year, faculty);
    stack_push(stack, pdata);
    student_print(pdata);
    printf("\n");
    system("pause");
}

void inter_pop(struct Stack* stack)
{
    void* student = stack_pop(stack);
    student_print(student);
    student_free(student);
    printf("\n");
    system("pause");
}

void inter_free(struct Stack* stack)
{
    stack_free(stack);
    printf("\nStack emptied.\n");
    system("pause");
}

void inter_quit(struct Stack* stack)
{
    stack_free(stack);
    free(stack);
    exit(0);
}

void inter_print(struct Stack* stack)
{
    stack_print(stack, student_print);
    printf("\n");
    system("pause");
}

void inter_save(struct Stack* stack)
{
    stack_save(stack, student_save);
    printf("\n");
    system("pause");
}

void inter_read(struct Stack* stack)
{
    printf("\n");
    stack_read(stack, student_read);
    printf("\n");
    system("pause");
}

void inter_find(struct Stack* stack)
{
    printf("\nSearch by:\n");
    printf("0 - Lastname\n");
    printf("1 - Year\n");
    printf("2 - Faculty\n");
    printf("Option: ");
    int opt;
    scanf("%d", &opt);
    char* temp = (char*)malloc(150 * sizeof(char));
    switch (opt)
    {
    case 0:
        printf("\nEnter lastname: ");
        char* lastname;
        size_t len;
        if (temp)
        {
            scanf("%s", temp);
            len = strlen(temp) + 1;
            lastname = (char*)malloc(len * sizeof(char));
            if (lastname)
            {
                strcpy(lastname, temp);
            }
            else
            {
                free(temp);
                my_mess(MY_MESS_ALLOC_ERROR, stack);
                return;
            }
        }
        else
        {
            free(temp);
            my_mess(MY_MESS_ALLOC_ERROR, stack);
            return;
        }
        stack_find_lastname(stack, lastname, student_find_lastname);
        printf("\n");
        system("pause");
        break;
    case 1:
        int year;
        printf("\nEnter year: ");
        scanf("%d", &year);
        stack_find_year(stack, year, student_find_year);
        printf("\n");
        system("pause");
        break;
    case 2:
        faculty_print();
        printf("\nChoose faculty: ");
        int fac;
        scanf("%d", &fac);
        if (fac >= COMPUTER_SCIENCE && fac <= BIOLOGY)
        {
            int k;
            stack_find_faculty(stack, (Faculty)fac, student_find_faculty);
        }
        else
            my_mess(MY_MESS_INVALID);
        printf("\n");
        system("pause");
        break;
    default:
        my_mess(MY_MESS_INVALID);
        break;
    }
    free(temp);
}