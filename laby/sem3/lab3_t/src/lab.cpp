#include <string.h>
#include <iostream>

void AddStudent(int *numberOfStudents, char *** namesList, int ** yearsList, char * name, int  year)
{
    (*numberOfStudents)++;
    char ** new_namesList = new char *[*numberOfStudents];
    int * new_yearsList = new int [*numberOfStudents];

    if(*numberOfStudents > 1)
    {
        for(int i = 0; i < *numberOfStudents - 1; i++)
        {
            new_namesList[i] = new char [strlen((*namesList)[i]) + 1];
            strcpy(new_namesList[i],(*namesList)[i]);
            delete [] (*namesList)[i];

            new_yearsList[i] = (*yearsList)[i];

        }
        
        delete[] *namesList;
        delete[] *yearsList;

    }

    new_namesList[*numberOfStudents - 1] = new char[strlen(name) + 1];
    strcpy(new_namesList[*numberOfStudents - 1],name);

    new_yearsList[*numberOfStudents - 1] = year;

    *namesList = new_namesList;
    *yearsList = new_yearsList;
    
    
    
     return;
}

void Cat(int numberOfStudents, char ** namesList)
{
    for(int i = 0; i < numberOfStudents; i++)
        std::cout << namesList[i] << std::endl;

    return;
}

void Cat(int numberOfStudents, int * yearsList)
{
    for(int i = 0; i < numberOfStudents; i++)
        std::cout << yearsList[i] << std::endl;


    return;
}

void ClearList(int numberOfStudents, char *** namesList)
{
    for(int i = 0; i < numberOfStudents; i++)
        delete [] (*namesList)[i];
    
    delete [] *namesList;

    return;
}

void ClearList(int numberOfStudents, int ** yearsList)
{ 
    delete [] *yearsList;

    return;    
}