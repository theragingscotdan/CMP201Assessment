#include "StringSetup.h"

#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::ifstream;
using std::vector;

#define characters 256

StringSetup::StringSetup()
{

}

//void StringSetup::load_file(const std::string& filename, std::string& str)
//{
//	// To make this program less fussy about where exactly it's run
//	// from relative to the file, try looking in parent directories too.
//	std::string directory = "";
//	for (int i = 0; i < 6; i++) {
//		ifstream f(directory + filename, std::ios_base::binary);
//		if (!f.good()) {
//			directory = "../" + directory;
//			continue;
//		}
//
//		// Seek to the end of the file to find its length.
//		f.seekg(0, std::ios_base::end);
//		const size_t length = f.tellg();
//
//		// Seek back to the start of the file and read the data.
//		vector<char> buf(length);
//		f.seekg(0);
//		f.read(buf.data(), length);
//		str.assign(buf.begin(), buf.end());
//
//		return;
//	}
//
//	//die("Unable to find " + filename);
//}


Position StringSetup::find_bm(const string& pat, const string& text) 
{
	Position pat_len = pat.size();
	Position text_len = text.size();

	int skip[256];
	for (Position i = 0; i < 256; ++i)
	{
		skip[i] = pat_len;
	}
	for (int i = 0; i < pat_len; ++i)
		skip[int(pat[i])] = (pat_len - 1) - i;

	for (int i = 0; i < text_len - pat_len; ++i) {

		//show_context(pat, i);
		//(text, i);

		int s = skip[int(text[i + pat_len - 1])];
		if (s != 0) {
			i += s - 1;
			continue;
		}

		
		int j;
		for (j = 0; j < pat_len; j++) {
			
			if (text[i + j] != pat[j]) {
				break; // Doesn't match here.
			}
		}
		if (j == pat_len) {
			return i; // Matched here.
		}
	}
	return -1; // Not found.
}


// the basis of this algortihm came from https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

// i will comment the aspects of the code that needed to be changed in order to fit my application's requirements and
// what is already existing

// I changed the function to return a position as opposed to the original which was a void
// this is because I want to know and return the position of the word in the text to pass into my SetupText.cpp
// since I am using strings, I set the passed in variables to be const strings as opposed to the char[] used
Position StringSetup::findrk(const string& pat, const string& text, int q) 
{
	//string pati;
	Position M = pat.size(); // to match my scenario since position already exists and i can use .size() to work out the length
	Position N = text.size(); // this is adapted to fix
	
	int i, j; // used for the iterator
	int p = 0; // the hash value for the pattern
	int t = 0; // hash value for the text
	int h = 1; //need to figure out what this means

	for (i = 0; i < M - 1; ++i)
	{
		 h = (h * characters) % q;  // // % is the modulus function. this takes the value left over from the previous sum and uses it
		// the % q will take the remainder and use
	}

	for (i = 0; i < M; ++i)
	{
		p = (characters * p + pat[i]) % q; // hash of the pattern
		t = (characters * t + text[i]) % q;// hash of the text
	}

	// compare the text to the pattern
	for (i = 0; i <= N - M; ++i)
	{
		// cehck  
		if (p == t)
		{
			for (j = 0; j < M; ++j)
			{
				if (text[i + j] != pat[j])
				{
					//return -1;
					break;
				}
			}
			if (j == M)
			{
				// the original code had this as a cout printing the found
				// in the context of my own code however, this is not suitable
				// instead, I need to return the current position which is M (position of the word)
				return M;
			}
		}
		if (i < N - M)
		{
			t = (characters * (t - text[i] * h) + text[i + M]) % q;

			if (t < 0)
			{
				t = (t + q);
			}
		}
	}
	
	return -1; // string not found so return not found
}