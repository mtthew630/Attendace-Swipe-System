#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "School.h"
//#include "Course.h"
#include "AttendanceRecord.h"
#include "Date.h"

using namespace std;

void School::addStudents(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');  // stores id into uin
    string name;
    getline(ss, name);  // stores student name into name
    if (!ss.fail()) {
      students.push_back(Student(uin, name));
    }
  }
}

void School::addCourses(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    if (line.empty()) {
      break;
    }
    string courseNum;
    getline(ss, courseNum, ',');  // stores course id into courseNum
    string startHour;
    string startMin;
    getline(ss, startHour, ':');  
    getline(ss, startMin, ',');
    string endHour;
    string endMin;
    getline(ss, endHour, ':');  
    getline(ss, endMin, ',');
    string courseName;
    getline(ss, courseName, '\n');  // stores course into courseName
    if (!ss.fail()) {
      courses.push_back(Course(courseNum, courseName, Date(stoi(startHour), stoi(startMin)), Date(stoi(endHour), stoi(endMin)))); // sec?
    }
  }
}

void School::addAttendanceData(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    if (line.empty()) {
      break;
    }
    string year;
    getline(ss, year, '-');  
    string month;
    getline(ss, month, '-');  
    string day;
    getline(ss, day, ' ');
    string swipeHour;
    string swipeMin;
    string swipeSec;
    getline(ss, swipeHour, ':');  
    getline(ss, swipeMin, ':');
    getline(ss, swipeSec, ',');
    string courseId;
    getline(ss, courseId, ',');  
    string stuId;
    getline(ss, stuId, '\n');
    if (!ss.fail()) {
      AttendanceRecord ar = AttendanceRecord(courseId, stuId, Date(stoi(year), stoi(month), stoi(day), stoi(swipeHour), stoi(swipeMin), stoi(swipeSec)));
      for (unsigned int i=0; i<courses.size(); i++) {
        if (courses[i].getID() == courseId) {
          courses[i].addAttendanceRecord(ar);
        }
      }
    }
  }
}

void School::listCourses() {
  if (courses.size() == 0) {
    cout << "No Courses" << endl;
  }
  for(unsigned int i=0; i<courses.size(); i++) {
    cout << courses.at(i).getID() << ",";
    cout << courses.at(i).getStartTime().getTime(false) << ",";
    cout << courses.at(i).getEndTime().getTime(false) << ","; 
    cout << courses.at(i).getTitle() << endl;
  }
}

void School::listStudents() {
  if (students.size() == 0) {
    cout << "No Students" << endl;
  }
  for(unsigned int i=0; i<students.size(); ++i) {
    cout << students.at(i).get_id() << "," << students.at(i).get_name() << endl;
  }
}

void School::outputCourseAttendance(std::string course_id) {
  for (unsigned int i=0; i<courses.size(); ++i) {
    if (courses[i].getID() == course_id) {
      courses[i].outputAttendance();
    }
  }
}

void School::outputStudentAttendance(std::string student_id, std::string course_id) {
  for (unsigned int i=0; i<courses.size(); ++i) {
    if (courses[i].getID() == course_id) {
      courses[i].outputAttendance(student_id);
    }
  }
}

