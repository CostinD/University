#pragma once

//#include "University.h"
#include <vector>
#include <string>

using namespace std;

class Section
{
private:
	int callNumber;
	string ID;
	string instructorName;
	vector<string> meetingTimes;
	vector<int> studentIDs;
	string location;

	//Constructors
public:
	Section();
	Section(int callNum, string iD, string instrName, vector<string> meetTimes, vector<int> stdntIDs, string loc);
	//Destructor
	~Section();

	//Accessors
	int GetCallNumber();
	string GetID();
	string GetInstructorName();
	vector<string> GetMeetingTimes();
	vector<int> GetStudentIDs();
	string GetLocation();

	//Mutators
	void SetCallNumber(int value);
	void SetID(string value);
	void SetInstructorName(string value);
	void SetMeetingTimes(vector<string> value);
	void SetStudentIDs(vector<int> value);
	void SetLocation(string value);
};