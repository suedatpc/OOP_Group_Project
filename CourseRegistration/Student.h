#include <iostream>
#include <string>
#include <vector>
#include "Course.h" // Include Course header for registration functionality
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Course; // Forward declaration

class Student {
private:
    long int studentId;
    string name;
    vector<Course*> coursesRegistered; // List of registered courses
    vector<Course*> waitlist; // List of courses in the waitlist

public:
    Student() : studentId(0), name("") {}

    Student(long int studentId, const string& name) : studentId(studentId), name(name) {}

    long int getStudentId() const {
    return studentId;
}

const string& getName() const {
    return name;
}

void registerCourse(Course* course) {
    coursesRegistered.push_back(course);
}

void addToWaitlist(Course* course) {
    waitlist.push_back(course);
}

void displayRegisteredCourses() const {
    cout << "Registered Courses for " << name << ":" << endl;
    for (const auto& course : coursesRegistered) {
        course->displayCourseInfo();
    }
}

void displayWaitlist() const {
    cout << "Waitlisted Courses for " << name << ":" << endl;
    for (const auto& course : waitlist) {
        course->displayCourseInfo();
    }
}

    // Function to get student information from user input
    void getInfo() {
        cout << "Enter student ID: ";
        cin >> studentId;
        cout << "Enter student name: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, name);
    }
};

#endif