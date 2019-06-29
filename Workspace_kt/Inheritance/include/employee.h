//Employee.h

#include "person.h"
//typedef struct _Person Person;

typedef struct _Employee Employee;

//Note: interface for this class is in the base class
//object since all functions are virtual.
//If there is any additional functions in employee add
//interface for those functions in this structure 
typedef void    (*employeSpecific)(Employee*);

typedef struct _Employee
{
//    Person* pBaseObj;
    char* pDepartment;
    char* pCompany;
    int nSalary;
    //If there is any employee specific functions; add interface here.
    employeSpecific EmployeSpecific;
}Employee;

Person* new_Employee(const char* const pFirstName, const char* const pLastName,
        const char* const pDepartment, const char* const pCompany, 
        int nSalary);    //constructor
void delete_Employee(Person* const pPersonObj);    //destructor

void Employee_DisplayInfo(Person* const pPersonObj);
void Employee_WriteToFile(Person* const pPersonObj, const char* const pFileName);
    
//Employee.c
