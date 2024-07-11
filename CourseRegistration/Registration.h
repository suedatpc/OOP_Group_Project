#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
using namespace std;

#ifndef REGISTRATION_H
#define REGISTRATION_H

class Registration {
private:
    long int registrationId;
    long int studentId;
    long int courseCode;
    string registrationDate;
    string status;
    string paymentStatus;

public:
    Registration(long int registrationId, long int studentId, long int courseCode,const string& registrationDate, const string& status, const string& paymentStatus)
    : registrationId(registrationId), studentId(studentId), courseCode(courseCode),
      registrationDate(registrationDate), status(status), paymentStatus(paymentStatus) {}


long int getRegistrationId() const {
    return registrationId;
}

long int getStudentId() const {
    return studentId;
}

long int getCourseCode() const {
    return courseCode;
}

const string& getRegistrationDate() const {
    return registrationDate;
}

const string& getStatus() const {
    return status;
}

const string& getPaymentStatus() const {
    return paymentStatus;
}

};

#endif