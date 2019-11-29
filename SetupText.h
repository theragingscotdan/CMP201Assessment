#pragma once

#include <string>
#include <list>

#include "StringSetup.h"

class SetupText
{
public:
	SetupText();
	//SetupList();
	std::string ChangeCase(const std::string text);
	bool check(std::string pat, std::string text);
	void searchText();

protected:
	StringSetup* strings;

private:
	std::list<std::string> spamWords;

};