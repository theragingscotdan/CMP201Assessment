#include "StringSetup.h"

using std::string;

#define characters 256

StringSetup::StringSetup()
{

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
Position StringSetup::findrk(char pat[], char text[], int q)
{
	string pati;
	Position pat_len = pati.size();
	//Position text_len = text.size();
	int i, j; // used for the iterator
	int p = 0; // the hash value for the pattern
	int t = 0; // hash value for the text
	//int h = 1; need to figure out what this means

	for (i = 0; i < pat_len - 1; ++i)
	{
		// h = (h * d) % q;  // need to confirm what this fully means
		// the % q will take the remainder and use
	}

	return pat_len;
}