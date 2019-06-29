#include <stdio.h>
#include "include/employee.h"
#include <memory.h>
int main()
{
    Person* PersonObj = new_Person("Anjali", "Jaiswal");
    Person* EmployeeObj = new_Employee("Gauri", "Jaiswal","HR", "TCS", 40000);
    Person* EmployeObj1 = new_Employee("Gauri", "Jaiswal","HR", "TCS", 40000);


    //accessing person object

//    //displaying person info
//    PersonObj->Display(PersonObj);
//    //writing person info in the persondata.txt file
//    PersonObj->WriteToFile(PersonObj,"persondata.txt");
//    //calling destructor
//    PersonObj->Delete(PersonObj);

    //accessing to employee object

    //displaying employee info
    EmployeeObj->Display(EmployeeObj);
    //writing empolyee info in the employeedata.txt file
    EmployeeObj->WriteToFile(EmployeeObj, "employeedata.txt");
    //calling destrutor
    EmployeeObj->Delete(EmployeeObj);
    Employee* employee = (Employee*)(EmployeObj1->pDerivedObj);
    printf("%s\n",employee->pCompany);
    printf("%s\n",employee->pDepartment);
    printf("%d",employee->nSalary);
//    printf("%s",one->pCompany);
//    char* c = (Employee*)(EmployeeObj)->pDepartment;
    return 0;
}
