#pragma once

#include "Section.h"
#include <vector>
#include <string>

using namespace std;

class University{
private:
	vector<Section> sections;

public:
	//Add new section
	string addSection(int sectionID, string courseID, string instructor, string location);
	string addMeetingTimeToSection(int secID, string meetTime);
	string addStudentToSection(int secID, int studentID);
	string removeMeetingTimeFromSection(int secID, string meetTime);
	string removeStudentFromSection(int secID, int studentID);
	string displaySections(bool withStudents);
	string findSectionByCourseID(string courseID);
	string findSectionByInstructor(string instructor);
	string findSectionByLocation(string location);
	string editSection(int secID, string courseID, string instructor, string location);
	string removeSection(int secID);
	string clearAllSections();

	Section* findSection(int secID);

};