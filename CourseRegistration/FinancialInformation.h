#include <iostream>
#include <string>
using namespace std;

#ifndef FINANCIALINFORMATION_H
#define FINANCIALINFORMATION_H

class FinancialInformation {
private:
    long int studentFinancial;
    double courseFees;
    string paymentHistory;
    string financialStatus;

public:
FinancialInformation(long int studentFinancial, double courseFees,const string& paymentHistory, const string& financialStatus)
    : studentFinancial(studentFinancial), courseFees(courseFees), paymentHistory(paymentHistory),
      financialStatus(financialStatus) {}


long int getStudentFinancial() const {
    return studentFinancial;
}

double getCourseFees() const {
    return courseFees;
}

const string& getPaymentHistory() const {
    return paymentHistory;
}

const string& getFinancialStatus() const {
    return financialStatus;
}

};

#endif