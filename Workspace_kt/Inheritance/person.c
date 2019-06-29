#include "include/person.h"
//Person.c
//construction of Person object
Person* new_Person(const char* const pFirstName, const char* const pLastName)
{
    Person* pObj = NULL;
    //allocating memory
    pObj = (Person*)malloc(sizeof(Person));
    if (pObj == NULL)
    {
        return NULL;
    }
    //pointing to itself as we are creating base class object
    pObj->pDerivedObj = pObj;
    pObj->pFirstName = malloc(sizeof(char)*(strlen(pFirstName)+1));
    if (pObj->pFirstName == NULL)
    {
        return NULL;
    }
    strcpy(pObj->pFirstName, pFirstName);

    pObj->pLastName = malloc(sizeof(char)*(strlen(pLastName)+1));
    if (pObj->pLastName == NULL)
    {
        return NULL;
    }
    strcpy(pObj->pLastName, pLastName);

    //Initializing interface for access to functions
    //destructor pointing to destrutor of itself
//    pObj->Delete = delete_Person;
//    pObj->Display = Person_DisplayInfo;
//    pObj->WriteToFile = Person_WriteToFile;

    return pObj;
}
