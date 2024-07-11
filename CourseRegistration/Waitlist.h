#include "Course.h"
#include "Student.h"

#ifndef WAITLIST_H
#define WAITLIST_H

class Waitlist {
private:
    long int waitlistId; 
    long int studentId;
    long int courseCode;

public:
    Waitlist(long int waitlistId, long int studentId, long int courseCode)
        : waitlistId(waitlistId), studentId(studentId), courseCode(courseCode) {}


    long int getWaitlistId() const {
        return waitlistId;
    }

    long int getStudentId() const {
        return studentId;
    }

    long int getCourseCode() const {
        return courseCode;
    }

};

#endif
