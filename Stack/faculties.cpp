#include <stdio.h>
#include <stdlib.h>

#include "faculties.h"

const char* faculties[] = {
    "Computer Science",
    "Data Science",
    "Biology"
};

void faculty_print()
{
    printf("Faculty: \n");
    for (int i = 0; i < END; i++)
    {
        printf("%d - %s\n", i, faculties[i]);
    }
}

const char* faculty_get(int fac)
{
    return faculties[fac];
}