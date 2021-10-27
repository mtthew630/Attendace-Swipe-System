#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"
#include <algorithm>

using namespace std;

Student::Student(string student_id, string student_name) {
    this->id = student_id;
    this->name = student_name;
};

string Student::get_id() {
    return id;
}
string Student::get_name() {
    return name;
}

// 0 points
void Student::addCourse(string course_id) {
    if (count(course_ids.begin(), course_ids.end(), course_id)) {
        cout << "Course ID already in course";
    }
    else {
        course_ids.push_back(course_id);
    }
}
// 0 points
void Student::listCourses() {
    if(course_ids.empty()) {
        cout << "No Courses" << endl;
    }
    else {
        cout << "Courses for " << id << endl;
        for(unsigned int i = 0; i < course_ids.size(); ++i) {
            cout << course_ids[i] << endl;
        }
    }
}
