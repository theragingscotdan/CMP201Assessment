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
	Position findrk(const std::string& pat, const std::string& text, int q);
	
private:
	int q;



};

#endif