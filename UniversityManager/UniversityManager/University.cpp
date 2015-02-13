#include "University.h"

string University::addSection(int sectionID, string courseID, string instructor, string location)
{
	string result;
	Section sec(sectionID, courseID, instructor, location);
	Section* secPtr = findSection(sectionID);
	if (secPtr == nullptr)
	{
		sections.push_back(sec);
		result = to_string(sectionID) + "	" + courseID + "    " + instructor + "    " + location + " was added.\n";
	}
	else result = "Section " + to_string(sectionID) + " already exists. Sectiond ID has to be unique!\n";


	return result;
}

string University::addMeetingTimeToSection(int secID, string meetTime)
{
	string result;
	Section* secPtr = findSection(secID);
	if (secPtr != nullptr)
	{
		secPtr->GetMeetingTimes()->push_back(meetTime);
		result = meetTime + "    added to section     " + to_string(secPtr->GetCallNumber()) + "\n";
	}
	else
	{
		result = "Could not find Section!\n";
	}
	return result;
}
string University::addStudentToSection(int secID, int studentID)
{
	string result;
	//Grab pointer to section
	Section* secPtr = findSection(secID);
	if (secPtr != nullptr)
	{
		//Add student
		secPtr->GetStudentIDs()->push_back(studentID);
		//Display feedback
		result = to_string(studentID) + "    added to section     " + to_string(secPtr->GetCallNumber()) + "\n";
	}
	else
	{
		result = "Could not find Section!\n";
	}
	return result;
}

string University::removeMeetingTimeFromSection(int secID, string meetTime)
{
	string result;

	Section* secPtr = findSection(secID);
	if (secPtr != nullptr)
	{
		//Get meeting times pointer
		vector<string>* meetTimes = secPtr->GetMeetingTimes();
		if (meetTimes->size() > 0)
		{
			for (unsigned int i = 0; i < meetTimes->size(); i++)
			{
				if (meetTimes->at(i) == meetTime)
				{
					meetTimes->erase(meetTimes->begin() + i);
					result = "Meeting time " + meetTime + " was removed from section " + to_string(secID) + "\n";
					break;
				}
			}
		}
		else result = "Meeting Times is empty.\n";
	}
	else result = "Section " + to_string(secID) + " not found!\n";

	return result;
}

string University::removeStudentFromSection(int secID, int studentID)
{
	string result;

	Section* secPtr = findSection(secID);
	if (secPtr != nullptr)
	{
		//Get students pointer
		vector<int>* students = secPtr->GetStudentIDs();
		if (students->size() > 0)
		{
			for (unsigned int i = 0; i < students->size(); i++)
			{
				if (students->at(i) == studentID)
				{
					students->erase(students->begin() + i);
					result = "Student " + to_string(studentID) + " was removed from section " + to_string(secID) + "\n";
					break;
				}
			}
		}
		else result = "StudentIDs is empty.\n";
	}
	else result = "Section " + to_string(secID) + " not found!\n";

	return result;
}

string University::displaySections(bool withStudents)
{
	string result = "";
	string lineBreak = "-------------------------------------------------------------------------------\n";
	string meetTimeIndent = "\t\t\t\t\t\t\t\t";
	result = "\n";
	result += "Call Number\tID\t\tInstructor\tLocation\tMeeting Times\n";
	//Run through all sections;
	for (unsigned int i = 0; i < sections.size(); i++)
	{
		result += lineBreak;
		result += to_string(sections[i].GetCallNumber()) + "\t\t" + sections[i].GetID() + "\t\t" + sections[i].GetInstructorName();
		//Make sure instructor name aligns properly
		if (sections[i].GetInstructorName().size() < 8)
			result += "\t\t";
		else result += "\t";

		result += sections[i].GetLocation();
		if (sections[i].GetMeetingTimes()->size() > 0)
		{
			//Print first meeting time on same line.
			result += "\t\t" + sections[i].GetMeetingTimes()->at(0) + "\n";
			//Loop through all meeting times and print them underneath
			for (unsigned int x = 1; x < sections[i].GetMeetingTimes()->size(); x++)
			{
				result += meetTimeIndent;
				result += sections[i].GetMeetingTimes()->at(x) + "\n";
			}
		}
		else result += "\n";
		//Display all students
		if (withStudents)
		{
			if (sections[i].GetStudentIDs()->size() > 0)
			{
				int count = 0;
				result += "\tStudents:\t";
				for (unsigned int x = 0; x < sections[i].GetStudentIDs()->size(); x++)
				{
					count++;
					result += to_string(sections[i].GetStudentIDs()->at(x)) + "\t|\t";
					if (count == 3)
						result += "\n\t\t\t";
				}
				result += "\n";
			}
			else result += "There are no students in this section.\n";
		}
		result += lineBreak;
	}

	return result;
}

//Find section by courseID	
string University::findSectionByCourseID(string courseID)
{
	string result;
	string meetTimeIndent = "\t\t\t\t\t\t";
	string lineBreak = "-------------------------------------------------------------------------------\n";
	if (sections.size() > 0)
	{
		result = "\n";
		result += "Sections with ID " + courseID + ":\n";
		result += "Call Number\tInstructor\tLocation\tMeeting Times\n";
		int found = 0;
		for (unsigned int i = 0; i < sections.size(); i++)
		{
			if (sections[i].GetID() == courseID)
			{
				result += lineBreak;
				result += to_string(sections[i].GetCallNumber()) + "\t\t" + sections[i].GetInstructorName();
				//Make sure instructor name aligns properly
				if (sections[i].GetInstructorName().size() < 8)
					result += "\t\t";
				else result += "\t";
				result += sections[i].GetLocation();
				if (sections[i].GetMeetingTimes()->size() > 0)
				{
					//Print first meeting time on same line.
					result += "\t\t" + sections[i].GetMeetingTimes()->at(0) + "\n";
					//Loop through all meeting times and print them underneath
					for (unsigned int x = 1; x < sections[i].GetMeetingTimes()->size(); x++)
					{
						result += meetTimeIndent;
						result += sections[i].GetMeetingTimes()->at(x) + "\n";
					}
				}
				else result += "\n";
				result += lineBreak;
				found++;
			}
		}
		if (found == 0)
		{
			result = "There are no sections with ID	" + courseID + "!\n";
		}
	}
	else result = "Sections is empty!\n";
	return result;
}

