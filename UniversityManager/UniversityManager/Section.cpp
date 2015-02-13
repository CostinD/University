#pragma once

#include "Section.h"

using namespace std;

Section::Section()
{
	callNumber = 00000;
	ID = "N/A";
	//meetingTimes.clear();
	//studentIDs.clear();
	instructorName = "N/A";
	location = "N/A";
}
Section::Section(int cNumber, string cID, string instructor, string loc)
{
	callNumber = cNumber;
	ID = cID;
	instructorName = instructor;
	location = loc;
	//meetingTimes.clear();
	//studentIDs.clear();
}
Section::Section(int callNum, string iD, string instrName, vector<string> meetTimes, vector<int> stdntIDs, string loc)
{
	callNumber = callNum;
	ID = iD;
	instructorName = instrName;
	meetingTimes = meetTimes;
	studentIDs = stdntIDs;
	location = loc;
}
Section::~Section()
{
	//Destructor
	//delete this;
}
//Accessors
int Section::GetCallNumber()
{
	return callNumber;
}
string Section::GetID()
{
	return ID;
}
string Section::GetInstructorName()
{
	return instructorName;
}
vector<string>* Section::GetMeetingTimes()
{
	return &meetingTimes;
}
vector<int>* Section::GetStudentIDs()
{
	return &studentIDs;
}
string Section::GetLocation()
{
	return location;
}

//Mutators
void Section::SetCallNumber(int value)
{
	callNumber = value;
}
void Section::SetID(string value)
{
	ID = value;
}
void Section::SetInstructorName(string value)
{
	instructorName = value;
}
void Section::SetMeetingTimes(vector<string> value)
{
	meetingTimes = value;
}
void Section::SetStudentIDs(vector<int> value)
{
	studentIDs = value;
}
void Section::SetLocation(string value)
{
	location = value;
}