#include <string>
#include <list>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <chrono>

#include "SetupText.h"

using std::transform;
using std::string;
using std::list;
using std::ifstream;
using std::vector;
using std::cout;
using std::endl;

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using theClock = std::chrono::steady_clock;


 


SetupText::SetupText()
{
	/*spamWords.push_back("Tiger");
	spamWords.push_back("World");
	spamWords.push_back("spam");
	spamWords.push_back("cloud");
	spamWords.push_back("banana");
	spamWords.push_back("percentage");
	spamWords.push_back("keyboard");
	spamWords.push_back("mouse");
	spamWords.push_back("perched");
	spamWords.push_back("nanomachines");
	spamWords.push_back("game");*/
	spamWords.push_back("anime");
	spamWords.push_back("growl");
	spamWords.push_back("mathematics");
	spamWords.push_back("debug");
	spamWords.push_back("programming");
	spamWords.push_back("sword");
	spamWords.push_back("artist");
	spamWords.push_back("online");
	spamWords.push_back("bells");
	spamWords.push_back("whistles");
	spamWords.push_back("octagon");
	spamWords.push_back("JoJo");
	spamWords.push_back("reference");
	spamWords.push_back("internet");
	spamWords.push_back("memes");
	spamWords.push_back("Nirvana");

	spamWords.push_back("grown");
	
}


void SetupText::load_file(const std::string& filename, std::string& str)
{
	// To make this program less fussy about where exactly it's run
	// from relative to the file, try looking in parent directories too.
	std::string directory = "";
	for (int i = 0; i < 6; i++) {
		ifstream f(directory + filename, std::ios_base::binary);
		if (!f.good()) {
			directory = "../" + directory;
			continue;
		}

		// Seek to the end of the file to find its length.
		f.seekg(0, std::ios_base::end);
		const size_t length = f.tellg();

		// Seek back to the start of the file and read the data.
		vector<char> buf(length);
		f.seekg(0);
		f.read(buf.data(), length);
		str.assign(buf.begin(), buf.end());

		return;
	}

	//die("Unable to find " + filename);
}
/*list<string> SetupText::ChangeCase(string& s, string& pat)
{

	string temp;

	// iterate through spamwords
	// change each character to lowercase
	list<string>::iterator it;

	for (it = spamWords.begin(); it != spamWords.end(); ++it)
	{
		temp = *it;

		//if 
		//pat.tolower();
		//for (int i = 0; i < pat.end; ++i)
		//{
			//tolower();
		//}

		return spamWords;
	}

} */

bool SetupText::check(string pat, string text)
{
	
	//Position pos = strings->find_bm(pat, text);
	
	Position pos = strings->findrk(pat, text, q);


	if (pos == -1)
	{
		return false;
	}
	return true;
}

void SetupText::searchText()
{
	string temp;
	string pat;

	

	// make a list of strings then loop through the list assigning each entry to pat
	string text;
	//text = "World is over spam";
	//text = "The Indian roller(Coracias benghalensis) is a member of the bird family Coraciidae, the rollers.It occurs widely from the Arabian Peninsula to the Indian subcontinentand is designated as Least Concern on the IUCN Red List.The bird is best known for the aerobatic displays of males during the breeding season.It is commonly found in open grasslandand scrub forest habitats, and is often seen perched on roadside bare treesand wires, which give it a good view of the ground below where it finds its prey.Its diet consists mainly of insects such as beetlesand grasshoppers, but also includes spiders, scorpions, amphibiansand small reptiles. The largest population occurs in India, and several states in India have chosen it as their state bird.This picture shows an Indian roller of the benghalensis subspecies, photographed in Kanha Tiger Reserve in the Indian state of Madhya Pradesh. ";
	//load_file("verylongstring.txt", text);
	//load_file("longtext1.txt", text);
	//load_file("wordcasetext.txt", text);
	//load_file("wordcasetext1.txt", text);
	//load_file("nirvana.txt", text);
	//load_file("3mChar.txt", text);
	load_file("6mChar.txt", text);
	//load_file("9mChar.txt", text);
	//load_file("243kChar.txt", text);
	//load_file("600kChar.txt", text);

	list<string>::iterator it;


	
	for (it = spamWords.begin(); it != spamWords.end(); ++it)
	{
	
		pat = *it;

		
		if (check(pat, text))
		{
			//Position pos = strings->find_bm(pat, text);
			Position pos = strings->findrk(pat, text, q);
	

			cout << "spam detected" << endl;
			cout << "spam word \"" << pat << "\" was found at position " << pos << endl;
			break;
		}
		else if (check(pat, text) == false)
		{

		
			cout << "The spam word \"" << pat << "\" was not found in the text" << endl;

		}
	/*auto time_taken = duration_cast<milliseconds>(endTime - startTime).count();
		cout << "It took " << time_taken << " ms." << endl;*/
	}

}