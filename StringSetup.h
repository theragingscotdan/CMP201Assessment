#pragma once

#ifndef _STRINGSETUP_H
#define _STRINGSETUP_H

#include <string>




using Position = long long int;

class StringSetup
{
public:
	StringSetup();
	/** Load the whole of a text file into str. */
	void load_file(const std::string& filename, std::string& str);

	// boyer-moore algorithm
	Position find_bm(const std::string& pat, const std::string& text);
	Position find_kmp(const std::string& pat, const std::string& text);
	Position findrk(char pat[], char txt[], int q);
	
private:
	int q = 157;



};

#endif