#ifndef MY_FACULTIES___H
#define MY_FACULTIES___H

enum Faculty
{
	COMPUTER_SCIENCE,
	DATA_SCIENCE,
	BIOLOGY,
	END
};

const char* faculty_get(int fac);
void faculty_print();

#endif