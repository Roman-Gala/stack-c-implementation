#ifndef MY_STUDENT___H
#define MY_STUDENT___H

#include "faculties.h"

struct Student
{
	char* lastname;
	int year;
	Faculty faculty;
};

void student_free(void* pdata);
void student_print(void* pdata);
void* student_init(char* lastname, int year, Faculty faculty);
void student_save(void* pdata, FILE** fptr);
void* student_read(FILE** fptr);
int student_find_year(void* pdata, int year);
int student_find_faculty(void* pdata, Faculty faculty);
int student_find_lastname(void* pdata, char* lastname);

#endif
