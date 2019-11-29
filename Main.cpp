#include <iostream>
#include <string>
#include <list>

#include "StringSetup.h"
#include "SetupText.h"

using std::cout;
using std::endl;
using std::string;
using std::list;

//StringSetup* strings;
SetupText* txt;



// https://www.oreilly.com/library/view/c-cookbook/0596007612/ch04s15.html


int main(int argc, char* argv[])
{
	txt = new SetupText;
	//FillList();
	txt->searchText();


	delete txt;
	return 0;
	
}

