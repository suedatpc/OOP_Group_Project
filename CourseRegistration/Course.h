#include <iostream>
#include <string>
#include <vector>
//#include "Student.h"
using namespace std;

#ifndef COURSE_H
#define COURSE_H

class Student;
enum class CourseType {
    LECTURE,
    SEMINAR,
    LAB,
    HONORS,
    REMOTE
};

class Course {
private:
    long int courseCode;
    string title;
    int credits;
    string instructor;
    vector<Student*> enrolledStudents;

    CourseType type;

public:
    Course(long int courseCode, const string& title, int credits, const string& instructor, CourseType type)
    : courseCode(courseCode), title(title), credits(credits), instructor(instructor), type(type) {}



long int getCourseCode() const {
    return courseCode;
}

const string& getTitle() const {
    return title;
}

int getCredits() const {
    return credits;
}

const string& getInstructor() const {
    return instructor;
}

void displayCourseInfo() const {
    cout << "Course Code: " << courseCode << ", Title: " << title << ", Credits: " << credits
              << ", Instructor: " << instructor;

    switch (static_cast<int>(type)){
        case static_cast<int>(CourseType::LECTURE):
            cout << ", Type: Lecture";
            break;
        case static_cast<int>(CourseType::SEMINAR):
            cout << ", Type: Seminar";
            break;
        case static_cast<int>(CourseType::LAB):
            cout << ", Type: Lab";
            break;
        case static_cast<int>(CourseType::HONORS):
            cout << ", Type: Honors";
            break;
        case static_cast<int>(CourseType::REMOTE):
            cout << ", Type: Remote";
            break;
    }
    cout << endl;
}

void registerStudent(Student* student) {
    enrolledStudents.push_back(student);
}

};


#endif