#include <iostream>
#include <string>
using namespace std;

#ifndef SCHEDULE_H
#define SCHEDULE_H

class Schedule {
private:
    long int studentId;
    long int courseCode;
    string semester;
    string days;
    string room;

public:
    Schedule(long int studentId, long int courseCode, const string& semester,const string& days, const string& room)
    : studentId(studentId), courseCode(courseCode), semester(semester), days(days), room(room) {}

long int getStudentId() const {
    return studentId;
}

long int getCourseCode() const {
    return courseCode;
}

const string& getSemester() const {
    return semester;
}

const string& getDays() const {
    return days;
}

const string& getRoom() const {
    return room;
}

};

#endif