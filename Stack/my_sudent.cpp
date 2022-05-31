#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_student.h"
#include "faculties.h"
#include "my_messages.h"


void student_free(void* pdata)
{
	struct Student* student = (struct Student*)pdata;
	if (student)
		free(student->lastname);
		free(student);
}

void student_print(void* pdata)
{
	struct Student* student = (struct Student*)pdata;
	if (student)
	{
		printf("\n -- Student --\n");
		printf("Lastname:\t%s\n", student->lastname);
		printf("Year:\t\t%d\n", student->year);
		printf("Faculty:\t%s\n", faculty_get(student->faculty));
	}
}

void* student_init(char* lastname, int year, Faculty faculty)
{
	struct Student* student = (struct Student*)malloc(sizeof(struct Student));
	if (student)
	{
		student->lastname = lastname;
		student->faculty = faculty;
		student->year = year;
	}
	return (void*)student;
}

void student_save(void* pdata, FILE** fptr)
{
	struct Student* student = (struct Student*)pdata;
	fwrite(&(student->year), sizeof(int), 1, *fptr);
	fwrite(&(student->faculty), sizeof(student->faculty), 1, *fptr);

	size_t strsize = (strlen(student->lastname)+1) * sizeof(char);
	fwrite(&strsize, sizeof(size_t), 1, *fptr);
	fwrite(student->lastname, strsize, 1, *fptr);
	printf(" saving...\n");
}

void* student_read(FILE** fptr)
{
	struct Student* pdata = (struct Student*)malloc(sizeof(struct Student));
	if (pdata)
	{
		if (!(fread(&(pdata->year), sizeof(int), 1, *fptr)))
		{
			free(pdata);
			pdata = NULL;
			printf("\nEOF\n");
		}
		else
		{
			fread(&(pdata->faculty), sizeof(COMPUTER_SCIENCE), 1, *fptr);
			size_t size;
			fread(&size, sizeof(size_t), 1, *fptr);
			pdata->lastname = (char*)malloc(size);
			fread(pdata->lastname, size, 1, *fptr);
			printf(" loading...\n");
		}
	}
	else
		pdata = NULL;
	return (void*)pdata;
}

int student_find_year(void* pdata, int year)
{
	struct Student* student = (struct Student*)pdata;
	if (student->year == year)
	{
		student_print(pdata);
		return 1;
	}
	return 0;
}

int student_find_faculty(void* pdata, Faculty faculty)
{
	struct Student* student = (struct Student*)pdata;
	if (student->faculty == faculty)
	{
		student_print(pdata);
		return 1;
	}
	return 0;
}

int student_find_lastname(void* pdata, char* lastname)
{
	struct Student* student = (struct Student*)pdata;
	if (!strcmp(student->lastname, lastname))
	{
		student_print(pdata);
		return 1;
	}
	return 0;
}