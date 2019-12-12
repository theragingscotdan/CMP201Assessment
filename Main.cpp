#include <iostream>
#include <string>
#include <list>
#include <chrono>
#include <fstream>

#include "StringSetup.h"
#include "SetupText.h"

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using theClock = std::chrono::steady_clock;
using std::ofstream;


//StringSetup* strings;
SetupText* txt;


int main(int argc, char* argv[])
{
	txt = new SetupText;

	ofstream my_file("Testing/rklesswords6m.csv");
	my_file << "time taken \n";

	for (int i = 0; i < 100; ++i) {
		theClock::time_point startTime = theClock::now();
		txt->searchText();
		theClock::time_point endTime = theClock::now();

		auto time_taken = duration_cast<milliseconds>(endTime - startTime).count();
		cout << "It took " << time_taken << " ms." << endl;
		my_file << time_taken << endl;
	}

	delete txt;
	return 0;
	
}

