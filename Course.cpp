#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using namespace std;

Course::Course(std::string id, std::string title, Date startTime, Date endTime) : startTime(startTime), endTime(endTime) {
    // data member = parameter
    this->id = id;
    this->title = title;
    this->startTime = startTime;
    this->endTime = endTime;
};

string Course::getID() {
    return id;
}

string Course::getTitle() {
    return title;
}

Date Course::getStartTime() {
    return startTime;
}

Date Course::getEndTime() {
    return endTime;
}
// 0 points

void Course::addAttendanceRecord(AttendanceRecord ar) {
    Date time = ar.getDate();
    if (time >= getStartTime() && time <= getEndTime()) {
        attendanceRecords.push_back(ar);
    }
    else {
        cout << "did not save this record." << endl;
    }
}

// 0 points
void Course::outputAttendance() {
    for(auto & attendanceRecord : attendanceRecords) {
       cout << attendanceRecord.getDate().getDateTime() << ",";
       cout << attendanceRecord.getCourseID() << ",";
       cout << attendanceRecord.getStudentID() << endl;
   }
   if(attendanceRecords.empty()) {   
       cout << "No Records" << endl;
   }
}
    /*
    AttendanceRecord attendanceRecord;
    for (unsigned int i=0; i<attendanceRecords.size(); i++) {
        cout << attendanceRecord.getDate().getDateTime() << ",";
        cout << attendanceRecord.getCourseID() << ",";
        cout << attendanceRecord.getStudentID() << endl;
        */

// 0 points
void Course::outputAttendance(string student_id) {
    bool isValid = false;
    for (auto & attendanceRecord : attendanceRecords) {
        if (attendanceRecord.getStudentID() == student_id) {
            isValid = true;
            cout << attendanceRecord.getDate().getDateTime() << ",";
            cout << attendanceRecord.getCourseID() << ",";
            cout << attendanceRecord.getStudentID() << endl;
        }
    }
    if (isValid == false) {
        cout << "No Records" << endl;
    }
}


