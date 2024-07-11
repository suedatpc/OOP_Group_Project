#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
using namespace std;

#ifndef ADMINISTRATIVESTAFF_H
#define ADMINISTRATIVESTAFF_H

class AdministrativeStaff {
public:
    void enrollStudentInCourse(Student* student, Course* course) {
    // Logic for enrolling student in course
    cout << "Enrolled student " << student->getName() << " in course " << course->getTitle() << endl;
}
};

#endif