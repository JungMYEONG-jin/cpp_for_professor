#include <iostream>
#include <string>


using namespace std;


std::string to_camel_case(std::string text) {
	// TODO: Your code goes here!
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == '-')
		{

			if (text[i + 1] >= 97 && text[i + 1] <= 122)
			{
				text[i + 1] -= 32;
				
			}
			text.erase(find(text.begin(), text.end(), '-'));

		}
		else if (text[i] == '_')
		{
			if (text[i + 1] >= 97 && text[i + 1] <= 122)
			{
				text[i + 1] -= 32;
				
			}
			text.erase(find(text.begin(), text.end(), '_'));

		}


	}


	return text;

}

int main()
{

	cout << to_camel_case("the-stealth-warrior") << endl;
	cout << to_camel_case("The-Stealth-Warrior") << endl;
}