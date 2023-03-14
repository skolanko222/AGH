#include <iostream>
#include <string.h>

void AddStudent(int *numberOfStudents, char *** namesList, int ** yearsList, char * name, int  year);
void Cat(int numberOfStudents, char ** namesList);
void Cat(int numberOfStudents, int * yearsList);
void ClearList(int numberOfStudents, char *** namesList);
void ClearList(int numberOfStudents, int ** yearsList);