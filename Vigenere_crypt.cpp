string vignere_encrypt(string_view text, string_view key)
{
	map<pair<char, int>, char> res;
	map<char, int> temp;
	temp['A'] = 26;
	int count = 1;
	for (auto i = 'B'; i <= 'Z'; i++)
	{
		temp[i] = count++;
	}

	for (auto i = 'A'; i <= 'Z'; i++)
	{
		for (auto j = 1; j <= 26; j++)
		{
			res[make_pair(i, j)] = static_cast<char>('A' + (i - 'A' + j) % 26);
		}
	}
	string str;
	str.reserve(text.length());
	int j = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (isalpha(text[i]) && isupper(text[i]))
		{
			int k = temp[text[i]];
			str += res[make_pair(key[j++ % key.length()], k)];
		}
		else
			str += text[i];
	}


	return str;
}
string vigenere_decrypt(string_view text, string_view key)
{
	map<int, char> temp;
	temp[26] = 'A';
	for (int i = 1; i <= 25; i++)
		temp[i] = char('A' + i);
	map<pair<char, int>, char> res;
	for (auto i = 'A'; i <= 'Z'; i++)
	{
		for (auto j = 1; j <= 26; j++)
		{
			res[make_pair(i, j)] = static_cast<char>('A' + (i - 'A' + j) % 26);
		}
	}

	string str;
	str.reserve(text.length());

	int count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (isupper(text[i]) && isalpha(text[i]))
		{
			for (int j = 1; j <= 26; j++)
			{
				if (res[make_pair(key[count % key.length()], j)] == text[i])
				{
					str += temp[j];
					break;
				}
			}
			count++;
		}
		else
			str += text[i];
	}
	return str;


}
int main()
{
	cout << vignere_encrypt("DIVERT TROOPS TO EAST RIDGE", "SKY") << endl;
	cout << vigenere_decrypt("VSTWBR LBMGZQ LY CSCR JSBYO", "SKY") << endl;
}
