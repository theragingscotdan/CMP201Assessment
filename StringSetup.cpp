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
			//show_context(pat, j);
			//show_context(text, j);
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
	/*string S;
	string W;

	string W;
	int nP;

	Position j;
	Position k; */
	return -1;

} 