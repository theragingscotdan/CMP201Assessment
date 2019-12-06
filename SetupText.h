#pragma once

#include <string>
#include <list>

#include "StringSetup.h"

class SetupText
{
public:
	SetupText();
	//SetupList();
	//std::string ChangeCase(const std::string text);
	bool check(std::string pat, std::string text);
	void searchText();

protected:
	StringSetup* strings;
	//inline bool caseCompare(char a, char b);
	std::list<std::string> ChangeCase(std::string& s, std::string& pat);

private:
	std::list<std::string> spamWords;
	int q = 157;

};