
long long sum_digit(long long num)
{

	long long res = 0;
	while (num > 0)
	{
		res += num % 10;
		num /= 10;
	}
	return res;

}

bool lonely(long long number)
{
	
	string k = to_string(number);

	if (k.find('1') == k.npos)
		return false;

	if (k.size() == 1 && k[0] == '1')
		return true;





	int mins = 9999;
	int min_lone = 9999;
	int min_friend = 9999;
	int p = k.size();
	for (int i = 0; i < k.size(); i++)
	{
		string left = k.substr(max(0, i-(k[i] - '0')), min(i, k[i]-'0'));
		string right = k.substr(i + 1, min(p-i-1, k[i] - '0'));
		long long loneliness = 0;
		if (!left.empty() && !right.empty())
			loneliness = sum_digit(stoll(left)) + sum_digit(stoll(right));
		else if (left.empty() && !right.empty())
			loneliness = sum_digit(stoll(right));
		else if (!left.empty() && right.empty())
			loneliness = sum_digit(stoll(left));
		long long count = left.size() + right.size();
		
		
		if (k[i] == '1' && loneliness==0)
			count = -1;
		cout << left << "  " << right << " " << count << " " << loneliness << " " << min_lone <<" "<<min_friend<<" "<<mins<< endl;
		//cout << left << " " << right << " " << loneliness << endl;
		if (loneliness < min_lone)
		{
			mins= k[i]-'0';
			min_lone = loneliness;
			min_friend = count;

		}
		else if (loneliness == min_lone && count < min_friend)
		{
			if(k[i]-'0'<mins || k[i]=='1')
				mins = k[i] - '0';
			min_friend = count;
		}

	}
	
	return mins == 1;

}
