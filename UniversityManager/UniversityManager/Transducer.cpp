#include "Transducer.h"
#include "Helper.h"

string Transducer::Transduce(string cmd)
{
	string result;
	vector<string> token = StringToVector(cmd);

	if ((token[0] == "HELP") || (token[0] == "H"))
	{
		string indent = "       ";
		string dots = ".....";
		string lineBreak = "--------------------------------------------------------------------\n";
		result = "Commands:\n";
		result += lineBreak;
		result += indent + "HELP (H)\n";
		result += indent + "ADDSECTION (AS)<sectionID>;<courseID>;<instructor>;<location>\n";
		result += indent + "ADDMEETINGTIMETOSECTION (AMT)<sectionID>;<meetingTime>\n";
		result += indent + "ADDSTUDENTTOSECTION (AST)<sectionID>;<studentID>\n";
		result += indent + "REMOVEMEETINGTIMEFROMSECTION (RMT)<sectionID>;<meetingTime>\n";
		result += indent + "REMOVESTUDENTFROMSECTION (RST)<sectionID>;<studentID>\n";
		result += indent + "DISPLAYALLSECTIONS (DS)\n";
		result += indent + "DISPLAYALLSECTIONSANDSTUDENTS (DSAS)\n";
		result += indent + "FINDSECTIONBYCOURSEID (FSBC)<courseID>\n";
		result += indent + "FINDSECTIONBYLOCATION (FSBL)<location>\n";
		result += indent + "EDITSECTION (ES)<sectionID>;<newCourseID>;<newInstructor>;<newLocation>\n";
		result += indent + "REMOVESECTION (RS)<sectionID>\n";
		result += indent + "CLEARALLSECTIONS (CAS)\n";

		//ADD REMAINING COMMANDS HERE
	}
	else if ((token[0] == "ADDSECTION") || (token[0] == "AS"))
	{
		result = university.addSection(stoi(token[1], nullptr, 10), token[2], token[3], token[4]);
	}
	else if ((token[0] == "ADDMEETINGTIMETOSECTION") || (token[0] == "AMT"))
	{
		result = university.addMeetingTimeToSection(stoi(token[1], nullptr, 10), token[2]);
	}
	else if ((token[0] == "ADDSTUDENTTOSECTION") || (token[0] == "AST"))
	{
		result = university.addStudentToSection(stoi(token[1], nullptr, 10), stoi(token[2], nullptr, 10));
	}
	else if ((token[0] == "REMOVEMEETINGTIMEFROMSECTION") || (token[0] == "RMT"))
	{
		result = university.removeMeetingTimeFromSection(stoi(token[1], nullptr, 10), token[2]);
	}
	else if ((token[0] == "REMOVESTUDENTFROMSECTION") || (token[0] == "RST"))
	{
		result = university.removeStudentFromSection(stoi(token[1], nullptr, 10), stoi(token[2],nullptr,10));
	}
	else if ((token[0] == "DISPLAYALLSECTIONS") || (token[0] == "DS"))
	{
		result = university.displaySections(false);
	}
	else if ((token[0] == "DISPLAYALLSECTIONSANDSTUDENTS") || (token[0] == "DSAS"))
	{
		result = university.displaySections(true);
	}
	else if ((token[0] == "FINDSECTIONBYCOURSEID") || (token[0] == "FSBC"))
	{
		result = university.findSectionByCourseID(token[1]);
	}
	else if ((token[0] == "FINDSECTIONBYINSTRUCTOR") || (token[0] == "FSBI"))
	{
		result = university.findSectionByInstructor(token[1]);
	}
	else if ((token[0] == "FINDSECTIONBYLOCATION") || (token[0] == "FSBL"))
	{
		result = university.findSectionByLocation(token[1]);
	}
	else if ((token[0] == "EDITSECTION") || (token[0] == "ES"))
	{
		result = university.editSection(stoi(token[1], nullptr, 10), token[2], token[3], token[4]);
	}
	else if ((token[0] == "REMOVESECTION") || (token[0] == "RS"))
	{
		result = university.removeSection(stoi(token[1],nullptr,10));
	}
	else if ((token[0] == "CLEARALLSECTIONS") || (token[0] == "CAS"))
	{
		result = university.clearAllSections();
	}

	return result;
}