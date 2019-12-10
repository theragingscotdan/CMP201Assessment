#include <iostream>
#include <string>
#include <list>
#include <chrono>

#include "StringSetup.h"
#include "SetupText.h"

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using theClock = std::chrono::steady_clock;


//StringSetup* strings;
SetupText* txt;



// https://www.oreilly.com/library/view/c-cookbook/0596007612/ch04s15.html


int main(int argc, char* argv[])
{
	txt = new SetupText;
	//FillList();

	theClock::time_point startTime = theClock::now();
	txt->searchText();
	theClock::time_point endTime = theClock::now();

	auto time_taken = duration_cast<milliseconds>(endTime - startTime).count();
	cout << "It took " << time_taken << " ms." << endl;


	delete txt;
	return 0;
	
}

