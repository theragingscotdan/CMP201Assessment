#include <string>
#include <list>
#include <iostream>

#include "SetupText.h"


using std::string;
using std::list;
using std::cout;
using std::endl;


SetupText::SetupText()
{
	spamWords.push_back("Tiger");
	spamWords.push_back("World");
	spamWords.push_back("spam");
	spamWords.push_back("Cloud");
	spamWords.push_back("Banana");
	spamWords.push_back("Percentage");
	spamWords.push_back("Keyboard");
	spamWords.push_back("Mouse");
	spamWords.push_back("perched");
	spamWords.push_back("nanomachines");
	spamWords.push_back("game");
	spamWords.push_back("anime");
	
}

string SetupText::ChangeCase(const string text)
{
	/*
		char a, b;

		return(tolower(a) == b);

		string temp;

		std::transform(text.begin(), text.end())*/
		return text;
}

bool SetupText::check(string pat, string text)
{
	Position pos = strings->find_bm(pat, text);

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
	text = "The Indian roller(Coracias benghalensis) is a member of the bird family Coraciidae, the rollers.It occurs widely from the Arabian Peninsula to the Indian subcontinentand is designated as Least Concern on the IUCN Red List.The bird is best known for the aerobatic displays of males during the breeding season.It is commonly found in open grasslandand scrub forest habitats, and is often seen perched on roadside bare treesand wires, which give it a good view of the ground below where it finds its prey.Its diet consists mainly of insects such as beetlesand grasshoppers, but also includes spiders, scorpions, amphibiansand small reptiles. The largest population occurs in India, and several states in India have chosen it as their state bird.This picture shows an Indian roller of the benghalensis subspecies, photographed in Kanha Tiger Reserve in the Indian state of Madhya Pradesh. ";

	//auto it = spamWords.begin();
	//string pat = "Tiger"; // insert what to look for here
	//for (int i = 0; i < spamWords.size(); ++i)

	list<string>::iterator it;

	for (it = spamWords.begin(); it != spamWords.end(); ++it)
	{
		//pat = it->data;
		pat = *it;


		if (check(pat, text))
		{
			Position pos = strings->find_bm(pat, text);
			cout << "spam detected" << endl;
			cout << "spam word \"" << pat << "\" was found at position " << pos << endl;
			break;
		}
		else if (check(pat, text) == false)
		{
			cout << "No spam found" << endl;
		}
		//spamWords.pop_front();
	}
}