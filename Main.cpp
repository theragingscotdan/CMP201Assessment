#include <iostream>
#include <string>
#include <list>

#include "StringSetup.h"

using std::cout;
using std::endl;
using std::string;
using std::list;

StringSetup* strings;


int main(int argc, char* argv[])
{
	string text;
	text = "The Indian roller(Coracias benghalensis) is a member of the bird family Coraciidae, the rollers.It occurs widely from the Arabian Peninsula to the Indian subcontinentand is designated as Least Concern on the IUCN Red List.The bird is best known for the aerobatic displays of males during the breeding season.It is commonly found in open grasslandand scrub forest habitats, and is often seen perched on roadside bare treesand wires, which give it a good view of the ground below where it finds its prey.Its diet consists mainly of insects such as beetlesand grasshoppers, but also includes spiders, scorpions, amphibiansand small reptiles. The largest population occurs in India, and several states in India have chosen it as their state bird.This picture shows an Indian roller of the benghalensis subspecies, photographed in Kanha Tiger Reserve in the Indian state of Madhya Pradesh. ";

	string pat = "Tiger"; // insert what to look for here

	Position pos = strings->find_bm(pat, text);

	cout << "found " << pat << " at position " << pos << endl;

	return 0;
	
}

bool check()
{
	return false;
}