string University::findSectionByInstructor(string instructor)
{
	string result;
	string meetTimeIndent = "\t\t\t\t\t\t";
	string lineBreak = "-------------------------------------------------------------------------------\n";
	if (sections.size() > 0)
	{
		result = "\n";
		result += "Sections from Instructor " + instructor + ":\n";
		result += "Call Number\tID\t\tLocation\tMeeting Times\n";
		int found = 0;
		for (unsigned int i = 0; i < sections.size(); i++)
		{
			if (sections[i].GetInstructorName() == instructor)
			{
				result += lineBreak;
				result += to_string(sections[i].GetCallNumber()) + "\t\t" + sections[i].GetID() + "\t\t";
				result += sections[i].GetLocation();
				if (sections[i].GetMeetingTimes()->size() > 0)
				{
					//Print first meeting time on same line.
					result += "\t\t" + sections[i].GetMeetingTimes()->at(0) + "\n";
					//Loop through all meeting times and print them underneath
					for (unsigned int x = 1; x < sections[i].GetMeetingTimes()->size(); x++)
					{
						result += meetTimeIndent;
						result += sections[i].GetMeetingTimes()->at(x) + "\n";
					}
				}
				else result += "\n";
				result += lineBreak;
				found++;
			}
		}
		if (found == 0)
		{
			result = "Instructor " + instructor + " does not have any active sections.\n";
		}
	}
	else result = "Sctions is empty!\n";
	return result;
}

string University::findSectionByLocation(string location)
{
	string result;
	string meetTimeIndent = "\t\t\t\t\t\t";
	string lineBreak = "-------------------------------------------------------------------------------\n";
	if (sections.size() > 0)
	{
		result = "\n";
		result += "Sections in room " + location + ":\n";
		result += "Call Number\tID\t\tInstructor\tMeeting Times\n";
		int found = 0;
		for (unsigned int i = 0; i < sections.size(); i++)
		{
			if (sections[i].GetLocation() == location)
			{
				result += lineBreak;
				result += to_string(sections[i].GetCallNumber()) + "\t\t" + sections[i].GetID() + "\t\t";
				result += sections[i].GetInstructorName();
				//Make sure instructor name aligns properly
				if (sections[i].GetInstructorName().size() < 8)
					result += "\t\t";
				else result += "\t";
				if (sections[i].GetMeetingTimes()->size() > 0)
				{
					//Print first meeting time on same line.
					result += sections[i].GetMeetingTimes()->at(0) + "\n";
					//Loop through all meeting times and print them underneath
					for (unsigned int x = 1; x < sections[i].GetMeetingTimes()->size(); x++)
					{
						result += meetTimeIndent;
						result += sections[i].GetMeetingTimes()->at(x) + "\n";
					}
				}
				else result += "\n";
				result += lineBreak;
				found++;
			}
		}
		if (found == 0)
		{
			result = "There are no sections at location " + location + "!\n";
		}
	}
	else result = "Sctions is empty!\n";
	return result;
}

string University::editSection(int secID, string courseID, string instructor, string location)
{
	string result;
	Section* secPtr = findSection(secID);
	if (secPtr != nullptr)
	{
		result += "Section " + to_string(secPtr->GetCallNumber()) + "\t" + secPtr->GetID() + "\t";
		result += secPtr->GetInstructorName() + "\t" + secPtr->GetLocation() + " changes: \n";
		if (courseID != "" && courseID != " ")
		{
			secPtr->SetID(courseID);
			result += "Course ID changed to " + courseID + "\n";
		}
		if (instructor != "" && instructor != " ")
		{
			secPtr->SetInstructorName(instructor);
			result += "Instructor changed to " + instructor + "\n";
		}
		if (location != "" && location != " ")
		{
			secPtr->SetLocation(location);
			result += "Location changed to " + location + "\n";
		}
	}
	else result = "Section " + to_string(secID) + " was not found!\n";

	return result;
}

string University::removeSection(int secID)
{
	string result;

	if (sections.size() > 0)
	{
		int count = 0;
		for (unsigned int i = 0; i < sections.size(); i++)
		{
			if (sections[i].GetCallNumber() == secID)
			{
				sections.erase(sections.begin() + i);
				//sections[i].~Section();
				result += "Removed section " + to_string(secID) + "!\n";
				break;
			}
			count++;
		}
		if (count == sections.size())
			result = "Section not found!\n";
	}
	else result = "Sections is empty!\n";

	return result;
}

string University::clearAllSections()
{
	string result;

	if (sections.size() > 0)
	{
		sections.clear();
		result = "Sections cleared!\n";
	}
	else result = "Sections is empty!\n";

	return result;
}
//Find section by id and return a pointer to it
Section* University::findSection(int secID)
{
	Section* secPtr = nullptr;

	for (unsigned int i = 0; i < sections.size(); i++)
	{
		if (sections[i].GetCallNumber() == secID)
		{
			secPtr = &sections[i];
			break;
		}
	}

	return secPtr;
}