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

void StringSetup::load_file(const std::string& filename, std::string& str)
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

Position StringSetup::find_kmp(const std::string& pat, const std::string& text)
{
	Position pat_len = pat.size();
	Position text_len = text.size();
	string P;
	int nP;

	Position j = 0;
	Position k = 0; 


	nP = 0;

	/*do
	{
		//if 




	} while (j < text_len); */

	return -1;

} 

// the basis of this algortihm came from https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// % is the modulus function. this takes the value left over from the previous sum and uses it
Position StringSetup::findrk(const string& pat, const string& text, int q)  //(char pat[], char text[], int q)
{
	//string pati;
	Position M = pat.size();
	Position N = text.size();
	//Position M = strlen(pat); // change me later!!!!!!
	//Position N = strlen(text);  // change me later!!!!!!
	int i, j; // used for the iterator
	int p = 0; // the hash value for the pattern
	int t = 0; // hash value for the text
	int h = 1; //need to figure out what this means

	for (i = 0; i < M - 1; ++i)
	{
		 h = (h * characters) % q;  // need to confirm what this fully means
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
				// instead, I need to return the current position
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
	
	return -1; // string not found
}