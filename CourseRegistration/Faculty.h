#include <iostream>
#include <string>
using namespace std;

#ifndef FACULTY_H
#define FACULTY_H

class Faculty {
private:
    int facultyId;
    string facultyName;
    string facultyEmail;
    string facultyPhoneNumber;
    string department;
    string coursesTaught;

public:
    Faculty(int facultyId, const string& facultyName, const string& facultyEmail,const string& facultyPhoneNumber, const string& department, const string& coursesTaught)
    : facultyId(facultyId), facultyName(facultyName), facultyEmail(facultyEmail),
      facultyPhoneNumber(facultyPhoneNumber), department(department), coursesTaught(coursesTaught) {}

int getFacultyId() const {
    return facultyId;
}

const string& getFacultyName() const {
    return facultyName;
}

const string& getFacultyEmail() const {
    return facultyEmail;
}

const string& getFacultyPhoneNumber() const {
    return facultyPhoneNumber;
}

const string& getDepartment() const {
    return department;
}

const string& getCoursesTaught() const {
    return coursesTaught;
}

};

#endif