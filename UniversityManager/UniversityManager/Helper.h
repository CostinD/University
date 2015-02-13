#pragma once

#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> StringToVector(string cmd)
{
	istringstream is(cmd);
	vector<string> vs;
	string s;
	while (!is.eof())
	{
		if (vs.size() == 0)
		{
			getline(is, s, ' ');
		}
		else
		{
			getline(is, s, ';');
		}
		vs.push_back(s);
	}
	return vs;
}