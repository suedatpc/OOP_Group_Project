    #include <iostream>
#include <vector>
#include "Student.h"
#include "Course.h"
#include "Registration.h"
#include "AdministrativeStaff.h"

using namespace std;

int main() {
    // Create some courses
    vector<Course> courses = {
        Course(101, "Introduction to Programming", 3, "Dr. Smith", CourseType::LECTURE),
        Course(102, "Data Structures", 4, "Dr. Johnson", CourseType::LAB),
        Course(103, "General Physics I", 4, "Dr. M. Fatih Hasoglu", CourseType::LECTURE),
        Course(104, "General Physics II", 4, "Dr. M. Fatih Hasoglu", CourseType::LECTURE),
        Course(105, "Technical English", 3, "Prof. Robert Harris", CourseType::LECTURE),
        Course(106, "Calculus", 4, "Dr. Laura Chen", CourseType::LECTURE),
        Course(107, "Introduction to Computer Science", 3, "Dr. John", CourseType::LECTURE),
        Course(108, "Introduction to Computer Science Lab", 2, "Dr. John", CourseType::REMOTE),
        Course(109, "Introduction to Software Programming", 3, "Dr. Olivia Martinez", CourseType::LECTURE),
        Course(110, "Introduction to Software Programming Lab", 3, "Dr. Olivia Martinez", CourseType::LAB),
        Course(111, "Database Systems", 3, "Dr. Emma Wilson", CourseType::LECTURE),
        Course(112, "Database Systems Lab", 3, "Dr. Emma Wilson", CourseType::LAB),
        Course(113, "Introduction to Operating Systems", 2, "Dr. Michael Davis", CourseType::REMOTE),
        Course(114, "Artificial Intelligence", 4, "Prof. Christopher Moore", CourseType::LECTURE),
        Course(115, "Artificial Intelligence Lab", 4, "Prof. Christopher Moore", CourseType::LAB),
        Course(116, "Machine Learning", 4, "Dr. Sophia Anderson", CourseType::LECTURE),
        Course(117, "Machine Learning Lab", 4, "Dr. Sophia Anderson", CourseType::LAB),
        Course(118, "Natural Language Processing", 3, "Prof. Emily Thompson", CourseType::LECTURE),    
        Course(119, "Full-Stack Web Development", 4, "Prof. Jane Doe", CourseType::LECTURE),
        Course(120, "Full-Stack Web Development Lab", 4, "Prof. Jane Doe", CourseType::LAB),
        Course(121, "Object Oriented Programming", 4, "Assoc. Prof. Dr. Abdul HAFEZ", CourseType::LECTURE),
    };

    cout << "Welcome to the Hasan Kalyoncu University Registration System!" << endl;
    cout << "Faculty of Engineering" << endl;
    cout << "Software Engineering Department" << endl;
    cout << "Faculty ID: 201650180" << endl;
    cout << "--------------------------------" << endl;
    cout << "Faculty Phone Number: +90 342 211 80 80" << endl;
    cout << "Faculty email: info@hku.edu.tr" << endl;
    cout << "--------------------------------" << endl;
    cout << "Press any key to continue..." << endl;
    cin.get();

    int userType;
    cout << "Enter your user type (0-Student, 1-Administrative Staff, 2-Faculty Advisor): ";
    cin >> userType;

    bool loginSuccess = false;

    if (userType == 0) {
        // Student login
        string sys_username, sys_password;
        const string username = "student1";
        const string password = "student123";

        while (!loginSuccess) {
            cout << "Enter your username: ";
            cin >> sys_username;
            cout << "Enter your password: ";
            cin >> sys_password;
            if (sys_username == username && sys_password == password) {
                cout << "Login successful. Welcome, " << username << "!" << endl;
                loginSuccess = true;
            } else {
                cout << "Invalid username or password. Please try again." << endl;
            }
        }

        // Let the student enter their details
        long int studentId;
        string studentName;
        cout << "Enter your student ID: ";
        cin >> studentId;
        cout << "Enter your student name: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, studentName);

        // Create a student
        Student student(studentId, studentName);

        // Display available courses
        cout << "Available Courses:" << endl;
        for (const auto& course : courses) {
            course.displayCourseInfo();
        }
        cout << endl;

        // Let the student choose a course
        int selectedCourseCode;
        cout << "Enter the course code of the course you want to register for: ";
        cin >> selectedCourseCode;

        /* long int registrationId;
        cout << "Enter registration ID: ";
        cin >> registrationId; */

        string registrationDate;
        cout << "Enter registration date (YYYY-MM-DD): ";
        cin >> registrationDate;

        // Find the selected course
        Course* selectedCourse = nullptr;
        for (auto& course : courses) {
            if (course.getCourseCode() == selectedCourseCode) {
                selectedCourse = &course;
                break;
            }
        }

        if (selectedCourse == nullptr) {
            cout << "Invalid course code." << endl;
            return 1;
        }

        // Register the student in the selected course
       
      Registration registration(001, student.getStudentId(), selectedCourse->getCourseCode(), registrationDate, "Registered", "Pending Payment");

        cout << endl;
        // Display registration details
        cout << "Registration Details:" << endl;
        cout << "Student Name: " << student.getName() << endl;
        cout << "Course Name: " << selectedCourse->getTitle() << endl;
        //cout << "Registration ID: " << registration.getRegistrationId() << endl;
        cout << "Registration Date: " << registration.getRegistrationDate() << endl;
        cout << "Registration Status: " << registration.getStatus() << endl;
        cout << "Payment Status: " << registration.getPaymentStatus() << endl;

    } else if (userType == 1) {
        // Administrative staff login
        string sys_username, sys_password;
        const string username = "admin1";
        const string password = "admin123";

        while (!loginSuccess) {
            cout << "Enter your username: ";
            cin >> sys_username;
            cout << "Enter your password: ";
            cin >> sys_password;
            if (sys_username == username && sys_password == password) {
                cout << "Login successful. Welcome, " << username << "!" << endl;
                loginSuccess = true;
            } else {
                cout << "Invalid username or password. Please try again." << endl;
            }
        }

        // Administrative Staff
        long int studentId;
        string studentName;
        cout << "Enter the student ID to enroll in a course: ";
        cin >> studentId;
        cout << "Enter the student name: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, studentName);

        // Create a student
        Student student(studentId, studentName);

        // Display available courses
        cout << "Available Courses:" << endl;
        for (const auto& course : courses) {
            course.displayCourseInfo();
        }
        cout << endl;

        // Let the staff choose a course
        int selectedCourseCode;
        cout << "Enter the course code of the course to enroll the student in: ";
        cin >> selectedCourseCode;

        // Find the selected course
        Course* selectedCourse = nullptr;
        for (auto& course : courses) {
            if (course.getCourseCode() == selectedCourseCode) {
                selectedCourse = &course;
                break;
            }
        }

        if (selectedCourse == nullptr) {
            cout << "Invalid course code." << endl;
            return 1;
        }

        // Enroll the student in the selected course
        AdministrativeStaff admin;
        admin.enrollStudentInCourse(&student, selectedCourse);

    } else if (userType == 2) {
        // Faculty Advisor login
        string sys_username, sys_password;
        const string username = "advisor1";
        const string password = "advisor123";

        while (!loginSuccess) {
            cout << "Enter your username: ";
            cin >> sys_username;
            cout << "Enter your password: ";
            cin >> sys_password;
            if (sys_username == username && sys_password == password) {
                cout << "Login successful. Welcome, " << username << "!" << endl;
                loginSuccess = true;
            } else {
                cout << "Invalid username or password. Please try again." << endl;
            }
        }

        // Faculty Advisor
        long int studentId;
        string studentName;
        cout << "Enter the student ID to enroll in a course: ";
        cin >> studentId;
        cout << "Enter the student name: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, studentName);

        // Create a student
        Student student(studentId, studentName);

        // Display available courses
        cout << "Available Courses:" << endl;
        for (const auto& course : courses) {
            course.displayCourseInfo();
        }
        cout << endl;

        // Let the advisor choose a course
        int selectedCourseCode;
        cout << "Enter the course code of the course to enroll the student in: ";
        cin >> selectedCourseCode;

        // Find the selected course
        Course* selectedCourse = nullptr;
        for (auto& course : courses) {
            if (course.getCourseCode() == selectedCourseCode) {
                selectedCourse = &course;
                break;
            }
        }

        if (selectedCourse == nullptr) {
            cout << "Invalid course code." << endl;
            return 1;
        }

        // Approve and enroll the student in the selected course
        cout << "Approving course enrollment..." << endl;
        AdministrativeStaff admin;
        admin.enrollStudentInCourse(&student, selectedCourse);
        cout << "Course enrollment approved by Faculty Advisor." << endl;

    } else {
        cout << "Invalid user type." << endl;
    }

    return 0;
}

