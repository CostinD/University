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
};