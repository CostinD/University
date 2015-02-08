#pragma once

#include "Section.h"

using namespace std;

Section::Section()
{
	callNumber = 00000;
	ID = "N/A";
	instructorName = "N/A";
	location = "N/A";
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