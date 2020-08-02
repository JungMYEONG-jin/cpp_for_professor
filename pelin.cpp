#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <assert.h>
#include <string>
#include <map>

using namespace std;


bool is_palindrome(string_view text)
{
	for (int i = 0; i < text.length()/2; i++)
	{
		if (text[i] != text[text.length() - 1 - i])
			return false;
	}
	return true;
}

// MyCode

string get_longest_palindrome(string_view code)
{
	unsigned int len = 1;
	string test = "";
	map<int, string> res;
	int j = 0;
	int idx = 0;
	while (len <= code.length())
	{
		
		while (j + len <= code.length())
		{
			for (int i = j; i < len+j; i++)
			{
				test += code[i];
				
			}
			if (is_palindrome(test))
			{
				idx = len;
				res.insert(pair(idx, test));// map restricts duplicated key so it can secure its first idx value
				
			}
			test.clear();
			j++;
		}
		j = 0;
		len++;
	}

	return res[idx];

}

// BookCode

string longest_palindrome(string_view text)
{
	size_t const len = text.size();

	size_t longestBegin = 0;
	size_t maxlen = 1;
	vector<bool> table(len * len, false);

	for (size_t i = 0; i < len; i++)
		table[i * len + i] = true;


	for (size_t i = 0; i < len - 1; i++)
	{
		if (text[i] == text[i + 1])
		{
			table[i * len + i + 1] = true;
			if (maxlen < 2)
			{
				longestBegin = 1;
				maxlen = 2;
			}
		}
	}


	for (size_t k = 3; k <= len; k++)
	{
		for (size_t i = 0; i < len - k + 1; i++)
		{
			size_t j = i + k - 1;
			if (text[i] == text[j] && table[(i + 1) * len + j - 1])
			{
				table[i * len + j] = true;
				if (maxlen < k)
				{
					longestBegin = i;
					maxlen = k;
				}
			}
		}
	}

	return string(text.substr(longestBegin, maxlen));







}






int main()
{

	cout << is_palindrome("sexxes") << endl;
	cout << is_palindrome("sos") << endl;
	cout << get_longest_palindrome("sahararahnide") << endl;
	cout << get_longest_palindrome("level") << endl;
}

