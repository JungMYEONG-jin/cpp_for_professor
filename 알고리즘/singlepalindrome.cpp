#include <string>
#include <iostream>




using namespace std;



bool is_palindrome_check(string_view text)
{
	for (int i = 0; i < text.length() / 2; i++)
	{
		if (text[i] != text[text.length() - 1 - i])
			return false;
	}
	return true;
}

std::string solve(std::string s) {
	//..
	if (is_palindrome_check(s))
		return "OK";
	else
	{
		string test = "";
		int i = 0;
		while (i<s.size())
		{
			test = s;
			test.erase(test.begin()+i);
			if (is_palindrome_check(test))
				return "remove one";
			else
				i++;



		}
		return "not possible";
	}


}

int main()
{
	cout << solve("abba") << endl; //("OK")
	cout << solve("abbaa") << endl; //("remove one"))
	cout << solve("abbaab") << endl; //("not possible"))
	cout << solve("madmam") << endl; //("remove one"))
	cout << solve("raydarm") << endl; //("not possible"))
	cout << solve("hannah") << endl; //("OK"))

	string ts = "sexe";
	
	

}