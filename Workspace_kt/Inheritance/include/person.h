//person.h
#include <stdio.h>

typedef struct _Person Person;

//pointers to function
typedef void    (*fptrDisplayInfo)(Person*);
typedef void    (*fptrWriteToFile)(Person*, const char*);
typedef void    (*fptrDelete)(Person*) ;

typedef struct _Person
{
    void* pDerivedObj;
    char* pFirstName;
    char* pLastName;
    fptrDisplayInfo Display;
    fptrWriteToFile WriteToFile;
    fptrDelete        Delete;
}Person;

Person* new_Person(const char* const pFristName,
                   const char* const pLastName);    //constructor
void delete_Person(Person* const pPersonObj);    //destructor

void Person_DisplayInfo(Person* const pPersonObj);
void Person_WriteToFile(Person* const pPersonObj, const char* const pFileName);
