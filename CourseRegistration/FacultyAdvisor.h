#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

#ifndef FACULTYADVISOR_H
#define FACULTYADVISOR_H

class FacultyAdvisor {
public:
void adviseStudent(Student* student) {
    // Logic for advising student
    cout << "Advising student " << student->getName() << endl;
}
};

#endif